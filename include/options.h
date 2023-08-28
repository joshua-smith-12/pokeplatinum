#ifndef POKEPLATINUM_OPTIONS_H
#define POKEPLATINUM_OPTIONS_H

#include "struct_defs/options.h"
#include "struct_decls/struct_021C0794_decl.h"

Options * Options_New(u32 param0);
void Options_Copy(const Options * src, Options * dest);
void Options_Init(Options * options);
void Options_SetButtonModeOnMain(UnkStruct_021C0794 * param0, int param1);
int Options_GetTextSpeed(const Options * options);
void Options_SetTextSpeed(Options * options, int param1);
u8 Options_GetTextFrameDelay(const Options * options);
int Options_GetSoundMethod(const Options * options);
void Options_SetSoundMethod(Options * options, int param1);
int Options_GetBattleScene(const Options * options);
void Options_SetBattleScene(Options * options, int param1);
int Options_GetBattleStyle(const Options * options);
void Options_SetBattleStyle(Options * options, int param1);
int Options_GetButtonMode(const Options * options);
void Options_SetButtonMode(Options * options, int param1);
int Options_GetFrame(const Options * options);
void Options_SetFrame(Options * options, int param1);

#endif // POKEPLATINUM_OPTIONS_H
