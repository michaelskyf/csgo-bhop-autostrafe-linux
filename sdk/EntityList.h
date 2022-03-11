#ifndef ENTITYLIST_H
#define ENTITYLIST_H

#include <stdbool.h>

void *entityList_GetClientNetworkable(int entindex);
void *entityList_GetClientNetworkableFromHandle(void *handle);
void *entityList_GetClientUnknownFromHandle(void *handle);
void *entityList_GetClientEntity(int entindex);
void *entityList_GetClientEntityFromHandle(void* handle);
int   entityList_NumberOfEntities(bool include_non_networkable);
int   entityList_GetHighestEntityIndex(void);
void  entityList_SetMaxEntities(int max_entities);
int   entityList_GetMaxEntities(void);

#endif
