#ifndef UTILS_H
#define UTILS_H

#include <sys/types.h>

void **get_vtable(void *c, size_t offset);
void *get_vfunc(void *c, size_t i, size_t offset);

#endif
