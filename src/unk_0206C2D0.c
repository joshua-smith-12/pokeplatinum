#include <nitro.h>
#include <string.h>

#include "struct_decls/struct_02025E6C_decl.h"
#include "struct_decls/struct_0202C834_decl.h"
#include "struct_decls/struct_0202C844_decl.h"
#include "struct_decls/struct_021C0794_decl.h"

#include "player_data.h"
#include "unk_02025E68.h"
#include "unk_0202C7FC.h"
#include "unk_0206C2D0.h"

void sub_0206C2D0 (UnkStruct_021C0794 * param0, const s32 param1)
{
    u8 v0;
    int v1;
    UnkStruct_0202C834 * v2;
    UnkStruct_0202C844 * v3;
    UnkStruct_02025E6C * v4;

    if (param1 <= 0) {
        return;
    }

    v2 = sub_0202C834(param0);
    v3 = sub_0202C844(v2);
    v4 = PlayerData_GetProfileAddr(param0);

    for (v0 = 0; v0 < 8; v0++) {
        if (sub_02025F34(v4, v0) == 0) {
            continue;
        }

        v1 = sub_0202C848(v0, v3);

        if ((0 < v1) && (v1 < 200)) {
            v1 -= (10 * param1);
        } else {
            GF_ASSERT(v1 < 200);
            v1 = 0;
        }

        if (v1 < 0) {
            v1 = 0;
        }

        sub_0202C850(v0, v1, v3);
    }
}
