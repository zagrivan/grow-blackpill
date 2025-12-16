#include "app_main.h"

#include "FreeRTOS.h"
#include "RTT_Setup.hpp"
#include "SEGGER_RTT.h"
#include "dht.h"
#include "main.h"
#include "projdefs.h"
#include "task.h"

void dummyRtosTask(void*) {
  DHT_t dht22;
  bool dht22_ok;
  for (;;) {
    SEGGER_RTT_printf(0, "hello world\n");
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

extern "C" {
int app_main_init() {
  SetupRtt_NoOptimize();
  return 0;
}

void freertos_tasks_init() {
  xTaskCreate(dummyRtosTask, "dummy", 1024, nullptr, 6, NULL);
}
}  // extern "C"