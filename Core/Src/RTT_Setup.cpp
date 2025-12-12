#include <SEGGER_RTT.h>

#include <RTT_Setup.hpp>

// пример с init еще двух буферов
// void SetupRTT()
// {
//     SEGGER_RTT_Init();
//     // static uint8_t __rttbuf1[5000];
//     // SEGGER_RTT_ConfigDownBuffer(1, NULL, __rttbuf1, sizeof(__rttbuf1),
//     SEGGER_RTT_MODE_NO_BLOCK_SKIP); static uint8_t __rttbuf2[512];
//     SEGGER_RTT_ConfigUpBuffer(1, NULL, __rttbuf2, sizeof(__rttbuf2),
//     SEGGER_RTT_MODE_NO_BLOCK_SKIP); static uint8_t __rttbuf3[5000];
//     SEGGER_RTT_ConfigUpBuffer(2, NULL, __rttbuf3, sizeof(__rttbuf3),
//     SEGGER_RTT_MODE_NO_BLOCK_SKIP);
// }

// char __rtt_buf1[1024];
// char __rtt_buf2[1024];

#ifdef __clang__  // gcc __attribute__((optimize("O0")))
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-attributes"
#endif
__attribute__((optimize("O0"))) void __rtt_helper_for_gdb_breakpoint() {
  (void)0;
}

__attribute__((optimize("O0"))) void SetupRtt_NoOptimize() {
  SEGGER_RTT_Init();
  __rtt_helper_for_gdb_breakpoint();
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
