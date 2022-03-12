#include "hooks.h"
#include "createmove.h"
#include <stdio.h>
#include <math.h>

static int was_on_ground = 1;

bool hook_CreateMove(void *this, float flInputSampleTime, void *cmd_v)
{
	struct UserCmd *cmd = cmd_v;
	((bool (*)(void*, float, void*))hooks[CREATE_MOVE].original)(this, flInputSampleTime, cmd_v);

	void *localplayer = entityList_GetClientEntity(engine_GetLocalPlayer());
	int *player_flags = localplayer + offsets.DT_BasePlayer.m_fFlags;

	if(!localplayer)
		return 0;

	if(!(*player_flags & 1))
	{
		// Bhop
		if(!was_on_ground)
		{
			cmd->buttons &= ~IN_JUMP;
		}
		was_on_ground = *player_flags & 1;

		// Autostrafe
		if(cmd->mousedx < 0)
			cmd->sidemove = -250.0f;
		else if(cmd->mousedx > 0)
			cmd->sidemove = 250.0f;
	}


	return 0;
}
