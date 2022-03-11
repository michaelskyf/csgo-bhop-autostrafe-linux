#include <string.h>

#include "offsets.h"
#include "sdk/recv.h"
#include "sdk/client.h"

struct offsets offsets;

uintptr_t getOffset(struct RecvTable* table, const char* tableName, const char* netvarName) {
    for (int i = 0; i < table->propCount; i++) {
        struct RecvProp prop = table->props[i];

        if (!strcmp(prop.name, netvarName)) {
            return prop.offset;
        }

        if (prop.dataTable) {
            uintptr_t offset = getOffset(prop.dataTable, tableName, netvarName);

            if (offset) {
                return offset + prop.offset;
            }
        }
    }
    return 0;
}

uintptr_t getNetvarOffset(const char* tableName, const char* netvarName) {
    for (struct ClientClass* cur = client_GetAllClasses(); cur; cur = cur->next) {
        if (!strcmp(tableName, cur->recvTable->netTableName)) {
            return getOffset(cur->recvTable, tableName, netvarName);
        }
    }
    return 0;
}

void offsets_init(void)
{
	offsets.DT_BasePlayer.m_fFlags = getNetvarOffset("DT_BasePlayer", "m_fFlags");
	offsets.DT_BasePlayer.m_iHealth = getNetvarOffset("DT_BasePlayer", "m_iHealth");
	offsets.DT_BasePlayer.m_vecVelocity = getNetvarOffset("DT_BasePlayer", "m_vecVelocity[0]");
}
