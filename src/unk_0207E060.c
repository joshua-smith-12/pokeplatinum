#include <nitro.h>
#include <string.h>

#include "struct_decls/player_profile_decl.h"

#include "struct_defs/struct_0207E060.h"

#include "heap.h"
#include "player_profile.h"
#include "unk_0207E060.h"
#include "overlay004/ov4_021D0D80.h"

UnkStruct_0207E060 * sub_0207E060 (const PlayerProfile * param0, u32 param1)
{
    UnkStruct_0207E060 * v0;
    BOOL v1;

    v0 = Heap_AllocFromHeap(param1, (sizeof(UnkStruct_0207E060)));
    memset(v0, 0, (sizeof(UnkStruct_0207E060)));

    v0->unk_1B = 28;
    v0->unk_1E = PlayerProfile_GetGender(param0);
    v0->unk_1D = PlayerProfile_GetAvatar(param0);
    v0->unk_18 = PlayerProfile_GetVersion(param0);
    v0->unk_19 = PlayerProfile_GetLanguage(param0);

    v1 = ov4_021D222C(v0, (sizeof(UnkStruct_0207E060)));
    GF_ASSERT(v1 == 1);

    return v0;
}

void sub_0207E0B0 (UnkStruct_0207E060 * param0)
{
    Heap_FreeToHeap(param0);
}
