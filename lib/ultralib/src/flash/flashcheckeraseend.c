#include "ultra64.h"
#include "PR/os_internal_flash.h"

extern u32 __osBbFlashSize;

s32 osFlashCheckEraseEnd(void) {
#ifdef BBPLAYER
    if (__osBbFlashSize != 0) {
        return FLASH_STATUS_ERASE_OK;
    } else {
        return FLASH_STATUS_ERASE_ERROR;
    }
#else
    u8 status;

    osFlashReadStatus(&status);

    if ((status & FLASH_STATUS_ERASE_BUSY) == FLASH_STATUS_ERASE_BUSY) {
        return FLASH_STATUS_ERASE_BUSY;
    } else {
        // not busy, read and clear status
        osFlashReadStatus(&status);
    }
    osFlashClearStatus();

    // check for success
    if (((status & 0xFF) == 8) || ((status & 0xFF) == 0x48) || ((status & 8) == 8)) {
        return FLASH_STATUS_ERASE_OK;
    } else {
        return FLASH_STATUS_ERASE_ERROR;
    }
#endif
}
