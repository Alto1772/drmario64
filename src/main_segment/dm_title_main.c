#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "boot_functions.h"
#include "boot_variables.h"
#include "main_segment_functions.h"
#include "main_segment_variables.h"
#include "rom_offsets.h"
#include "audio/audio_stuff.h"
#include "buffers.h"

void func_80075F30(void) {
    title_exit_flag = 0;
    B_800E59A0 = 0;
    B_800E59A8 = -8;
    D_80088401 = 0;
    title_fade_count = -(B_800EB4F0 == MAIN_NO_6) & 0xFF;
    func_80077FA4(&Gzip_bufferp, B_800EB4F0 != MAIN_NO_6);
}

/**
 * Original name: _stageTbl
 */
const u8 _stageTbl[] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
};

enum_main_no dm_title_main(struct_800EB670 *arg0) {
    OSMesgQueue sp10;
    OSMesg sp28[8];
    struct_800FAF98_unk_64 sp48;
    u32 var_s0 = 0;
    s32 var_s1 = -(B_800EB4F0 == MAIN_NO_6) & 0x63;

    osCreateMesgQueue(&sp10, sp28, ARRAY_COUNT(sp28));
    func_8002A184(arg0, &sp48, &sp10);
    func_8002E830(osGetCount());
    func_80075F30();
    evs_playmax = joyResponseCheck();
    osRecvMesg(&sp10, NULL, 1);
    graphic_no = 2;

    while (var_s0 == 0) {
        joyProcCore();
        osRecvMesg(&sp10, NULL, 1);

        title_fade_count = CLAMP(title_fade_count + B_800E59A8, 0, 0xFF);

        switch (B_800E59A0) {
            case 0:
                var_s1++;
                if (title_exit_flag == -1) {
                    B_800E59A0 = 7;
                } else {
                    if (var_s1 == 0x64) {
                        func_8002AFC4(0xB);
                    }
                    if (title_exit_flag == 1) {
                        B_800E59A0 = 6;
                    }
                }
                break;

            case 6:
            case 7:
                B_800E59A8 = -B_800E59A8;
                if (B_800E59A0 == 6) {
                    var_s0 = 1;
                } else if (B_800E59A0 == 7) {
                    var_s0 = 2;
                }
                break;
        }

        func_8002AE58();
    }

    func_8002B0E4();

    while (!func_8002AFA4() || (title_fade_count < 0xFF)) {
        osRecvMesg(&sp10, NULL, 1);
        func_8002AE58();

        title_fade_count = CLAMP(title_fade_count + B_800E59A8, 0, 0xFF);
    }

    graphic_no = 0;
    while (D_80088128 != 0) {
        osRecvMesg(&sp10, NULL, 1);
        func_8002AE58();
    }

    func_8002A1DC(arg0, &sp48);

    if (var_s0 == 1) {
        return MAIN_NO_6;
    }

    if (var_s0 != 2) {
        return MAIN_NO_2;
    }

    if (D_800A7390 == MAIN_NO_0) {
        u32 temp = rand();

        story_proc_no = _stageTbl[temp % ARRAY_COUNT(_stageTbl)];

        if (title_demo_no == 0) {
            evs_gamesel = 4;
        } else if (title_demo_no == 1) {
            evs_gamesel = 5;
        } else if (title_demo_no == 2) {
            evs_gamesel = 6;
        }

        B_801236F0 = 0;

        title_demo_no++;
        if (title_demo_no >= 3) {
            title_demo_no = 0;
        }
        D_800A7390 ^= 1;
        return MAIN_NO_1;
    }

    if (D_800A7390 == MAIN_NO_1) {
        D_80088410 = D_800A7398;

        D_800A7398++;
        if (D_800A7398 >= 4) {
            D_800A7398 = 0;
        }
        D_800A7390 = MAIN_NO_0;
        return MAIN_NO_4;
    }

    return D_800A7390;
}

/**
 * Original name: dm_title_graphic
 */
void dm_title_graphic(void) {
    s32 color;
    s32 alpha;
    OSScTask *ptr;

    gGfxHead = gGfxGlist[gCurrentFramebufferIndex];

    ptr = &B_800FAE80[gCurrentFramebufferIndex];
    gSPSegment(gGfxHead++, 0x00, NULL);
    S2RDPinitRtn(true);
    S2ClearCFBRtn(true);

    gSPDisplayList(gGfxHead++, D_800881E0);
    gDPSetScissor(gGfxHead++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);

    title_exit_flag = demo_title(&gGfxHead, evs_level_21 != 0);

    color = 255;
    alpha = CLAMP(((title_fade_count - 127) * 1.2) + 127.0, 0.0, 255.0);
    if (alpha > 0) {
        FillRectRGBA(&gGfxHead, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, color, color, color, alpha);
    }

    gDPFullSync(gGfxHead++);
    gSPEndDisplayList(gGfxHead++);
    osWritebackDCacheAll();

    gfxTaskStart(ptr, gGfxGlist[gCurrentFramebufferIndex], (gGfxHead - gGfxGlist[gCurrentFramebufferIndex]) * sizeof(Gfx), 0, OS_SC_SWAPBUFFER);
}

const char D_800B32A8[] RODATA = "This game is not designed~nfor use on this system.~z";

/**
 * Original name: _mesBootContErr
 */
const char _mesBootContErr[] RODATA = "There is no controller~nconnected. Please turn OFF~nthe Nintendo* 64 and insert~na controller in socket 1.~z";

/**
 * Original name: _mesBootCSumErr
 */
const char _mesBootCSumErr[] RODATA = "A Backup File is damaged.~nPress the A Button to delete this file.~z";

/**
 * Original name: main_boot_error
 */
enum_main_no main_boot_error(struct_800EB670 *arg0) {
    OSMesgQueue sp18;
    OSMesg sp30[8];
    struct_800FAF98_unk_64 sp50;
    UNK_PTR sp58;
    struct_800E5A70 *temp_s0 = ALIGN_PTR(Gzip_bufferp);
    bool var_s1 = true;

    sp58 = &temp_s0[1];
    bzero(temp_s0, sizeof(struct_800E5A70));
    osCreateMesgQueue(&sp18, sp30, ARRAY_COUNT(sp30));
    func_8002A184(arg0, &sp50, &sp18);

    switch (main_no) {
        case MAIN_NO_8:
            msgWnd_init(temp_s0, &sp58, 0x40, 5, 0x40, 0x60);
            msgWnd_addStr(temp_s0, _mesBootContErr);
            break;

        case MAIN_NO_9:
            msgWnd_init(temp_s0, &sp58, 0x40, 5, 0x40, 0x72);
            msgWnd_addStr(temp_s0, D_800B32A8);
            break;

        case MAIN_NO_10:
            msgWnd_init(temp_s0, &sp58, 0x40, 5, 0x28, 0x6C);
            msgWnd_addStr(temp_s0, _mesBootCSumErr);
            break;

        default:
            break;
    }

    msgWnd_skip(temp_s0);

    while (var_s1) {
        joyProcCore();
        osRecvMesg(&sp18, NULL, OS_MESG_BLOCK);
        func_8005D428(temp_s0);
        if ((main_no == MAIN_NO_10) && (gControllerPressedButtons[B_800EBD16[0]] & A_BUTTON)) {
            var_s1 = false;
            dm_snd_play(0x46);
        }
        func_8002AE58();
        graphic_no = 7;
    }

    graphic_no = 0;
    while (D_80088128 != 0) {
        osRecvMesg(&sp18, NULL, OS_MESG_BLOCK);
    }

    func_8002A1DC(arg0, &sp50);
    if (main_no == MAIN_NO_10) {
        EepRom_WriteAll(0, 0);
    }
    return MAIN_NO_3;
}

/**
 * Original name: graphic_boot_error
 */
void graphic_boot_error(void) {
    struct_8005D78C_arg0 *ptr;

    gGfxHead = gGfxGlist[B_800FAD2C];
    ptr = ALIGN_PTR(&Gzip_bufferp);
    F3RCPinitRtn();
    F3ClearFZRtn(true);
    msgWnd_draw(ptr, &gGfxHead);

    gDPFullSync(gGfxHead++);
    gSPEndDisplayList(gGfxHead++);

    osWritebackDCacheAll();
    gfxTaskStart(&B_800FAE80[B_800FAD2C], gGfxGlist[B_800FAD2C], (gGfxHead - gGfxGlist[B_800FAD2C]) * sizeof(Gfx), 0, OS_SC_SWAPBUFFER);
}
