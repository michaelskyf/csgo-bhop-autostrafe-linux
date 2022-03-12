#ifndef CLIENT_H
#define CLIENT_H

typedef enum ClassId {
    ClassId_BaseCSGrenadeProjectile = 9,
    ClassId_BreachChargeProjectile = 29,
    ClassId_BumpMineProjectile = 33,
    ClassId_C4,
    ClassId_Chicken = 36,
    ClassId_CSPlayer = 40,
    ClassId_CSRagdoll = 42,
    ClassId_Deagle = 46,
    ClassId_DecoyProjectile = 48,
    ClassId_Drone,
    ClassId_Dronegun,
    ClassId_EconEntity = 53,
    ClassId_Hostage = 97,
    ClassId_Knife = 107,
    ClassId_KnifeGG,
    ClassId_MolotovProjectile = 113,
    ClassId_PlantedC4 = 128,
    ClassId_PropDoorRotating = 142,
    ClassId_SensorGrenadeProjectile = 152,
    ClassId_SmokeGrenadeProjectile = 156,
    ClassId_SnowballProjectile = 160,
    ClassId_Tablet = 171,
    ClassId_Aug = 231,
    ClassId_Awp,
    ClassId_Elite = 238,
    ClassId_FiveSeven = 240,
    ClassId_G3sg1,
    ClassId_Glock = 244,
    ClassId_P2000,
    ClassId_P250 = 257,
    ClassId_Scar20 = 260,
    ClassId_Sg553 = 264,
    ClassId_Ssg08 = 266,
    ClassId_Tec9 = 268
} ClassId;

struct ClientClass {
    void *(*createFunction)(int, int);
    void *createEventFunction;
    char *networkName;
    struct RecvTable *recvTable;
    struct ClientClass* next;
    enum ClassId classId;
};

struct ClientClass *client_GetAllClasses(void);

#endif
