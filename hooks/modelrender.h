#pragma once

//void hook_DrawModelExecute(void* ctx, void *state, const void *pInfo, void* pCustomBoneToWorld);
void hook_modelRender(void *this, void* ctx, void *state, const void *pInfo, void* pCustomBoneToWorld);
