#ifndef RECV_H
#define RECV_H

#include <stdint.h>
#include <stdbool.h>

struct Vector {
    float x, y, z;
};

typedef struct RecvProxyData {
    int pad;
    union {
        float _float;
        int _int;
        char *_string;
        void *data;
        struct Vector vector;
        int64_t int64;
    } value;
} RecvProxyData;

typedef struct RecvProp {
    char *name;
    int type;
    int flags;
    int stringBufferSize;
    int insideArray;
    const void *extraData;
    struct RecvProp* arrayProp;
    void * arrayLengthProxy;
    void(*proxy)(RecvProxyData*, void *, void *);
    void * dataTableProxy;
    struct RecvTable* dataTable;
    int offset;
    int elementStride;
    int elementCount;
    const char *parentArrayPropName;
} RecvProp;

typedef struct RecvTable {
    RecvProp* props;
    int propCount;
    void *decoder;
    char *netTableName;
    bool isInitialized;
    bool isInMainList;
} RecvTable;

#endif
