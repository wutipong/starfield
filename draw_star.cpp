//
// Created by mr_ta on 2/19/2023.
//

#include "draw_star.h"

void DrawStar::Init() { generateSpherePoints(&vertices, &vertexCount, 1, 1.0f); }
void DrawStar::Exit() { tf_free(vertices); }
void DrawStar::Load() {}
void DrawStar::Unload(ReloadDesc *pReloadDesc) {}
void DrawStar::Update(float deltaTime, CameraMatrix &mProjectView) { DrawStar::viewMat = viewMat; }
void DrawStar::Draw(Cmd *pCmd) {}
