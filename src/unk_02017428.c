#include <nitro.h>
#include <string.h>

#include "struct_decls/igt_decl.h"

#include "unk_02017428.h"
#include "unk_02022844.h"
#include "igt.h"

static BOOL Unk_021BF658 = 0;
static u64 Unk_021BF668 = 0;
static u64 Unk_021BF660 = 0;
static u64 Unk_021BF670 = 0;
static IGT * Unk_021BF65C = NULL;

void sub_02017428 (void)
{
    Unk_021BF658 = 0;
}

void sub_02017434 (IGT * param0)
{
    Unk_021BF658 = 1;
    Unk_021BF668 = 0;
    Unk_021BF660 = 0;
    Unk_021BF65C = param0;
    Unk_021BF670 = sub_0202293C();
}

void sub_02017458 (void)
{
    if (Unk_021BF658) {
        u64 v0 = sub_0202295C(sub_0202293C() - Unk_021BF670);

        if (v0 > Unk_021BF660) {
            IGT_AddSeconds(Unk_021BF65C, (v0 - Unk_021BF660));
            Unk_021BF660 = v0;
        }
    }
}
