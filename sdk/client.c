#include "client.h"
#include "../interfaces.h"
#include "../utils/utils.h"

struct ClientClass *client_GetAllClasses(void)
{
	static void* (*func)(void*);
	void *client = interfaces.client;
	if(!func)
	{
		func = get_vfunc(client, 8, 0);
	}

	return func(client);

}
