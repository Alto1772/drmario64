#ifndef BOOT_FUNCTIONS
#define BOOT_FUNCTIONS

#include "ultra64.h"
#include "libc/stdint.h"
#include "unk.h"


// void func_80000460();
// void func_80000468();
// void func_80000488();
// void bootproc();
// void func_800004F0();
void func_80000580(void* arg0);

// void func_80000604();
void *func_80000620(romoffset_t segmentRom, void *segmentVram, size_t segmentSize);
// void func_80000720();
// void func_8000075C();
// void func_80000778();
// void func_80000D0C();
// void func_80000D48();
// void func_80001260();
// void func_80001480();
// void func_80001620();
// void func_80001D4C();
// void func_80001EB4();
UNK_TYPE func_80001F90(romoffset_t segmentRom, UNK_TYPE arg1, size_t segmentSize);
// void func_80001FD8();
// void func_80002064();
UNK_TYPE func_800020A0(void);
// void func_80002148();
void func_800021A0(void);
// void func_800021CC();
// void func_800022A8();
// void func_80002300();
void *func_80002380(romoffset_t segmentRom, UNK_TYPE arg1, romoffset_t segmentSize);
// void func_800023B4();
// void func_80002400();

// void func_8000D7E0();
// void func_8000D868();
// void func_8000D8C4();
// void func_8000D940();
// void func_8000D9C0();
// void func_8000DAC4();
// void func_8000DB0C();
// void func_8000DB30();
// void func_8000DBD0();
// void func_8000DC00();
// void func_8000DCB0();
// void func_8000DCE4();
// void func_8000DCF0();
// void func_8000DDC4();
// void func_8000DDF8();
// void func_8000DEF4();
// void func_8000DFC0();
// void __udivdi3();

#endif
