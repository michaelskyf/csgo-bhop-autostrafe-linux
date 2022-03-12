#ifndef SDK_H
#define SDK_H

#include "vector.h"
#include "EntityList.h"
#include "client.h"
#include "recv.h"
#include "engine.h"
#include "usercmd.h"
#include "GlowObjectManager.h"
#include "glow.h"
#include "UtlVector.h"

#define FUNCTION_BODY(ret_type, interface, index, ...) \
	static ret_type(*func)(); \
	if(!func) \
	{ \
		func = get_vfunc(interface, index, 0); \
	} \
	return func(interface, ##__VA_ARGS__)

#endif
