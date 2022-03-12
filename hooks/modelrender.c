#include <stdio.h>
#include "modelrender.h"
#include "hooks.h"

void hook_modelRender(void *this, void* ctx, void *state, const void *pInfo, void* pCustomBoneToWorld)
{
	((void (*)())hooks[MODEL_RENDER].original)(this, ctx, state, pInfo, pCustomBoneToWorld);
	printf("Hello VMT!\n");
}
