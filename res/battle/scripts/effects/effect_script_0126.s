    .include "macros/btlcmd.inc"

    .data

_000:
    UpdateVar OPCODE_FLAG_ON, BTLVAR_BATTLE_CTX_STATUS, SYSCTL_HIT_DURING_DIG
    UpdateVar OPCODE_SET, BTLVAR_POWER_MULTI, 10
    CompareMonDataToValue OPCODE_FLAG_NOT, BTLSCR_DEFENDER, BATTLEMON_MOVE_EFFECTS_MASK, MOVE_EFFECT_UNDERGROUND, _017
    UpdateVar OPCODE_SET, BTLVAR_POWER_MULTI, 20

_017:
    UpdateVar OPCODE_SET, BTLVAR_SIDE_EFFECT_FLAGS_DIRECT, MOVE_SIDE_EFFECT_ON_HIT|MOVE_SIDE_EFFECT_TO_DEFENDER|MOVE_SUBSCRIPT_PTR_MAGNITUDE
    CalcMagnitudePower 
    CalcCrit 
    CalcDamage 
    End 
