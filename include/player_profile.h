#ifndef POKEPLATINUM_PLAYER_PROFILE_H
#define POKEPLATINUM_PLAYER_PROFILE_H

#include "struct_decls/struct_02023790_decl.h"
#include "struct_decls/player_profile.h"

int PlayerProfile_sizeof(void);
PlayerProfile * PlayerProfile_New(u32 param0);
void PlayerProfile_Copy(const PlayerProfile * src, PlayerProfile * dest);
void PlayerProfile_Init(PlayerProfile * playerProfile);
BOOL PlayerProfile_IsPlayerNameEmpty(const PlayerProfile * playerProfile);
void PlayerProfile_SetPlayerName(PlayerProfile * playerProfile, const u16 * newName);
void sub_02025EE0(PlayerProfile * param0, const Strbuf *param1);
const u16 * sub_02025EF0(const PlayerProfile * param0);
void sub_02025EF4(const PlayerProfile * param0, Strbuf *param1);
Strbuf* sub_02025F04(const PlayerProfile * param0, int param1);
void sub_02025F1C(PlayerProfile * param0, u32 param1);
u32 sub_02025F20(const PlayerProfile * param0);
u16 sub_02025F24(const PlayerProfile * param0);
void sub_02025F2C(PlayerProfile * param0, int param1);
u32 sub_02025F30(const PlayerProfile * param0);
BOOL sub_02025F34(const PlayerProfile * param0, int param1);
void sub_02025F48(PlayerProfile * param0, int param1);
int sub_02025F58(const PlayerProfile * param0);
u32 sub_02025F74(const PlayerProfile * param0);
u32 sub_02025F78(PlayerProfile * param0, u32 param1);
u8 sub_02025F8C(const PlayerProfile * param0);
void sub_02025F90(PlayerProfile * param0, u8 param1);
u32 sub_02025F94(PlayerProfile * param0, u32 param1);
u32 sub_02025FB8(PlayerProfile * param0, u32 param1);
u8 sub_02025FCC(const PlayerProfile * param0);
void sub_02025FD0(PlayerProfile * param0, u8 param1);
u8 sub_02025FD4(void);
u8 sub_02025FD8(const PlayerProfile * param0);
void sub_02025FDC(PlayerProfile * param0, u8 param1);
void sub_02025FE0(PlayerProfile * param0);
int sub_02025FF0(PlayerProfile * param0);
void sub_02025FF8(PlayerProfile * param0);
int sub_02026004(PlayerProfile * param0);
BOOL sub_0202600C(const PlayerProfile * param0, const PlayerProfile * param1);

#endif // POKEPLATINUM_PLAYER_PROFILE_H
