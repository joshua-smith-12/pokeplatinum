    .include "macros/btlcmd.inc"

    .data

_000:
    // Gravity intensified!
    PrintMessage pl_msg_00000368_00997, TAG_NONE
    Wait 
    WaitButtonABTime 30
    UpdateVar OPCODE_FLAG_ON, BTLVAR_FIELD_CONDITIONS, FIELD_CONDITION_GRAVITY_INIT
    UpdateVar OPCODE_SET, BTLVAR_BATTLER_SPEED_TEMP, 0

_013:
    GetMonBySpeedOrder BTLVAR_MSG_BATTLER_TEMP
    CompareMonDataToValue OPCODE_EQU, BTLSCR_MSG_TEMP, BATTLEMON_CUR_HP, 0, _085
    CompareMonDataToValue OPCODE_NEQ, BTLSCR_MSG_TEMP, BATTLEMON_MAGNET_RISE_TURNS, 0, _065
    CompareMonDataToValue OPCODE_FLAG_SET, BTLSCR_MSG_TEMP, BATTLEMON_MOVE_EFFECTS_MASK, MOVE_EFFECT_AIRBORNE, _072
    CompareMonDataToValue OPCODE_FLAG_SET, BTLSCR_MSG_TEMP, BATTLEMON_MOVE_EFFECTS_MASK, MOVE_EFFECT_ABILITY_SUPPRESSED, _085
    CompareMonDataToValue OPCODE_FLAG_SET, BTLSCR_MSG_TEMP, BATTLEMON_MOVE_EFFECTS_MASK, MOVE_EFFECT_INGRAIN, _085
    CompareMonDataToValue OPCODE_EQU, BTLSCR_MSG_TEMP, BATTLEMON_ABILITY, ABILITY_LEVITATE, _078
    CompareMonDataToValue OPCODE_EQU, BTLSCR_MSG_TEMP, BATTLEMON_TYPE_1, TYPE_FLYING, _078
    CompareMonDataToValue OPCODE_EQU, BTLSCR_MSG_TEMP, BATTLEMON_TYPE_2, TYPE_FLYING, _078
    GoTo _085

_065:
    UpdateMonData OPCODE_SET, BTLSCR_MSG_TEMP, BATTLEMON_MAGNET_RISE_TURNS, 0
    GoTo _078

_072:
    UnlockMoveChoice BTLSCR_MSG_TEMP
    ToggleVanish BTLSCR_MSG_TEMP, FALSE
    Wait 

_078:
    // {0} couldn’t stay airborne because of gravity!
    PrintMessage pl_msg_00000368_00998, TAG_NICKNAME, BTLSCR_MSG_TEMP
    Wait 
    WaitButtonABTime 30

_085:
    UpdateVar OPCODE_ADD, BTLVAR_BATTLER_SPEED_TEMP, 1
    GoToIfValidMon BTLVAR_BATTLER_SPEED_TEMP, _013
    End 
