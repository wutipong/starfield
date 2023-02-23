//
// Created by mr_ta on 2/19/2023.
//

#ifndef STARFIELD_DRAW_STAR_H
#define STARFIELD_DRAW_STAR_H

#include <ICameraController.h>
#include <IGraphics.h>
#include <IOperatingSystem.h>
#include <Math/MathTypes.h>

class DrawStar
{
public:
    void Init(uint32_t imageCount);
    void Exit();
    void Load(ReloadDesc *pReloadDesc, Renderer *pRenderer, SwapChain *pSwapChain, RenderTarget *pDepthBuffer,
              uint32_t imageCount);
    void Unload(ReloadDesc *pReloadDesc, Renderer *pRenderer);
    void Update(float deltaTime, CameraMatrix &cameraMatrix);
    void PreDraw(uint32_t frameIndex);
    void Draw(Cmd *pCmd, uint32_t frameIndex);

private:
    int vertexCount{};

    vec3 position{};
    vec3 lightPosition{0, 0, 0};
    vec3 lightColor{0.9f, 0.9f, 0.7f};

    Shader *pShader;
    RootSignature *pRootSignature;
    DescriptorSet *pDescriptorSetUniforms;
    Buffer **pProjViewUniformBuffer = nullptr;
    Buffer *pSphereVertexBuffer = nullptr;
    Pipeline *pSpherePipeline;

    struct UniformBlock
    {
        CameraMatrix mProjectView;
        mat4 mToWorldMat;
        vec4 mColor;

        vec3 mLightPosition;
        vec3 mLightColor;
    } uniform = {};
};


#endif // STARFIELD_DRAW_STAR_H
