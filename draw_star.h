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
    void Init();
    void Exit();
    void Load();
    void Unload(ReloadDesc *pReloadDesc);
    void Update(float deltaTime, CameraMatrix &mProjectView);
    void Draw(Cmd *pCmd);

private:
    float *vertices;
    int vertexCount;

    mat4 viewMat{};
    vec4 position{};
    vec3 lightPosition{0, 0, 0};
    vec3 lightColor{0.9f, 0.9f, 0.7f};
};


#endif // STARFIELD_DRAW_STAR_H
