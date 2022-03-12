#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>
#include <string.h>

#include "hooks.h"
#include "../memory.h"
#include "../interfaces.h"
#include "../utils/utils.h"

#include "createmove.h"
#include "modelrender.h"

struct hook hooks[NUM_FUNC];

static int pagesize;
static int pagemask;

static int unprotect(void* region) {
    mprotect((void*) ((intptr_t)region & pagemask), pagesize, PROT_READ|PROT_WRITE|PROT_EXEC);
    return PROT_READ|PROT_EXEC;
}

static void protect(void* region, int protection) {
    mprotect((void*) ((intptr_t)region & pagemask), pagesize, protection);
}

static void *vmt_hook(void *interface, void *hook, int offset)
{
        intptr_t vtable = *(intptr_t*)interface;
        intptr_t entry = vtable + sizeof(intptr_t) * offset;
        intptr_t original = *(intptr_t*)entry;

        int orig_prot = unprotect((void*)entry);
        *(intptr_t*)entry = (intptr_t)hook;
        protect((void*)entry, orig_prot);

        return (void*)original;
}

#define HOOK(func_num, hook_fn, intfce, off) \
	hooks[func_num].hook = hook_fn; hooks[func_num].interface = intfce; hooks[func_num].offset = off; \
	hooks[func_num].original = vmt_hook(intfce, hook_fn, off)


void hooks_init(void)
{
	printf("Initializing hooks\n");

	pagesize = sysconf(_SC_PAGE_SIZE);
        pagemask = ~(pagesize-1);

	HOOK(CREATE_MOVE, hook_CreateMove, memory.clientMode, 25);
	HOOK(MODEL_RENDER, hook_modelRender, interfaces.modelRender, 21);
}

void hooks_exit()
{
	printf("Unhooking functions\n");

	for(size_t i = 0; i < NUM_FUNC; i++)
	{
		struct hook *h = &hooks[i];
		HOOK(i, h->original, h->interface, h->offset);
	}
}
