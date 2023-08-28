#ifndef POKEPLATINUM_PLAYER_DATA_H
#define POKEPLATINUM_PLAYER_DATA_H

#include "struct_decls/player_data_decl.h"
#include "struct_decls/igt_decl.h"
#include "struct_decls/player_profile_decl.h"
#include "struct_defs/options.h"
#include "struct_decls/struct_021C0794_decl.h"

int Save_PlayerData_sizeof(void);
void Save_PlayerData_Init(PlayerData * playerData);
PlayerProfile * Save_PlayerData_GetProfileAddr(UnkStruct_021C0794 * param0);
Options * Save_PlayerData_GetOptionsAddr(UnkStruct_021C0794 * param0);
u16 * Save_PlayerData_GetCoinsAddr(UnkStruct_021C0794 * param0);
IGT * Save_PlayerData_GetIGTAddr(UnkStruct_021C0794 * param0);

#endif // POKEPLATINUM_PLAYER_DATA_H
