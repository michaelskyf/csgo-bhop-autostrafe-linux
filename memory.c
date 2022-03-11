#include <stdio.h>

#include "memory.h"
#include "interfaces.h"
#include "utils/utils.h"

struct memory memory;

void *get_abs_addr(void *ptr, int offset, int size)
{
	return ptr + *(int*)(ptr + offset) + size;
}

void memory_init(void)
{
	void *hudprocessinput = get_vfunc(interfaces.client, 10, 0);
	memory.clientMode = ((void* (*)(void))get_abs_addr(hudprocessinput + 11, 1, 5))();

	printf("Memory loaded!\n");
}
