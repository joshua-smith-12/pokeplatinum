#include <nitro.h>
#include <string.h>
#include <dwc.h>

#include "trainer_info.h"
#include "struct_decls/struct_0202B370_decl.h"
#include "struct_decls/struct_0202B4A0_decl.h"
#include "struct_decls/struct_0202C878_decl.h"
#include "savedata.h"

#include "struct_defs/struct_0202610C.h"

#include "heap.h"
#include "constants/heap.h"
#include "unk_02025E08.h"
#include "trainer_info.h"
#include "unk_0202602C.h"
#include "unk_0202854C.h"
#include "unk_0202ACE0.h"
#include "unk_0202B37C.h"
#include "unk_0202C858.h"
#include "communication_information.h"
#include "unk_02033200.h"
#include "communication_system.h"
#include "unk_0203909C.h"

typedef struct {
    u8 unk_00[32];
    u8 unk_20[32];
    DWCFriendData unk_40;
    u16 unk_4C[8];
    u8 unk_5C[6];
    u8 netId;
    u8 unk_63;
    u8 unk_64;
    u8 unk_65;
} CommPlayerData;

typedef struct {
    u16 win;
    u16 lose;
    u16 trades;
} CommPlayerRecord;

typedef struct {
    TrainerInfo * personalTrainerInfo;
    const BattleRegulation * regulation;
    SaveData * saveData;
    CommPlayerData playerData[8];
    TrainerInfo * trainerInfo[8];
    CommPlayerRecord playerRecord[8];
    u8 unk_38C[8];
    u8 dataFinishedReading;
    u8 dataRecvFlag;
    u8 curNetId;
} CommunicationInformation;

static CommunicationInformation * sCommInfo;

void sub_020329E0 (SaveData * saveData, const BattleRegulation * regulation)
{
    int netId;
    TrainerInfo * trainerInfo = SaveData_GetTrainerInfo(saveData);

    if (sCommInfo) {
        return;
    }

    sCommInfo = Heap_AllocFromHeap(HEAP_ID_COMMUNICATION, sizeof(CommunicationInformation));
    MI_CpuClear8(sCommInfo, sizeof(CommunicationInformation));

    for (netId = 0; netId < (7 + 1); netId++) {
        sCommInfo->trainerInfo[netId] = (TrainerInfo *)&sCommInfo->playerData[netId].unk_20[0];
        sub_02032D98(netId);
    }

    sCommInfo->dataFinishedReading = FALSE;
    sCommInfo->dataRecvFlag = FALSE;
    sCommInfo->curNetId = 0;
    sCommInfo->saveData = saveData;
    sCommInfo->regulation = regulation;

    TrainerInfo_Copy(trainerInfo, sCommInfo->trainerInfo[0]);
}

void sub_02032A70 (void)
{
    int v0;

    if (sCommInfo) {
        for (v0 = 0; v0 < (7 + 1); v0++) {
            sCommInfo->trainerInfo[v0] = NULL;
        }

        if (sCommInfo) {
            Heap_FreeToHeap(sCommInfo);
        }

        sCommInfo = NULL;
    }
}

BOOL sub_02032AAC (void)
{
    return sCommInfo != NULL;
}

void sub_02032AC0 (void)
{
    u16 v0 = sub_0203608C();
    TrainerInfo * v1;
    const u16 * v2;
    UnkStruct_0202B4A0 * v3 = sub_0202B4A0(sCommInfo->saveData);
    UnkStruct_0202B370 * v4 = sub_0202B370(sCommInfo->saveData);
    UnkStruct_0202C878 * v5 = sub_0202C878(sCommInfo->saveData);

    if (sCommInfo->personalTrainerInfo) {
        v1 = sCommInfo->personalTrainerInfo;
    } else {
        v1 = SaveData_GetTrainerInfo(sCommInfo->saveData);
    }

    TrainerInfo_Copy(v1, sCommInfo->trainerInfo[v0]);
    OS_GetMacAddress(&sCommInfo->playerData[v0].unk_5C[0]);

    v2 = sub_0202B42C(v3, 1, 0);

    MI_CpuCopy8(v2, sCommInfo->playerData[v0].unk_4C, sizeof(sCommInfo->playerData[v0].unk_4C));

    sCommInfo->playerData[v0].unk_63 = sub_0202C8C0(v5);
    sCommInfo->playerData[v0].unk_64 = sub_0202C8C4(v5);
    sCommInfo->playerData[v0].unk_65 = sub_02028810(sCommInfo->saveData);
    sCommInfo->playerData[v0].unk_65 = 1 - sCommInfo->playerData[v0].unk_65;

    DWC_CreateExchangeToken(sub_0202AD28(v4), &sCommInfo->playerData[v0].unk_40);
    MI_CpuClear8(sCommInfo->playerData[v0].unk_00, 32);

    if (sCommInfo->regulation) {
        sub_02026034(sCommInfo->regulation, (BattleRegulation *)sCommInfo->playerData[v0].unk_00);
    }

    CommunicationSystem_SendData(3, &sCommInfo->playerData[v0], sizeof(CommPlayerData));
}

int CommPlayerData_sizeof (void)
{
    return sizeof(CommPlayerData);
}

void sub_02032BC4 (int param0, int param1, void * param2, void * param3)
{
    if (sCommInfo) {
        sCommInfo->dataFinishedReading = TRUE;
    } else {
        (void)0;
    }
}

BOOL CommunicationInformation_IsDataFinishedReading (void)
{
    return sCommInfo->dataFinishedReading;
}

void sub_02032BEC (int param0, int param1, void * param2, void * param3)
{
    CommPlayerData * v0 = (CommPlayerData *)param2;

    if (!sCommInfo) {
        return;
    }

    if (!sub_02035D78(param0)) {
        return;
    }

    MI_CpuCopy8(param2, &sCommInfo->playerData[v0->netId], sizeof(CommPlayerData));
    sCommInfo->curNetId = v0->netId;

    if (TrainerInfo_HasNoName(sCommInfo->trainerInfo[sCommInfo->curNetId]) == 1) {
        return;
    }

    if (sCommInfo->unk_38C[sCommInfo->curNetId] < 2) {
        sCommInfo->unk_38C[sCommInfo->curNetId] = 1;

        if (sub_0203608C() == sCommInfo->curNetId) {
            sCommInfo->unk_38C[sCommInfo->curNetId] = 3;
        }
    }
}

void sub_02032C80 (int netId, int param1, void * param2, void * param3)
{
    int v0;

    if (!sCommInfo) {
        return;
    }

    MI_CpuCopy8(param2, &sCommInfo->playerData[netId], sizeof(CommPlayerData));
    sub_02033FDC(&sCommInfo->playerData[netId].unk_5C[0], netId);

    sCommInfo->unk_38C[netId] = 1;

    if (sub_0203608C() == netId) {
        sCommInfo->unk_38C[netId] = 3;
    } else {
        sCommInfo->dataRecvFlag = 1;
    }
}

BOOL sub_02032CE8 (void)
{
    int v0;

    if (!sCommInfo->dataRecvFlag) {
        return 0;
    }

    if (sub_0203608C() != 0) {
        return 0;
    }

    if (!sub_02036254(5)) {
        for (v0 = 0; v0 < (7 + 1); v0++) {
            if (sCommInfo->unk_38C[v0] != 0) {
                sCommInfo->playerData[v0].netId = v0;
                MI_CpuCopy8(sCommInfo->trainerInfo[v0], sCommInfo->playerData[v0].unk_20, TrainerInfo_Size());
                sub_02035F00(4, &sCommInfo->playerData[v0], sizeof(CommPlayerData));
            }
        }

        sub_02035F00(5, NULL, 0);
        sCommInfo->dataRecvFlag = 0;
        return 1;
    }

    return 0;
}

BOOL sub_02032D84 (void)
{
    return sCommInfo->dataRecvFlag;
}

void sub_02032D98 (int param0)
{
    TrainerInfo_Init(sCommInfo->trainerInfo[param0]);
    sCommInfo->unk_38C[param0] = 0;
}

BOOL sub_02032DC4 (int param0)
{
    return sCommInfo->unk_38C[param0] == 1;
}

BOOL sub_02032DE0 (int param0)
{
    return (sCommInfo->unk_38C[param0] == 2) || (sCommInfo->unk_38C[param0] == 1);
}

BOOL sub_02032E00 (int param0)
{
    return sCommInfo->unk_38C[param0] == 2;
}

void sub_02032E1C (int param0)
{
    sCommInfo->unk_38C[param0] = 2;
}

void sub_02032E30 (int param0)
{
    sCommInfo->unk_38C[param0] = 3;
}

int sub_02032E44 (void)
{
    int v0;

    for (v0 = 0; v0 < (7 + 1); v0++) {
        if (sCommInfo->unk_38C[v0] == 1) {
            return v0;
        }
    }

    return 0xff;
}

int sub_02032E64 (void)
{
    int v0;
    int v1 = 0;

    for (v0 = 0; v0 < (7 + 1); v0++) {
        switch (sCommInfo->unk_38C[v0]) {
        case 2:
        case 3:
            v1++;
            break;
        }
    }

    return v1;
}

BOOL sub_02032E90 (void)
{
    int v0;
    BOOL v1 = 0;

    if (sCommInfo) {
        if (sub_02035E18() == 0) {
            return v1;
        }

        for (v0 = 0; v0 < (7 + 1); v0++) {
            if (!sub_02035D78(v0) && !((v0 == 0) && sub_02036180())) {
                if (sCommInfo->unk_38C[v0] != 0) {
                    sub_02032D98(v0);
                    v1 = 1;
                }
            }
        }
    }

    return v1;
}

TrainerInfo * sub_02032EE8 (int param0)
{
    if (!sCommInfo) {
        return NULL;
    }

    switch (sCommInfo->unk_38C[param0]) {
    case 1:
    case 2:
    case 3:
        return sCommInfo->trainerInfo[param0];
    }

    return NULL;
}

DWCFriendData * sub_02032F1C (int param0)
{
    if (sCommInfo->unk_38C[param0] != 0) {
        return &sCommInfo->playerData[param0].unk_40;
    }

    return NULL;
}

int sub_02032F40 (int param0)
{
    return sub_02039390(sCommInfo->saveData, param0);
}

u16 * sub_02032F54 (int param0)
{
    if (sCommInfo->unk_38C[param0] != 0) {
        return sCommInfo->playerData[param0].unk_4C;
    }

    return NULL;
}

int sub_02032F78 (int param0)
{
    if (sCommInfo->unk_38C[param0] != 0) {
        return sCommInfo->playerData[param0].unk_63;
    }

    return 0;
}

int sub_02032F9C (int param0)
{
    if (sCommInfo->unk_38C[param0] != 0) {
        return sCommInfo->playerData[param0].unk_64;
    }

    return 0;
}

int sub_02032FC0 (int param0)
{
    if (sCommInfo->unk_38C[param0] != 0) {
        return sCommInfo->playerData[param0].unk_65;
    }

    return 0;
}

BOOL sub_02032FE4 (void)
{
    int v0, v1;

    for (v0 = 0; v0 < (7 + 1) - 1; v0++) {
        if (sub_02035D78(v0) && (sCommInfo->unk_38C[v0] != 0)) {
            if (sub_02035D78(v0 + 1) && (sCommInfo->unk_38C[v0 + 1] != 0)) {
                for (v1 = 0; v1 < 32; v1++) {
                    if (sCommInfo->playerData[v0].unk_00[v1] != sCommInfo->playerData[v0 + 1].unk_00[v1]) {
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

static void sub_02033054 (int param0, int param1)
{
    int v0;
    int v1, v2;

    if (sCommInfo == NULL) {
        return;
    }

    if (param0 != 2) {
        v1 = sub_020362F4(sub_0203608C()) & 0x1;
    }

    for (v0 = 0; v0 < sub_02035E18(); v0++) {
        if (sub_02035D78(v0) && (sCommInfo->unk_38C[v0] != 0)) {
            if (param0 == 0) {
                v2 = sub_020362F4(v0) & 0x1;

                if (v1 != v2) {
                    sCommInfo->playerRecord[v0].win += param1;
                }
            } else if (param0 == 1) {
                v2 = sub_020362F4(v0) & 0x1;

                if (v1 != v2) {
                    sCommInfo->playerRecord[v0].lose += param1;
                }
            } else {
                sCommInfo->playerRecord[v0].trades += param1;
            }
        }
    }
}

void sub_02033114 (SaveData * param0)
{
    UnkStruct_0202B370 * v0 = sub_0202B370(param0);
    int v1, v2, v3;

    for (v1 = 0; v1 < sub_02035E18(); v1++) {
        DWCFriendData * v4 = sub_02032F1C(v1);

        if (v4 == NULL) {
            continue;
        }

        v2 = sub_0203909C(param0, v4, &v3);

        switch (v2) {
        case 0:
        case 1:
            GF_ASSERT(v3 >= 0);

            sub_0202B174(v0, v3, sCommInfo->playerRecord[v1].win, sCommInfo->playerRecord[v1].lose, sCommInfo->playerRecord[v1].trades);
            break;
        }
    }

    for (v1 = 0; v1 < (7 + 1); v1++) {
        sCommInfo->playerRecord[v1].win = 0;
        sCommInfo->playerRecord[v1].lose = 0;
        sCommInfo->playerRecord[v1].trades = 0;
    }
}

void sub_020331B4 (SaveData * param0, int param1)
{
    if (param1 == 1) {
        sub_02033054(0, 1);
    } else if (param1 == -1) {
        sub_02033054(1, 1);
    }

    sub_02033114(param0);
}

void sub_020331E0 (SaveData * param0, int param1)
{
    sub_02033054(2, param1);
    sub_02033114(param0);
}

void sub_020331F4 (TrainerInfo * param0)
{
    sCommInfo->personalTrainerInfo = param0;
}
