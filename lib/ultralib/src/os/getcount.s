#include "PR/R4300.h"
#include "sys/asm.h"
#include "sys/regdef.h"

.text

#ifndef BBPLAYER

LEAF(osGetCount)
    STAY2(mfc0 v0, C0_COUNT)
    jr ra
END(osGetCount)

#else
// needed to match elf header flags
.set noreorder
#endif
