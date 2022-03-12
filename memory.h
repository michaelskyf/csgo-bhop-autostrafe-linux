#ifndef MEMORY_H
#define MEMORY_H

#include <sys/types.h>
#include "sdk/sdk_common.h"

struct memory
{
	void *clientMode;
	struct GlowObjectManager *glowObjectManager;
}
extern memory;

void memory_init(void);
void *find_pattern(void *buffer, size_t buffer_size, char *pattern, size_t pattern_len);
void *write_pattern(void *buffer, char *pattern, size_t buffer_size, size_t pattern_len);


#endif
