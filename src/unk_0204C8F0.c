#include <nitro.h>
#include <string.h>

#include "inlines.h"

#include "struct_decls/struct_02025E6C_decl.h"
#include "struct_decls/struct_0203E724_decl.h"

#include "struct_defs/struct_0203CDB0.h"
#include "struct_defs/struct_0203E724_t.h"
#include "struct_defs/struct_0205AA50.h"

#include "player_data.h"
#include "unk_02025E68.h"
#include "unk_0203CC84.h"
#include "unk_0203E724.h"
#include "unk_0203E880.h"
#include "unk_0204C8F0.h"
#include "overlay005/ov5_021DC018.h"


BOOL sub_0204C8F0 (UnkStruct_0203E724 * param0)
{
    UnkStruct_02025E6C * v0 = PlayerData_GetProfileAddr(sub_0203D174(param0->unk_34));
    u32 v1;

    v1 = sub_0203E850(param0);
    sub_02025F94(v0, v1);

    return 0;
}

BOOL sub_0204C914 (UnkStruct_0203E724 * param0)
{
    UnkStruct_02025E6C * v0 = PlayerData_GetProfileAddr(sub_0203D174(param0->unk_34));
    u32 v1;

    v1 = sub_0203E850(param0);
    sub_02025FB8(v0, v1);

    return 0;
}

BOOL sub_0204C938 (UnkStruct_0203E724 * param0)
{
    UnkStruct_02025E6C * v0 = PlayerData_GetProfileAddr(sub_0203D174(param0->unk_34));
    u32 v1;

    v1 = inline_02049538(param0);
    sub_02025FB8(v0, v1);

    return 0;
}

BOOL sub_0204C968 (UnkStruct_0203E724 * param0)
{
    UnkStruct_02025E6C * v0 = PlayerData_GetProfileAddr(sub_0203D174(param0->unk_34));
    u16 * v1;
    u32 v2, v3;

    v1 = inline_0204FCAC(param0);
    v2 = sub_0203E850(param0);
    v3 = sub_02025F74(v0);

    if (v3 < v2) {
        *v1 = 0;
    } else {
        *v1 = 1;
    }

    return 0;
}

BOOL sub_0204C9AC (UnkStruct_0203E724 * param0)
{
    UnkStruct_02025E6C * v0 = PlayerData_GetProfileAddr(sub_0203D174(param0->unk_34));
    u16 * v1;
    u32 v2, v3;

    v1 = inline_0204FCAC(param0);
    v2 = inline_02049538(param0);
    v3 = sub_02025F74(v0);

    if (v3 < v2) {
        *v1 = 0;
    } else {
        *v1 = 1;
    }

    return 0;
}

BOOL sub_0204C9FC (UnkStruct_0203E724 * param0)
{
    UnkStruct_0203CDB0 * v0 = param0->unk_34;
    u16 v1 = inline_02049538(param0);
    u16 v2 = inline_02049538(param0);
    UnkStruct_0205AA50 ** v3;

    v3 = sub_0203F098(v0, 39);
    *v3 = ov5_021DCEB0(param0->unk_34, v1, v2);

    return 0;
}

BOOL sub_0204CA4C (UnkStruct_0203E724 * param0)
{
    UnkStruct_0203CDB0 * v0 = param0->unk_34;
    UnkStruct_0205AA50 ** v1 = sub_0203F098(v0, 39);

    ov5_021DCF58(*v1);
    return 0;
}

BOOL sub_0204CA64 (UnkStruct_0203E724 * param0)
{
    UnkStruct_0203CDB0 * v0 = param0->unk_34;
    UnkStruct_0205AA50 ** v1 = sub_0203F098(v0, 39);

    ov5_021DCF6C(param0->unk_34, *v1);
    return 0;
}
