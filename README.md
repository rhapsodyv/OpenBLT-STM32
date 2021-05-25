# OpenBLT-STM32
A generic OpenBLT for any STM32 board using Stm32duino

# Why?

This project takes OpenBLT and add stm32duino (https://github.com/stm32duino/Arduino_Core_STM32) as HAL, so any STM32 is already supported, so you don't need any extra OpenBLT setup/config.

All you need to do is:

1) Configure SD:
```cpp
#define HSE_VALUE 12000000
#define SDCARD_SS_PIN                       PA4
#define SDCARD_SCK_PIN                      PA5
#define SDCARD_MISO_PIN                     PA6
#define SDCARD_MOSI_PIN                     PA7
#define SD_DETECT_PIN                       -1
#define SPI_SPEED                           2

#define FIRMWARE_FILENAME                   "firmware.srec"
#define FIRMWARE_FILENAME_RENAME            "firmware.cur"
```

2) Select your MCU in the `platformio.ini`.

3) Build using PlatformIO
