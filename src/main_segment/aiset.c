/**
 * Original filename: aiset.c
 *
 * List of known original function names:
 * - aifMakeBlkWork
 * - aifMakeFlagSet
 * - aifGameInit
 * - aifFirstInit
 * - aifMake
 * - aifMake2
 * - aiHiruSideLineEraser
 * - aifEraseLineCore
 * - aifRensaCheckCore
 * - aifRensaCheck
 * - aifSearchLineCore
 * - aifMiniPointK3
 * - aifMiniAloneCapNumber
 * - aifMiniAloneCapNumberW
 * - flash_virus
 * - search_Vflash
 * - aifSearchLineMS
 * - aiHiruAllPriSet
 * - aiSetCharacter
 * - aifFieldCopy
 * - aifPlaceSearch
 * - aifMoveCheck
 * - aifTRecur
 * - aifTRecurUP
 * - aifYRecur
 * - aifYRecurUP
 * - aifReMoveCheck
 * - aifKeyMake
 * - aifKeyOut
 * - search_flash_3
 * - flash_special
 * - aiCOM_MissTake
 */

#include "aif.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "boot_functions.h"
#include "boot_variables.h"
#include "main_segment_functions.h"
#include "main_segment_variables.h"
#include "gamemap.h"

// no original name :c
void func_8002EB00(struct_game_state_data *gameStateDataRef) {
    gameStateDataRef->unk_3BC = gameStateDataRef->unk_178.unk_0;
    gameStateDataRef->unk_3BD = gameStateDataRef->unk_178.unk_2;
    gameStateDataRef->unk_3C1[0] = (s8)gameStateDataRef->unk_02F;
    gameStateDataRef->unk_3C0 = gameStateDataRef->unk_02D;
    gameStateDataRef->unk_3BE[0] = (s8)(u8)gameStateDataRef->unk_178.unk_6;
    gameStateDataRef->unk_3BE[1] = (s8)(u8)gameStateDataRef->unk_178.unk_7;
    gameStateDataRef->unk_299[2] = (s8)gameStateDataRef->unk_025;
    gameStateDataRef->unk_299[1] = (s8)gameStateDataRef->unk_026;
    gameStateDataRef->unk_299[0] = gameStateDataRef->unk_014 == 0x12;
    gameStateDataRef->unk_298 = gameStateDataRef->unk_04B;

    if (gameStateDataRef->unk_298 == 0) {
        game_state_data[0].unk_04E = game_state_data[1].unk_04E;
    }
}

/**
 * Original name: aifMakeBlkWork
 */
void aifMakeBlkWork(struct_game_state_data *gameStateDataRef) {
    s32 column;
    s32 row;

    for (column = 0; column < GAME_MAP_COLUMNS; column++) {
        gameStateDataRef->unk_29C[0][column][0] = 10;
        gameStateDataRef->unk_29C[0][column][1] = 3;
    }

    for (row = 1; row < GAME_MAP_ROWS; row++) {
        for (column = 0; column < GAME_MAP_COLUMNS; column++) {
            s32 index = GAME_MAP_GET_INDEX(row - 1, column);

            if (game_map_data[gameStateDataRef->unk_298].cells[index].unk_4[0] != 0) {
                gameStateDataRef->unk_29C[row][column][0] =
                    capsGCnv_122[game_map_data[gameStateDataRef->unk_298].cells[index].unk_2];
                gameStateDataRef->unk_29C[row][column][1] =
                    capsCCnv_123[game_map_data[gameStateDataRef->unk_298].cells[index].unk_3];
            } else {
                gameStateDataRef->unk_29C[row][column][0] = 10;
                gameStateDataRef->unk_29C[row][column][1] = 3;
            }
        }
    }

    if (gameStateDataRef->unk_178.unk_2 != 0) {
        gameStateDataRef->unk_29C[gameStateDataRef->unk_178.unk_2 - 1][gameStateDataRef->unk_178.unk_0][0] = 10;
        gameStateDataRef->unk_29C[gameStateDataRef->unk_178.unk_2 - 1][gameStateDataRef->unk_178.unk_0][1] = 3;
        gameStateDataRef->unk_29C[gameStateDataRef->unk_178.unk_3 - 1][gameStateDataRef->unk_178.unk_1][0] = 10;
        gameStateDataRef->unk_29C[gameStateDataRef->unk_178.unk_3 - 1][gameStateDataRef->unk_178.unk_1][1] = 3;
    }
}

/**
 * Original name: aifMakeFlagSet
 */
void aifMakeFlagSet(struct_game_state_data *gameStateDataRef) {
    gameStateDataRef->unk_23D = 0;
    gameStateDataRef->unk_241 = 0;
    gameStateDataRef->unk_237 = 0;
    gameStateDataRef->unk_238 = 0;
    gameStateDataRef->unk_239 = 0;
}

/**
 * Original name: aifGameInit
 */

void aifGameInit(void) {
    s32 i;

    fool_mode = 0;
    s_hard_mode = 0;
    MissRate = 0;
    PlayTime = 0;
    for (i = 0; i < ARRAY_COUNT(game_state_data); i++) {
        s32 j;

        game_state_data[i].unk_23D = 1;
        game_state_data[i].unk_23E = 1;
        game_state_data[i].unk_292 = 0;
        game_state_data[i].unk_294 = 0x64;

        for (j = 0; j < 0x10; j++) {
            game_state_data[i].unk_242[j] = 0;
            game_state_data[i].unk_272[j] = 0;
        }
    }
}

#if VERSION_US
/**
 * Original name: aifFirstInit
 */
#if 0
typedef struct struct_800F48D0 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x1C0];
} struct_800F48D0; // size = 0x1C0

typedef struct struct_80088660 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x1C0];
} struct_80088660; // size = 0x1C0

typedef struct struct_800890E0_unk_00 {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x00 */ UNK_TYPE4 unk_04;
    /* 0x00 */ UNK_TYPE4 unk_08;
    /* 0x00 */ UNK_TYPE4 unk_0C;
} struct_800890E0_unk_00; // size = 0x10

typedef struct struct_800E9BC0 {
    /* 0x00 */ struct_800890E0_unk_00 unk_00[6];
    /* 0x60 */ UNK_TYPE1 unk_00[0xC];
} struct_800E9BC0; // size = 0x6C

typedef struct struct_800890E0 {
    /* 0x00 */ struct_800890E0_unk_00 unk_00[6];
    /* 0x60 */ UNK_TYPE1 unk_00[0xC];
} struct_800890E0; // size = 0x6C

//s32 func_8002ED2C(?, s32, ? *, ? *);                /* extern */
extern struct_800E9BC0 B_800E9BC0[];
extern struct_800F48D0 B_800F48D0[];
extern struct_80088660 D_80088660[];
extern struct_800890E0 D_800890E0[];

void aifFirstInit(void) {
    struct_800890E0_unk_00 *var_a2;
    struct_800890E0_unk_00 *var_a3;
    struct_800890E0 *var_t0;
    struct_800F48D0 *var_t1;
    struct_80088660 *var_t2;
    struct_800E9BC0 *var_t2_2;
    ? temp_a0;
    s32 var_a1;
    s32 var_t3;
    s32 var_t5;
    s32 var_t5_2;
    s32 var_t6;
    void *temp_t0;
    void *var_a2_2;
    void *var_a3_2;

    var_t5 = 0;
    var_t6 = 0;
    do {
        var_t3 = 0;
        var_t2 = &D_80088660;
        var_t1 = &B_800F48D0;
loop_2:
        var_a3_2 = var_t6 + var_t1;
        var_a2_2 = var_t6 + var_t2;
        temp_t0 = var_a2_2 + 0x30;
        if (((s32) var_a2_2 | (s32) var_a3_2) & 3) {
            do {
                var_a3_2->unk_0 = (unaligned s32) var_a2_2->unk_0;
                var_a3_2->unk_4 = (unaligned s32) var_a2_2->unk_4;
                var_a3_2->unk_8 = (unaligned s32) var_a2_2->unk_8;
                var_a3_2->unk_C = (unaligned s32) var_a2_2->unk_C;
                var_a2_2 += 0x10;
                var_a3_2 += 0x10;
            } while (var_a2_2 != temp_t0);
        } else {
            do {
                var_a3_2->unk_0 = (s32) var_a2_2->unk_0;
                var_a3_2->unk_4 = (s32) var_a2_2->unk_4;
                var_a3_2->unk_8 = (s32) var_a2_2->unk_8;
                var_a3_2->unk_C = (s32) var_a2_2->unk_C;
                var_a2_2 += 0x10;
                var_a3_2 += 0x10;
            } while (var_a2_2 != temp_t0);
        }
        var_a3_2->unk_0 = (unaligned s32) var_a2_2->unk_0;
        var_a3_2->unk_4 = (unaligned s32) var_a2_2->unk_4;
        var_t2 += 0x1C0;
        var_t3 += 1;
        var_t1 += 0x1C0;
        if (var_t3 < 6) {
            goto loop_2;
        }
        var_t5 += 1;
        var_t6 += 0x38;
    } while (var_t5 < 8);

    var_t5_2 = 0;
    var_t0 = &D_800890E0;
    var_t2_2 = &B_800E9BC0;
    do {
        var_a3 = var_t2_2;
        var_a2 = var_t0;
        if (((s32) var_t0 | (s32) var_t2_2) & 3) {
            do {
                //var_a1 = (unaligned s32) var_a2->unk_C;
                //var_a3->unk_0 = (unaligned s32) var_a2->unk_0;
                //var_a3->unk_4 = (unaligned s32) var_a2->unk_4;
                //var_a3->unk_8 = (unaligned s32) var_a2->unk_8;
                var_a1 = var_a2->unk_0C;
                var_a3->unk_00 = var_a2->unk_00;
                var_a3->unk_04 = var_a2->unk_04;
                var_a3->unk_08 = var_a2->unk_08;
                var_a3->unk_0C = var_a1;
                var_a2 += 0x10;
                var_a3 += 0x10;
            } while (var_a2 != (var_t0 + 0x60));
        } else {
            do {
                var_a1 = var_a2->unk_0C;
                var_a3->unk_00 = (s32) var_a2->unk_00;
                var_a3->unk_04 = (s32) var_a2->unk_04;
                var_a3->unk_08 = (s32) var_a2->unk_08;
                var_a3->unk_0C = var_a1;
                var_a2 += 0x10;
                var_a3 += 0x10;
            } while (var_a2 != (var_t0 + 0x60));
        }
        temp_a0 = (unaligned s32) var_a2->unk_8;
        var_a3->unk_0 = (unaligned s32) var_a2->unk_0;
        var_a3->unk_4 = (unaligned s32) var_a2->unk_4;
        var_a3->unk_8 = temp_a0;
        var_t0 += 0x6C;
        var_t5_2 += 1;
        var_t2_2 += 0x6C;
    } while (var_t5_2 < 0x10);
    return aifGameInit(temp_a0, var_a1, var_a2, var_a3);
}
#else
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifFirstInit);
#endif
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", aifFirstInit);
#endif

/**
 * Original name: aifMake
 */
#if VERSION_US
void aifMake(struct_game_state_data *gameStateDataRef) {
    pGameState = gameStateDataRef;

    if (gameStateDataRef->unk_23D == 0) {
        func_8002EB00(gameStateDataRef);
        aifMakeBlkWork(gameStateDataRef);

        aiGoalX = gameStateDataRef->unk_3BC + 1;

        aiGoalY = gameStateDataRef->unk_3BD;
        if (aiGoalY == 0) {
            aiGoalY++;
        }

        aipn = gameStateDataRef->unk_298;
        gameStateDataRef->unk_23C = gameStateDataRef->unk_04E;
        if (FallSpeed[gameStateDataRef->unk_3C0] > aiSlideFSpeed[aiSelSpeed][gameStateDataRef->unk_23C]) {
            aiMoveSF = 1;
        } else {
            aiMoveSF = 0;
        }

        aifFieldCopy(gameStateDataRef);
        aifPlaceSearch();
        aifMoveCheck();
        delpos_cnt = 0;

        if (evs_gamemode == ENUM_EVS_GAMEMODE_1) {
            s32 var_v1;

            flash_special();
            last_flash = 0;

            for (var_v1 = 0; var_v1 < pGameState->unk_164; var_v1++) {
                if (pGameState->unk_0D4.unk_00[var_v1].unk_8 >= 0) {
                    last_flash++;
                }
            }
        }

        aiSetCharacter(gameStateDataRef);
        aiHiruAllPriSet(gameStateDataRef);
        aiHiruSideLineEraser(gameStateDataRef);
        aifReMoveCheck();
        aifKeyMake(gameStateDataRef);
        gameStateDataRef->unk_234 = 0;
        gameStateDataRef->unk_23D = 1;
    }
}
#endif

#if VERSION_US
/**
 * Original name: aifMake2
 */
bool aifMake2(struct_game_state_data *gameStateDataRef, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 temp_v1;

    if (gameStateDataRef->unk_23D != 0) {
        return false;
    }

    func_8002EB00(gameStateDataRef);
    aifMakeBlkWork(gameStateDataRef);

    MissRate = 0;
    aiGoalX = gameStateDataRef->unk_3BC + 1;

    aiGoalY = gameStateDataRef->unk_3BD;
    if (aiGoalY == 0) {
        aiGoalY++;
    }

    aipn = gameStateDataRef->unk_298;
    temp_v1 = gameStateDataRef->unk_04E;
    gameStateDataRef->unk_23C = temp_v1;

    if (FallSpeed[gameStateDataRef->unk_3C0] > aiSlideFSpeed[aiSelSpeed][temp_v1]) {
        aiMoveSF = 1;
    } else {
        aiMoveSF = 0;
    }

    aifFieldCopy(gameStateDataRef);
    aiFlag[1] = arg3 == 0;
    aiFlag[2] = arg1 + 1;
    aiFlag[3] = arg2;
    aiFlag[4] = arg4 != 0;

    aiFlagCnt = 1;
    decide = 0;
    aifReMoveCheck();
    aifKeyMake(gameStateDataRef);
    gameStateDataRef->unk_234 = 0;
    gameStateDataRef->unk_23D = 1;

    return true;
}
#endif

#if VERSION_US
/**
 * Original name: aiHiruSideLineEraser
 */
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aiHiruSideLineEraser);
#endif

#if VERSION_US
// no original name :c
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", func_8002F924);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifEraseLineCore);
#endif

#if VERSION_US
/**
 * Original name: aifRensaCheckCore
 */
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifRensaCheckCore);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifRensaCheck);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifSearchLineCore);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifMiniPointK3);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifMiniAloneCapNumber);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifMiniAloneCapNumberW);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", flash_virus);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", search_Vflash);
#endif

#if VERSION_US
// no original name :c
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", func_8003151C);
#endif

#if VERSION_US
/**
 * Original name: aifSearchLineMS
 */
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifSearchLineMS);
#endif

#if VERSION_US
/**
 * Original name: aiHiruAllPriSet
 */
#if 0
u8 aifRensaCheckCore(struct_game_state_data *, u8 *, u32, u8, s32, s32, u32, s32, s32, s32); /* extern */
s32 aifSearchLineMS(u8 *, s32, u8, s32);              /* extern */
extern u16 aiHiErB;
extern u16 B_800F3E32;
extern u16 aiHiErY;
extern u16 aiHiErR;
extern u16 aiHiEraseCtr;
extern s16 D_8008856A;
extern s16 D_800885D2;
extern s16 D_800885D4;

void aiHiruAllPriSet(struct_game_state_data *gameStateDataRef) {
    struct_game_state_data *sp2C;
    s32 sp34;
    u8 sp3F;
    s8 sp47;                                        /* compiler-managed */
    u8 sp4F;
    u8 sp57;
    u8 sp5F;
    u8 sp67;
    u8 sp6F;
    s32 sp8C;
    s32 sp90;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_fp;
    s32 temp_s0;
    s32 temp_s0_11;
    s32 temp_s0_13;
    s32 temp_s0_14;
    s32 temp_s0_3;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s0_8;
    s32 temp_s0_9;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s2_3;
    s32 temp_s4;
    s32 temp_s5_2;
    s32 temp_s5_3;
    s32 temp_t4;
    s32 temp_t4_3;
    s32 temp_t4_4;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a2_2;
    s32 var_a3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s4;
    s32 var_s4_2;
    s32 var_s5;
    s32 var_t1_2;
    s32 var_v0;
    s8 temp_a0_2;
    s8 var_t1;
    u32 temp_s1_2;
    u32 temp_s1_3;
    u32 temp_s1_4;
    u32 temp_s1_5;
    u32 temp_s1_6;
    u32 temp_s1_7;
    u32 temp_s2_4;
    u32 temp_s5;
    u32 temp_s6;
    u8 *temp_s3;
    u8 temp_a0;
    u8 temp_s0_10;
    u8 temp_s0_12;
    u8 temp_s0_2;
    u8 temp_s0_4;
    u8 temp_s0_7;
    u8 temp_t4_2;
    u8 var_a2;
    u8 var_s1;
    u8 var_v1;

    sp2C = gameStateDataRef;
    sp34 = 0;
    if ((s32) aiFlagCnt > 0) {
        sp8C = 0;
        do {
            if (aiFlag[sp8C].unk_0 != 0) {
                temp_s3 = &aiFlag[sp8C];
                bcopy(aiFieldData, &aif_field, 0x110);
                var_a2 = temp_s3->unk_3;
                temp_a0 = temp_s3->unk_2;
                temp_s4 = temp_a0 - 1;
                if (temp_s3->unk_1 == 0) {
                    var_s5 = temp_s4;
                    var_s2 = var_s5;
                    temp_a0_2 = var_a2 - 1;
                    sp3F = var_a2;
                    sp47 = temp_a0_2;
                    sp57 &= -(temp_a0_2 < 1);
                    if (temp_s3->unk_4 == 0) {
                        var_s1 = aiNext[1];
                        if (temp_a0_2 > 0) {
                            sp4F = *aiNext;
                        }
                    } else {
                        var_s1 = *aiNext;
                        if (temp_a0_2 > 0) {
                            sp4F = aiNext[1];
                        }
                    }
                    if (sp3F != 0) {
                        temp_v0 = ((var_s5 & 0xFF) * 2) + (sp3F * 0x10);
                        *(&B_800FAD41 + temp_v0) = 1;
                        *(&aif_field + temp_v0) = var_s1;
                    }
                    if ((u8) sp47 != 0) {
                        temp_v0_2 = ((var_s2 & 0xFF) * 2) + ((u8) sp47 * 0x10);
                        *(&B_800FAD41 + temp_v0_2) = sp57;
                        *(&aif_field + temp_v0_2) = sp4F;
                    }
                    temp_a0_3 = temp_s4 * 2;
                    if (*(&aif_field + (temp_a0_3 + ((var_a2 - 1) * 0x10))) == *(&aif_field + (temp_a0_3 + (var_a2 * 0x10)))) {

                    }
                    var_a1 = temp_s4;
                    var_a3 = var_s1 & 0xFF;
                    sp90 = (s32) 1;
                } else {
                    var_s5 = temp_s4;
                    if (*(&B_800FAD41 + ((temp_s4 * 2) + ((var_a2 + 1) * 0x10))) != 0xA) {
                        sp3F = var_a2;
                        var_t1 = 2;
                        var_s2 = (s32) temp_a0;
                        sp47 = sp3F;
                        sp57 = 3;
                        if (temp_s3->unk_4 == 0) {
                            var_s1 = *aiNext;
                            sp4F = aiNext[1];
                        } else {
                            var_s1 = aiNext[1];
                            sp4F = *aiNext;
                        }
                    } else {
                        var_s5 = (s32) temp_a0;
                        sp3F = var_a2;
                        var_t1 = 3;
                        var_s2 = temp_s4;
                        sp47 = sp3F;
                        sp57 = 2;
                        if (temp_s3->unk_4 == 0) {
                            var_s1 = aiNext[1];
                            sp4F = *aiNext;
                        } else {
                            var_s1 = *aiNext;
                            sp4F = aiNext[1];
                        }
                    }
                    var_a3 = var_s1 & 0xFF;
                    if (var_a3 == sp4F) {

                    }
                    var_a2 = sp3F;
                    if (var_a2 != 0) {
                        temp_v0_3 = ((var_s5 & 0xFF) * 2) + (var_a2 * 0x10);
                        *(&B_800FAD41 + temp_v0_3) = var_t1;
                        *(&aif_field + temp_v0_3) = var_s1;
                    }
                    if (sp47 != 0) {
                        temp_v0_4 = ((var_s2 & 0xFF) * 2) + (sp47 * 0x10);
                        *(&B_800FAD41 + temp_v0_4) = sp57;
                        *(&aif_field + temp_v0_4) = sp4F;
                    }
                    var_a1 = var_s5 & 0xFF;
                    sp90 = (s32) var_t1;
                }
                temp_v0_5 = aifSearchLineMS(temp_s3, var_a1, var_a2, var_a3);
                var_t1_2 = sp90;
                if ((temp_v0_5 != 0) && (D_800885D2 != 0)) {
                    if (temp_v0_5 == 2) {
                        temp_s0 = var_s5;
                        var_s5 = var_s2;
                        var_s2 = temp_s0;
                        temp_t4_2 = sp47;
                        sp47 = sp3F;
                        temp_s0_2 = var_s1;
                        var_s1 = sp4F;
                        sp4F = temp_s0_2;
                        temp_s0_3 = var_t1_2;
                        var_t1_2 = (s32) sp57;
                        sp3F = temp_t4_2;
                        sp57 = (u8) temp_s0_3;
                    }
                    temp_s6 = var_s5 & 0xFF;
                    temp_fp = var_s1 & 0xFF;
                    temp_s1 = var_t1_2 & 0xFF;
                    temp_s5 = var_s2 & 0xFF;
                    sp5F = aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, temp_s1, temp_s5, (s32) sp47, 0, (s32) sp57);
                    aiHiErR = aiHiEraseCtr;
                    sp67 = aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, temp_s1, temp_s5, (s32) sp47, 1, (s32) sp57);
                    aiHiErY = aiHiEraseCtr;
                    sp6F = aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, temp_s1, temp_s5, (s32) sp47, 2, (s32) sp57);
                    aiHiErB = aiHiEraseCtr;
                    var_s0 = 0;
                    if (temp_s6 == temp_s5) {
                        temp_s2 = var_s2 - 1;
                        if (sp47 < sp3F) {
                            temp_s1_2 = temp_s2 & 0xFF;
                            sp47 += 1;
                            temp_s5_2 = (u8) sp47 * 0x10;
                            if (sp2C->unk_29C[0][0][(temp_s1_2 * 2) + temp_s5_2] == 0xA) {
                                temp_s0_4 = aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 3, temp_s1_2, (s32) (u8) sp47, 0, 2);
                                temp_s0_5 = temp_s0_4 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 3, temp_s1_2, (s32) (u8) sp47, 1, 2);
                                var_s0 = temp_s0_5 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 3, temp_s1_2, (s32) (u8) sp47, 2, 2);
                            }
                            temp_s1_3 = (temp_s2 + 2) & 0xFF;
                            sp57 = 3;
                            if (sp2C->unk_29C[0][0][(temp_s1_3 * 2) + temp_s5_2] == 0xA) {
                                temp_s0_6 = var_s0 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 2, temp_s1_3, (s32) (u8) sp47, 0, 3);
                                var_s0_2 = temp_s0_6 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 2, temp_s1_3, (s32) (u8) sp47, 1, 3);
                                goto block_53;
                            }
                        } else {
                            temp_s1_4 = temp_s2 & 0xFF;
                            sp47 = (u8) sp47 - 1;
                            temp_s5_3 = (u8) sp47 * 0x10;
                            if (sp2C->unk_29C[0][0][(temp_s1_4 * 2) + temp_s5_3] == 0xA) {
                                temp_s0_7 = aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 3, temp_s1_4, (s32) (u8) sp47, 0, 2);
                                temp_s0_8 = temp_s0_7 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 3, temp_s1_4, (s32) (u8) sp47, 1, 2);
                                var_s0 = temp_s0_8 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 3, temp_s1_4, (s32) (u8) sp47, 2, 2);
                            }
                            temp_s1_5 = (temp_s2 + 2) & 0xFF;
                            sp57 = 3;
                            if (sp2C->unk_29C[0][0][(temp_s1_5 * 2) + temp_s5_3] == 0xA) {
                                temp_s0_9 = var_s0 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 2, temp_s1_5, (s32) (u8) sp47, 0, 3);
                                var_s0_2 = temp_s0_9 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 2, temp_s1_5, (s32) (u8) sp47, 1, 3);
                                goto block_53;
                            }
                        }
                    } else {
                        temp_v1 = sp47 * 0x10;
                        if (temp_s5 < temp_s6) {
                            temp_s2_2 = var_s2 + 2;
                            temp_s1_6 = temp_s2_2 & 0xFF;
                            if (sp2C->unk_29C[0][0][(temp_s1_6 * 2) + temp_v1] == 0xA) {
                                temp_s0_10 = aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 2, temp_s1_6, (s32) sp47, 0, 3);
                                temp_s0_11 = temp_s0_10 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 2, temp_s1_6, (s32) sp47, 1, 3);
                                var_s0 = temp_s0_11 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 2, temp_s1_6, (s32) sp47, 2, 3);
                            }
                            var_s2_2 = temp_s2_2 - 1;
                        } else {
                            temp_s2_3 = var_s2 - 2;
                            temp_s1_7 = temp_s2_3 & 0xFF;
                            if (sp2C->unk_29C[0][0][(temp_s1_7 * 2) + temp_v1] == 0xA) {
                                temp_s0_12 = aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 3, temp_s1_7, (s32) sp47, 0, 2);
                                temp_s0_13 = temp_s0_12 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 3, temp_s1_7, (s32) sp47, 1, 2);
                                var_s0 = temp_s0_13 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 3, temp_s1_7, (s32) sp47, 2, 2);
                            }
                            var_s2_2 = temp_s2_3 + 1;
                        }
                        temp_s2_4 = var_s2_2 & 0xFF;
                        sp47 = (u8) sp47 - 1;
                        sp57 = 0;
                        if (sp2C->unk_29C[0][0][(temp_s2_4 * 2) + ((u8) sp47 * 0x10)] == 0xA) {
                            temp_s0_14 = var_s0 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 1, temp_s2_4, (s32) (u8) sp47, 0, 0);
                            var_s0_2 = temp_s0_14 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F, temp_fp, 1, temp_s2_4, (s32) (u8) sp47, 1, 0);
block_53:
                            var_s0 = var_s0_2 | aifRensaCheckCore(sp2C, temp_s3, temp_s6, sp3F);
                        }
                    }
                    switch (sp4F) {                 /* irregular */
                        case 0x0:
                            var_a1_2 = temp_s3->unk_8 + ((s16) aiHiErR * D_8008856A);
                            temp_s3->unk_8 = var_a1_2;
                            if (sp5F != 0) {
                                if ((((sp67 != 0) | (sp6F != 0)) != 0) || (var_s0 & 0xFF)) {
                                    var_v0 = var_a1_2 + (D_800885D2 * sp5F);
                                } else {
                                    var_v0 = var_a1_2 + (D_800885D2 * sp5F);
                                }
                                goto block_88;
                            }
                            var_v1 = sp67;
block_68:
                            if ((((var_v1 != 0) | (sp6F != 0)) == 0) && !(var_s0 & 0xFF)) {
                                temp_s3->unk_8 = var_a1_2;
                            } else {
block_86:
                                if (sp3F >= 3U) {
                                    var_v0 = var_a1_2 + D_800885D4;
block_88:
                                    temp_s3->unk_8 = var_v0;
                                }
                            }
                            break;
                        case 0x1:
                            var_a1_2 = temp_s3->unk_8 + ((s16) aiHiErY * D_8008856A);
                            temp_s3->unk_8 = var_a1_2;
                            if (sp67 != 0) {
                                if ((((sp5F != 0) | (sp6F != 0)) != 0) || (var_s0 & 0xFF)) {
                                    var_v0 = var_a1_2 + (D_800885D2 * sp67);
                                } else {
                                    var_v0 = var_a1_2 + (D_800885D2 * sp67);
                                }
                                goto block_88;
                            }
                            var_v1 = sp5F;
                            goto block_68;
                        case 0x2:
                            var_a1_2 = temp_s3->unk_8 + ((s16) aiHiErB * D_8008856A);
                            temp_s3->unk_8 = var_a1_2;
                            if (sp6F != 0) {
                                if ((((sp67 != 0) | (sp5F != 0)) != 0) || (var_s0 & 0xFF)) {
                                    var_v0 = var_a1_2 + (D_800885D2 * sp6F);
                                } else {
                                    var_v0 = var_a1_2 + (D_800885D2 * sp6F);
                                }
                                goto block_88;
                            }
                            if (((sp67 != 0) | (sp5F != 0)) == 0) {
                                if (!(var_s0 & 0xFF)) {
                                    temp_s3->unk_8 = var_a1_2;
                                } else {
                                    goto block_86;
                                }
                            } else {
                                goto block_86;
                            }
                            break;
                    }
                }
            } else {
                (aiFlag + 8)[sp8C] = 0xFFF0BDC0;
            }
            sp8C += 0x40;
            temp_t4 = sp34 + 1;
            sp34 = temp_t4;
        } while (temp_t4 < (s32) aiFlagCnt);
    }
    if ((u8) sp2C->unk_23E != 0) {
        var_s4 = 0xFFF0BDBF;
        var_s0_3 = 0;
        sp34 = 0;
        if ((s32) aiFlagCnt > 0) {
            var_s1_2 = 0;
            do {
                var_a2_2 = 0;
                if (B_800F3E32 != 0) {
                    var_a2_2 = genrand((s32) B_800F3E32) & 0xFFFF;
                }
                temp_v1_2 = (aiFlag + 8)[var_s1_2] + var_a2_2;
                if (var_s4 < temp_v1_2) {
                    var_s4 = temp_v1_2;
                    var_s0_3 = sp34;
                }
                var_s1_2 += 0x40;
                temp_t4_3 = sp34 + 1;
                sp34 = temp_t4_3;
            } while (temp_t4_3 < (s32) aiFlagCnt);
        }
    } else {
        var_s2_3 = 0xFFF0BDBF;
        var_s4_2 = -0xF4241;
        var_s0_3 = 0;
        sp34 = 0;
        if ((s32) aiFlagCnt > 0) {
            var_s1_3 = 0;
            do {
                if (B_800F3E32 != 0) {
                    var_a0 = (B_800F3E32 + 0x64) & 0xFFFF;
                } else {
                    var_a0 = 0x64;
                }
                temp_a0_4 = (aiFlag + 8)[var_s1_3];
                temp_v1_3 = temp_a0_4 + (genrand(var_a0) & 0xFFFF);
                if (var_s2_3 < temp_v1_3) {
                    var_s2_3 = temp_v1_3;
                    if (var_s4_2 < temp_a0_4) {
                        var_s4_2 = temp_a0_4;
                    }
                    var_s0_3 = sp34;
                }
                if (*(aiFlag + 8 + (var_s0_3 << 6)) < var_s4_2) {
                    sp2C->unk_23E = 1;
                }
                var_s1_3 += 0x40;
                temp_t4_4 = sp34 + 1;
                sp34 = temp_t4_4;
            } while (temp_t4_4 < (s32) aiFlagCnt);
        }
    }
    decide = (s8) var_s0_3;
}
#else
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aiHiruAllPriSet);
#endif
#endif

#if VERSION_US
/**
 * Original name: aiSetCharacter
 */
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aiSetCharacter);
#endif

#if VERSION_US
/**
 * Original name: aifFieldCopy
 */
#if 0
typedef struct struct_800EB4F8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ UNK_TYPE1 unk_06[2];
    /* 0x08 */ UNK_TYPE1 unk_08[0xC];
} struct_800EB4F8; // size = 0x14

extern struct_800EB4F8 aiRecurData[];
extern u8 B_800EB4F9[];
extern u8 B_800EB50A;
extern u8 B_800EB50B;
extern u8 B_800EB64C[][8][2];
extern u8 B_800EBD15;
extern u8 aiFieldData[][8][2];

void aifFieldCopy(struct_game_state_data *gameStateDataRef) {
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_t0;
    s32 var_t1;
    s32 var_v1;
    s32 var_v1_2;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 *temp_a0;

    aiNext[0] = (u8) gameStateDataRef->unk_3BE[0];
    aiNext[1] = (u8) gameStateDataRef->unk_3BE[1];
    var_t0 = 0;
    var_t1 = 2;
    while (var_t0 < 8) {
        var_a3 = 0;
        var_a2 = var_t0;
        var_a1 = var_t1;

        while (var_a3 < 0x11) {
            temp_v0 = gameStateDataRef->unk_29C[var_a3][var_t0][1];
            aiFieldData[var_a3][var_t0][0] = temp_v0;
            aiRecurData[var_a3].unk_00 = temp_v0;
            temp_v0_2 = gameStateDataRef->unk_29C[var_a3][var_t0][0];
            aiFieldData[var_a3][var_t0][1] = temp_v0_2;
            B_800EB4F9[var_a1] = temp_v0_2;
            var_a2 += 0x10;
            var_a1 += 0x14;
            var_a3 += 1;
        }
        var_t0 += 1;
        var_t1 += 2;
    }

    var_v1 = 0;
    do {
        B_800EB64C[0][var_v1][0] = 0xFF;
        B_800EB64C[0][var_v1][1] = 0xFF;
        var_v1 += 1;
    } while (var_v1 < 0x14/2);
    var_a3_2 = 0;
    do {
        aiRecurData[var_a3_2].unk_00 = 0xFF;
        aiRecurData[var_a3_2].unk_01 = 0xFF;
        aiRecurData[var_a3_2].unk_02 = 0xFF;
        aiRecurData[var_a3_2].unk_03 = 0xFF;
        var_a3_2 += 1;
    } while (var_a3_2 < 0x12);
}
#else
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifFieldCopy);
#endif
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80031014_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80031230_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_800313D4_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80031A54_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80031AF0_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80032008_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_800329A0_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80032A84_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80033280_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_800333BC_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_800334F4_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80033578_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_800335E0_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_800336A4_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80033700_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80034824_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_800357CC_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80036558_cn);
#endif

// no original name :c
void func_80034310(void) {
    s32 column;

    for (column = 0; column < GAME_MAP_COLUMNS; column++) {
        s32 row;

        for (row = 0; row < GAME_MAP_ROWS; row++) {
            aiRecurData[row][column + 1].unk_0 = aiFieldData[row][column].unk_0;
            aiRecurData[row][column + 1].unk_1 = aiFieldData[row][column].unk_1;
        }
    }
}

#if VERSION_US
/**
 * Original name: aifPlaceSearch
 */
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifPlaceSearch);
#endif

#if VERSION_US
/**
 * Original name: aifMoveCheck
 */
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifMoveCheck);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifTRecur);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifTRecurUP);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifYRecur);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifYRecurUP);
#endif

#if VERSION_US
/**
 * Original name: aifReMoveCheck
 */
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifReMoveCheck);
#endif

#if VERSION_US
INCLUDE_RODATA("asm/us/nonmatchings/main_segment/aiset", RO_800ACF10);
#endif

#if VERSION_US
/**
 * Original name: aifKeyMake
 */
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifKeyMake);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80036710_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80036BD4_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80036EE4_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_800371B0_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_800372E8_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80037598_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_800376C8_cn);
#endif

#if VERSION_CN
#if 0
//s8 func_800329A0_cn(void *, void *, u8 *, u8 *);    /* extern */
extern f32 B_800CA1C4_cn;
extern u8 decide;
extern u8 B_800CA22A_cn;
extern u8 B_800CA254_cn;
extern u8 B_800CA2AA_cn;
extern ? aiFlag;
extern u8 B_8010DF34_cn;
extern ? D_800932B8_cn;
extern ? RO_800C3FD8_cn;

void func_8003793C_cn(void *arg0) {
    s32 temp_v1_2;
    s32 var_t1;
    s32 var_v0;
    s32 var_v0_2;
    u8 *var_a0_2;
    u8 *var_a2;
    u8 *var_a3;
    u8 *var_t0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v1;
    void *temp_a1;
    void *temp_v0;
    void *var_a0;
    void *var_v1;

    temp_a1 = arg0 + 0x190;
    var_a0 = temp_a1;
    var_v1 = (decide << 6) + &aiFlag;
    temp_v0 = var_v1 + 0x40;
    do {
        var_a0->unk_0 = (s32) var_v1->unk_0;
        var_a0->unk_4 = (s32) var_v1->unk_4;
        var_a0->unk_8 = (s32) var_v1->unk_8;
        var_a0->unk_C = (s32) var_v1->unk_C;
        var_v1 += 0x10;
        var_a0 += 0x10;
    } while (var_v1 != temp_v0);
    var_t1 = 0;
    var_t0 = arg0 + 0x1D1;
    var_a3 = &B_8010DF34_cn + 1;
    var_a2 = arg0 + 0x1D0;
    var_a0_2 = &B_8010DF34_cn;
    do {
        temp_v0_2 = *var_a0_2;
        var_a0_2 += 2;
        var_t1 += 1;
        *var_a2 = temp_v0_2;
        temp_v1 = *var_a3;
        var_a3 += 2;
        var_a2 += 2;
        *var_t0 = temp_v1;
        var_t0 += 2;
    } while (var_t1 < 0x32);
    arg0->unk_23F = (u8) *(((B_800CA254_cn - 1) * 2) + &B_8010DF34_cn);
    arg0->unk_240 = (u8) (&B_8010DF34_cn + ((B_800CA254_cn - 1) * 2))->unk_1;
    arg0->unk_1CF = func_800329A0_cn(arg0, temp_a1, var_a2, var_a3);
    temp_v1_2 = ((((sp + ((arg0->unk_194 * 4) + (arg0->unk_191 * 8)))->unk_18 - (arg0->unk_241 - 0x28)) + arg0->unk_237) - B_800CA22A_cn) + arg0->unk_238;
    var_v0 = temp_v1_2;
    if (temp_v1_2 < 0) {
        var_v0 = temp_v1_2 + 3;
    }
    temp_v0_3 = temp_v1_2 - ((var_v0 >> 2) * 4);
    arg0->unk_237 = temp_v0_3;
    arg0->unk_241 = temp_v0_3;
    arg0->unk_238 = (u8) B_800CA22A_cn;
    arg0->unk_235 = 2;
    arg0->unk_236 = 1;
    arg0->unk_293 = (u8) B_800CA2AA_cn;
    var_v0_2 = 0x64;
    if (!(B_800CA1C4_cn > 100.0f)) {
        if (B_800CA1C4_cn >= 2.1474836e9f) {
            var_v0_2 = (s32) (B_800CA1C4_cn - 2.1474836e9f) | 0x80000000;
        } else {
            var_v0_2 = (s32) B_800CA1C4_cn;
        }
    }
    arg0->unk_294 = (s8) var_v0_2;
    if ((u32) (genrand((s32) *(&D_800932B8_cn + (arg0->unk_23C + ((s8) B_800CA2AA_cn * 3)))) & 0xFF) >= 7U) {
        arg0->unk_23A = 0;
        return;
    }
    arg0->unk_23A = 1;
    arg0->unk_23B = genrand(5);
}
#else
INCLUDE_RODATA("asm/cn/nonmatchings/main_segment/aiset", RO_800C3FD8_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_8003793C_cn);
#endif
#endif


#if VERSION_US
INCLUDE_RODATA("asm/us/nonmatchings/main_segment/aiset", wave_tbl_2879);
#endif

#if VERSION_US
/**
 * Original name: aifKeyOut
 */
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", aifKeyOut);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", search_flash_3);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/aiset", flash_special);
#endif

#if VERSION_CN
INCLUDE_RODATA("asm/cn/nonmatchings/main_segment/aiset", wave_tbl_2879);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80037BBC_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80038190_cn);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/aiset", func_80038778_cn);
#endif

/**
 * Original name: aiCOM_MissTake
 */
void aiCOM_MissTake(void) {
    PlayTime++;

    if (PlayTime > 18000) {
        MissRate = (PlayTime - 18000) / 720;
    } else {
        MissRate = 0;
    }
}
