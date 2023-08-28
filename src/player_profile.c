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
    PlayerProfile * playerProfile = Heap_AllocFromHeap(param0, sizeof(PlayerProfile));
    PlayerProfile_Init(playerProfile);
    return playerProfile;
}

void PlayerProfile_Copy (const PlayerProfile * src, PlayerProfile * dest)
{
    MI_CpuCopy8(src, dest, sizeof(PlayerProfile));
}

void PlayerProfile_Init (PlayerProfile * playerProfile)
{
    memset(playerProfile, 0, sizeof(PlayerProfile));
    playerProfile->language = GAME_LANGUAGE;

    PlayerProfile_SetVersion(playerProfile, GAME_VERSION);
}

BOOL PlayerProfile_IsNameEmpty (const PlayerProfile * playerProfile)
{
    int index;
    for (index = 0; index < 7 + 1; index++) {
        if (playerProfile->name[index] != 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void PlayerProfile_SetName (PlayerProfile * playerProfile, const u16 * newName)
{
    int newNameLength = sub_020021F0(newName);
    GF_ASSERT(newNameLength < 7 + 1);

    sub_020021B0(playerProfile->name, newName);
}

void PlayerProfile_Name_StringToFlat (PlayerProfile * playerProfile, const Strbuf *str)
{
    Strbuf_ToChars(str, playerProfile->name, 7 + 1);
}

const u16 * PlayerProfile_GetName (const PlayerProfile * playerProfile)
{
    return playerProfile->name;
}

void PlayerProfile_Name_FlatToString (const PlayerProfile * playerProfile, Strbuf *str)
{
    Strbuf_CopyChars(str, playerProfile->name);
}

Strbuf* PlayerProfile_GetName_NewString (const PlayerProfile * playerProfile, int param1)
{
    Strbuf* str = Strbuf_Init(7 + 1, param1);
    PlayerProfile_Name_FlatToString(playerProfile, str);
    return str;
}

void PlayerProfile_SetTrainerID (PlayerProfile * playerProfile, u32 newTrainerID)
{
    playerProfile->trainerID = newTrainerID;
}

u32 PlayerProfile_GetTrainerID (const PlayerProfile * playerProfile)
{
    return playerProfile->trainerID;
}

u16 PlayerProfile_GetTrainerID_VisibleHalf (const PlayerProfile * playerProfile)
{
    return playerProfile->trainerID & 0xffff;
}

void PlayerProfile_SetGender (PlayerProfile * playerProfile, int newGender)
{
    playerProfile->gender = newGender;
}

u32 PlayerProfile_GetGender (const PlayerProfile * playerProfile)
{
    return playerProfile->gender;
}

BOOL PlayerProfile_TestBadgeFlag (const PlayerProfile * playerProfile, int badgeNo)
{
    if (playerProfile->badges & (1 << badgeNo)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void PlayerProfile_SetBadgeFlag (PlayerProfile * playerProfile, int newBadgeNo)
{
    playerProfile->badges |= (1 << newBadgeNo);
}

int PlayerProfile_CountBadges (const PlayerProfile * playerProfile)
{
    int badgeCount = 0;
    u32 badgeNo;

    for (badgeNo = playerProfile->badges; badgeNo != 0; badgeNo >>= 1) {
        if (badgeNo & 1) {
            badgeCount++;
        }
    }

    return badgeCount;
}

u32 PlayerProfile_GetMoney (const PlayerProfile * playerProfile)
{
    return playerProfile->money;
}

u32 PlayerProfile_SetMoney (PlayerProfile * playerProfile, u32 newMoney)
{
    if (newMoney > MAX_MONEY) {
        newMoney = MAX_MONEY;
    }

    playerProfile->money = newMoney;
    return playerProfile->money;
}

u8 PlayerProfile_GetAvatar (const PlayerProfile * playerProfile)
{
    return playerProfile->avatar;
}

void PlayerProfile_SetAvatar (PlayerProfile * playerProfile, u8 newAvatar)
{
    playerProfile->avatar = newAvatar;
}

u32 PlayerProfile_AddMoney (PlayerProfile * playerProfile, u32 amount)
{
    if (amount > MAX_MONEY) {
        playerProfile->money = MAX_MONEY;
    } else {
        playerProfile->money += amount;
    }

    if (playerProfile->money > MAX_MONEY) {
        playerProfile->money = MAX_MONEY;
    }

    return playerProfile->money;
}

u32 PlayerProfile_SubMoney (PlayerProfile * playerProfile, u32 amount)
{
    if (playerProfile->money < amount) {
        playerProfile->money = 0;
    } else {
        playerProfile->money -= amount;
    }

    return playerProfile->money;
}

u8 PlayerProfile_GetVersion (const PlayerProfile * playerProfile)
{
    return playerProfile->version;
}

void PlayerProfile_SetVersion (PlayerProfile * playerProfile, u8 newVersion)
{
    playerProfile->version = newVersion;
}

u8 sub_02025FD4 (void) // TODO: maybe PlayerProfile_GetBaseVersion?
{
    return 0;
}

u8 PlayerProfile_GetLanguage (const PlayerProfile * playerProfile)
{
    return playerProfile->language;
}

void PlayerProfile_SetLanguage (PlayerProfile * playerProfile, u8 newLanguage)
{
    playerProfile->language = newLanguage;
}

void PlayerProfile_SetGameClearedFlag (PlayerProfile * playerProfile)
{
    playerProfile->gameCleared = 1;
}

int PlayerProfile_GetGameClearedFlag (PlayerProfile * playerProfile)
{
    return playerProfile->gameCleared;
}

void PlayerProfile_SetNationalDexFlag (PlayerProfile * playerProfile)
{
    playerProfile->nationalDex = 1;
}

int PlayerProfile_GetNationalDexFlag (PlayerProfile * playerProfile)
{
    return playerProfile->nationalDex;
}

BOOL PlayerProfile_DoPlayerProfilesMatch (const PlayerProfile * first, const PlayerProfile * second)
{
    if (FALSE == sub_02002238(first->name, second->name, 7)) {
        if (first->trainerID == second->trainerID) {
            return TRUE;
        }
    }

    return FALSE;
}
