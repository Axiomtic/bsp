#ifndef BSP_BUZZER_H
#define BSP_BUZZER_H
#include "struct_typedef.h"
#include "stm32f4xx_hal.h"
extern void buzzer_on(uint16_t psc, uint16_t pwm);
extern void buzzer_off(void);

#endif
