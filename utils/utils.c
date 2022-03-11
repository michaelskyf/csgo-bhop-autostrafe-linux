#include "utils.h"

void **get_vtable(void *c, size_t offset)
{
	return *(void***)(c + offset);
}

void *get_vfunc(void *c, size_t i, size_t offset)
{
	return (void*)get_vtable(c, offset)[i];
}
