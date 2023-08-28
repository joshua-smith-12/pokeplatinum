#ifndef POKEPLATINUM_PLAYER_PROFILE_H
#define POKEPLATINUM_PLAYER_PROFILE_H

#include "struct_decls/struct_02023790_decl.h"
#include "struct_decls/player_profile_decl.h"

#define MAX_MONEY 999999

int PlayerProfile_sizeof(void);
PlayerProfile * PlayerProfile_New(u32 param0);
void PlayerProfile_Copy(const PlayerProfile * src, PlayerProfile * dest);
void PlayerProfile_Init(PlayerProfile * playerProfile);
BOOL PlayerProfile_IsNameEmpty(const PlayerProfile * playerProfile);
void PlayerProfile_SetName(PlayerProfile * playerProfile, const u16 * newName);
void PlayerProfile_Name_StringToFlat(PlayerProfile * playerProfile, const Strbuf *str);
const u16 * PlayerProfile_GetName(const PlayerProfile * playerProfile);
void PlayerProfile_Name_FlatToString(const PlayerProfile * playerProfile, Strbuf *str);
Strbuf* PlayerProfile_GetName_NewString(const PlayerProfile * playerProfile, int param1);
void PlayerProfile_SetTrainerID(PlayerProfile * playerProfile, u32 newTrainerID);
u32 PlayerProfile_GetTrainerID(const PlayerProfile * playerProfile);
u16 PlayerProfile_GetTrainerID_VisibleHalf(const PlayerProfile * playerProfile);
void PlayerProfile_SetGender(PlayerProfile * playerProfile, int newGender);
u32 PlayerProfile_GetGender(const PlayerProfile * playerProfile);
BOOL PlayerProfile_TestBadgeFlag(const PlayerProfile * playerProfile, int badgeNo);
void PlayerProfile_SetBadgeFlag(PlayerProfile * playerProfile, int newBadgeNo);
int PlayerProfile_CountBadges(const PlayerProfile * playerProfile);
u32 PlayerProfile_GetMoney(const PlayerProfile * playerProfile);
u32 PlayerProfile_SetMoney(PlayerProfile * playerProfile, u32 newMoney);
u8 PlayerProfile_GetAvatar(const PlayerProfile * playerProfile);
void PlayerProfile_SetAvatar(PlayerProfile * playerProfile, u8 newAvatar);
u32 PlayerProfile_AddMoney(PlayerProfile * playerProfile, u32 amount);
u32 PlayerProfile_SubMoney(PlayerProfile * playerProfile, u32 amount);
u8 PlayerProfile_GetVersion(const PlayerProfile * playerProfile);
void PlayerProfile_SetVersion(PlayerProfile * playerProfile, u8 newVersion);
u8 sub_02025FD4(void);
u8 PlayerProfile_GetLanguage(const PlayerProfile * playerProfile);
void PlayerProfile_SetLanguage(PlayerProfile * playerProfile, u8 newLanguage);
void PlayerProfile_SetGameClearedFlag(PlayerProfile * playerProfile);
int PlayerProfile_GetGameClearedFlag(PlayerProfile * playerProfile);
void PlayerProfile_SetNationalDexFlag(PlayerProfile * playerProfile);
int PlayerProfile_GetNationalDexFlag(PlayerProfile * playerProfile);
BOOL PlayerProfile_DoPlayerProfilesMatch(const PlayerProfile * first, const PlayerProfile * second);

#endif // POKEPLATINUM_PLAYER_PROFILE_H
