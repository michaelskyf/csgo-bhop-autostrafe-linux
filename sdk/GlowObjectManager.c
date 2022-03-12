#include <stdio.h>
#include "GlowObjectManager.h"
#include "sdk_common.h"

bool GlowObjectManager_hasGlowEffect(struct GlowObjectManager *glowObjectManager, void *entity)
{
    for (int i = 0; i < glowObjectManager->glowObjectDefinitions.size; i++) {
        struct GlowObjectDefinition* glowObject = (struct GlowObjectDefinition*)glowObjectManager->glowObjectDefinitions.memory + i;
        if (glowObject->nextFreeSlot == -2 && glowObject->entity == entity)
            return true;
    }
    return false;

}
int GlowObjectManager_registerGlowObject(struct GlowObjectManager *glowObjectManager, void *entity)
{
    int index = glowObjectManager->firstFreeSlot;
    if (index != -1) {
        struct GlowObjectDefinition* glowObject = (struct GlowObjectDefinition*)glowObjectManager->glowObjectDefinitions.memory + index;
        glowObjectManager->firstFreeSlot = glowObject->nextFreeSlot;
        glowObject->entity = entity;
        glowObject->fullBloomRender = false;
        glowObject->fullBloomStencilTestValue = 0;
        glowObject->splitScreenSlot = -1;
        glowObject->nextFreeSlot = -2;
    }
    return index;

}
void GlowObjectManager_unregisterGlowObject(struct GlowObjectManager *glowObjectManager, int index)
{
    struct GlowObjectDefinition* glowObject = (struct GlowObjectDefinition*)glowObjectManager->glowObjectDefinitions.memory + index;
    glowObject->nextFreeSlot = glowObjectManager->firstFreeSlot;
    glowObject->entity = NULL;
    glowObject->renderWhenOccluded = false;
    glowObject->renderWhenUnoccluded = false;
    glowObjectManager->firstFreeSlot = index;

}
