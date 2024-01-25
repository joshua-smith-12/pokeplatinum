    .include "macros/btlcmd.inc"

    .data

_000:
    CompareVarToValue OPCODE_FLAG_SET, BTLVAR_MOVE_STATUS_FLAGS, MOVE_STATUS_SEMI_INVULNERABLE, _074
    CheckIgnorableAbility CHECK_HAVE, BTLSCR_DEFENDER, ABILITY_SUCTION_CUPS, _079
    CompareMonDataToValue OPCODE_EQU, BTLSCR_DEFENDER, BATTLEMON_MOVE_EFFECTS_MASK, MOVE_EFFECT_INGRAIN, _086
    CompareVarToValue OPCODE_EQU, BTLVAR_BATTLE_TYPE, BATTLE_TYPE_DOUBLES|BATTLE_TYPE_2vs2|BATTLE_TYPE_AI, _074
    TryWhirlwind _074
    Call BATTLE_SUBSCRIPT_ATTACK_MESSAGE_AND_ANIMATION
    TryRestoreStatusOnSwitch BTLSCR_DEFENDER, _032
    UpdateMonData OPCODE_SET, BTLSCR_DEFENDER, BATTLEMON_STATUS, MON_CONDITION_NONE

_032:
    DeletePokemon BTLSCR_DEFENDER
    Wait 
    CompareVarToValue OPCODE_FLAG_NOT, BTLVAR_BATTLE_TYPE, BATTLE_TYPE_TRAINER, _067
    HealthbarSlideOut BTLSCR_DEFENDER
    Wait 
    SwitchAndUpdateMon BTLSCR_FORCED_OUT
    Wait 
    PokemonSendOut BTLSCR_DEFENDER
    WaitTime 72
    HealthbarSlideIn BTLSCR_DEFENDER
    Wait 
    // {0} was dragged out!
    PrintMessage pl_msg_00000368_00603, TAG_NICKNAME, BTLSCR_DEFENDER
    Wait 
    WaitButtonABTime 30
    UpdateVarFromVar OPCODE_SET, BTLVAR_SWITCHED_MON, BTLVAR_DEFENDER
    Call BATTLE_SUBSCRIPT_HAZARDS_CHECK
    End 

_067:
    FadeOutBattle 
    Wait 
    UpdateVar OPCODE_FLAG_ON, BTLVAR_RESULT_MASK, BATTLE_RESULT_PLAYER_FLED
    End 

_074:
    UpdateVar OPCODE_FLAG_ON, BTLVAR_MOVE_STATUS_FLAGS, MOVE_STATUS_FAILED
    End 

_079:
    // {0} anchors itself with {1}!
    BufferMessage pl_msg_00000368_00659, TAG_NICKNAME_ABILITY, BTLSCR_DEFENDER, BTLSCR_DEFENDER
    GoTo _090

_086:
    // {0} anchored itself with its roots!
    BufferMessage pl_msg_00000368_00542, TAG_NICKNAME, BTLSCR_DEFENDER

_090:
    PrintAttackMessage 
    Wait 
    WaitButtonABTime 30
    PrintBufferedMessage 
    Wait 
    WaitButtonABTime 30
    UpdateVar OPCODE_FLAG_ON, BTLVAR_MOVE_STATUS_FLAGS, MOVE_STATUS_NO_MORE_WORK
    End 
