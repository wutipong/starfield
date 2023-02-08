#include <cstdlib>
#include <iostream>

#include <IApp.h>

class MainApp : public IApp
{
public:
    bool Init() override {return true;}
    void Exit() override {}

    bool Load(ReloadDesc *pReloadDesc) override {return true;}
    void Unload(ReloadDesc *pReloadDesc) override {}

    void Update(float deltaTime) override {}
    void Draw() override {}

    const char *GetName() override {return "StarField test";}
};

DEFINE_APPLICATION_MAIN(MainApp);