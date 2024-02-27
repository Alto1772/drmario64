#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "viint.h"

// TODO: this comes from a header
#ifdef BBPLAYER
#ident "$Revision: 1.1 $"
#endif

void osViExtendVStart(u32 value) {
#ifdef _DEBUG
    if (!__osViDevMgr.active) {
        __osError(134, 0);
        return;
    }

    if (value > 48) {
        __osError(135, 1, value);
        return;
    }
#endif
    __additional_scanline = value;
    return;
}
