#ifndef HOOK_H
#define HOOK_H

#include <stdbool.h>

#include "../offsets.h"
#include "../sdk/sdk_common.h"
#include "modelrender.h"

struct hook
{
	void *hook;
	void *interface;
	int offset;
	void *original;
};

void hooks_init(void);
void hooks_exit(void);

enum functions
{
	CREATE_MOVE = 0,
	MODEL_RENDER,
	NUM_FUNC
};

extern struct hook hooks[];

#endif
