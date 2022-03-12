#include <stdio.h>
#include <pthread.h>

#include "interfaces.h"
#include "memory.h"
#include "offsets.h"
#include "hooks/hooks.h"

void *cheat_init(void *args)
{
	printf("Starting init\n");

	interfaces_init();
	memory_init();
	offsets_init();
	hooks_init();

	printf("Init done\n");

	return NULL;
}

int __attribute__((constructor)) library_init(void)
{
	pthread_t init_thread;
	pthread_create(&init_thread, NULL, &cheat_init, NULL);
	pthread_detach(init_thread);

	return 0;
}

void __attribute__((destructor)) library_exit(void)
{
	printf("Unloading hooks\n");
	hooks_exit();

	printf("Exiting\n");
}
