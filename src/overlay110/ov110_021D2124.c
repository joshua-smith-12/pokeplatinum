#include "overlay110/ov110_021D2124.h"

#include <nitro.h>
#include <string.h>

#include "bg_window.h"

typedef struct {
    const WindowTemplate *unk_00;
    u32 unk_04;
} UnkStruct_ov110_021D2278;

void ov110_021D2124(BgConfig *param0, Window *param1, u8 param2);
void ov110_021D216C(Window *param0, u8 param1);

static const WindowTemplate Unk_ov110_021D22A0[] = {
    { 0x0, 0x2, 0x2, 0x1E, 0x2, 0xD, 0x1 },
    { 0x0, 0x2, 0x7, 0x1C, 0x2, 0xD, 0x3D },
    { 0x0, 0x2, 0xA, 0x1C, 0x2, 0xD, 0x75 },
    { 0x0, 0x2, 0xC, 0x1C, 0x2, 0xD, 0xAD },
    { 0x0, 0x2, 0xF, 0x10, 0x2, 0xD, 0xE5 },
    { 0x0, 0x2, 0x12, 0x1C, 0x2, 0xD, 0x105 },
    { 0x0, 0x2, 0x14, 0x1C, 0x2, 0xD, 0x13D }
};

static const WindowTemplate Unk_ov110_021D2238[] = {
    { 0x0, 0x2, 0x2, 0x1C, 0x2, 0xD, 0x1 },
    { 0x0, 0x2, 0x7, 0x1C, 0x2, 0xD, 0x39 },
    { 0x0, 0x2, 0xA, 0x1C, 0x2, 0xD, 0x71 },
    { 0x0, 0x2, 0xD, 0x1C, 0x2, 0xD, 0xA9 }
};

static const WindowTemplate Unk_ov110_021D2258[] = {
    { 0x0, 0x2, 0x2, 0x1C, 0x2, 0xD, 0x1 },
    { 0x0, 0x12, 0x7, 0xC, 0x2, 0xD, 0x39 },
    { 0x0, 0x2, 0xA, 0x1C, 0x2, 0xD, 0x51 },
    { 0x0, 0x2, 0xD, 0x1C, 0x2, 0xD, 0x89 }
};

static const WindowTemplate Unk_ov110_021D2220[] = {
    { 0x0, 0x2, 0x2, 0x1C, 0x2, 0xD, 0x1 },
    { 0x0, 0x2, 0x8, 0x1C, 0x2, 0xD, 0x39 },
    { 0x0, 0x2, 0xB, 0x1C, 0x2, 0xD, 0x71 }
};

static const WindowTemplate Unk_ov110_021D22D8[] = {
    { 0x0, 0x2, 0x2, 0x1E, 0x2, 0xD, 0x1 },
    { 0x0, 0x2, 0x7, 0x1C, 0x2, 0xD, 0x3D },
    { 0x0, 0x2, 0x7, 0x1C, 0x2, 0xD, 0x75 },
    { 0x0, 0x2, 0xA, 0x1C, 0x2, 0xD, 0xAD },
    { 0x0, 0x2, 0xA, 0x1C, 0x2, 0xD, 0x75 },
    { 0x0, 0x2, 0xC, 0x1C, 0x2, 0xD, 0xAD },
    { 0x0, 0x2, 0xF, 0x10, 0x2, 0xD, 0xE5 },
    { 0x0, 0x2, 0x12, 0x1C, 0x2, 0xD, 0x105 },
    { 0x0, 0x2, 0x14, 0x1C, 0x2, 0xD, 0x13D }
};

static const UnkStruct_ov110_021D2278 Unk_ov110_021D2278[5] = {
    { Unk_ov110_021D22A0, 0x7 },
    { Unk_ov110_021D2238, 0x4 },
    { Unk_ov110_021D2258, 0x4 },
    { Unk_ov110_021D2220, 0x3 },
    { Unk_ov110_021D22D8, 0x9 }
};

void ov110_021D2124(BgConfig *param0, Window *param1, u8 param2)
{
    u8 v0;
    const WindowTemplate *v1 = Unk_ov110_021D2278[param2].unk_00;
    u32 v2 = Unk_ov110_021D2278[param2].unk_04;

    for (v0 = 0; v0 < v2; v0++) {
        Window_AddFromTemplate(param0, &param1[v0], &v1[v0]);
        Window_FillTilemap(&param1[v0], 0);
    }

    return;
}

void ov110_021D216C(Window *param0, u8 param1)
{
    u16 v0;
    u32 v1 = Unk_ov110_021D2278[param1].unk_04;

    for (v0 = 0; v0 < v1; v0++) {
        Window_Remove(&param0[v0]);
    }

    return;
}
