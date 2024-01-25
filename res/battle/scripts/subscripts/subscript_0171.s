    .include "macros/btlcmd.inc"

    .data

_000:
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_NOT_ZERO, SIDE_COND_REFLECT_TURNS, _041
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_NOT_ZERO, SIDE_COND_LIGHT_SCREEN_TURNS, _041
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_NOT_ZERO, SIDE_COND_MIST_TURNS, _041
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_NOT_ZERO, SIDE_COND_SAFEGUARD_TURNS, _041
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_NOT_ZERO, SIDE_COND_SPIKES_LAYERS, _041
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_NOT_ZERO, SIDE_COND_TOXIC_SPIKES_LAYERS, _041
    CompareVarToValue OPCODE_FLAG_SET, BTLVAR_SIDE_CONDITIONS_DEFENDER, SIDE_CONDITION_STEALTH_ROCK, _041
    CompareVarToValue OPCODE_FLAG_SET, BTLVAR_FIELD_CONDITIONS, FIELD_CONDITION_DEEP_FOG, _041
    GoTo _043

_041:
    Call BATTLE_SUBSCRIPT_ATTACK_MESSAGE_AND_ANIMATION

_043:
    UpdateVar OPCODE_SET, BTLVAR_SIDE_EFFECT_PARAM, MOVE_SUBSCRIPT_PTR_EVASION_DOWN_1_STAGE
    Call BATTLE_SUBSCRIPT_UPDATE_STAT_STAGE
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_ZERO, SIDE_COND_REFLECT_TURNS, _065
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_CLEAR, SIDE_COND_REFLECT_TURNS, _065
    UpdateVar OPCODE_SET, BTLVAR_MSG_MOVE_TEMP, MOVE_REFLECT
    Call BATTLE_SUBSCRIPT_DEFOG_MESSAGE

_065:
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_ZERO, SIDE_COND_LIGHT_SCREEN_TURNS, _081
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_CLEAR, SIDE_COND_LIGHT_SCREEN_TURNS, _081
    UpdateVar OPCODE_SET, BTLVAR_MSG_MOVE_TEMP, MOVE_LIGHT_SCREEN
    Call BATTLE_SUBSCRIPT_DEFOG_MESSAGE

_081:
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_ZERO, SIDE_COND_MIST_TURNS, _097
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_CLEAR, SIDE_COND_MIST_TURNS, _097
    UpdateVar OPCODE_SET, BTLVAR_MSG_MOVE_TEMP, MOVE_MIST
    Call BATTLE_SUBSCRIPT_DEFOG_MESSAGE

_097:
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_ZERO, SIDE_COND_SAFEGUARD_TURNS, _113
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_CLEAR, SIDE_COND_SAFEGUARD_TURNS, _113
    UpdateVar OPCODE_SET, BTLVAR_MSG_MOVE_TEMP, MOVE_SAFEGUARD
    Call BATTLE_SUBSCRIPT_DEFOG_MESSAGE

_113:
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_ZERO, SIDE_COND_SPIKES_LAYERS, _133
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_CLEAR, SIDE_COND_SPIKES_LAYERS, _133
    UpdateVar OPCODE_FLAG_OFF, BTLVAR_SIDE_CONDITIONS_DEFENDER, SIDE_CONDITION_SPIKES
    UpdateVar OPCODE_SET, BTLVAR_MSG_MOVE_TEMP, MOVE_SPIKES
    Call BATTLE_SUBSCRIPT_DEFOG_MESSAGE

_133:
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_VAL_ZERO, SIDE_COND_TOXIC_SPIKES_LAYERS, _149
    CheckSideCondition BTLSCR_DEFENDER, CHECK_SIDE_COND_CLEAR, SIDE_COND_TOXIC_SPIKES_LAYERS, _149
    UpdateVar OPCODE_SET, BTLVAR_MSG_MOVE_TEMP, MOVE_TOXIC_SPIKES
    Call BATTLE_SUBSCRIPT_DEFOG_MESSAGE

_149:
    CompareVarToValue OPCODE_FLAG_NOT, BTLVAR_SIDE_CONDITIONS_DEFENDER, SIDE_CONDITION_STEALTH_ROCK, _164
    UpdateVar OPCODE_FLAG_OFF, BTLVAR_SIDE_CONDITIONS_DEFENDER, SIDE_CONDITION_STEALTH_ROCK
    UpdateVar OPCODE_SET, BTLVAR_MSG_MOVE_TEMP, MOVE_STEALTH_ROCK
    Call BATTLE_SUBSCRIPT_DEFOG_MESSAGE

_164:
    CompareVarToValue OPCODE_FLAG_NOT, BTLVAR_FIELD_CONDITIONS, FIELD_CONDITION_DEEP_FOG, _181
    UpdateVar OPCODE_FLAG_OFF, BTLVAR_FIELD_CONDITIONS, FIELD_CONDITION_DEEP_FOG
    // {0} blew away the deep fog with {1}!
    PrintMessage pl_msg_00000368_01045, TAG_NICKNAME_MOVE, BTLSCR_ATTACKER, BTLSCR_ATTACKER
    Wait 
    WaitButtonABTime 30

_181:
    End 
