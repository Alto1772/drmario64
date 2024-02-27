#include "piint.h"
#include "PR/ultraerror.h"

// TODO: this comes from a header
#ifndef BBPLAYER
#ident "$Revision: 1.17 $"
#else
#include "PR/bcp.h"
#ident "$Revision: 1.1 $"
#endif

s32 __osEPiRawStartDma(OSPiHandle* pihandle, s32 direction, u32 devAddr, void* dramAddr, u32 size) {
#ifdef BBPLAYER
    u64 dummybuf[2];
#endif
    u32 stat;
    u32 domain;
#ifdef BBPLAYER
    u32 buffer;
    u32 pgsize;
    u16* adr;
    u32 i;
#endif

#ifdef _DEBUG
    if ((direction != OS_READ) && (direction != OS_WRITE)) {
        __osError(ERR_OSPIRAWSTARTDMA_DIR, 1, direction);
        return -1;
    }

    if (devAddr & 0x1) {
        __osError(ERR_OSPIRAWSTARTDMA_DEVADDR, 1, devAddr);
        return -1;
    }

    if ((u32)dramAddr & 0x7) {
        __osError(ERR_OSPIRAWSTARTDMA_ADDR, 1, dramAddr);
        return -1;
    }

    if (size & 0x1) {
        __osError(ERR_OSPIRAWSTARTDMA_SIZE, 1, size);
        return -1;
    }

    if ((size == 0) || (size > (16 * 1024 * 1024))) {
        __osError(ERR_OSPIRAWSTARTDMA_RANGE, 1, size);
        return -1;
    }
#endif

    EPI_SYNC(pihandle, stat, domain);

#ifdef BBPLAYER
    if (direction == OS_READ) {
        pgsize = 1;

        for (i = 1; i <= pihandle->pageSize + 2; i++) {
            pgsize *= 2;
        }

        if ((devAddr & (pgsize - 1)) == (pgsize - 2)) {
            __osEPiRawReadIo(pihandle, devAddr - 2, &buffer);

            adr = (u16*)PHYS_TO_K1(dramAddr);
            *(adr++) = (u16)buffer;

            devAddr += 2;
            dramAddr = adr;
            size -= 2;

            if (size >= 4) {
                __osEPiRawReadIo(pihandle, devAddr, &buffer);

                adr = (u16*)dramAddr;
                *(adr++) = buffer >> 16;
                *(adr++) = (u16)buffer;

                devAddr += 4;
                dramAddr = adr;
                size -= 4;

                if (size != 0) {
                    __osEPiRawReadIo(pihandle, devAddr, &buffer);

                    adr = (u16*)PHYS_TO_K1(dramAddr);
                    *(adr++) = buffer >> 16;

                    devAddr += 2;
                    dramAddr = adr;
                    size -= 2;
                }
            }
        }

        if (((((devAddr + size) & (pgsize - 1)) == 2) | (size == 2)) != 0) {
            if ((devAddr + size) & 2) {
                __osEPiRawReadIo(pihandle, devAddr + size - 2, &buffer);
                adr = (u16*)PHYS_TO_K1(dramAddr) + (size - 2) / 2;
                *adr = buffer >> 16;
            } else {
                __osEPiRawReadIo(pihandle, devAddr + size - 4, &buffer);
                adr = (u16*)PHYS_TO_K1(dramAddr) + (size - 2) / 2;
                *adr = (u16)buffer;
            }
            size -= 2;
        }

        if (size == 0) {
            size = 8;
            dramAddr = (void*)dummybuf;
            devAddr = 0;
        }
    }
#endif

    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    IO_WRITE(PI_CART_ADDR_REG, K1_TO_PHYS(pihandle->baseAddress | devAddr));

#ifdef BBPLAYER
    if (direction >= 2u) {
        return -1;
    }

    if ((pihandle->baseAddress | devAddr) <= 0x400) {
        IO_WRITE((direction == OS_READ) ? PI_5C_REG : PI_58_REG, size - 1);
    } else {
        IO_WRITE((direction == OS_READ) ? PI_WR_LEN_REG : PI_RD_LEN_REG, size - 1);
    }
#else
    switch (direction) {
        case OS_READ:
            IO_WRITE(PI_WR_LEN_REG, size - 1);
            break;
        case OS_WRITE:
            IO_WRITE(PI_RD_LEN_REG, size - 1);
            break;
        default:
            return -1;
    }
#endif
    return 0;
}
