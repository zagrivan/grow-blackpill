#pragma once


void SetupRTT();

#ifdef __clang__
#    pragma clang diagnostic push
#    pragma clang diagnostic ignored "-Wunknown-attributes"
#endif
__attribute__((optimize("O0"))) void __rtt_helper_for_gdb_breakpoint();

__attribute__((optimize("O0"))) void SetupRtt_NoOptimize();
#ifdef __clang__
#    pragma clang diagnostic pop
#endif
