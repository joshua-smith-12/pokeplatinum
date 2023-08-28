#ifndef POKEPLATINUM_STRUCT_PLAYER_PROFILE_H
#define POKEPLATINUM_STRUCT_PLAYER_PROFILE_H

typedef struct PlayerProfile_t {
    u16 name[8];
    u32 trainerID;
    u32 money;
    u8 gender;
    u8 language;
    u8 badges;
    u8 avatar;
    u8 version;
    u8 gameCleared : 1;
    u8 nationalDex : 1;
    u8 padding1D : 6;
    u8 padding1E;
    u8 padding1F;
} PlayerProfile;

#endif // POKEPLATINUM_STRUCT_PLAYER_PROFILE_H
