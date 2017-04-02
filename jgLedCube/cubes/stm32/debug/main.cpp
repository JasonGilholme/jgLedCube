#if defined STM32F1
# include <stm32f1xx.h>
#elif defined STM32F2
# include <stm32f2xx.h>
#elif defined STM32F4
# include <stm32f4xx.h>
# include "stm32f4xx_hal.h"
#endif

#include <jgLedCube/core.h>

int main(void)
{
//    jgLedCube::core::setLed(1, 1, 1, 15, 15, 15);
}
