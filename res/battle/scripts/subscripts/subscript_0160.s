    .include "macros/btlcmd.inc"

    .data

_000:
    CompareVarToValue OPCODE_FLAG_SET, BTLVAR_SIDE_CONDITIONS_ATTACKER, SIDE_CONDITION_TAILWIND, _018
    Call BATTLE_SUBSCRIPT_ATTACK_MESSAGE_AND_ANIMATION
    // The tailwind blew from behind your team!
    PrintMessage pl_msg_00000368_01230, TAG_NONE_SIDE_CONSCIOUS, BTLSCR_ATTACKER
    Wait 
    WaitButtonABTime 30
    UpdateVar OPCODE_FLAG_ON, BTLVAR_SIDE_CONDITIONS_ATTACKER, SIDE_CONDITION_TAILWIND
    End 

_018:
    UpdateVar OPCODE_FLAG_ON, BTLVAR_MOVE_STATUS_FLAGS, MOVE_STATUS_FAILED
    End 
