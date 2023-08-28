#include <nitro.h>
#include <string.h>

#include "struct_decls/player_data_decl.h"
#include "struct_decls/struct_021C0794_decl.h"

#include "struct_defs/igt.h"
#include "struct_defs/player_profile.h"
#include "struct_defs/options.h"

#include "unk_020244AC.h"
#include "player_data.h"
#include "player_profile.h"
#include "options.h"
#include "coins.h"
#include "igt.h"

struct PlayerData_t {
    Options options;
    PlayerProfile profile;
    u16 coins;
    IGT igt;
};

int Save_PlayerData_sizeof (void)
{
    return sizeof(PlayerData);
}

void Save_PlayerData_Init (PlayerData * playerData)
{
    MI_CpuClearFast(playerData, sizeof(PlayerData));

    Options_Init(&playerData->options);
    PlayerProfile_Init(&playerData->profile);
    Coins_Init(&playerData->coins);
    IGT_Init(&playerData->igt);
}

PlayerProfile * Save_PlayerData_GetProfileAddr (UnkStruct_021C0794 * param0)
{
    PlayerData* playerData = sub_020245BC(param0, 1);
    return &playerData->profile;
}

Options * Save_PlayerData_GetOptionsAddr (UnkStruct_021C0794 * param0)
{
    PlayerData* playerData = sub_020245BC(param0, 1);
    return &playerData->options;
}

u16 * Save_PlayerData_GetCoinsAddr (UnkStruct_021C0794 * param0)
{
    PlayerData* playerData = sub_020245BC(param0, 1);
    return &playerData->coins;
}

IGT * Save_PlayerData_GetIGTAddr (UnkStruct_021C0794 * param0)
{
    PlayerData* playerData = sub_020245BC(param0, 1);
    return &playerData->igt;
}
