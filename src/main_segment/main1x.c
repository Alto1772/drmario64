#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_segment_functions.h"
#include "main_segment_variables.h"

/**
 * Original name: main11
 */
enum_main_no main11(void) {
    enum_main_no ret = MAIN_NO_3;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(game_state_data); i++) {
        game_state_data[i].unk_026 = 0xA;
        game_state_data[i].unk_02C = 1;
        game_state_data[i].unk_090 = i;
        game_state_data[i].unk_04B = i;
        game_state_data[i].unk_04C = 0;
        game_state_data[i].unk_04D = i;
        game_state_data[i].unk_04E = 1;
        game_state_data[i].unk_16C = 1;
    }

    evs_select_name_no[0] = evs_select_name_no[1] = 8;

    switch (EepRom_Init()) {
        case 0x2:
            EepRom_InitFirst(0, 0);
            break;

        case 0x5:
            ret = MAIN_NO_10;
            break;

        default:
            break;
    }

    return ret;
}

/**
 * Original name: adjust_story_ai
 */
#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/main1x", adjust_story_ai);
#endif

#if VERSION_CN
#if 0
//extern ? B_8010084C_cn;
//extern ? B_80100CF0_cn;

// ai_char_data // size = 0x6C0

typedef struct struct_ai_char_data {
    /* 0x00 */ UNK_TYPE1 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ UNK_TYPE1 unk_02[0x2];
    /* 0x04 */ UNK_TYPE1 unk_04[0x8];
    /* 0x02 */ UNK_TYPE1 unk_0C[0x2];
    /* 0x02 */ u8 unk_0E;
    /* 0x02 */ UNK_TYPE1 unk_0F[0x1];
    /* 0x02 */ UNK_TYPE1 unk_10[0x10];
    /* 0x02 */ u8 unk_20;
    /* 0x04 */ UNK_TYPE1 unk_21[0x3];
    /* 0x02 */ UNK_TYPE1 unk_24[0x18];
    /* 0x3C */ u8 unk_3C;
    /* 0x3D */ u8 unk_3D;
    /* 0x3E */ UNK_TYPE1 unk_3E;
    /* 0x3E */ UNK_TYPE1 unk_3F[0x1];
    /* 0x40 */ UNK_TYPE1 unk_40[0x2C];
} struct_ai_char_data; // size = 0x6C

extern struct_ai_char_data ai_char_data[0x10];

void adjust_story_ai(void) {

    #if 0
    ? *var_v1;
    ? *var_v1_2;
    s32 var_t1;
    s32 var_v0;
    s8 var_v0_3;
    s8 var_v0_4;
    s8 var_v0_5;
    s8 var_v0_6;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32 temp_v1_5;
    u32 temp_v1_6;
    void *temp_a1;
    void *temp_a3;
    void *temp_v1;
    void *temp_v1_2;
    void *var_a0;
    void *var_a0_2;
    void *var_a2;
    void *var_v0_2;
    #endif
    struct_game_state_data * gameStateDataP = game_state_data;

    s32 i; // t1
    //s32 v0;


    for (i = 0; i < evs_playcnt; i++) {
        struct_game_state_data *ptr; // a3

        ptr = &gameStateDataP[i];

        if (ptr->unk_04C != 1) {
            continue;
        }

        ai_char_data[i] = ai_char_data[ptr->unk_04D];


        switch (evs_story_level) {          /* switch 5; irregular */
            case 0x0:                       /* switch 5 */
                switch (ptr->unk_090) {        /* switch 1 */
                    case 0x0:               /* switch 1 */
                    case 0x1:               /* switch 1 */
                        if (evs_story_no == 1) {
                            #if 0
                            var_v1 = &B_8010084C_cn;
                            var_a0 = temp_a1;
                            if (((s32) temp_a1 | (s32) &B_8010084C_cn) & 3) {
                                do {
                                    var_a0->unk_0 = (unaligned s32) var_v1->unk_0;
                                    var_a0->unk_4 = (unaligned s32) var_v1->unk_4;
                                    var_a0->unk_8 = (unaligned s32) var_v1->unk_8;
                                    var_a0->unk_C = (unaligned s32) var_v1->unk_C;
                                    var_v1 += 0x10;
                                    var_a0 += 0x10;
                                } while (var_v1 != (&B_8010084C_cn + 0x60));
                            } else {
                                do {
                                    var_a0->unk_0 = (s32) var_v1->unk_0;
                                    var_a0->unk_4 = (s32) var_v1->unk_4;
                                    var_a0->unk_8 = (s32) var_v1->unk_8;
                                    var_a0->unk_C = (s32) var_v1->unk_C;
                                    var_v1 += 0x10;
                                    var_a0 += 0x10;
                                } while (var_v1 != (&B_8010084C_cn + 0x60));
                            }

                            var_a0->unk_0 = (unaligned s32) var_v1->unk_0;
                            var_a0->unk_4 = (unaligned s32) var_v1->unk_4;
                            var_a0->unk_8 = (unaligned s32) var_v1->unk_8;
                            temp_a1->unk_1 = 1;
                            #endif
                            ai_char_data[i] = ai_char_data[0xB];
                            ai_char_data[i].unk_01 = 1;
                        }
                        break;
                    case 0xC:               /* switch 1 */
                    #if 0
                        temp_a1->unk_1 = 1;
                        temp_a1->unk_3C = 0;
                        temp_a1->unk_3E = 0;
                        #endif
                        ai_char_data[i].unk_01 = 1;
                        ai_char_data[i].unk_3C = 0;
                        ai_char_data[i].unk_3D = 0;
                        break;
                    case 0xD:               /* switch 1 */
                    case 0xE:               /* switch 1 */
                    #if 0
                        temp_a1->unk_1 = 2;
                        temp_a1->unk_3C = 0;
                        #endif
                        ai_char_data[i].unk_01 = 2;
                        ai_char_data[i].unk_3C = 0;
                        break;
                    case 0x6:               /* switch 2 */
                    #if 0
                        temp_a1->unk_3C = 0;
                        #endif
                        ai_char_data[i].unk_3C = 0;
                        break;
                    case 0xA:               /* switch 1 */
                    case 0x9:               /* switch 4 */
                    case 0x8:               /* switch 2 */
                    //case 0xA:               /* switch 3 */
                    #if 0
                        temp_a1->unk_1 = 2;
                        #endif
                        ai_char_data[i].unk_01 = 2;
                        break;
                }
                break;
            case 0x3:                       /* switch 5 */
                switch (ptr->unk_090) {        /* switch 4 */
                    case 0x0:               /* switch 4 */
                    case 0x1:               /* switch 4 */
                    #if 0
                        if (evs_story_no == 1) {
                            var_v1_2 = &B_8010084C_cn;
                            var_a0_2 = temp_a1;
                            if (((s32) temp_a1 | (s32) &B_8010084C_cn) & 3) {
                                do {
                                    var_a0_2->unk_0 = (unaligned s32) var_v1_2->unk_0;
                                    var_a0_2->unk_4 = (unaligned s32) var_v1_2->unk_4;
                                    var_a0_2->unk_8 = (unaligned s32) var_v1_2->unk_8;
                                    var_a0_2->unk_C = (unaligned s32) var_v1_2->unk_C;
                                    var_v1_2 += 0x10;
                                    var_a0_2 += 0x10;
                                } while (var_v1_2 != (&B_8010084C_cn + 0x60));
                            } else {
                                do {
                                    var_a0_2->unk_0 = (s32) var_v1_2->unk_0;
                                    var_a0_2->unk_4 = (s32) var_v1_2->unk_4;
                                    var_a0_2->unk_8 = (s32) var_v1_2->unk_8;
                                    var_a0_2->unk_C = (s32) var_v1_2->unk_C;
                                    var_v1_2 += 0x10;
                                    var_a0_2 += 0x10;
                                } while (var_v1_2 != (&B_8010084C_cn + 0x60));
                            }
                            var_a0_2->unk_0 = (unaligned s32) var_v1_2->unk_0;
                            var_a0_2->unk_4 = (unaligned s32) var_v1_2->unk_4;
                            var_a0_2->unk_8 = (unaligned s32) var_v1_2->unk_8;
                            temp_a1->unk_3D = 0;
                        case 0x5:           /* switch 2 */
                        case 0x7:           /* switch 2 */
                        case 0xA:           /* switch 2 */
                        }
                        temp_a1->unk_1 = 1;
                        #endif
                        if (evs_story_no == 1) {
                            ai_char_data[i] = ai_char_data[0xB];
                        }
                        ai_char_data[i].unk_01 = 1;
                        break;
                    case 0x3:               /* switch 4 */
                    #if 0
                        temp_a1->unk_1 = 2;
                        temp_a1->unk_3D = 0;
                        #endif
                        ai_char_data[i].unk_01 = 2;
                        ai_char_data[i].unk_3D = 0;
                        break;
                    case 0x8:               /* switch 4 */
                    //case 0x8:               /* switch 3 */
                    #if 0
                        temp_a1->unk_1 = 5;
                        #endif
                        ai_char_data[i].unk_01 = 5;
                        break;
                    case 0x5:               /* switch 4 */
                    #if 0
                        temp_a1->unk_1 = 4;
                        #endif
                        ai_char_data[i].unk_01 = 4;
                        break;
                    case 0x2:               /* switch 4 */
                    case 0x4:               /* switch 4 */
                    case 0x6:               /* switch 4 */
                    case 0x7:               /* switch 4 */
                    #if 0
                        temp_a1->unk_1 = 3;
                        #endif
                        ai_char_data[i].unk_01 = 3;
                        break;
                    case 0xC:               /* switch 4 */
                    #if 0
                        temp_a1->unk_1 = 5;
                        temp_a1->unk_3D = 0;
                        #endif
                        ai_char_data[i].unk_01 = 5;
                        ai_char_data[i].unk_3D = 0;
                        break;
                    case 0xD:               /* switch 4 */
                    case 0xE:               /* switch 4 */
                    #if 0
                        temp_a1->unk_1 = 5;
                        temp_a1->unk_3C = 6;
                        #endif
                        ai_char_data[i].unk_01 = 5;
                        ai_char_data[i].unk_3C = 6;
                        break;
                }
                break;
            case 0x1:                       /* switch 5 */
                switch (ptr->unk_090) {        /* switch 2 */
                    case 0x0:               /* switch 2 */
                    case 0x1:               /* switch 2 */
                    #if 0
                        if (evs_story_no != 1) {
                            temp_a1->unk_1 = 1;
                            temp_a1->unk_3D = 0;
                        } else {
                            var_v1 = &B_8010084C_cn;
                            var_a0 = temp_a1;
                            if (((s32) temp_a1 | (s32) &B_8010084C_cn) & 3) {
                                do {
                                    var_a0->unk_0 = (unaligned s32) var_v1->unk_0;
                                    var_a0->unk_4 = (unaligned s32) var_v1->unk_4;
                                    var_a0->unk_8 = (unaligned s32) var_v1->unk_8;
                                    var_a0->unk_C = (unaligned s32) var_v1->unk_C;
                                    var_v1 += 0x10;
                                    var_a0 += 0x10;
                                } while (var_v1 != (&B_8010084C_cn + 0x60));
                            } else {
                                do {
                                    var_a0->unk_0 = (s32) var_v1->unk_0;
                                    var_a0->unk_4 = (s32) var_v1->unk_4;
                                    var_a0->unk_8 = (s32) var_v1->unk_8;
                                    var_a0->unk_C = (s32) var_v1->unk_C;
                                    var_v1 += 0x10;
                                    var_a0 += 0x10;
                                } while (var_v1 != (&B_8010084C_cn + 0x60));
                            }
                            var_a0->unk_0 = (unaligned s32) var_v1->unk_0;
                            var_a0->unk_4 = (unaligned s32) var_v1->unk_4;
                            var_a0->unk_8 = (unaligned s32) var_v1->unk_8;
                            temp_a1->unk_1 = 1;
                        }
                        #endif
                        if (evs_story_no != 1) {
                            ai_char_data[i].unk_01 = 1;
                            ai_char_data[i].unk_3D = 0;
                        } else {
                            ai_char_data[i] = ai_char_data[0xB];
                            ai_char_data[i].unk_01 = 1;
                        }
                        break;
                    case 0xB:               /* switch 2 */
                    #if 0
                        var_v0_6 = 1;
                        temp_a1->unk_1 = var_v0_6;
                        temp_a1->unk_3C = 0;
                        temp_a1->unk_3D = 0;
                        #endif
                        ai_char_data[i].unk_01 = 1;
                        ai_char_data[i].unk_3C = 0;
                        ai_char_data[i].unk_3D = 0;
                        break;
                    case 0xC:               /* switch 2 */
                    #if 0
                        var_v0_3 = 2;
                        temp_a1->unk_1 = var_v0_3;
                        temp_a1->unk_3C = 0;
                        temp_a1->unk_3E = 0;
                        #endif
                        ai_char_data[i].unk_3C = 0;
                        ai_char_data[i].unk_3E = 0;
                        break;
                    case 0xD:               /* switch 2 */
                    case 0xE:               /* switch 2 */
                    #if 0
                        var_v0_4 = 2;
                        temp_a1->unk_1 = var_v0_4;
                        temp_a1->unk_3C = 0;
                        #endif
                        ai_char_data[i].unk_01 = 2;
                        ai_char_data[i].unk_3C = 0;
                        break;
                }
                break;
            case 0x2:                       /* switch 5 */
                switch (ptr->unk_090) {        /* switch 3 */
                    case 0x0:               /* switch 3 */
                    case 0x1:               /* switch 3 */
                    #if 0
                        var_v0_5 = 2;
                        if (evs_story_no == 1) {
                            var_v1 = &B_8010084C_cn;
                            var_a0 = temp_a1;
                            if (((s32) temp_a1 | (s32) &B_8010084C_cn) & 3) {
                                do {
                                    var_a0->unk_0 = (unaligned s32) var_v1->unk_0;
                                    var_a0->unk_4 = (unaligned s32) var_v1->unk_4;
                                    var_a0->unk_8 = (unaligned s32) var_v1->unk_8;
                                    var_a0->unk_C = (unaligned s32) var_v1->unk_C;
                                    var_v1 += 0x10;
                                    var_a0 += 0x10;
                                } while (var_v1 != (&B_8010084C_cn + 0x60));
                            } else {
                                do {
                                    var_a0->unk_0 = (s32) var_v1->unk_0;
                                    var_a0->unk_4 = (s32) var_v1->unk_4;
                                    var_a0->unk_8 = (s32) var_v1->unk_8;
                                    var_a0->unk_C = (s32) var_v1->unk_C;
                                    var_v1 += 0x10;
                                    var_a0 += 0x10;
                                } while (var_v1 != (&B_8010084C_cn + 0x60));
                            }
                            var_a0->unk_0 = (unaligned s32) var_v1->unk_0;
                            var_a0->unk_4 = (unaligned s32) var_v1->unk_4;
                            var_a0->unk_8 = (unaligned s32) var_v1->unk_8;
                            temp_a1->unk_1 = 1;
                            break;
                        }
                        temp_a1->unk_1 = var_v0_5;
                        temp_a1->unk_3D = 0;
                        #endif
                        if (evs_story_no == 1) {
                            ai_char_data[i] = ai_char_data[0xB];
                        } else {
                            ai_char_data[i].unk_01 = 2;
                            ai_char_data[i].unk_3D = 0;
                        }
                        break;
                    case 0x3:               /* switch 3 */
                    #if 0
                        var_v0_5 = 2;
                        temp_a1->unk_1 = var_v0_5;
                        temp_a1->unk_3D = 0;
                        #endif
                        ai_char_data[i].unk_01 = 2;
                        ai_char_data[i].unk_3D = 0;
                        break;

                    case 0x9:               /* switch 3 */
                    #if 0
                        temp_a1->unk_1 = 2;
                        temp_a1->unk_3E = 0;
                    #endif
                        ai_char_data[i].unk_01 = 2;
                        ai_char_data[i].unk_3E = 0;
                        break;
                    case 0x7:               /* switch 3 */
                    #if 0
                        var_v0_5 = 3;
                        temp_a1->unk_1 = var_v0_5;
                        temp_a1->unk_3D = 0;
                        #endif
                        ai_char_data[i].unk_01 = 3;
                        ai_char_data[i].unk_3D = 0;
                        break;
                    case 0xB:               /* switch 3 */
                    #if 0
                        var_v0_6 = 2;
                        temp_a1->unk_1 = var_v0_6;
                        temp_a1->unk_3C = 0;
                        temp_a1->unk_3D = 0;
                        #endif
                        ai_char_data[i].unk_01 = 2;
                        ai_char_data[i].unk_3C = 0;
                        ai_char_data[i].unk_3C = 0;
                        break;
                    case 0xC:               /* switch 3 */
                    #if 0
                        temp_a1->unk_1 = 3;
                        temp_a1->unk_0 = 0;
                        temp_a1->unk_E = 2;
                        temp_a1->unk_20 = 0xF;
                        temp_a1->unk_3E = 2;
                        #endif
                        ai_char_data[i].unk_01 = 3;
                        ai_char_data[i].unk_00 = 0;
                        ai_char_data[i].unk_0E = 2;
                        ai_char_data[i].unk_20 = 0xF;
                        ai_char_data[i].unk_3E = 2;
                        break;
                    case 0x2:               /* switch 3 */
                    case 0x4:               /* switch 3 */
                    case 0xD:               /* switch 3 */
                    case 0xE:               /* switch 3 */
                    #if 0
                        var_v0_4 = 3;
                        temp_a1->unk_1 = var_v0_4;
                        temp_a1->unk_3C = 0;
                    #endif
                        ai_char_data[i].unk_01 = 3;
                        ai_char_data[i].unk_3C = 0;
                        break;
                }
                break;
        }
    }

    #if 0
    var_t1 = 0;
    if (evs_playcnt != 0) {
        var_v0 = 0 * 0x10;
        do {
            temp_a3 = ((((var_v0 - var_t1) * 0x10) + var_t1) * 4) + game_state_data;
            temp_a1 = (var_t1 * 0x6C) + &B_80100CF0_cn;
            if (temp_a3->unk_4C == 1) {
                var_v0_2 = (temp_a3->unk_4D * 0x6C) + (&B_80100CF0_cn - 0x510);
                var_a2 = temp_a1;
                if (((s32) var_v0_2 | (s32) temp_a1) & 3) {
                    temp_v1 = var_v0_2 + 0x60;
                    do {
                        var_a2->unk_0 = (unaligned s32) var_v0_2->unk_0;
                        var_a2->unk_4 = (unaligned s32) var_v0_2->unk_4;
                        var_a2->unk_8 = (unaligned s32) var_v0_2->unk_8;
                        var_a2->unk_C = (unaligned s32) var_v0_2->unk_C;
                        var_v0_2 += 0x10;
                        var_a2 += 0x10;
                    } while (var_v0_2 != temp_v1);
                } else {
                    temp_v1_2 = var_v0_2 + 0x60;
                    do {
                        var_a2->unk_0 = (s32) var_v0_2->unk_0;
                        var_a2->unk_4 = (s32) var_v0_2->unk_4;
                        var_a2->unk_8 = (s32) var_v0_2->unk_8;
                        var_a2->unk_C = (s32) var_v0_2->unk_C;
                        var_v0_2 += 0x10;
                        var_a2 += 0x10;
                    } while (var_v0_2 != temp_v1_2);
                }
                var_a2->unk_0 = (unaligned s32) var_v0_2->unk_0;
                var_a2->unk_4 = (unaligned s32) var_v0_2->unk_4;
                var_a2->unk_8 = (unaligned s32) var_v0_2->unk_8;
                temp_a3->unk_4D = (u8) (var_t1 + 0xC);
                switch (evs_story_level) {          /* switch 5; irregular */
                    case 0x0:                       /* switch 5 */
                        temp_v1_3 = temp_a3->unk_90;
                        switch (temp_v1_3) {        /* switch 1 */
                            case 0x0:               /* switch 1 */
                            case 0x1:               /* switch 1 */
                                if (evs_story_no == 1) {
                                    var_v1 = &B_8010084C_cn;
                                    var_a0 = temp_a1;
                                    if (((s32) temp_a1 | (s32) &B_8010084C_cn) & 3) {
                                        do {
                                            var_a0->unk_0 = (unaligned s32) var_v1->unk_0;
                                            var_a0->unk_4 = (unaligned s32) var_v1->unk_4;
                                            var_a0->unk_8 = (unaligned s32) var_v1->unk_8;
                                            var_a0->unk_C = (unaligned s32) var_v1->unk_C;
                                            var_v1 += 0x10;
                                            var_a0 += 0x10;
                                        } while (var_v1 != (&B_8010084C_cn + 0x60));
                                    } else {
                                        do {
                                            var_a0->unk_0 = (s32) var_v1->unk_0;
                                            var_a0->unk_4 = (s32) var_v1->unk_4;
                                            var_a0->unk_8 = (s32) var_v1->unk_8;
                                            var_a0->unk_C = (s32) var_v1->unk_C;
                                            var_v1 += 0x10;
                                            var_a0 += 0x10;
                                        } while (var_v1 != (&B_8010084C_cn + 0x60));
                                    }
block_59:
                                    var_a0->unk_0 = (unaligned s32) var_v1->unk_0;
                                    var_a0->unk_4 = (unaligned s32) var_v1->unk_4;
                                    var_a0->unk_8 = (unaligned s32) var_v1->unk_8;
                                    temp_a1->unk_1 = 1;
                                }
                                break;
                            case 0xC:               /* switch 1 */
                                var_v0_3 = 1;
block_47:
                                temp_a1->unk_1 = var_v0_3;
                                temp_a1->unk_3C = 0;
                                temp_a1->unk_3E = 0;
                                break;
                            case 0xD:               /* switch 1 */
                            case 0xE:               /* switch 1 */
                                var_v0_4 = 2;
block_67:
                                temp_a1->unk_1 = var_v0_4;
                            case 0x6:               /* switch 2 */
                                temp_a1->unk_3C = 0;
                                break;
                            case 0xA:               /* switch 1 */
                            case 0x9:               /* switch 4 */
                            case 0x8:               /* switch 2 */
                            case 0xA:               /* switch 3 */
                                temp_a1->unk_1 = 2;
                                break;
                        }
                        break;
                    case 0x3:                       /* switch 5 */
                        temp_v1_4 = temp_a3->unk_90;
                        switch (temp_v1_4) {        /* switch 4 */
                            case 0x0:               /* switch 4 */
                            case 0x1:               /* switch 4 */
                                if (evs_story_no == 1) {
                                    var_v1_2 = &B_8010084C_cn;
                                    var_a0_2 = temp_a1;
                                    if (((s32) temp_a1 | (s32) &B_8010084C_cn) & 3) {
                                        do {
                                            var_a0_2->unk_0 = (unaligned s32) var_v1_2->unk_0;
                                            var_a0_2->unk_4 = (unaligned s32) var_v1_2->unk_4;
                                            var_a0_2->unk_8 = (unaligned s32) var_v1_2->unk_8;
                                            var_a0_2->unk_C = (unaligned s32) var_v1_2->unk_C;
                                            var_v1_2 += 0x10;
                                            var_a0_2 += 0x10;
                                        } while (var_v1_2 != (&B_8010084C_cn + 0x60));
                                    } else {
                                        do {
                                            var_a0_2->unk_0 = (s32) var_v1_2->unk_0;
                                            var_a0_2->unk_4 = (s32) var_v1_2->unk_4;
                                            var_a0_2->unk_8 = (s32) var_v1_2->unk_8;
                                            var_a0_2->unk_C = (s32) var_v1_2->unk_C;
                                            var_v1_2 += 0x10;
                                            var_a0_2 += 0x10;
                                        } while (var_v1_2 != (&B_8010084C_cn + 0x60));
                                    }
                                    var_a0_2->unk_0 = (unaligned s32) var_v1_2->unk_0;
                                    var_a0_2->unk_4 = (unaligned s32) var_v1_2->unk_4;
                                    var_a0_2->unk_8 = (unaligned s32) var_v1_2->unk_8;
                                    temp_a1->unk_3D = 0;
                                case 0x5:           /* switch 2 */
                                case 0x7:           /* switch 2 */
                                case 0xA:           /* switch 2 */
                                }
                                temp_a1->unk_1 = 1;
                                break;
                            case 0x3:               /* switch 4 */
                                var_v0_5 = 2;
block_87:
                                temp_a1->unk_1 = var_v0_5;
                                temp_a1->unk_3D = 0;
                                break;
                            case 0x8:               /* switch 4 */
                            case 0x8:               /* switch 3 */
                                temp_a1->unk_1 = 5;
                                break;
                            case 0x5:               /* switch 4 */
                                temp_a1->unk_1 = 4;
                                break;
                            case 0x2:               /* switch 4 */
                            case 0x4:               /* switch 4 */
                            case 0x6:               /* switch 4 */
                            case 0x7:               /* switch 4 */
                                temp_a1->unk_1 = 3;
                                break;
                            case 0xC:               /* switch 4 */
                                var_v0_5 = 5;
                                goto block_87;
                            case 0xD:               /* switch 4 */
                            case 0xE:               /* switch 4 */
                                temp_a1->unk_1 = 5;
                                temp_a1->unk_3C = 6;
                                break;
                        }
                        break;
                    case 0x1:                       /* switch 5 */
                        temp_v1_5 = temp_a3->unk_90;
                        switch (temp_v1_5) {        /* switch 2 */
                            case 0x0:               /* switch 2 */
                            case 0x1:               /* switch 2 */
                                if (evs_story_no != 1) {
                                    temp_a1->unk_1 = 1;
                                    temp_a1->unk_3D = 0;
                                } else {
                                    var_v1 = &B_8010084C_cn;
                                    var_a0 = temp_a1;
                                    if (((s32) temp_a1 | (s32) &B_8010084C_cn) & 3) {
                                        do {
                                            var_a0->unk_0 = (unaligned s32) var_v1->unk_0;
                                            var_a0->unk_4 = (unaligned s32) var_v1->unk_4;
                                            var_a0->unk_8 = (unaligned s32) var_v1->unk_8;
                                            var_a0->unk_C = (unaligned s32) var_v1->unk_C;
                                            var_v1 += 0x10;
                                            var_a0 += 0x10;
                                        } while (var_v1 != (&B_8010084C_cn + 0x60));
                                    } else {
                                        do {
                                            var_a0->unk_0 = (s32) var_v1->unk_0;
                                            var_a0->unk_4 = (s32) var_v1->unk_4;
                                            var_a0->unk_8 = (s32) var_v1->unk_8;
                                            var_a0->unk_C = (s32) var_v1->unk_C;
                                            var_v1 += 0x10;
                                            var_a0 += 0x10;
                                        } while (var_v1 != (&B_8010084C_cn + 0x60));
                                    }
                                    goto block_59;
                                }
                                break;
                            case 0xB:               /* switch 2 */
                                var_v0_6 = 1;
block_64:
                                temp_a1->unk_1 = var_v0_6;
                                temp_a1->unk_3C = 0;
                                temp_a1->unk_3D = 0;
                                break;
                            case 0xC:               /* switch 2 */
                                var_v0_3 = 2;
                                goto block_47;
                            case 0xD:               /* switch 2 */
                            case 0xE:               /* switch 2 */
                                var_v0_4 = 2;
                                goto block_67;
                        }
                        break;
                    case 0x2:                       /* switch 5 */
                        temp_v1_6 = temp_a3->unk_90;
                        switch (temp_v1_6) {        /* switch 3 */
                            case 0x0:               /* switch 3 */
                            case 0x1:               /* switch 3 */
                                var_v0_5 = 2;
                                if (evs_story_no == 1) {
                                    var_v1 = &B_8010084C_cn;
                                    var_a0 = temp_a1;
                                    if (((s32) temp_a1 | (s32) &B_8010084C_cn) & 3) {
                                        do {
                                            var_a0->unk_0 = (unaligned s32) var_v1->unk_0;
                                            var_a0->unk_4 = (unaligned s32) var_v1->unk_4;
                                            var_a0->unk_8 = (unaligned s32) var_v1->unk_8;
                                            var_a0->unk_C = (unaligned s32) var_v1->unk_C;
                                            var_v1 += 0x10;
                                            var_a0 += 0x10;
                                        } while (var_v1 != (&B_8010084C_cn + 0x60));
                                    } else {
                                        do {
                                            var_a0->unk_0 = (s32) var_v1->unk_0;
                                            var_a0->unk_4 = (s32) var_v1->unk_4;
                                            var_a0->unk_8 = (s32) var_v1->unk_8;
                                            var_a0->unk_C = (s32) var_v1->unk_C;
                                            var_v1 += 0x10;
                                            var_a0 += 0x10;
                                        } while (var_v1 != (&B_8010084C_cn + 0x60));
                                    }
                                    goto block_59;
                                }
                                goto block_87;
                            case 0x3:               /* switch 3 */
                                var_v0_5 = 2;
                                goto block_87;
                            case 0x9:               /* switch 3 */
                                temp_a1->unk_1 = 2;
                                temp_a1->unk_3E = 0;
                                break;
                            case 0x7:               /* switch 3 */
                                var_v0_5 = 3;
                                goto block_87;
                            case 0xB:               /* switch 3 */
                                var_v0_6 = 2;
                                goto block_64;
                            case 0xC:               /* switch 3 */
                                temp_a1->unk_1 = 3;
                                temp_a1->unk_0 = 0;
                                temp_a1->unk_E = 2;
                                temp_a1->unk_20 = 0xF;
                                temp_a1->unk_3E = 2;
                                break;
                            case 0x2:               /* switch 3 */
                            case 0x4:               /* switch 3 */
                            case 0xD:               /* switch 3 */
                            case 0xE:               /* switch 3 */
                                var_v0_4 = 3;
                                goto block_67;
                        }
                        break;
                }
            }
            var_t1 += 1;
            var_v0 = var_t1 * 0x10;
        } while (var_t1 < (s32) evs_playcnt);
    }
    #endif
}
#else
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/main1x", adjust_story_ai);
#endif
#endif

#if VERSION_US
INCLUDE_RODATA("asm/us/nonmatchings/main_segment/main1x", _seqTbl_224);
#endif

#if VERSION_US
INCLUDE_RODATA("asm/us/nonmatchings/main_segment/main1x", _demoSeqTbl_225);
#endif

#if VERSION_US
INCLUDE_RODATA("asm/us/nonmatchings/main_segment/main1x", StoryVirLv_226);
#endif

#if VERSION_US
INCLUDE_RODATA("asm/us/nonmatchings/main_segment/main1x", _charToAi_227);
#endif

#if VERSION_US
INCLUDE_RODATA("asm/us/nonmatchings/main_segment/main1x", _stageToChar_tbl_228);
#endif

#if VERSION_US
INCLUDE_RODATA("asm/us/nonmatchings/main_segment/main1x", _story4PChar_tbl_229);
#endif

#if VERSION_US
INCLUDE_RODATA("asm/us/nonmatchings/main_segment/main1x", _team_flg_230);
#endif

#if VERSION_US
INCLUDE_RODATA("asm/us/nonmatchings/main_segment/main1x", GameSize_231);
#endif

extern const u8 _seqTbl_224[];
extern const u8 _demoSeqTbl_225[];
extern const u8 StoryVirLv_226[][10];
extern const u8 _charToAi_227[];
extern const s8 _stageToChar_tbl_228[][10];
extern const s8 _story4PChar_tbl_229[][4];
extern const u8 _team_flg_230[][4];
extern const u8 GameSize_231[ENUM_EVS_GAMESEL_MAX];

#if VERSION_CN

ASM_RODATA;
const u8 _seqTbl_224[] = {
    0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x04, 0x02,
};

const u8 _demoSeqTbl_225[] = {
    0,
    1,
};

const u8 StoryVirLv_226[][10] = {
    { 0x00, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06 },
    { 0x00, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08, 0x08, 0x09, 0x09 },
    { 0x00, 0x0B, 0x0C, 0x0C, 0x0D, 0x0D, 0x0E, 0x0E, 0x0F, 0x0F },
};

const u8 _charToAi_227[] = {
    0x00, // CHARANIMEMODE_M
    0x00, // CHARANIMEMODE_N
    0x03, // CHARANIMEMODE_H
    0x01, // CHARANIMEMODE_I
    0x03, // CHARANIMEMODE_J
    0x06, // CHARANIMEMODE_D
    0x07, // CHARANIMEMODE_E
    0x04, // CHARANIMEMODE_F
    0x05, // CHARANIMEMODE_A
    0x02, // CHARANIMEMODE_B
    0x08, // CHARANIMEMODE_C
    0x09, // CHARANIMEMODE_G
    0x0A, // CHARANIMEMODE_K
    0x0B, // CHARANIMEMODE_L
    0x0B, // CHARANIMEMODE_O
};

const s8 _stageToChar_tbl_228[][10] = {
    { CHARANIMEMODE_M, CHARANIMEMODE_N, CHARANIMEMODE_I, CHARANIMEMODE_B, CHARANIMEMODE_H, CHARANIMEMODE_F,
      CHARANIMEMODE_D, CHARANIMEMODE_C, CHARANIMEMODE_K, CHARANIMEMODE_L },

    { CHARANIMEMODE_M, CHARANIMEMODE_M, CHARANIMEMODE_I, CHARANIMEMODE_B, CHARANIMEMODE_J, CHARANIMEMODE_A,
      CHARANIMEMODE_E, CHARANIMEMODE_C, CHARANIMEMODE_K, CHARANIMEMODE_O },
};

const s8 _story4PChar_tbl_229[][4] = {
    { CHARANIMEMODE_M, CHARANIMEMODE_N, CHARANIMEMODE_G, CHARANIMEMODE_C },

    { CHARANIMEMODE_N, CHARANIMEMODE_M, CHARANIMEMODE_G, CHARANIMEMODE_C },
};

const u8 _team_flg_230[][4] = {
    { 0x00, 0x01, 0x02, 0x03 },
    { 0x00, 0x01, 0x02, 0x03 },
    { 0x00, 0x01, 0x02, 0x03 },
};

const u8 GameSize_231[ENUM_EVS_GAMESEL_MAX] = {
    0x01, // ENUM_EVS_GAMESEL_0
    0x02, // ENUM_EVS_GAMESEL_1
    0x04, // ENUM_EVS_GAMESEL_2
    0x02, // ENUM_EVS_GAMESEL_3
    0x01, // ENUM_EVS_GAMESEL_4
    0x02, // ENUM_EVS_GAMESEL_5
    0x04, // ENUM_EVS_GAMESEL_6
};
#endif

/**
 * Original name: main12
 */
#if VERSION_US
#if 0
extern s8 evs_story_no;
extern s8 evs_story_level;
extern u8 D_800ACE1C[];
extern u8 D_800ACE28[];
extern u8 D_800ACE2C[][0xA];
extern s8 D_800ACE4C[];
extern u8 D_800ACE5C[][0xA];
extern s8 D_800ACE70[][4];
extern u8 D_800ACE78[][4];
extern u8 D_800ACE84[];
extern s8 evs_story_flg;

__asm__(".section .text\n");
enum_main_no main12() {
    struct_game_state_data *ptr;
    s32 arg1;
    s32 arg2;
    s32 temp_a3;
    s32 temp_v1;
    s32 var_a1_2;
    s32 i;

    evs_playcnt = D_800ACE84[evs_gamesel];

    switch (evs_gamesel) {
        case ENUM_EVS_GAMESEL_0:
            game_state_data[0].unk_04C = 0;
            evs_story_flg = 0;
            break;

        case ENUM_EVS_GAMESEL_1:
            evs_story_flg = 0;

            for (i = 1; i >= 0; i--) {
                ptr = &game_state_data[i];
                ptr->unk_04C = 0;
            }
            break;

        case ENUM_EVS_GAMESEL_2:
            for (i = 0; i < 4; i++) {
                game_state_data[i].unk_04D = D_800ACE4C[game_state_data[i].unk_090];
            }
            break;

        case ENUM_EVS_GAMESEL_3:
            if (evs_story_flg != 0) {
                temp_a3 = (story_proc_no >= STORY_PROC_NO_12);
                ptr = game_state_data;
                for (i = 0; i < 4; i++) {
                    var_a1_2 = 2;
                    if (evs_story_level < 3) {
                        var_a1_2 = evs_story_level;
                    }
                    ptr[i].unk_026 = D_800ACE2C[var_a1_2][evs_story_no];
                    ptr[i].unk_02C = 1;
                    ptr[i].unk_090 = D_800ACE5C[temp_a3][evs_story_no];
                    ptr[i].unk_04D = D_800ACE4C[ptr[i].unk_090];
                    ptr[i].unk_16C = var_a1_2;
                    ptr[i].unk_04C = 1;
                    ptr[i].unk_04E = var_a1_2;
                    ptr[i].unk_04F = D_800ACE78[var_a1_2][i];
                }

                if ((evs_story_level > 0) && (evs_story_no == 7)) {

                    evs_gamesel = ENUM_EVS_GAMESEL_2;
                    evs_playcnt = 4;

                    for (i = 0; i < 4; i++) {
                        ptr = game_state_data;

                        temp_v1 = D_800ACE70[temp_a3][i];
                        ptr[i].unk_04D = D_800ACE4C[temp_v1];
                        ptr[i].unk_090 = temp_v1;
                        if (evs_story_level < 3) {
                            ptr[i].unk_04E = 0;
                        }
                    }
                } else {
                    ptr = game_state_data;
                    evs_playcnt = 2;
                    ptr->unk_090 = temp_a3;
                }
                ptr = game_state_data;

                ptr->unk_04C = 0;
                adjust_story_ai();

                evs_seqnumb = D_800ACE1C[evs_story_no];
                evs_seqence = 1;
            } else {
                ptr = game_state_data;

                ptr[1].unk_04D = D_800ACE4C[ptr[1].unk_090];
                ptr[0].unk_04C = 0;
                ptr[1].unk_04C = 1;
            }
            break;

        case ENUM_EVS_GAMESEL_4:
            evs_playcnt = 1;
            evs_game_time = 0;
            evs_one_game_flg = 0;
            game_state_data[0].unk_04D = D_800ACE4C[0];
            game_state_data[0].unk_000 = 0;
            game_state_data[0].unk_04B = 0;
            game_state_data[0].unk_04C = 1;
            game_state_data[0].unk_04E = 1;
            game_state_data[0].unk_026 = 0xA;
            game_state_data[0].unk_02C = 1;
            game_state_data[0].unk_090 = 0;
            evs_seqence = 1;

            evs_seqnumb = D_800ACE28[rand() & 2];
            break;

        case ENUM_EVS_GAMESEL_5:
            evs_playcnt = 2;
            evs_story_flg = 0;
            evs_one_game_flg = 0;
            for (i = 0; i < 2; i++) {
                evs_select_name_no[i] = 8;
                ptr = game_state_data;

                do {
                    game_state_data[i].unk_090 = genrand(0xD);

                    arg2 = 0;
                    for (arg1 = 0; arg1 < 2; arg1++) {
                        if (i != arg1) {
                            arg2 += game_state_data[i].unk_090 == game_state_data[arg1].unk_090;
                        }
                    }
                } while (arg2 != 0);

                game_state_data[i].unk_04D = D_800ACE4C[game_state_data[i].unk_090];
                game_state_data[i].unk_04B = i;
                game_state_data[i].unk_000 = 0;
                game_state_data[i].unk_04C = 1;
                game_state_data[i].unk_04E = 1;
                game_state_data[i].unk_02C = 1;
                game_state_data[i].unk_026 = 0xA;
            }

            evs_seqence = 1;
            evs_seqnumb = D_800ACE28[rand() & 2];
            break;

        case ENUM_EVS_GAMESEL_6:
            evs_playcnt = 4;
            evs_story_flg = 0;
            evs_one_game_flg = 0;
            for (i = 0; i < 4; i++) {
                do {
                    game_state_data[i].unk_090 = genrand(0xD);

                    arg2 = 0;
                    for (arg1 = 0; arg1 < 4; arg1++) {
                        if (i != arg1) {
                            arg2 += game_state_data[i].unk_090 == game_state_data[arg1].unk_090;
                        }
                    }
                } while (arg2 != 0);

                game_state_data[i].unk_04D = D_800ACE4C[game_state_data[i].unk_090];
                game_state_data[i].unk_04C = 1;
                game_state_data[i].unk_04E = 1;
                game_state_data[i].unk_02C = 1;
                game_state_data[i].unk_000 = 0;
                game_state_data[i].unk_04B = i;
                game_state_data[i].unk_04F = i;
                game_state_data[i].unk_026 = 0xA;
            }
            evs_seqence = 1;
            evs_seqnumb = D_800ACE28[rand() & 2];
            break;
    }

    return MAIN_NO_5;
}
#else
INCLUDE_ASM("asm/us/nonmatchings/main_segment/main1x", main12);
#endif
#endif

#if VERSION_CN
extern s32 B_800CA2B8_cn;
extern s8 D_8009321E_cn;

enum_main_no main12(void) {
    enum_main_no ret;
    s32 i;
    s32 var_a1_3;
    s32 j;

    evs_playcnt = GameSize_231[evs_gamesel];

    switch (evs_gamesel) {
        case ENUM_EVS_GAMESEL_0:
            game_state_data[0].unk_04C = 0;
            evs_story_flg = 0;
            ret = MAIN_NO_5;
            break;

        case ENUM_EVS_GAMESEL_1:
            ret = MAIN_NO_5;
            evs_story_flg = 0;
            for (i = 0; i < 2; i++) {
                game_state_data[i].unk_04C = 0;
            }
            break;

        case ENUM_EVS_GAMESEL_2:
            for (i = 0; i < 4; i++) {
                game_state_data[i].unk_04D = _charToAi_227[game_state_data[i].unk_090];
            }
            ret = MAIN_NO_5;
            break;

        case ENUM_EVS_GAMESEL_3:
            if (evs_story_flg != 0) {
                s32 temp_s2 = ((s32)story_proc_no >= 0xC);

                for (i = 0; i < 4; i++) {
                    CharAnimeMode temp_a0;

                    j = MIN(ARRAY_COUNT(StoryVirLv_226) - 1, evs_story_level);

                    game_state_data[i].unk_026 = StoryVirLv_226[j][evs_story_no];
                    temp_a0 = _stageToChar_tbl_228[temp_s2][evs_story_no];
                    game_state_data[i].unk_02C = 1;
                    game_state_data[i].unk_090 = temp_a0;
                    game_state_data[i].unk_04C = 1;
                    game_state_data[i].unk_04E = j;
                    game_state_data[i].unk_04D = _charToAi_227[temp_a0];
                    game_state_data[i].unk_04F = _team_flg_230[j][i];
                    game_state_data[i].unk_16C = j;
                }

                if ((evs_story_level > 0) && (evs_story_no == 7)) {
                    evs_gamesel = ENUM_EVS_GAMESEL_2;
                    evs_playcnt = 4;

                    for (i = 0; i < 4; i++) {
                        struct_game_state_data *ptr = game_state_data;
                        CharAnimeMode temp_v0_2 = _story4PChar_tbl_229[temp_s2][i];

                        ptr[i].unk_090 = temp_v0_2;
                        ptr[i].unk_04D = _charToAi_227[temp_v0_2];
                        if (evs_story_level < 3) {
                            ptr[i].unk_04E = 0;
                        }
                    }

                    game_state_data[0].unk_04C = 0;
                } else {
                    evs_playcnt = 2;
                    game_state_data[0].unk_090 = temp_s2;
                    game_state_data[0].unk_04C = 0;
                }

                adjust_story_ai();
                evs_seqence = 1;
                evs_seqnumb = _seqTbl_224[evs_story_no];
            } else {
                game_state_data[0].unk_04C = 0;
                game_state_data[1].unk_04C = 1;
                game_state_data[1].unk_04D = _charToAi_227[game_state_data[1].unk_090];
            }

            ret = MAIN_NO_5;
            break;

        case ENUM_EVS_GAMESEL_4:
            evs_playcnt = 1;
            B_800CA2B8_cn = 0;
            D_8009321E_cn = 0;
            game_state_data->unk_000 = 0;
            game_state_data->unk_04B = 0;
            game_state_data->unk_04C = 1;
            game_state_data->unk_04E = 1;
            game_state_data->unk_026 = 0xA;
            game_state_data->unk_02C = 1;
            game_state_data->unk_090 = CHARANIMEMODE_M;
            evs_seqence = 1;
            game_state_data->unk_04D = _charToAi_227[0];
            evs_seqnumb = _demoSeqTbl_225[rand() & 2];
            ret = MAIN_NO_5;
            break;

        case ENUM_EVS_GAMESEL_5:
            evs_playcnt = 2;
            evs_story_flg = 0;
            D_8009321E_cn = 0;

            for (i = 0; i < 2; i++) {
                evs_select_name_no[i] = 8;

                do {
                    game_state_data[i].unk_090 = genrand(0xD);
                    var_a1_3 = 0;

                    for (j = 0; j < 2; j++) {
                        if ((i != j) && (game_state_data[i].unk_090 == game_state_data[j].unk_090)) {
                            var_a1_3++;
                        }
                    }

                } while (var_a1_3 != 0);

                game_state_data[i].unk_000 = CHARANIMEMODE_M;
                game_state_data[i].unk_04B = i;
                game_state_data[i].unk_04C = 1;
                game_state_data[i].unk_04D = _charToAi_227[game_state_data[i].unk_090];
                game_state_data[i].unk_04E = 1;
                game_state_data[i].unk_026 = 0xA;
                game_state_data[i].unk_02C = 1;
            }

            evs_seqence = 1;
            evs_seqnumb = _demoSeqTbl_225[rand() & 2];
            ret = MAIN_NO_5;
            break;

        case ENUM_EVS_GAMESEL_6:
            evs_playcnt = 4;
            evs_story_flg = 0;
            D_8009321E_cn = 0;

            for (i = 0; i < 4; i++) {
                do {
                    game_state_data[i].unk_090 = genrand(0xD);
                    var_a1_3 = 0;

                    for (j = 0; j < 4; j++) {
                        if ((i != j) && (game_state_data[i].unk_090 == game_state_data[j].unk_090)) {
                            var_a1_3++;
                        }
                    }
                } while (var_a1_3 != 0);

                game_state_data[i].unk_000 = CHARANIMEMODE_M;
                game_state_data[i].unk_04B = i;
                game_state_data[i].unk_04C = 1;
                game_state_data[i].unk_04D = _charToAi_227[game_state_data[i].unk_090];
                game_state_data[i].unk_04E = 1;
                game_state_data[i].unk_04F = i;
                game_state_data[i].unk_026 = 0xA;
                game_state_data[i].unk_02C = 1;
            }

            evs_seqence = 1;
            evs_seqnumb = _demoSeqTbl_225[rand() & 2];
            ret = MAIN_NO_5;
            break;

        default:
            UNREACHABLE;
            break;
    }

    return ret;
}
#endif
