#include "sdk_common.h"
#include "../interfaces.h"
#include "../utils/utils.h"

int engine_GetLocalPlayer(void)
{
	FUNCTION_BODY(int, interfaces.engine, 12);
}

void engine_GetViewAngles(struct Vector *angle)
{
	FUNCTION_BODY(void, interfaces.engine, 18, angle);
}
