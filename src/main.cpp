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

/************************************************************************************//**
** \brief     DeInitializes the Global MSP. This function is called from HAL_DeInit()
**            function to perform system level de-initialization (GPIOs, clock, DMA,
**            interrupt).
** \return    none.
**
****************************************************************************************/
void HAL_MspDeInit(void)
{
  /* Reset the RCC clock configuration to the default reset state. */
  HAL_RCC_DeInit();
  
  /* Deinit used GPIOs. */
  HAL_GPIO_DeInit(GPIOA, GPIO_PIN_All);
  HAL_GPIO_DeInit(GPIOB, GPIO_PIN_All);
  HAL_GPIO_DeInit(GPIOC, GPIO_PIN_All);
  HAL_GPIO_DeInit(GPIOD, GPIO_PIN_All);
  HAL_GPIO_DeInit(GPIOE, GPIO_PIN_All);

  // #if (BOOT_COM_CAN_ENABLE > 0)
  //   /* CAN clock disable. */
  //   LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_CAN2);
  //   LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_CAN1);
  // #endif


  // #if (BOOT_COM_RS232_ENABLE > 0) || (BOOT_FILE_LOGGING_ENABLE > 0)
  //   #if (BOOT_FILE_LOGGING_ENABLE > 0) && (BOOT_COM_RS232_ENABLE == 0)
  //   /* Disable UART peripheral */
  //   LL_USART_Disable(USART1);
  //   #endif
  //   /* UART clock disable. */
  //   LL_APB2_GRP1_DisableClock(LL_APB2_GRP1_PERIPH_USART1);
  // #endif

  __HAL_RCC_GPIOA_CLK_DISABLE();
  __HAL_RCC_GPIOB_CLK_DISABLE();
  __HAL_RCC_GPIOC_CLK_DISABLE();
  __HAL_RCC_GPIOD_CLK_DISABLE();
  __HAL_RCC_GPIOE_CLK_DISABLE();

  /* SYSCFG and PWR clock disable. */
  __HAL_RCC_PWR_CLK_DISABLE();
  __HAL_RCC_SYSCFG_CLK_DISABLE();

} /*** end of HAL_MspDeInit ***/