    .include "macros/btlcmd.inc"

    .data

_000:
    CompareVarToValue OPCODE_FLAG_SET, BTLVAR_MOVE_STATUS_FLAGS, MOVE_STATUS_MISSED|MOVE_STATUS_SEMI_INVULNERABLE, _018
    TrySpite _018
    Call BATTLE_SUBSCRIPT_ATTACK_MESSAGE_AND_ANIMATION
    // It reduced the PP of {0}’s {1} by {2}!
    PrintMessage pl_msg_00000368_00398, TAG_NICKNAME_MOVE_NUMBER, BTLSCR_DEFENDER, BTLSCR_MSG_TEMP, BTLSCR_MSG_TEMP
    Wait 
    WaitButtonABTime 30
    End 

_018:
    UpdateVar OPCODE_FLAG_ON, BTLVAR_MOVE_STATUS_FLAGS, MOVE_STATUS_FAILED
    End 
