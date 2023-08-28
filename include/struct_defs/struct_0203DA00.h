#ifndef POKEPLATINUM_STRUCT_0203DA00_H
#define POKEPLATINUM_STRUCT_0203DA00_H

#include "struct_decls/player_profile_decl.h"
#include "struct_defs/options.h"
#include "struct_decls/struct_02029C68_decl.h"
#include "struct_decls/struct_02029D04_decl.h"
#include "struct_decls/struct_0202CD88_decl.h"
#include "struct_defs/pokemon.h"

typedef struct {
    Pokemon * unk_00;
    UnkStruct_02029C68 * unk_04;
    const UnkStruct_02029D04 * unk_08;
    const Options * unk_0C;
    UnkStruct_0202CD88 * unk_10;
    const PlayerProfile * unk_14;
    BOOL * unk_18;
    BOOL unk_1C;
} UnkStruct_0203DA00;

#endif // POKEPLATINUM_STRUCT_0203DA00_H
