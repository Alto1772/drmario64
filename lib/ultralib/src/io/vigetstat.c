#include "PR/os_internal.h"
#include "PR/rcp.h"

// TODO: this comes from a header
#ifdef BBPLAYER
#ident "$Revision: 1.1 $"
#endif

u32 osViGetStatus(void) {
    return IO_READ(VI_STATUS_REG);
}
