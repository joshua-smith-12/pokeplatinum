#ifndef POKEPLATINUM_PLAYER_DATA_H
#define POKEPLATINUM_PLAYER_DATA_H

#include "struct_decls/player_data.h"
#include "struct_decls/struct_02025E5C_decl.h"
#include "struct_decls/player_profile.h"
#include "struct_defs/struct_020279FC.h"
#include "struct_decls/struct_021C0794_decl.h"

int PlayerData_sizeof(void);
void PlayerData_Init(PlayerData * param0);
PlayerProfile * PlayerData_GetProfileAddr(UnkStruct_021C0794 * param0);
UnkStruct_020279FC * PlayerData_GetOptionsAddr(UnkStruct_021C0794 * param0);
u16 * PlayerData_GetCoinsAddr(UnkStruct_021C0794 * param0);
UnkStruct_02025E5C * PlayerData_GetIGTAddr(UnkStruct_021C0794 * param0);

#endif // POKEPLATINUM_PLAYER_DATA_H
