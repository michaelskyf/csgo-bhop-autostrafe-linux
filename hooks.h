#ifndef HOOK_H
#define HOOK_H

#include <stdbool.h>

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
	NUM_FUNC
};

extern struct hook hooks[];

#endif
