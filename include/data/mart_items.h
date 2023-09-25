#include "constants/items.h"

typedef struct {
    u16 itemID;
    u16 unk_02;
} PokeMartCommonItem;

const PokeMartCommonItem PokeMartCommonItems[] = {
	{ ITEM_POKE_BALL, 0x1 },
	{ ITEM_GREAT_BALL, 0x3 },
	{ ITEM_ULTRA_BALL, 0x4 },
	{ ITEM_POTION, 0x1 },
	{ ITEM_SUPER_POTION, 0x2 },
	{ ITEM_HYPER_POTION, 0x4 },
	{ ITEM_MAX_POTION, 0x5 },
	{ ITEM_FULL_RESTORE, 0x6 },
	{ ITEM_REVIVE, 0x3 },
	{ ITEM_ANTIDOTE, 0x1 },
	{ ITEM_PARLYZ_HEAL, 0x1 },
	{ ITEM_AWAKENING, 0x2 },
	{ ITEM_BURN_HEAL, 0x2 },
	{ ITEM_ICE_HEAL, 0x2 },
	{ ITEM_FULL_HEAL, 0x4 },
	{ ITEM_ESCAPE_ROPE, 0x2 },
	{ ITEM_REPEL, 0x2 },
	{ ITEM_SUPER_REPEL, 0x3 },
	{ ITEM_MAX_REPEL, 0x4 }
};

const u16 JubilifeMartSpecialties[] = {
	ITEM_AIR_MAIL,
	ITEM_HEAL_BALL,
	0xffff
};

const u16 OreburghMartSpecialties[] = {
	ITEM_TUNNEL_MAIL,
	ITEM_HEAL_BALL,
	ITEM_NET_BALL,
	0xffff
};

const u16 FloaromaMartSpecialties[] = {
	ITEM_BLOOM_MAIL,
	ITEM_HEAL_BALL,
	ITEM_NET_BALL,
	0xffff
};

const u16 EternaMartSpecialties[] = {
	ITEM_AIR_MAIL,
	ITEM_HEAL_BALL,
	ITEM_NET_BALL,
	ITEM_NEST_BALL,
	0xffff
};

const u16 EternaHerbShopStock[] = {
	ITEM_HEAL_POWDER,
	ITEM_ENERGYPOWDER,
	ITEM_ENERGY_ROOT,
	ITEM_REVIVAL_HERB,
	0xffff
};

const u16 HearthomeMartSpecialties[] = {
	ITEM_HEART_MAIL,
	ITEM_HEAL_BALL,
	ITEM_NET_BALL,
	ITEM_NEST_BALL,
	0xffff
};

const u16 SolaceonMartSpecialties[] = {
	ITEM_AIR_MAIL,
	ITEM_NET_BALL,
	ITEM_NEST_BALL,
	ITEM_DUSK_BALL,
	0xffff
};

const u16 PastoriaMartSpecialties[] = {
	ITEM_AIR_MAIL,
	ITEM_NEST_BALL,
	ITEM_DUSK_BALL,
	ITEM_QUICK_BALL,
	0xffff
};

const u16 VeilstoneDeptStoreStock_1F_RIGHT[] = {
	ITEM_POTION,
	ITEM_SUPER_POTION,
	ITEM_HYPER_POTION,
	ITEM_MAX_POTION,
	ITEM_REVIVE,
	ITEM_ANTIDOTE,
	ITEM_PARLYZ_HEAL,
	ITEM_BURN_HEAL,
	ITEM_ICE_HEAL,
	ITEM_AWAKENING,
	ITEM_FULL_HEAL,
	0xffff
};

const u16 VeilstoneDeptStoreStock_1F_LEFT[] = {
	ITEM_POKE_BALL,
	ITEM_GREAT_BALL,
	ITEM_ULTRA_BALL,
	ITEM_ESCAPE_ROPE,
	ITEM_POKE_DOLL,
	ITEM_REPEL,
	ITEM_SUPER_REPEL,
	ITEM_MAX_REPEL,
	ITEM_GRASS_MAIL,
	ITEM_FLAME_MAIL,
	ITEM_BUBBLE_MAIL,
	ITEM_SPACE_MAIL,
	0xffff
};

const u16 VeilstoneDeptStoreStock_2F_UP[] = {
	ITEM_X_SPEED,
	ITEM_X_ATTACK,
	ITEM_X_DEFENSE,
	ITEM_GUARD_SPEC_,
	ITEM_DIRE_HIT,
	ITEM_X_ACCURACY,
	ITEM_X_SPECIAL,
	ITEM_X_SP__DEF,
	0xffff
};

const u16 VeilstoneDeptStoreStock_2F_MID[] = {
	ITEM_PROTEIN,
	ITEM_IRON,
	ITEM_CALCIUM,
	ITEM_ZINC,
	ITEM_CARBOS,
	ITEM_HP_UP,
	0xffff
};

const u16 VeilstoneDeptStoreStock_3F_UP[] = {
	ITEM_TM83,
	ITEM_TM17,
	ITEM_TM54,
	ITEM_TM20,
	ITEM_TM33,
	ITEM_TM16,
	ITEM_TM70,
	0xffff
};

const u16 VeilstoneDeptStoreStock_3F_DOWN[] = {
	ITEM_TM38,
	ITEM_TM25,
	ITEM_TM14,
	ITEM_TM22,
	ITEM_TM52,
	ITEM_TM15,
	0xffff
};

const u16 CelesticMartSpecialties[] = {
	ITEM_AIR_MAIL,
	ITEM_DUSK_BALL,
	ITEM_QUICK_BALL,
	ITEM_TIMER_BALL,
	0xffff
};

const u16 SnowpointMartSpecialties[] = {
	ITEM_SNOW_MAIL,
	ITEM_DUSK_BALL,
	ITEM_QUICK_BALL,
	ITEM_TIMER_BALL,
	0xffff
};

const u16 CanalaveMartSpecialties[] = {
	ITEM_AIR_MAIL,
	ITEM_QUICK_BALL,
	ITEM_TIMER_BALL,
	ITEM_REPEAT_BALL,
	0xffff
};

const u16 SunyshoreMartSpecialties[] = {
	ITEM_STEEL_MAIL,
	ITEM_LUXURY_BALL,
	0xffff
};

const u16 PokemonLeagueMartSpecialties[] = {
	ITEM_HEAL_BALL,
	ITEM_NET_BALL,
	ITEM_NEST_BALL,
	ITEM_DUSK_BALL,
	ITEM_QUICK_BALL,
	ITEM_TIMER_BALL,
	ITEM_REPEAT_BALL,
	ITEM_LUXURY_BALL,
	0xffff
};

const u16 VeilstoneDeptStoreStock_B1F_DOWN_LEFT[] = {
	ITEM_FIGY_BERRY,
	ITEM_WIKI_BERRY,
	ITEM_MAGO_BERRY,
	ITEM_AGUAV_BERRY,
	ITEM_IAPAPA_BERRY,
	0xffff
};

const u16 *PokeMartSpecialties[] = {
	JubilifeMartSpecialties,
	OreburghMartSpecialties,
	FloaromaMartSpecialties,
	EternaMartSpecialties,
	EternaHerbShopStock,
	HearthomeMartSpecialties,
	SolaceonMartSpecialties,
	PastoriaMartSpecialties,
	VeilstoneDeptStoreStock_1F_RIGHT,
	VeilstoneDeptStoreStock_1F_LEFT,
	VeilstoneDeptStoreStock_2F_UP,
	VeilstoneDeptStoreStock_2F_MID,
	VeilstoneDeptStoreStock_3F_UP,
	VeilstoneDeptStoreStock_3F_DOWN,
	CelesticMartSpecialties,
	SnowpointMartSpecialties,
	CanalaveMartSpecialties,
	SunyshoreMartSpecialties,
	PokemonLeagueMartSpecialties,
	VeilstoneDeptStoreStock_B1F_DOWN_LEFT
};