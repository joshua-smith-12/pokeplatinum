#ifndef POKEPLATINUM_UNK_0207C908_H
#define POKEPLATINUM_UNK_0207C908_H

#include <nnsys.h>

#include "struct_decls/cell_actor_data.h"
#include "struct_decls/struct_0200C6E4_decl.h"
#include "struct_decls/struct_0200C704_decl.h"
#include "struct_defs/sprite_template.h"

#include "palette.h"

#define NARC_INDEX_BATTLE__GRAPHIC__PL_BATT_OBJ__TYPE_PALETTE 74

u32 BattleObj_TypeIDToNARCMember(int param0);
u32 BattleObj_GetPaletteNARCMember(void);
u32 sub_0207C924(void);
u32 sub_0207C928(void);
u8 BattleObj_TypeIDToPaletteIndex(int param0);
u32 BattleObj_GetNARCIndex(void);
void BattleObj_MakeTypeSpriteTiles(SpriteRenderer *param0, SpriteGfxHandler *param1, NNS_G2D_VRAM_TYPE param2, int param3, u32 param4);
void BattleObj_MakeTypeSpritePalette(SpriteRenderer *param0, SpriteGfxHandler *param1, NNS_G2D_VRAM_TYPE param2, u32 param3);
void sub_0207C9B0(PaletteData *param0, int param1, SpriteRenderer *param2, SpriteGfxHandler *param3, NNS_G2D_VRAM_TYPE param4, u32 param5);
void sub_0207C9EC(SpriteRenderer *param0, SpriteGfxHandler *param1, u32 param2, u32 param3);
void sub_0207CA34(SpriteGfxHandler *param0, u32 param1);
void sub_0207CA3C(SpriteGfxHandler *param0, u32 param1);
void sub_0207CA44(SpriteGfxHandler *param0, u32 param1, u32 param2);
CellActorData *sub_0207CA58(SpriteRenderer *param0, SpriteGfxHandler *param1, int param2, const SpriteTemplate *param3);
void sub_0207CA88(CellActorData *param0);
u32 BattleObj_MoveTypeIDToNARCMember(int param0);
u8 BattleObj_MoveTypeIDToPaletteIndex(int param0);
u32 BattleObj_GetMoveTypeNARCIndex(void);
void BattleObj_MakeMoveTypeSpriteTiles(SpriteRenderer *param0, SpriteGfxHandler *param1, NNS_G2D_VRAM_TYPE param2, int param3, u32 param4);
void sub_0207CAF8(SpriteGfxHandler *param0, u32 param1);
void sub_0207CB00(CellActorData *param0);

#endif // POKEPLATINUM_UNK_0207C908_H
