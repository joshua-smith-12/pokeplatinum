#ifndef POKEPLATINUM_IGT_H
#define POKEPLATINUM_IGT_H

#include "struct_decls/igt_decl.h"

#define IGT_HOURS_MAX 999
#define IGT_MINUTES_MAX 59
#define IGT_SECONDS_MAX 59

void IGT_Init(IGT * igt);
void IGT_AddSeconds(IGT * igt, u32 param1);
u16 IGT_GetHours(const IGT * igt);
u8 IGT_GetMinutes(const IGT * igt);
u8 IGT_GetSeconds(const IGT * igt);

#endif // POKEPLATINUM_IGT_H
