#ifndef INTERFACES_H
#define INTERFACES_H

#include "sdk/EntityList.h"

struct interfaces
{
	void *client;
	void *engine;
	struct EntityList *entityList;
	void *modelRender;
}
extern interfaces;

void interfaces_init(void);

#endif
