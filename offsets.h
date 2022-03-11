#ifndef OFFSETS_H
#define OFFSETS_H

#include <sys/types.h>

struct offsets
{
	struct
	{
		size_t m_Local;
		size_t m_aimPunchAngle;
		size_t m_viewPunchAngle;
		size_t m_vecViewOffset;
		size_t m_nTickBase;
		size_t m_vecVelocity;
		size_t m_iHealth;
		size_t m_lifeState;
		size_t m_fFlags;
		size_t m_iObserverMode;
		size_t m_hObserverTarget;
		size_t m_hViewModel;
		size_t m_szLastPlaceName;
		size_t deadflag;
	} DT_BasePlayer;

	struct
	{
		size_t m_flPoseParameter;
		size_t m_nForceBone;
		size_t m_iMostRecentModelBoneCounter;
		size_t m_hLightingOrigin;
		size_t m_flLastBoneSetupTime;
	} DT_BaseAnimating;

	struct
	{
		size_t m_flAnimTime;
		size_t m_flSimulationTime;
		size_t m_vecOrigin;
		size_t m_nRenderMode;
		size_t m_iTeamNum;
		size_t m_MoveType;
		size_t m_Collision;
		size_t m_bSpotted;
		size_t m_bSpottedByMask;
		size_t m_RefEHandle;
	} DT_BaseEntity;

	struct
	{
		size_t m_hActiveWeapon;
		size_t m_hMyWeapons;
		size_t m_hMyWearables;
	} DT_BaseCombatCharacter;

	struct
	{
		size_t m_iPing;
		size_t m_iKills;
		size_t m_iAssists;
		size_t m_iDeaths;
		size_t m_bConnected;
		size_t m_iTeam;
		size_t m_iPendingTeam;
		size_t m_bAlive;
		size_t m_iHealth;
	} DT_PlayerResource;

	struct
	{
		size_t m_iPlayerC4;
		size_t m_iPlayerVIP;
		size_t m_bHostageAlive;
		size_t m_isHostageFollowingSomeone;
		size_t m_iHostageEntityIDs;
		size_t m_bombsiteCenterB;
		size_t m_hostageRescueX;
		size_t m_hostageRescueY;
		size_t m_hostageRescueZ;
		size_t m_iMVPs;
		size_t m_iArmor;
		size_t m_bHasHelmet;
		size_t m_bHasDefuser;
		size_t m_iScore;
		size_t m_iCompetitiveRanking;
		size_t m_iCompetitiveWins;
		size_t m_iCompTeammateColor;
		size_t m_bControllingBot;
		size_t m_iControlledPlayer;
		size_t m_iControlledByPlayer;
		size_t m_iBotDifficulty;
		size_t m_szClan;
		size_t m_iTotalCashSpent;
		size_t m_iCashSpentThisRound;
		size_t m_nEndMatchNextMapVotes;
		size_t m_bEndMatchNextMapAllVoted;
		size_t m_nActiveCoinRank;
		size_t m_nMusicID;
		size_t m_nPersonaDataPublicLevel;
		size_t m_nPersonaDataPublicCommendsLeader;
		size_t m_nPersonaDataPublicCommendsTeacher;
		size_t m_nPersonaDataPublicCommendsFriendly;
	} DT_CSPlayerResource;

	struct
	{
		size_t m_bBombTicking;
		size_t m_flC4Blow;
		size_t m_bBombDefused;
		size_t m_hBombDefuser;
		size_t m_flDefuseCountDown;
		size_t m_flDefuseLength;
		size_t m_nBombSite;
	} DT_PlantedC4;

	struct
	{
		size_t m_iShotsFired;
		size_t m_angEyeAngles[2];
		size_t m_iAddonBits;
		size_t m_iAccount;
		size_t m_totalHitsOnServer;
		size_t m_ArmorValue;
		size_t m_bHasDefuser;
		size_t m_bIsDefusing;
		size_t m_bIsGrabbingHostage;
		size_t m_bIsScoped;
		size_t m_bGunGameImmunity;
		size_t m_bIsRescuing;
		size_t m_bHasHelmet;
		size_t m_flFlashDuration;
		size_t m_flFlashMaxAlpha;
		size_t m_flLowerBodyYawTarget;
		size_t m_nSurvivalTeam;
	} DT_CSPlayer;

	struct
	{
		size_t m_iItemDefinitionIndex;
		size_t m_iItemIDHigh;
		size_t m_iAccountID;
		size_t m_iEntityQuality;
		size_t m_szCustomName;
		size_t m_nFallbackPaintKit;
		size_t m_nFallbackSeed;
		size_t m_flFallbackWear;
		size_t m_nFallbackStatTrak;
		size_t m_bInitialized;
	} DT_BaseAttributableItem;

	struct
	{
		size_t m_nModelIndex;
		size_t m_hWeapon;
		size_t m_hOwner;
	} DT_BaseViewModel;

	struct
	{
		size_t m_bReloadVisuallyComplete;
		size_t m_fAccuracyPenalty;
        size_t m_flPostponeFireReadyTime;
	} DT_WeaponCSBase;

	struct
	{
		size_t m_bStartedArming;
	} DT_WeaponC4;

	struct
	{
		size_t m_bRedraw;
		size_t m_bIsHeldByPlayer;
		size_t m_bPinPulled;
		size_t m_fThrowTime;
		size_t m_bLoopingSoundPlaying;
		size_t m_flThrowStrength;
	} DT_BaseCSGrenade;

	struct
	{
		size_t m_flNextPrimaryAttack;
		size_t m_hOwner;
		size_t m_iClip1;
		size_t m_bInReload;
	} DT_BaseCombatWeapon;

	struct
	{
		size_t m_bShouldGlow;
	} DT_DynamicProp;

	struct
	{
		size_t m_bFreezePeriod;
		size_t m_bMatchWaitingForResume;
		size_t m_bWarmupPeriod;
		size_t m_fWarmupPeriodEnd;
		size_t m_fWarmupPeriodStart;
		size_t m_bTerroristTimeOutActive;
		size_t m_bCTTimeOutActive;
		size_t m_flTerroristTimeOutRemaining;
		size_t m_flCTTimeOutRemaining;
		size_t m_nTerroristTimeOuts;
		size_t m_nCTTimeOuts;
		size_t m_iRoundTime;
		size_t m_gamePhase;
		size_t m_totalRoundsPlayed;
		size_t m_nOvertimePlaying;
		size_t m_timeUntilNextPhaseStarts;
		size_t m_flCMMItemDropRevealStartTime;
		size_t m_flCMMItemDropRevealEndTime;
		size_t m_fRoundStartTime;
		size_t m_bGameRestart;
		size_t m_flRestartRoundTime;
		size_t m_flGameStartTime;
		size_t m_iHostagesRemaining;
		size_t m_bAnyHostageReached;
		size_t m_bMapHasBombTarget;
		size_t m_bMapHasRescueZone;
		size_t m_bMapHasBuyZone;
		size_t m_bIsQueuedMatchmaking;
		size_t m_bIsValveDS;
		size_t m_bIsQuestEligible;
		size_t m_bLogoMap;
		size_t m_iNumGunGameProgressiveWeaponsCT;
		size_t m_iNumGunGameProgressiveWeaponsT;
		size_t m_iSpectatorSlotCount;
		size_t m_bBombDropped;
		size_t m_bBombPlanted;
		size_t m_iRoundWinStatus;
		size_t m_eRoundWinReason;
		size_t m_flDMBonusStartTime;
		size_t m_flDMBonusTimeLength;
		size_t m_unDMBonusWeaponLoadoutSlot;
		size_t m_bDMBonusActive;
		size_t m_bTCantBuy;
		size_t m_bCTCantBuy;
		size_t m_flGuardianBuyUntilTime;
		size_t m_iMatchStats_RoundResults;
		size_t m_iMatchStats_PlayersAlive_T;
		size_t m_iMatchStats_PlayersAlive_CT;
		size_t m_GGProgressiveWeaponOrderC;
		size_t m_GGProgressiveWeaponOrderT;
		size_t m_GGProgressiveWeaponKillUpgradeOrderCT;
		size_t m_GGProgressiveWeaponKillUpgradeOrderT;
		size_t m_MatchDevice;
		size_t m_bHasMatchStarted;
		size_t m_TeamRespawnWaveTimes;
		size_t m_flNextRespawnWave;
		size_t m_nNextMapInMapgroup;
		size_t m_nEndMatchMapGroupVoteOptions;
		size_t m_bIsDroppingItems;
		size_t m_iActiveAssassinationTargetMissionID;
		size_t m_fMatchStartTime;
		size_t m_szTournamentEventName;
		size_t m_szTournamentEventStage;
		size_t m_szTournamentPredictionsTxt;
		size_t m_nTournamentPredictionsPct;
		size_t m_szMatchStatTxt;
		size_t m_nGuardianModeWaveNumber;
		size_t m_nGuardianModeSpecialKillsRemaining;
		size_t m_nGuardianModeSpecialWeaponNeeded;
		size_t m_nHalloweenMaskListSeed;
		size_t m_numGlobalGiftsGiven;
		size_t m_numGlobalGifters;
		size_t m_numGlobalGiftsPeriodSeconds;
		size_t m_arrFeaturedGiftersAccounts;
		size_t m_arrFeaturedGiftersGifts;
		size_t m_arrProhibitedItemIndices;
		size_t m_numBestOfMaps;
		size_t m_arrTournamentActiveCasterAccounts;
	} DT_CSGameRulesProxy;

	struct
	{
		size_t m_bBrokenOpen;
		size_t m_flRadius;
	} DT_BRC4Target;

	struct
	{
		size_t m_vecAttentionTarget;
		size_t m_vecTargetOffset;
		size_t m_iHealth;
		size_t m_bHasTarget;
	} DT_Dronegun;

	struct
	{
		size_t m_bRenderInPSPM;
		size_t m_bRenderInTablet;
		size_t m_iHealth;
		size_t m_iMaxHealth;
	} DT_PhysPropLootCrate;
}
extern offsets;

void offsets_init(void);

#endif
