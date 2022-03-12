#define _GNU_SOURCE
#include <stdio.h>
#include <limits.h>
#include <link.h>
#include <string.h>

#include "memory.h"
#include "interfaces.h"
#include "utils/utils.h"

struct memory memory;

void *find_pattern(void *buffer, size_t buffer_size, char *pattern, size_t pattern_len)
{
	char *pattern_orig = pattern;
	size_t pattern_len_orig = pattern_len;

	void *buffer_orig = buffer;
	size_t buffer_size_orig = buffer_size;

	void *ret = NULL;

	//char *example = "\x69\x12\x69??\x12";
	while(buffer_size_orig)
	{
		pattern = pattern_orig;
		pattern_len = pattern_len_orig;
		buffer = buffer_orig;
		buffer_size = buffer_size_orig;

		while(buffer_size)
		{
			/* skip byte if pattern is '??' */
			if(pattern_len >= 2 && *pattern == '?' && *(pattern + 1) == '?')
			{
				pattern_len = pattern_len - 2;
				pattern = pattern + 2;
			}
			else if(pattern_len)
			{
				if(*(char*)buffer == *pattern)
				{
					pattern++;
					pattern_len--;
				}
				else
				{
					break;
				}
			}

			if(pattern_len == 0)
			{
				return buffer_orig;
			}

			buffer++;
			buffer_size--;
		}

		/* go byte ahead if pattern was not found */
		buffer_orig++;
		buffer_size_orig--;
	}

	return ret;
}

void *get_abs_addr(void *ptr, int offset, int size)
{
	return ptr + *(int*)(ptr + offset) + size;
}

#define PATTERN(pattern) pattern, sizeof(pattern)-1
static void *address;
static const char *name;
static size_t size;

int find_lib_info(struct dl_phdr_info *info, size_t size, void *data)
{
	if(!strcmp(info->dlpi_name, name))
	{
		address = (void*)info->dlpi_addr + info->dlpi_phdr[0].p_vaddr;
		size = info->dlpi_phdr[0].p_memsz;

	}
	return 0;
}

void lib_info(const char *libname)
{
	name = libname;
	dl_iterate_phdr(find_lib_info, NULL);
}

void memory_init(void)
{
	void *hudprocessinput = get_vfunc(interfaces.client, 10, 0);
	memory.clientMode = ((void* (*)(void))get_abs_addr(hudprocessinput + 11, 1, 5))();
}
