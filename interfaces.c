#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "interfaces.h"

#include "sdk/EntityList.h"
#include "sdk/engine.h"

struct interfaces interfaces;

struct interface_reg
{
	void *(*m_CreateFn)();
	const char *name;
	struct interface_reg *next;
};

void *get_interface(const char *libname, const char *name)
{
	void *lib;
	void *symbol;
	struct interface_reg *curr_interface;

	lib = dlopen(libname, RTLD_NOLOAD | RTLD_NOW | RTLD_LOCAL);
	if(lib == NULL)
	{
		printf("Could not open library \"%s\"\n", libname);
		exit(EXIT_FAILURE);
	}

	symbol = dlsym(lib, "s_pInterfaceRegs");
	dlclose(lib);
	if(symbol == NULL)
	{
		printf("Failed to get dlsym %s\n", libname);
		exit(EXIT_FAILURE);
	}

	curr_interface = *(void**)symbol;
	for(; curr_interface; curr_interface = curr_interface->next)
	{
		if(strstr(curr_interface->name, name) && strlen(name) == strlen(curr_interface->name) - 3)
		{
			return curr_interface->m_CreateFn();
		}
	}

	printf("Could not find interface %s\n", name);
	exit(EXIT_FAILURE);
}

void interfaces_init(void)
{
	interfaces.client = get_interface("./csgo/bin/linux64/client_client.so", "VClient");
	interfaces.engine = get_interface("./bin/linux64/engine_client.so", "VEngineClient");
	interfaces.entityList = get_interface("./csgo/bin/linux64/client_client.so", "VClientEntityList");
	interfaces.modelRender = get_interface("./bin/linux64/engine_client.so", "VEngineModel");

	printf("Interfaces loaded!\n");
}
