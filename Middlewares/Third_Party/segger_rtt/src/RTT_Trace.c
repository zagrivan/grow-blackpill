#include <NuMicro.h>
#include <SEGGER_RTT.h>
#include <string.h>

void RTT_Trace(unsigned BufferIndex, char const* name) {
    unsigned buf[] = {0, DWT->CYCCNT};
    memcpy(buf, name, 4);
    SEGGER_RTT_WriteSkipNoLock(BufferIndex, buf, 8);
}
