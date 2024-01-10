#ifndef _000280_H
#define _000280_H

#include "libultra.h"
#include "PR/sched.h"
#include "unk.h"

typedef struct struct_800FAF98_unk_64 {
    /* 0x0 */ struct struct_800FAF98_unk_64 *unk_0;
    /* 0x4 */ OSMesgQueue *unk_4;
} struct_800FAF98_unk_64; // size = 0x8


typedef struct struct_800EB670 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ OSMesgQueue unk_004;
    /* 0x01C */ OSMesg unk_01C[8];
    /* 0x03C */ OSMesgQueue unk_03C;
    /* 0x054 */ OSMesg unk_054[8];
    /* 0x074 */ OSMesgQueue unk_074;
    /* 0x08C */ OSMesg unk_08C[8];
    /* 0x0AC */ OSMesgQueue unk_0AC;
    /* 0x0C4 */ OSMesg unk_0C4[8];
    /* 0x0E4 */ OSMesgQueue unk_0E4;
    /* 0x0FC */ OSMesg unk_0FC[8];
    /* 0x11C */ OSMesgQueue unk_11C;
    /* 0x134 */ OSMesg unk_134[8];
    /* 0x154 */ UNK_TYPE1 unk_154[0x4];
    /* 0x158 */ OSThread unk_158;
    /* 0x308 */ OSThread unk_308;
    /* 0x4B8 */ OSThread unk_4B8;
    /* 0x668 */ struct_800FAF98_unk_64 *unk_668;
    /* 0x66C */ OSScTask *unk_66C;
    /* 0x670 */ OSScTask *unk_670;
    /* 0x674 */ OSScTask *unk_674;
    /* 0x678 */ UNK_TYPE unk_678;
} struct_800EB670; // size = 0x67C


void func_80029ED0(struct struct_800EB670 *arg0, u8 viModeIndex, u8 retraceCount);
OSMesgQueue *func_8002A0CC(struct struct_800EB670 *arg0, void *arg1);
OSMesgQueue *func_8002A0D4(struct struct_800EB670 *arg0);
void func_8002A0DC(void *arg);
void func_8002A184(struct struct_800EB670 *arg0, struct struct_800FAF98_unk_64 *arg1, OSMesgQueue *arg2);
void func_8002A1DC(struct struct_800EB670 *arg0, struct struct_800FAF98_unk_64 *arg1);
void func_8002A26C(struct struct_800EB670 *arg0, OSMesg msg);
void func_8002A2B8(void * arg);
void func_8002A3F4(struct struct_800EB670 *arg0, OSScTask *arg1);
void func_8002A4D8(void *arg);
void func_8002A51C(struct struct_800EB670 *arg0, OSScTask *arg1);

#if VERSION_CN
void func_8002B8B4_cn(void);
void func_8002B910_cn();
void func_8002BA98_cn(s32 arg0, s32 arg1);
void func_8002BC30_cn(s32 arg0);
void func_8002BD04_cn(void);
void func_8002BD7C_cn(Gfx **gfxP, s32 arg1, s32 arg2);
#endif

#endif
