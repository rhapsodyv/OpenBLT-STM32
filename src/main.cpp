#include <Arduino.h>
extern "C" {
  #include "openblt/boot.h"
}

#include "sd.h"

// #include "SdFatFs.h"

// #ifndef SD_DETECT_PIN
// #define SD_DETECT_PIN SD_DETECT_NONE
// #endif

// Sd2Card card;
// SdFatFs fatFs;
// bool fatStarted = false;

static void Init(void)
{
  SDSetup();
  // card.init(SD_DETECT_PIN);
  // /* HAL library initialization */
  // HAL_Init();
  // /* configure system clock */
  // SystemClock_Config();
  //done by variant
} /*** end of Init ***/


void setup() {
  Init();
  /* initialize the bootloader */
  BootInit();
}

void loop() {
  // if (!fatStarted) {
  //   fatStarted = card.init(); //SD_DETECT_PIN
  //   if (fatStarted) {
  //     fatFs.init();
  //   }
  // }
  mountDisk();
  BootTask();
}