#include <nitro.h>
#include <string.h>

#include "struct_decls/struct_02023790_decl.h"

#include "struct_defs/player_profile.h"

#include "unk_020021B0.h"
#include "heap.h"
#include "strbuf.h"
#include "player_profile.h"

int PlayerProfile_sizeof (void)
{
    return sizeof(PlayerProfile);
}

PlayerProfile * PlayerProfile_New (u32 param0)
{
    PlayerProfile * newPlayerProfile = (PlayerProfile *)Heap_AllocFromHeap(param0, sizeof(PlayerProfile));
    sub_02025E8C(newPlayerProfile);
    return newPlayerProfile;
}

void PlayerProfile_Copy (const PlayerProfile * src, PlayerProfile * dest)
{
    MI_CpuCopy8(src, dest, sizeof(PlayerProfile));
}

void PlayerProfile_Init (PlayerProfile * playerProfile)
{
    memset(playerProfile, 0, sizeof(PlayerProfile));
    playerProfile->language = GAME_LANGUAGE;
    sub_02025FD0(playerProfile, GAME_VERSION);
}

BOOL PlayerProfile_IsTrainerNameEmpty (const PlayerProfile * playerProfile)
{
    int index;
    for (index = 0; index < 7 + 1; index++) {
        if (playerProfile->trainerName[index] != 0) {
            return 0;
        }
    }
    return 1;
}

void PlayerProfile_SetTrainerName (PlayerProfile * playerProfile, const u16 * newTrainerName)
{
    int v0;

    v0 = sub_020021F0(newTrainerName); // StringLengthU16
    GF_ASSERT(v0 < 7 + 1);

    sub_020021B0(playerProfile->trainerName, newTrainerName); // StringCopyU16
}

void PlayerProfile_SetTrainerNameFromStrbuf (PlayerProfile * playerProfile, const Strbuf *newTrainerName)
{
    Strbuf_ToChars(newTrainerName, playerProfile->trainerName, 7 + 1);
}

const u16 * PlayerProfile_GetTrainerNamePtr (const PlayerProfile * playerProfile)
{
    return playerProfile->trainerName;
}

void PlayerProfile_GetTrainerName (const PlayerProfile * playerProfile, Strbuf *buf)
{
    Strbuf_CopyChars(buf, playerProfile->trainerName);
}

Strbuf* PlayerProfile_GetTrainerNameAsStrbuf (const PlayerProfile * playerProfile, int param1)
{
    Strbuf* buf = Strbuf_Init(7 + 1, param1);
    PlayerProfile_GetPlayerName(playerProfile, buf);
    return buf;
}

void PlayerProfile_SetTrainerID (PlayerProfile * playerProfile, u32 newTrainerId)
{
    playerProfile->trainerId = newTrainerId;
}

u32 PlayerProfile_GetTrainerID (const PlayerProfile * playerProfile)
{
    return playerProfile->trainerId;
}

u16 PlayerProfile_GetVisibleTrainerID (const PlayerProfile * playerProfile)
{
    return (u16)(playerProfile->trainerId & 0xffff);
}

void PlayerProfile_SetGender (PlayerProfile * playerProfile, int newGender)
{
    playerProfile->gender = newGender;
}

u32 PlayerProfile_GetGender (const PlayerProfile * playerProfile)
{
    return playerProfile->gender;
}

BOOL PlayerProfile_TestBadgeFlag (const PlayerProfile * playerProfile, int badgeId)
{
    if (playerProfile->badges & (1 << badgeId)) {
        return 1;
    } else {
        return 0;
    }
}

void PlayerProfile_SetBadgeFlag (PlayerProfile * playerProfile, int badgeId)
{
    playerProfile->badges |= (1 << badgeId);
}

int PlayerProfile_CountBadges (const PlayerProfile * playerProfile)
{
    int v0 = 0;
    u32 v1;

    for (v1 = playerProfile->badges; v1 != 0; v1 >>= 1) {
        if (v1 & 1) {
            v0++;
        }
    }

    return v0;
}

u32 PlayerProfile_GetMoney (const PlayerProfile * playerProfile)
{
    return playerProfile->money;
}

u32 PlayerProfile_SetMoney (PlayerProfile * playerProfile, u32 newMoney)
{
    if (newMoney > 999999) {
        newMoney = 999999;
    }

    playerProfile->money = newMoney;
    return playerProfile->money;
}

u8 sub_02025F8C (const PlayerProfile * param0)
{
    return param0->unk_1B;
}

void sub_02025F90 (PlayerProfile * param0, u8 param1)
{
    param0->unk_1B = param1;
}

u32 sub_02025F94 (PlayerProfile * param0, u32 param1)
{
    if (param1 > 999999) {
        param0->unk_14 = 999999;
    } else {
        param0->unk_14 += param1;
    }

    if (param0->unk_14 > 999999) {
        param0->unk_14 = 999999;
    }

    return param0->unk_14;
}

u32 sub_02025FB8 (PlayerProfile * param0, u32 param1)
{
    if (param0->unk_14 < param1) {
        param0->unk_14 = 0;
    } else {
        param0->unk_14 -= param1;
    }

    return param0->unk_14;
}

u8 sub_02025FCC (const PlayerProfile * param0)
{
    return param0->unk_1C;
}

void sub_02025FD0 (PlayerProfile * param0, u8 param1)
{
    param0->unk_1C = param1;
}

u8 sub_02025FD4 (void)
{
    return 0;
}

u8 sub_02025FD8 (const PlayerProfile * param0)
{
    return param0->unk_19;
}

void sub_02025FDC (PlayerProfile * param0, u8 param1)
{
    param0->unk_19 = param1;
}

void sub_02025FE0 (PlayerProfile * param0)
{
    param0->unk_1D_0 = 1;
}

int sub_02025FF0 (PlayerProfile * param0)
{
    return param0->unk_1D_0;
}

void sub_02025FF8 (PlayerProfile * param0)
{
    param0->unk_1D_1 = 1;
}

int sub_02026004 (PlayerProfile * param0)
{
    return param0->unk_1D_1;
}

BOOL sub_0202600C (const PlayerProfile * param0, const PlayerProfile * param1)
{
    if (0 == sub_02002238(param0->unk_00, param1->unk_00, 7)) {
        if (param0->unk_10 == param1->unk_10) {
            return 1;
        }
    }

    return 0;
}
