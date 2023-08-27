#include <nitro.h>
#include <string.h>

#include "struct_decls/player_data.h"
#include "struct_decls/struct_021C0794_decl.h"

#include "struct_defs/struct_02025E5C.h"
#include "struct_defs/player_profile.h"
#include "struct_defs/struct_020279FC.h"

#include "unk_020244AC.h"
#include "player_data.h"
#include "player_profile.h"
#include "unk_020279FC.h"
#include "coins.h"
#include "unk_0202CBE4.h"

typedef struct PlayerData_t {
    UnkStruct_020279FC options;
    PlayerProfile profile;
    u16 coins;
    UnkStruct_02025E5C igt;
} PlayerData;

int PlayerData_sizeof (void)
{
    return sizeof(PlayerData);
}

void PlayerData_Init (PlayerData * playerData)
{
    MI_CpuClearFast(playerData, sizeof(PlayerData));

    sub_02027A1C(&playerData->options);
    sub_02025E8C(&playerData->profile);
    Coins_Init(&playerData->coins);
    sub_0202CBE4(&playerData->igt);
}

PlayerProfile * PlayerData_GetProfileAddr (UnkStruct_021C0794 * param0)
{
    return &((PlayerData *)sub_020245BC(param0, 1))->profile;
}

UnkStruct_020279FC * PlayerData_GetOptionsAddr (UnkStruct_021C0794 * param0)
{
    return &((PlayerData *)sub_020245BC(param0, 1))->options;
}

u16 * PlayerData_GetCoinsAddr (UnkStruct_021C0794 * param0)
{
    return &((PlayerData *)sub_020245BC(param0, 1))->coins;
}

UnkStruct_02025E5C * PlayerData_GetIGTAddr (UnkStruct_021C0794 * param0)
{
    return &((PlayerData *)sub_020245BC(param0, 1))->igt;
}
