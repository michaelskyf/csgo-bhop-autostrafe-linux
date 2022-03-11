#include "engine.h"
#include "../interfaces.h"
#include "../utils/utils.h"

int engine_GetLocalPlayer(void)
{
	static int (*func)(void*);
	void *engine = interfaces.engine;
	if(!func)
	{
		func = get_vfunc(engine, 12, 0);
	}

	return func(engine);
}

void engine_GetViewAngles(struct Vector *angle)
{
	static void (*func)(void*, void*);
	void *engine = interfaces.engine;
	if(!func)
	{
		func = get_vfunc(engine, 18, 0);
	}

	return func(engine, angle);
}
