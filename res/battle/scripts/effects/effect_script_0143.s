    .include "macros/btlcmd.inc"

    .data

_000:
    CopyStatStages 
    // {0} copied {1}’s stat changes!
    BufferMessage pl_msg_00000368_00452, TAG_NICKNAME_NICKNAME, BTLSCR_ATTACKER, BTLSCR_DEFENDER
    UpdateVar OPCODE_SET, BTLVAR_SIDE_EFFECT_FLAGS_INDIRECT, MOVE_SIDE_EFFECT_ON_HIT|MOVE_SUBSCRIPT_PTR_PRINT_MESSAGE_AND_PLAY_ANIMATION
    End 
