#include <nitro.h>
#include <string.h>

#include "data_021BF67C.h"

#include "struct_decls/struct_021C0794_decl.h"

#include "struct_defs/options.h"

#include "heap.h"
#include "player_data.h"
#include "options.h"

Options * Options_New (u32 param0)
{
    Options * options = Heap_AllocFromHeap(param0, sizeof(Options));
    Options_Init(options);
    return options;
}

void Options_Copy (const Options * src, Options * dest)
{
    MI_CpuCopy8(src, dest, sizeof(Options));
}

void Options_Init (Options * options)
{
    MI_CpuFill8(options, 0, sizeof(Options));

    options->textSpeed = 1;
    options->soundMethod = 0;
    options->battleStyle = 0;
    options->battleScene = 0;
    options->buttonMode = 0;
    options->frame = 0;
}

void Options_SetButtonModeOnMain (UnkStruct_021C0794 * param0, int buttonMode)
{
    if (param0 != NULL) {
        buttonMode = Options_GetButtonMode(Save_PlayerData_GetOptionsAddr(param0));
    }

    switch (buttonMode) {
        case 1:
            Unk_021BF67C.unk_34 = 1;
            break;
        case 2:
            Unk_021BF67C.unk_34 = 3;
            break;
        case 0:
        default:
            Unk_021BF67C.unk_34 = 0;
            break;
    }
}

int Options_GetTextSpeed (const Options * options)
{
    return options->textSpeed;
}

void Options_SetTextSpeed (Options * options, int newTextSpeed)
{
    options->textSpeed = newTextSpeed;
}

u8 Options_GetTextFrameDelay (const Options * options)
{
    int textSpeed = Options_GetTextSpeed(options);

    if (textSpeed == 0) {
        return 8;
    } else if (textSpeed == 1) {
        return 4;
    } else {
        return 1;
    }
}

int Options_GetSoundMethod (const Options * options)
{
    return options->soundMethod;
}

void Options_SetSoundMethod (Options * options, int newSoundMethod)
{
    options->soundMethod = newSoundMethod;
}

int Options_GetBattleScene (const Options * options)
{
    return options->battleScene;
}

void Options_SetBattleScene (Options * options, int newBattleScene)
{
    options->battleScene = newBattleScene;
}

int Options_GetBattleStyle (const Options * options)
{
    return options->battleStyle;
}

void Options_SetBattleStyle (Options * options, int newBattleStyle)
{
    options->battleStyle = newBattleStyle;
}

int Options_GetButtonMode (const Options * options)
{
    return options->buttonMode;
}

void Options_SetButtonMode (Options * options, int newButtonMode)
{
    options->buttonMode = newButtonMode;
}

int Options_GetFrame (const Options * options)
{
    return options->frame;
}

void Options_SetFrame (Options * options, int newFrame)
{
    options->frame = newFrame;
}
