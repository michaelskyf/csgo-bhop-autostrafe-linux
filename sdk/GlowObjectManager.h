#ifndef GLOW_OBJECT_MANAGER
#define GLOW_OBJECT_MANAGER

#include <stdbool.h>
#include "UtlVector.h"
#include "vector.h"

struct GlowObjectDefinition {
    int nextFreeSlot;
    void *entity;
    struct Vector glowColor;
    float   alpha;
    char pad[4];
    float m_flSomeFloat;
    float bloomAmount;
    float m_flAnotherFloat;
    bool renderWhenOccluded;
    bool renderWhenUnoccluded;
    bool fullBloomRender;
    char pad1;
    int fullBloomStencilTestValue;
    int glowStyle;
    int splitScreenSlot;
};

struct GlowObjectManager
{
	struct UtlVector glowObjectDefinitions;
	int firstFreeSlot;
};

bool GlowObjectManager_hasGlowEffect(struct GlowObjectManager*, void *);
int GlowObjectManager_registerGlowObject(struct GlowObjectManager*, void *);
void GlowObjectManager_unregisterGlowObject(struct GlowObjectManager*, int);

#endif
