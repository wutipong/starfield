#include "draw_star.h"
#include <IResourceLoader.h>
#include <stb_ds.h>

void DrawStar::Init(uint32_t imageCount)
{
    float *vertices{};
    generateSpherePoints(&vertices, &vertexCount, 1, 1.0f);

    uint64_t sphereDataSize = vertexCount * sizeof(float);
    BufferLoadDesc sphereVbDesc = {};
    sphereVbDesc.mDesc.mDescriptors = DESCRIPTOR_TYPE_VERTEX_BUFFER;
    sphereVbDesc.mDesc.mMemoryUsage = RESOURCE_MEMORY_USAGE_GPU_ONLY;
    sphereVbDesc.mDesc.mSize = sphereDataSize;
    sphereVbDesc.pData = vertices;
    sphereVbDesc.ppBuffer = &pSphereVertexBuffer;
    addResource(&sphereVbDesc, NULL);

    tf_free(vertices);

    arrsetlen(pProjViewUniformBuffer, imageCount);

    BufferLoadDesc ubDesc = {};
    ubDesc.mDesc.mDescriptors = DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    ubDesc.mDesc.mMemoryUsage = RESOURCE_MEMORY_USAGE_CPU_TO_GPU;
    ubDesc.mDesc.mSize = sizeof(UniformBlock);
    ubDesc.mDesc.mFlags = BUFFER_CREATION_FLAG_PERSISTENT_MAP_BIT;
    ubDesc.pData = NULL;
    for (uint32_t i = 0; i < imageCount; ++i)
    {
        ubDesc.ppBuffer = &pProjViewUniformBuffer[i];
        addResource(&ubDesc, nullptr);
    }
}

void DrawStar::Exit()
{
    for (int i = 0; i < arrlen(pProjViewUniformBuffer); i++)
    {
        removeResource(pProjViewUniformBuffer[i]);
    }

    arrfree(pProjViewUniformBuffer);

    removeResource(pSphereVertexBuffer);
}

void DrawStar::Load(ReloadDesc *pReloadDesc, Renderer *pRenderer, SwapChain *pSwapChain, RenderTarget *pDepthBuffer,
                    uint32_t imageCount)
{
    if (pReloadDesc->mType & RELOAD_TYPE_SHADER)
    {
        ShaderLoadDesc basicShader = {};
        basicShader.mStages[0] = {"basic.vert", NULL, 0, NULL, SHADER_STAGE_LOAD_FLAG_ENABLE_VR_MULTIVIEW};
        basicShader.mStages[1] = {"basic.frag", NULL, 0};

        addShader(pRenderer, &basicShader, &pShader);

        RootSignatureDesc rootDesc = {};
        rootDesc.mShaderCount = 1;
        rootDesc.ppShaders = &pShader;

        addRootSignature(pRenderer, &rootDesc, &pRootSignature);

        DescriptorSetDesc desc = {pRootSignature, DESCRIPTOR_UPDATE_FREQ_PER_FRAME, imageCount};
        addDescriptorSet(pRenderer, &desc, &pDescriptorSetUniforms);
    }

    if (pReloadDesc->mType & (RELOAD_TYPE_SHADER | RELOAD_TYPE_RENDERTARGET))
    {
        // layout and pipeline for sphere draw
        VertexLayout vertexLayout = {};
        vertexLayout.mAttribCount = 2;
        vertexLayout.mAttribs[0].mSemantic = SEMANTIC_POSITION;
        vertexLayout.mAttribs[0].mFormat = TinyImageFormat_R32G32B32_SFLOAT;
        vertexLayout.mAttribs[0].mBinding = 0;
        vertexLayout.mAttribs[0].mLocation = 0;
        vertexLayout.mAttribs[0].mOffset = 0;
        vertexLayout.mAttribs[1].mSemantic = SEMANTIC_NORMAL;
        vertexLayout.mAttribs[1].mFormat = TinyImageFormat_R32G32B32_SFLOAT;
        vertexLayout.mAttribs[1].mBinding = 0;
        vertexLayout.mAttribs[1].mLocation = 1;
        vertexLayout.mAttribs[1].mOffset = 3 * sizeof(float);

        RasterizerStateDesc rasterizerStateDesc = {};
        rasterizerStateDesc.mCullMode = CULL_MODE_NONE;

        RasterizerStateDesc sphereRasterizerStateDesc = {};
        sphereRasterizerStateDesc.mCullMode = CULL_MODE_FRONT;

        DepthStateDesc depthStateDesc = {};
        depthStateDesc.mDepthTest = true;
        depthStateDesc.mDepthWrite = true;
        depthStateDesc.mDepthFunc = CMP_GEQUAL;

        PipelineDesc desc = {};
        desc.mType = PIPELINE_TYPE_GRAPHICS;
        GraphicsPipelineDesc &pipelineSettings = desc.mGraphicsDesc;
        pipelineSettings.mPrimitiveTopo = PRIMITIVE_TOPO_TRI_LIST;
        pipelineSettings.mRenderTargetCount = 1;
        pipelineSettings.pDepthState = &depthStateDesc;
        pipelineSettings.pColorFormats = &pSwapChain->ppRenderTargets[0]->mFormat;
        pipelineSettings.mSampleCount = pSwapChain->ppRenderTargets[0]->mSampleCount;
        pipelineSettings.mSampleQuality = pSwapChain->ppRenderTargets[0]->mSampleQuality;
        pipelineSettings.mDepthStencilFormat = pDepthBuffer->mFormat;
        pipelineSettings.pRootSignature = pRootSignature;
        pipelineSettings.pShaderProgram = pShader;
        pipelineSettings.pVertexLayout = &vertexLayout;
        pipelineSettings.pRasterizerState = &sphereRasterizerStateDesc;
        pipelineSettings.mVRFoveatedRendering = true;
        addPipeline(pRenderer, &desc, &pSpherePipeline);
    }
    for (uint32_t i = 0; i < imageCount; ++i)
    {
        DescriptorData params[1] = {};

        params[0].pName = "uniformBlock";
        params[0].ppBuffers = &pProjViewUniformBuffer[i];
        updateDescriptorSet(pRenderer, i, pDescriptorSetUniforms, 1, params);
    }
}

void DrawStar::Unload(ReloadDesc *pReloadDesc, Renderer *pRenderer)
{
    if (pReloadDesc->mType & (RELOAD_TYPE_SHADER | RELOAD_TYPE_RENDERTARGET))
    {
        removePipeline(pRenderer, pSpherePipeline);
    }

    if (pReloadDesc->mType & RELOAD_TYPE_SHADER)
    {
        removeDescriptorSet(pRenderer, pDescriptorSetUniforms);
        removeRootSignature(pRenderer, pRootSignature);
        removeShader(pRenderer, pShader);
    }
}

void DrawStar::Update(float deltaTime, CameraMatrix &cameraMatrix)
{
    uniform.mProjectView = cameraMatrix;
    uniform.mColor = {1.0f, 1.0f, 1.0f, 1.0f};
    uniform.mToWorldMat = mat4{}.translation(position);
    uniform.mLightColor = lightColor;
    uniform.mLightPosition = lightPosition;
}

void DrawStar::Draw(Cmd *pCmd, uint32_t frameIndex)
{
    constexpr uint32_t sphereVbStride = sizeof(float) * 6;

    BufferUpdateDesc viewProjCbv = {pProjViewUniformBuffer[frameIndex]};
    beginUpdateResource(&viewProjCbv);
    *(UniformBlock *)viewProjCbv.pMappedData = uniform;
    endUpdateResource(&viewProjCbv, nullptr);

    cmdBindPipeline(pCmd, pSpherePipeline);
    cmdBindDescriptorSet(pCmd, frameIndex, pDescriptorSetUniforms);
    cmdBindVertexBuffer(pCmd, 1, &pSphereVertexBuffer, &sphereVbStride, NULL);

    cmdDraw(pCmd, vertexCount / 6, 0);
}
