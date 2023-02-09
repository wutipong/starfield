#include <cstdlib>
#include <iostream>

#include <IApp.h>
#include <IFileSystem.h>
#include <IGraphics.h>
#include <IResourceLoader.h>
#include <IUI.h>

class MainApp : public IApp
{
private:
    static constexpr uint32_t gImageCount = 3;

    Renderer *pRenderer = NULL;
    UIComponent *pGuiWindow = NULL;
    SwapChain *pSwapChain = NULL;
    RenderTarget *pDepthBuffer = NULL;
    Queue *pGraphicsQueue = NULL;


public:
    bool Init() override
    { // FILE PATHS
        fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_SHADER_SOURCES, "Shaders");
        fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_SHADER_BINARIES, "CompiledShaders");
        fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_GPU_CONFIG, "GPUCfg");
        fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_TEXTURES, "Textures");
        fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_FONTS, "Fonts");
        fsSetPathForResourceDir(pSystemFileIO, RM_DEBUG, RD_SCREENSHOTS, "Screenshots");
        fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_SCRIPTS, "Scripts");
        fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_OTHER_FILES, "Noesis");

        // window and renderer setup
        RendererDesc settings{};
        settings.mD3D11Supported = true;
        settings.mGLESSupported = false;

        initRenderer(GetName(), &settings, &pRenderer);
        // check for init success
        if (!pRenderer)
            return false;

        initResourceLoaderInterface(pRenderer);

        UserInterfaceDesc uiRenderDesc = {};
        uiRenderDesc.pRenderer = pRenderer;
        initUserInterface(&uiRenderDesc);

        UIComponentDesc guiDesc = {};
        guiDesc.mStartPosition = vec2(mSettings.mWidth * 0.01f, mSettings.mHeight * 0.2f);
        uiCreateComponent(GetName(), &guiDesc, &pGuiWindow);

        // Take a screenshot with a button.
        ButtonWidget screenshot;
        UIWidget *pScreenshot = uiCreateComponentWidget(pGuiWindow, "Screenshot", &screenshot, WIDGET_TYPE_BUTTON);

        waitForAllResourceLoads();

        return true;
    }
    void Exit() override
    {
        exitUserInterface();
        exitResourceLoaderInterface(pRenderer);
        exitRenderer(pRenderer);
        pRenderer = NULL;
    }

    bool Load(ReloadDesc *pReloadDesc) override
    {

        if (pReloadDesc->mType & (RELOAD_TYPE_RESIZE | RELOAD_TYPE_RENDERTARGET))
        {
            SwapChainDesc swapChainDesc = {};
            swapChainDesc.mWindowHandle = pWindow->handle;
            swapChainDesc.mPresentQueueCount = 1;
            swapChainDesc.ppPresentQueues = &pGraphicsQueue;
            swapChainDesc.mWidth = mSettings.mWidth;
            swapChainDesc.mHeight = mSettings.mHeight;
            swapChainDesc.mImageCount = gImageCount;
            swapChainDesc.mColorFormat = getRecommendedSwapchainFormat(true, true);
            swapChainDesc.mEnableVsync = mSettings.mVSyncEnabled;
            swapChainDesc.mFlags = SWAP_CHAIN_CREATION_FLAG_ENABLE_FOVEATED_RENDERING_VR;
            addSwapChain(pRenderer, &swapChainDesc, &pSwapChain);

            if (pSwapChain == nullptr)
                return false;

            RenderTargetDesc depthRT = {};
            depthRT.mArraySize = 1;
            depthRT.mClearValue.depth = 0.0f;
            depthRT.mClearValue.stencil = 0;
            depthRT.mDepth = 1;
            depthRT.mFormat = TinyImageFormat_D32_SFLOAT;
            depthRT.mStartState = RESOURCE_STATE_DEPTH_WRITE;
            depthRT.mHeight = mSettings.mHeight;
            depthRT.mSampleCount = SAMPLE_COUNT_1;
            depthRT.mSampleQuality = 0;
            depthRT.mWidth = mSettings.mWidth;
            depthRT.mFlags = TEXTURE_CREATION_FLAG_ON_TILE | TEXTURE_CREATION_FLAG_VR_MULTIVIEW;
            addRenderTarget(pRenderer, &depthRT, &pDepthBuffer);
            if (pDepthBuffer == nullptr)
                return false;
        }

        UserInterfaceLoadDesc uiLoad = {};
        uiLoad.mColorFormat = pSwapChain->ppRenderTargets[0]->mFormat;
        uiLoad.mHeight = mSettings.mHeight;
        uiLoad.mWidth = mSettings.mWidth;
        uiLoad.mLoadType = pReloadDesc->mType;
        loadUserInterface(&uiLoad);


        return true;
    }
    void Unload(ReloadDesc *pReloadDesc) override {
        waitQueueIdle(pGraphicsQueue);

		unloadUserInterface(pReloadDesc->mType);
		if (pReloadDesc->mType & (RELOAD_TYPE_RESIZE | RELOAD_TYPE_RENDERTARGET))
		{
			removeSwapChain(pRenderer, pSwapChain);
			removeRenderTarget(pRenderer, pDepthBuffer);
		}
    }

    void Update(float deltaTime) override {}
    void Draw() override {}

    const char *GetName() override { return "StarField test"; }
};

DEFINE_APPLICATION_MAIN(MainApp);