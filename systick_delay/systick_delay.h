#ifndef __SYSTICK_DELAY_H
#define __SYSTICK_DELAY_H

#include <stdint.h>

#define SYSTEM_CLOCK_FREQUENCY 84000000

void delay_init(void);

void delay_us(uint32_t us);

void delay_ms(uint32_t ms);

void sys_tick_handler(void);

#endif /* __SYSTICK_DELAY */
