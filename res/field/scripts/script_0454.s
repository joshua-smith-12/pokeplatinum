    .include "macros/scrcmd.inc"

    .data

    .long _001A-.-4
    .long _004D-.-4
    .long _006A-.-4
    .long _0087-.-4
    .long _048A-.-4
    .long _04C8-.-4
    .short 0xFD13

_001A:
    ScrCmd_01E 0x9EB
    ScrCmd_01E 0x257
    ScrCmd_01E 0x258
    ScrCmd_020 0xAB6
    ScrCmd_01C 0, _0033
    ScrCmd_002

_0033:
    ScrCmd_1B7 0x404C, 5
    ScrCmd_026 0x404C, 5
    ScrCmd_01E 0xAB6
    ScrCmd_024 0x37C
    ScrCmd_024 0x37D
    ScrCmd_002

_004D:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 0
    ScrCmd_031
    ScrCmd_034
    ScrCmd_05E 0, _04A8
    ScrCmd_05F
    ScrCmd_061
    ScrCmd_002

_006A:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 1
    ScrCmd_031
    ScrCmd_034
    ScrCmd_05E 1, _04B0
    ScrCmd_05F
    ScrCmd_061
    ScrCmd_002

_0087:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_025 0x37C
    ScrCmd_01C 1, _0396
    ScrCmd_025 0x37D
    ScrCmd_01C 1, _0396
    ScrCmd_1BD 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _00CB
    ScrCmd_011 0x800C, 1
    ScrCmd_01C 1, _00E5
    ScrCmd_016 _00FF
    ScrCmd_002

_00CB:
    ScrCmd_05E 2, _03EC
    ScrCmd_05E 0xFF, _042C
    ScrCmd_05F
    ScrCmd_016 _00FF
    ScrCmd_002

_00E5:
    ScrCmd_05E 2, _03F4
    ScrCmd_05E 0xFF, _043C
    ScrCmd_05F
    ScrCmd_016 _00FF
    ScrCmd_002

_00FF:
    ScrCmd_020 0x166
    ScrCmd_01D 0, _045A
    ScrCmd_020 0x166
    ScrCmd_01D 1, _0467
    ScrCmd_01E 0x166
    ScrCmd_03E 0x800C
    ScrCmd_011 0x800C, 1
    ScrCmd_01C 1, _0471
    ScrCmd_023 0x37C
    ScrCmd_023 0x37D
    ScrCmd_02C 5
    ScrCmd_034
    ScrCmd_05E 2, _03FC
    ScrCmd_05F
    ScrCmd_028 0x404D, 0
    ScrCmd_028 0x8005, 0
    ScrCmd_01F 0x257
    ScrCmd_064 5
    ScrCmd_05E 5, _0420
    ScrCmd_05F
    ScrCmd_02C 15
    ScrCmd_034
    ScrCmd_0E5 0x381, 0
    ScrCmd_0EC 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0484
    ScrCmd_026 0x8005, 0x404D
    ScrCmd_02C 16
    ScrCmd_034
    ScrCmd_05E 5, _0414
    ScrCmd_05F
    ScrCmd_05E 5, _0420
    ScrCmd_05F
    ScrCmd_02C 17
    ScrCmd_034
    ScrCmd_0E5 0x382, 0
    ScrCmd_0EC 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0484
    ScrCmd_026 0x8005, 0x404D
    ScrCmd_02C 18
    ScrCmd_034
    ScrCmd_05E 5, _0414
    ScrCmd_05F
    ScrCmd_05E 5, _0420
    ScrCmd_05F
    ScrCmd_02C 19
    ScrCmd_034
    ScrCmd_0E5 0x383, 0
    ScrCmd_0EC 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0484
    ScrCmd_026 0x8005, 0x404D
    ScrCmd_02C 20
    ScrCmd_034
    ScrCmd_05E 5, _0414
    ScrCmd_05F
    ScrCmd_05E 5, _0420
    ScrCmd_05F
    ScrCmd_02C 21
    ScrCmd_034
    ScrCmd_0E5 0x384, 0
    ScrCmd_0EC 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0484
    ScrCmd_026 0x8005, 0x404D
    ScrCmd_02C 22
    ScrCmd_034
    ScrCmd_05E 5, _0414
    ScrCmd_05F
    ScrCmd_05E 2, _0408
    ScrCmd_05F
    ScrCmd_0D5 0, 0x404C
    ScrCmd_0D5 1, 0x8005
    ScrCmd_02C 6
    ScrCmd_034
    ScrCmd_05E 2, _03FC
    ScrCmd_05F
    ScrCmd_05E 5, _0420
    ScrCmd_05F
    ScrCmd_02C 23
    ScrCmd_034
    ScrCmd_0E5 0x385, 0
    ScrCmd_0EC 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0484
    ScrCmd_026 0x8005, 0x404D
    ScrCmd_02C 24
    ScrCmd_034
    ScrCmd_05E 5, _0414
    ScrCmd_05F
    ScrCmd_065 5
    ScrCmd_05E 2, _0408
    ScrCmd_05F
    ScrCmd_0D5 0, 0x404C
    ScrCmd_0D5 1, 0x8005
    ScrCmd_02C 7
    ScrCmd_012 0x8005, 0x404C
    ScrCmd_01C 5, _044C
    ScrCmd_1B7 0x8006, 2
    ScrCmd_011 0x8006, 0
    ScrCmd_01D 1, _03A1
    ScrCmd_011 0x8006, 1
    ScrCmd_01D 1, _03B7
    ScrCmd_034
    ScrCmd_05E 2, _03FC
    ScrCmd_05F
    ScrCmd_01F 0x258
    ScrCmd_064 4
    ScrCmd_05E 4, _0420
    ScrCmd_05F
    ScrCmd_011 0x8006, 0
    ScrCmd_01D 1, _03CD
    ScrCmd_011 0x8006, 1
    ScrCmd_01D 1, _03D2
    ScrCmd_034
    ScrCmd_0E5 0x8007, 0
    ScrCmd_0EC 0x800C
    ScrCmd_011 0x800C, 0
    ScrCmd_01C 1, _0484
    ScrCmd_023 0x37C
    ScrCmd_023 0x37D
    ScrCmd_011 0x8006, 0
    ScrCmd_01D 1, _03D7
    ScrCmd_011 0x8006, 1
    ScrCmd_01D 1, _03DC
    ScrCmd_034
    ScrCmd_05E 4, _0414
    ScrCmd_05F
    ScrCmd_065 4
    ScrCmd_05E 2, _0408
    ScrCmd_05F
    ScrCmd_011 0x8006, 0
    ScrCmd_01D 1, _03E1
    ScrCmd_011 0x8006, 1
    ScrCmd_01D 1, _03E6
    ScrCmd_016 _0396
    ScrCmd_002

_0396:
    ScrCmd_02C 13
    ScrCmd_016 _047C
    ScrCmd_002

_03A1:
    ScrCmd_028 0x8007, 0x37C
    ScrCmd_028 0x4020, 62
    ScrCmd_2F3 2, 0x8007
    ScrCmd_02C 8
    ScrCmd_01B

_03B7:
    ScrCmd_028 0x8007, 0x37D
    ScrCmd_028 0x4020, 63
    ScrCmd_2F3 2, 0x8007
    ScrCmd_02C 9
    ScrCmd_01B

_03CD:
    ScrCmd_02C 25
    ScrCmd_01B

_03D2:
    ScrCmd_02C 27
    ScrCmd_01B

_03D7:
    ScrCmd_02C 26
    ScrCmd_01B

_03DC:
    ScrCmd_02C 28
    ScrCmd_01B

_03E1:
    ScrCmd_02C 10
    ScrCmd_01B

_03E6:
    ScrCmd_02C 11
    ScrCmd_01B

    .balign 4, 0
_03EC:
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_03F4:
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_03FC:
    .short 12, 1
    .short 33, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0408:
    .short 13, 1
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0414:
    .short 34, 1
    .short 69, 1
    .short 0xFE, 0x00

    .balign 4, 0
_0420:
    .short 70, 1
    .short 35, 1
    .short 0xFE, 0x00

    .balign 4, 0
_042C:
    .short 15, 1
    .short 12, 1
    .short 34, 1
    .short 0xFE, 0x00

    .balign 4, 0
_043C:
    .short 15, 1
    .short 13, 1
    .short 34, 1
    .short 0xFE, 0x00

_044C:
    ScrCmd_02C 12
    ScrCmd_02C 13
    ScrCmd_016 _047C
    ScrCmd_002

_045A:
    ScrCmd_02C 2
    ScrCmd_0D5 0, 0x404C
    ScrCmd_02C 3
    ScrCmd_01B

_0467:
    ScrCmd_0D5 0, 0x404C
    ScrCmd_02C 3
    ScrCmd_01B

_0471:
    ScrCmd_02C 4
    ScrCmd_016 _047C
    ScrCmd_002

_047C:
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

_0484:
    ScrCmd_0EB
    ScrCmd_061
    ScrCmd_002

_048A:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 14
    ScrCmd_031
    ScrCmd_034
    ScrCmd_05E 3, _04C0
    ScrCmd_05F
    ScrCmd_061
    ScrCmd_002

    .balign 4, 0
_04A8:
    .short 1, 1
    .short 0xFE, 0x00

    .balign 4, 0
_04B0:
    .short 1, 1
    .short 0xFE, 0x00

    .byte 3
    .byte 0
    .byte 1
    .byte 0
    .byte 254
    .byte 0
    .byte 0
    .byte 0

    .balign 4, 0
_04C0:
    .short 2, 1
    .short 0xFE, 0x00

_04C8:
    ScrCmd_049 0x5DC
    ScrCmd_060
    ScrCmd_068
    ScrCmd_02C 29
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    ScrCmd_002

    .byte 0