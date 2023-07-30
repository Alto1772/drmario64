/**
 * Original filename: tex_func.c
 */

#include "tex_func.h"
#include "include_asm.h"
#include "unk.h"
#include "macros_defines.h"
#include "boot_functions.h"
#include "boot_variables.h"
#include "main_segment_functions.h"
#include "main_segment_variables.h"

#if VERSION_US || VERSION_CN
Gfx D_8008E5E0[] = {
#include "main_segment/tex_func/D_8008E5E0.gfx.inc.c"
};

Gfx alpha_texture_init_dl[] = {
#include "main_segment/tex_func/alpha_texture_init_dl.gfx.inc.c"
};

Gfx normal_texture_init_dl[] = {
#include "main_segment/tex_func/normal_texture_init_dl.gfx.inc.c"
};

Gfx D_8008E728[] = {
#include "main_segment/tex_func/D_8008E728.gfx.inc.c"
};

Gfx init_dl_155[] = {
#include "main_segment/tex_func/init_dl_155.gfx.inc.c"
};

#endif

#if VERSION_US
/**
 * Original name: _modes_96
 */
const s32 _modes_96[] = { G_SC_ODD_INTERLACE, G_SC_EVEN_INTERLACE, G_SC_NON_INTERLACE, G_SC_NON_INTERLACE };

/**
 * Original name: gfxSetScissor
 */
void gfxSetScissor(Gfx **gfxP, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    struct {
        s32 ulx;
        s32 uly;
        s32 lrx;
        s32 lry;
    } corners;
    Gfx *gfx = *gfxP;

    corners.ulx = CLAMP(arg2, 0, 0x13F);
    corners.uly = CLAMP(arg3, 0, 0xEF);
    corners.lrx = CLAMP(arg2 + arg4 - 1, 0, 0x13F);
    corners.lry = CLAMP(arg3 + arg5 - 1, 0, 0xEF);

    gDPSetScissor(gfx++, _modes_96[arg1 % ARRAY_COUNTU(_modes_96)], corners.ulx, corners.uly, corners.lrx, corners.lry);

    *gfxP = gfx;
}
#endif

#if VERSION_CN
INCLUDE_RODATA("asm/cn/nonmatchings/main_segment/tex_func", _modes_96);

INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", gfxSetScissor);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80040D34);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80043274_cn);
#endif

#if VERSION_US || VERSION_CN
/**
 * Original name: FillRectRGBA
 */
void FillRectRGBA(Gfx **gfxP, s32 x0, s32 y0, s32 x1, s32 y1, s32 red, s32 green, s32 blue, s32 alpha) {
    Gfx *gfx = *gfxP;

    gSPDisplayList(gfx++, init_dl_155);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gDPScisFillRectangle(gfx++, x0, y0, x0 + x1, y0 + y1);

    *gfxP = gfx;
}
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80040F34);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_8004113C);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80041334);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80041480);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80041668);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_800417B4);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", CopyTexBlock16);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80043444_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80043634_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_8004383C_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_800439B0_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80043BA8_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80043D1C_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80043F14_cn);
#endif

#if VERSION_US || VERSION_CN
/**
 * Original name: StretchTexBlock
 */
void StretchTexBlock(StretchTexBlock_arg0 *arg0) {
    s32 sp18[2];
    StretchTexBlock_arg0_unk_4C *temp_s0;
    s32 var_a3;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v0_3;
    s32 var_v1;

    if (arg0->unk_28 < 0) {
        var_a3 = -arg0->unk_28;
        sp18[0] = -1;
    } else if (arg0->unk_28 > 0) {
        var_a3 = arg0->unk_28;
        sp18[0] = 1;
    } else {
        return;
    }

    if (arg0->unk_2C < 0) {
        var_s2 = -arg0->unk_2C;
        sp18[1] = -1;
    } else if (arg0->unk_2C > 0) {
        var_s2 = arg0->unk_2C;
        sp18[1] = 1;
    } else {
        return;
    }

    if ((arg0->unk_04 == 0) && (var_a3 == (arg0->unk_08 << 2)) && (var_s2 == (arg0->unk_0C << 2))) {
        gDPSetTextureFilter((*arg0->gfxP)++, G_TF_POINT);
        var_s4 = 0;
        var_s3 = arg0->unk_38;
    } else {
        gDPSetTextureFilter((*arg0->gfxP)++, G_TF_BILERP);
        var_s4 = -1;
        var_s3 = MAX(arg0->unk_38 - 1, 1);
    }

    temp_s0 = &arg0->unk_4C;

    arg0->unk_4C.unk_00 = arg0->unk_20;
    temp_s0->unk_08 = arg0->unk_20 + var_a3;

    if (sp18[0] < 0) {
        var_v0_3 = (arg0->unk_08 - 1) << 5;
    } else {
        var_v0_3 = 0;
    }
    temp_s0->unk_10 = var_v0_3;

    temp_s0->unk_18 = ((sp18[0] << 0xC) * arg0->unk_08) / var_a3;

    for (arg0->unk_40 = 0; arg0->unk_40 < arg0->unk_0C; arg0->unk_40 += var_s3) {
        arg0->unk_44 = MIN(arg0->unk_40 + arg0->unk_38, arg0->unk_0C);
        arg0->unk_48 = arg0->unk_44 - arg0->unk_40;
        if (arg0->unk_10 != NULL) {
            arg0->unk_30(arg0);
        }
        if (arg0->unk_18 != NULL) {
            arg0->unk_34(arg0);
        }

        if (sp18[1] < 0) {
            temp_s0->unk_04 = arg0->unk_0C - arg0->unk_44;
            temp_s0->unk_0C = arg0->unk_0C - arg0->unk_40;
            temp_s0->unk_14 = arg0->unk_48 - 1;
        } else {
            temp_s0->unk_04 = arg0->unk_40;
            temp_s0->unk_0C = arg0->unk_44;
            temp_s0->unk_14 = 0;
        }

        temp_s0->unk_04 = arg0->unk_24 + (((temp_s0->unk_04 << 2) * var_s2) / (arg0->unk_0C << 2));
        temp_s0->unk_0C = arg0->unk_24 + (((temp_s0->unk_0C << 2) * var_s2) / (arg0->unk_0C << 2));
        temp_s0->unk_14 = temp_s0->unk_14 << 5;
        temp_s0->unk_1C = (sp18[1] << 0xC) * arg0->unk_0C / var_s2;

        var_v1 = temp_s0->unk_1C;
        if (var_v1 < 0) {
            var_v1 += 0x3F;
        }
        temp_s0->unk_14 -= (var_v1 >> 6) & var_s4;

        arg0->unk_3C(arg0);
    }
}
#endif

#if VERSION_US || VERSION_CN
void StretchTexBlock_ScisRect(StretchTexBlock_arg0 *arg0) {
    StretchTexBlock_arg0_unk_4C *temp_a2 = &arg0->unk_4C;

    gSPScisTextureRectangle((*arg0->gfxP)++, temp_a2->unk_00, temp_a2->unk_04, temp_a2->unk_08, temp_a2->unk_0C,
                            G_TX_RENDERTILE, temp_a2->unk_10, temp_a2->unk_14, temp_a2->unk_18, temp_a2->unk_1C);
}
#endif

#if VERSION_US || VERSION_CN
void StretchAlphaTexBlock_LoadColorTex(StretchTexBlock_arg0 *arg0) {
    gDPLoadTextureBlock((*arg0->gfxP)++, (u16 *)arg0->unk_10 + (arg0->unk_14 * arg0->unk_40), G_IM_FMT_RGBA,
                        G_IM_SIZ_16b, arg0->unk_14, arg0->unk_48, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}
#endif

#if VERSION_US || VERSION_CN
void StretchAlphaTexBlock_LoadAlphaTex(StretchTexBlock_arg0 *arg0) {
    gDPLoadMultiBlock_4b((*arg0->gfxP)++, arg0->unk_18 + (arg0->unk_1C * arg0->unk_40) / 2, 0x19A, 1, G_IM_FMT_I,
                         arg0->unk_1C, arg0->unk_48, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}
#endif

#if VERSION_US || VERSION_CN
void StretchAlphaTexBlock(Gfx **gfxP, s32 arg1, s32 arg2, TexturePtr arg3, s32 arg4, TexturePtr arg5, s32 arg6, f32 arg7,
                          f32 arg8, f32 arg9, f32 argA) {
    StretchTexBlock_arg0 sp18;

    sp18.gfxP = gfxP;
    sp18.unk_04 = 0;
    sp18.unk_08 = arg1;
    sp18.unk_20 = arg7 * 4.0;
    sp18.unk_24 = arg8 * 4.0;
    sp18.unk_28 = arg9 * 4.0;
    sp18.unk_2C = argA * 4.0;
    sp18.unk_0C = arg2;
    sp18.unk_10 = arg3;
    sp18.unk_30 = StretchAlphaTexBlock_LoadColorTex;
    sp18.unk_34 = StretchAlphaTexBlock_LoadAlphaTex;
    sp18.unk_14 = arg4;
    sp18.unk_18 = arg5;
    sp18.unk_1C = arg6;

    sp18.unk_38 = 0x660 / MAX(arg4, arg6);
    sp18.unk_3C = StretchTexBlock_ScisRect;

    StretchTexBlock(&sp18);
}
#endif

#if VERSION_US || VERSION_CN
void StretchTexBlock4_LoadTex(StretchTexBlock_arg0 *arg0) {
    gDPLoadTextureBlock_4b((*arg0->gfxP)++, arg0->unk_10 + ((arg0->unk_14 * arg0->unk_40) / 2), G_IM_FMT_CI,
                           arg0->unk_14, arg0->unk_48, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}
#endif

#if VERSION_US || VERSION_CN
void StretchTexBlock4(Gfx **gfxP, s32 arg1, s32 arg2, TexturePtr tlut, UNK_PTR arg4, f32 arg5, f32 arg6, f32 arg7,
                      f32 arg8) {
    StretchTexBlock_arg0 sp10;

    sp10.gfxP = gfxP;
    sp10.unk_04 = 0;
    sp10.unk_08 = arg1;
    sp10.unk_0C = arg2;
    sp10.unk_14 = arg1;
    sp10.unk_18 = 0;
    sp10.unk_1C = 0;
    sp10.unk_34 = NULL;
    sp10.unk_30 = StretchTexBlock4_LoadTex;
    sp10.unk_3C = StretchTexBlock_ScisRect;
    sp10.unk_10 = arg4;
    sp10.unk_20 = arg5 * 4.0;
    sp10.unk_24 = arg6 * 4.0;
    sp10.unk_28 = arg7 * 4.0;
    sp10.unk_2C = arg8 * 4.0;
    sp10.unk_38 = 0x1000 / arg1;
    if (tlut != NULL) {
        gDPLoadTLUT_pal16((*gfxP)++, 0, tlut);
    }
    StretchTexBlock(&sp10);
}
#endif

#if VERSION_US
void func_800427E0(StretchTexBlock_arg0 *arg0) {
    gDPLoadTextureBlock((*arg0->gfxP)++, arg0->unk_10 + (arg0->unk_14 * arg0->unk_40), G_IM_FMT_CI, G_IM_SIZ_8b,
                        arg0->unk_14, arg0->unk_48, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80044D8C_cn);
#endif

#if VERSION_US
void func_800429B8(Gfx **gfxP, s32 arg1, s32 arg2, TexturePtr tlut, UNK_PTR arg4, f32 arg5, f32 arg6, f32 arg7,
                   f32 arg8) {
    StretchTexBlock_arg0 sp10;

    sp10.gfxP = gfxP;
    sp10.unk_04 = 0;
    sp10.unk_30 = func_800427E0;
    sp10.unk_08 = arg1;
    sp10.unk_0C = arg2;
    sp10.unk_14 = arg1;
    sp10.unk_18 = 0;
    sp10.unk_1C = 0;
    sp10.unk_34 = NULL;
    sp10.unk_3C = StretchTexBlock_ScisRect;
    sp10.unk_10 = arg4;
    sp10.unk_20 = arg5 * 4.0;
    sp10.unk_24 = arg6 * 4.0;
    sp10.unk_28 = arg7 * 4.0;
    sp10.unk_2C = arg8 * 4.0;
    sp10.unk_38 = 0x800 / arg1;
    if (tlut != NULL) {
        gDPLoadTLUT_pal256((*gfxP)++, tlut);
    }
    StretchTexBlock(&sp10);
}
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80044F74_cn);
#endif

#if VERSION_US
void func_80042B48(StretchTexBlock_arg0 *arg0) {
    gDPLoadTextureBlock((*arg0->gfxP)++, (u16 *)arg0->unk_10 + (arg0->unk_14 * arg0->unk_40), G_IM_FMT_RGBA,
                        G_IM_SIZ_16b, arg0->unk_14, arg0->unk_48, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_8004512C_cn);
#endif

#if VERSION_US
void func_80042D20(Gfx **gfxP, s32 arg1, s32 arg2, UNK_PTR arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    StretchTexBlock_arg0 sp10;

    sp10.gfxP = gfxP;
    sp10.unk_30 = func_80042B48;
    sp10.unk_04 = 0;
    sp10.unk_08 = arg1;
    sp10.unk_0C = arg2;
    sp10.unk_10 = arg3;
    sp10.unk_14 = arg1;
    sp10.unk_18 = 0;
    sp10.unk_1C = 0;
    sp10.unk_34 = NULL;
    sp10.unk_3C = StretchTexBlock_ScisRect;
    sp10.unk_20 = arg4 * 4.0;
    sp10.unk_24 = arg5 * 4.0;
    sp10.unk_28 = arg6 * 4.0;
    sp10.unk_2C = arg7 * 4.0;
    sp10.unk_38 = 0x800 / arg1;
    StretchTexBlock(&sp10);
}
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80045314_cn);
#endif

#if VERSION_US || VERSION_CN
void StretchTexBlock4i_LoadTex(StretchTexBlock_arg0 *arg0) {
    gDPLoadTextureBlock_4b((*arg0->gfxP)++, arg0->unk_10 + (arg0->unk_14 * arg0->unk_40) / 2, G_IM_FMT_I, arg0->unk_14,
                           arg0->unk_48, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}
#endif

#if VERSION_US || VERSION_CN
/**
 * Original name: StretchTexBlock4i
 */
void StretchTexBlock4i(Gfx **gfxP, s32 arg1, s32 arg2, void *arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    StretchTexBlock_arg0 sp10;

    sp10.gfxP = gfxP;
    sp10.unk_04 = 0;
    sp10.unk_08 = arg1;
    sp10.unk_0C = arg2;
    sp10.unk_10 = arg3;
    sp10.unk_14 = arg1;
    sp10.unk_18 = NULL;
    sp10.unk_1C = 0;
    sp10.unk_30 = StretchTexBlock4i_LoadTex;
    sp10.unk_34 = NULL;
    sp10.unk_3C = StretchTexBlock_ScisRect;
    sp10.unk_20 = arg4 * 4.0;
    sp10.unk_24 = arg5 * 4.0;
    sp10.unk_28 = arg6 * 4.0;
    sp10.unk_2C = arg7 * 4.0;
    sp10.unk_38 = 0x2000 / arg1;

    StretchTexBlock(&sp10);
}
#endif

#if VERSION_US
void func_800430D0(StretchTexBlock_arg0 *arg0) {
    gDPLoadTextureBlock((*arg0->gfxP)++, arg0->unk_10 + (arg0->unk_14 * arg0->unk_40), G_IM_FMT_I, G_IM_SIZ_8b,
                        arg0->unk_14, arg0->unk_48, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_800456F4_cn);
#endif

#if VERSION_US
void func_800432A8(Gfx **gfxP, s32 arg1, s32 arg2, UNK_PTR arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    StretchTexBlock_arg0 sp10;

    sp10.gfxP = gfxP;
    sp10.unk_30 = func_800430D0;
    sp10.unk_04 = 0;
    sp10.unk_08 = arg1;
    sp10.unk_0C = arg2;
    sp10.unk_10 = arg3;
    sp10.unk_14 = arg1;
    sp10.unk_18 = 0;
    sp10.unk_1C = 0;
    sp10.unk_34 = NULL;
    sp10.unk_3C = StretchTexBlock_ScisRect;
    sp10.unk_20 = arg4 * 4.0;
    sp10.unk_24 = arg5 * 4.0;
    sp10.unk_28 = arg6 * 4.0;
    sp10.unk_2C = arg7 * 4.0;
    sp10.unk_38 = 0x1000 / arg1;

    StretchTexBlock(&sp10);
}
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_800458DC_cn);
#endif

#if VERSION_US || VERSION_CN
void StretchTexTile(StretchTexTile_arg0 *arg0) {
    s32 sp18[2];
    StretchTexTile_arg0_unk_58 *temp_s0;
    s32 temp_s2;
    s32 var_a3;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_v1;
    s32 v0;
    s32 t0;

    if (arg0->unk_38 < 0) {
        var_a3 = -arg0->unk_38;
        sp18[0] = -1;
    } else if (arg0->unk_38 > 0) {
        var_a3 = arg0->unk_38;
        sp18[0] = 1;
    } else {
        return;
    }

    if (arg0->unk_3C < 0) {
        var_s3 = -arg0->unk_3C;
        sp18[1] = -1;
    } else if (arg0->unk_3C > 0) {
        var_s3 = arg0->unk_3C;
        sp18[1] = 1;
    } else {
        return;
    }

    v0 = arg0->unk_20;
    t0 = v0 + arg0->unk_28;
    temp_s2 = arg0->unk_24 + arg0->unk_2C;
    if ((arg0->unk_04 == 0) && (var_a3 == (arg0->unk_28 << 2)) && (var_s3 == (arg0->unk_2C << 2))) {
        gDPSetTextureFilter((*arg0->gfxP)++, G_TF_POINT);
        var_s5 = 0;
        var_s4 = arg0->unk_48;
    } else {
        gDPSetTextureFilter((*arg0->gfxP)++, G_TF_BILERP);
        var_s5 = -1;
        var_s4 = MAX(arg0->unk_48 - 1, 1);
    }

    temp_s0 = &arg0->unk_58;

    arg0->unk_58.unk_00 = arg0->unk_30;
    temp_s0->unk_08 = arg0->unk_30 + var_a3;

    temp_s0->unk_10 = ((sp18[0] < 0) ? (t0 - 1) : arg0->unk_20) << 5;

    temp_s0->unk_18 = ((sp18[0] << 0xC) * arg0->unk_28) / var_a3;

    for (arg0->unk_50 = arg0->unk_24; arg0->unk_50 < temp_s2; arg0->unk_50 += var_s4) {
        arg0->unk_54 = MIN(arg0->unk_50 + arg0->unk_48, temp_s2);

        if (arg0->unk_10 != NULL) {
            arg0->unk_40(arg0);
        }

        if (arg0->unk_18 != NULL) {
            arg0->unk_44(arg0);
        }

        if (sp18[1] < 0) {
            temp_s0->unk_04 = temp_s2 - arg0->unk_54;
            temp_s0->unk_0C = temp_s2 - arg0->unk_50;
            temp_s0->unk_14 = arg0->unk_54 - 1;
        } else {
            temp_s0->unk_04 = arg0->unk_50;
            temp_s0->unk_0C = arg0->unk_54;
            temp_s0->unk_14 = arg0->unk_50;
        }

        temp_s0->unk_04 = arg0->unk_34 + ((((temp_s0->unk_04 - arg0->unk_24) << 2) * var_s3) / (s32) (arg0->unk_2C << 2));
        temp_s0->unk_0C = arg0->unk_34 + ((((temp_s0->unk_0C - arg0->unk_24) << 2) * var_s3) / (s32) (arg0->unk_2C << 2));

        temp_s0->unk_14 = temp_s0->unk_14 << 5;
        temp_s0->unk_1C = ((sp18[1] << 0xC) * arg0->unk_2C) / var_s3;

        var_v1 = temp_s0->unk_1C;
        if (var_v1 < 0) {
            var_v1 += 0x3F;
        }
        temp_s0->unk_14 -= (var_v1 >> 6) & var_s5;

        arg0->unk_4C(arg0);
    }
}
#endif

#if VERSION_US || VERSION_CN
void StretchTexTile_ScisRect(StretchTexTile_arg0 *arg0) {
    StretchTexTile_arg0_unk_58 *temp_a2 = &arg0->unk_58;

    gSPScisTextureRectangle((*arg0->gfxP)++, temp_a2->unk_00, temp_a2->unk_04, temp_a2->unk_08, temp_a2->unk_0C,
                            G_TX_RENDERTILE, temp_a2->unk_10, temp_a2->unk_14, temp_a2->unk_18, temp_a2->unk_1C);
}
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_800438D0);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80045EE0_cn);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", StretchAlphaTexTile_LoadColorTex);
#endif

#if VERSION_CN
#if 0
void StretchAlphaTexTile_LoadColorTex(StretchTexTile_arg0 *arg0) {
    Gfx **temp_a1;
    Gfx **temp_a1_2;
    Gfx **temp_a1_3;
    Gfx **temp_a2;
    Gfx **temp_a2_2;
    Gfx **temp_a2_3;
    Gfx **temp_a2_4;
    Gfx *temp_v0;
    Gfx *temp_v0_2;
    Gfx *temp_v1;
    Gfx *temp_v1_2;
    Gfx *temp_v1_3;
    Gfx *temp_v1_4;
    Gfx *temp_v1_5;

    temp_a1 = arg0->gfxP;
    temp_v1 = *temp_a1;
    *temp_a1 = temp_v1 + 8;
    temp_v1->words.w0 = ((arg0->unk_14 - 1) & 0xFFF) | 0xFD100000;
    temp_v1->words.w1 = (u32) arg0->unk_10;
    temp_a2 = arg0->gfxP;
    temp_v1_2 = *temp_a2;
    *temp_a2 = temp_v1_2 + 8;
    temp_v1_2->words.w1 = 0x07080200;
    temp_v1_2->words.w0 = ((((s32) ((arg0->unk_28 * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5100000;
    temp_a1_2 = arg0->gfxP;
    temp_v1_3 = *temp_a1_2;
    *temp_a1_2 = temp_v1_3 + 8;
    temp_v1_3->words.w0 = 0xE6000000;
    temp_v1_3->words.w1 = 0;
    temp_a1_3 = arg0->gfxP;
    temp_v0 = *temp_a1_3;
    *temp_a1_3 = temp_v0 + 8;
    temp_v0->words.w0 = (((arg0->unk_20 * 4) & 0xFFF) << 0xC) | (((arg0->unk_50 * 4) & 0xFFF) | 0xF4000000);
    temp_v0->words.w1 = (((((arg0->unk_20 + arg0->unk_28) - 1) * 4) & 0xFFF) << 0xC) | ((((arg0->unk_54 - 1) * 4) & 0xFFF) | 0x07000000);
    temp_a2_2 = arg0->gfxP;
    temp_v0_2 = *temp_a2_2;
    *temp_a2_2 = temp_v0_2 + 8;
    temp_v0_2->words.w0 = 0xE7000000;
    temp_v0_2->words.w1 = 0;
    temp_a2_3 = arg0->gfxP;
    temp_v1_4 = *temp_a2_3;
    *temp_a2_3 = temp_v1_4 + 8;
    temp_v1_4->words.w1 = 0x80200;
    temp_v1_4->words.w0 = ((((s32) ((arg0->unk_28 * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5100000;
    temp_a2_4 = arg0->gfxP;
    temp_v1_5 = *temp_a2_4;
    *temp_a2_4 = temp_v1_5 + 8;
    temp_v1_5->words.w0 = (((arg0->unk_20 * 4) & 0xFFF) << 0xC) | (((arg0->unk_50 * 4) & 0xFFF) | 0xF2000000);
    temp_v1_5->words.w1 = (((((arg0->unk_20 + arg0->unk_28) - 1) * 4) & 0xFFF) << 0xC) | (((arg0->unk_54 - 1) * 4) & 0xFFF);
}
#else
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", StretchAlphaTexTile_LoadColorTex);
#endif
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", StretchAlphaTexTile_LoadAlphaTex);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", StretchAlphaTexTile_LoadAlphaTex);
#endif

#if VERSION_US || VERSION_CN
void StretchAlphaTexTile(Gfx **gfxP, s32 arg1, s32 arg2, void *arg3, s32 arg4, void *arg5, s32 arg6, s32 arg7, s32 arg8,
                         s32 arg9, s32 argA, f32 argB, f32 argC, f32 argD, f32 argE) {
    StretchTexTile_arg0 sp18;

    sp18.gfxP = gfxP;
    sp18.unk_04 = 0;
    sp18.unk_08 = arg1;
    sp18.unk_0C = arg2;
    sp18.unk_10 = arg3;
    sp18.unk_14 = arg4;
    sp18.unk_18 = arg5;
    sp18.unk_1C = arg6;
    sp18.unk_20 = arg7;
    sp18.unk_24 = arg8;
    sp18.unk_28 = arg9;
    sp18.unk_2C = argA;
    sp18.unk_40 = StretchAlphaTexTile_LoadColorTex;
    sp18.unk_44 = StretchAlphaTexTile_LoadAlphaTex;
    sp18.unk_30 = argB * 4.0;
    sp18.unk_34 = argC * 4.0;
    sp18.unk_38 = argD * 4.0;
    sp18.unk_3C = argE * 4.0;

    sp18.unk_48 = 0x660 / MAX(ALIGN4(arg4), ALIGN16(arg6));
    sp18.unk_4C = StretchTexTile_ScisRect;

    StretchTexTile(&sp18);
}
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80043F18);
#endif

#if VERSION_CN
#if 0
? StretchTexTile(s32 *, s32, s32, s32);           /* extern */
extern ? func_80045EE0_cn;
extern ? StretchAlphaTexTile_LoadColorTex;
extern ? StretchAlphaTexTile_LoadAlphaTex;

void RectAlphaTexTile(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, f32 argC, f32 argD, f32 argE, f32 argF) {
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    s32 sp38;
    s32 sp3C;
    s32 sp40;
    s32 sp44;
    s32 sp48;
    s32 sp4C;
    s32 sp50;
    s32 sp54;
    ? *sp58;
    ? *sp5C;
    s32 sp60;
    ? *sp64;
    s32 temp_a2;
    s32 var_a3;

    sp1C = arg1;
    sp58 = &StretchAlphaTexTile_LoadColorTex;
    sp5C = &StretchAlphaTexTile_LoadAlphaTex;
    sp20 = arg2;
    sp18 = arg0;
    sp24 = arg3;
    var_a3 = (arg7 + 0xF) & ~0xF;
    sp28 = arg4;
    sp34 = arg7;
    sp2C = arg5;
    sp30 = arg6;
    sp3C = arg9;
    sp40 = argA;
    sp44 = argB;
    sp38 = arg8;
    temp_a2 = (arg5 + 3) & ~3;
    sp48 = (s32) ((f64) argC * 4.0);
    sp4C = (s32) ((f64) argD * 4.0);
    sp50 = (s32) ((f64) argE * 4.0);
    sp54 = (s32) ((f64) argF * 4.0);
    if (var_a3 < temp_a2) {
        var_a3 = temp_a2;
    }
    sp64 = &func_80045EE0_cn;
    sp60 = 0x660 / var_a3;
    StretchTexTile(&sp18, argB, temp_a2, var_a3);
}
#else
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", RectAlphaTexTile);
#endif
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80044058);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_800466BC_cn);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", StretchTexTile4);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_800468B0_cn);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", StretchTexTile8_LoadTex);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", StretchTexTile8_LoadTex);
#endif

#if VERSION_US || VERSION_CN
void StretchTexTile8(Gfx **gfxP, s32 width, s32 height, u16 *tlut, u8 *tex, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                     f32 arg9, f32 argA, f32 argB, f32 argC) {
    StretchTexTile_arg0 sp18;

    sp18.gfxP = gfxP;
    sp18.unk_04 = 0;
    sp18.unk_08 = width;
    sp18.unk_0C = height;
    sp18.unk_10 = tex;
    sp18.unk_14 = width;
    sp18.unk_18 = NULL;
    sp18.unk_1C = 0;
    sp18.unk_20 = arg5;
    sp18.unk_24 = arg6;
    sp18.unk_28 = arg7;
    sp18.unk_30 = arg9 * 4.0;
    sp18.unk_34 = argA * 4.0;
    sp18.unk_38 = argB * 4.0;
    sp18.unk_3C = argC * 4.0;
    sp18.unk_48 = 0x800 / ALIGN8(arg7);
    sp18.unk_40 = StretchTexTile8_LoadTex;
    sp18.unk_2C = arg8;
    sp18.unk_44 = NULL;
    sp18.unk_4C = StretchTexTile_ScisRect;

    if (tlut != NULL) {
        gDPLoadTLUT_pal256((*gfxP)++, tlut);
    }

    StretchTexTile(&sp18);
}
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", RectTexTile8);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80046E5C_cn);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80044940);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80047044_cn);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80044B18);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80047230_cn);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80044C28);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80047350_cn);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80044E08);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80047544_cn);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", RectTexTile4i);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80047664_cn);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_8004502C);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", tiMappingAddr);
#endif

#if VERSION_US
#if 0
//? func_8004502C(s32, s32, s32);                     /* extern */

/**
 * Original name: tiLoadTexData
 */
TiTexData *tiLoadTexData(struct_80124610 **arg0, u32 segmentRom, u32 segmentRomEnd) {
    s32 *temp_v0;
    struct_80124610 *temp_s0;
    s32 temp_s1;

    temp_s0 = (void*)ALIGN16((uintptr_t)*arg0);
    *arg0 = DecompressRomToRam(segmentRom, (void *) temp_s0, segmentRomEnd - segmentRom);
    temp_s1 = temp_s0->unk_00 + (uintptr_t)temp_s0;
    temp_v0 = temp_s0->unk_04 + (uintptr_t)temp_s0;
    temp_s0->unk_00 = temp_s1;
    temp_s0->unk_04 = temp_v0;
    func_8004502C(temp_s1, *temp_v0, temp_s0);
    return temp_s1;
}
#else
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", tiLoadTexData);
#endif
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", tiLoadTexData);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80045110);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_800451C4);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", tiStretchTexBlock);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", tiStretchTexTile);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", tiStretchTexItem);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", tiStretchAlphaTexItem);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", func_80045914);
#endif

#if VERSION_US
INCLUDE_RODATA("asm/us/nonmatchings/main_segment/tex_func", RO_800ADBC0);
#endif

#if VERSION_US
INCLUDE_ASM("asm/us/nonmatchings/main_segment/tex_func", drawCursorPattern);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80047894_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_8004795C_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80047A64_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80047BC0_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80047D6C_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80047F90_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80048174_cn);
#endif

#if VERSION_CN
INCLUDE_ASM("asm/cn/nonmatchings/main_segment/tex_func", func_80048324_cn);
#endif

#if VERSION_CN
INCLUDE_RODATA("asm/cn/nonmatchings/main_segment/tex_func", RO_800C4A70_cn);
#endif
