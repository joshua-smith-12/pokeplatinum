    .include "macros/btlcmd.inc"

    .data

_000:
    TryHelpingHand _015
    // {0} is ready to help {1}!
    BufferMessage pl_msg_00000368_00503, TAG_NICKNAME_NICKNAME, BTLSCR_ATTACKER, BTLSCR_MSG_TEMP
    UpdateVar OPCODE_SET, BTLVAR_SIDE_EFFECT_FLAGS_INDIRECT, MOVE_SIDE_EFFECT_ON_HIT|MOVE_SUBSCRIPT_PTR_PRINT_MESSAGE_AND_PLAY_ANIMATION
    UpdateVar OPCODE_FLAG_ON, BTLVAR_BATTLE_CTX_STATUS, SYSCTL_HIT_DURING_FLY|SYSCTL_HIT_DURING_DIG|SYSCTL_HIT_DURING_DIVE|SYSCTL_HIT_DURING_SHADOW_FORCE
    End 

_015:
    UpdateVar OPCODE_FLAG_ON, BTLVAR_MOVE_STATUS_FLAGS, MOVE_STATUS_FAILED
    End 
