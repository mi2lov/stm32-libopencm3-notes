#include <libopencm3/cm3/systick.h>
#include "systick_delay.h"

static volatile uint32_t _ticks = 0;

void delay_init(void)
{
    /* Configure SysTick to trigger every microsecond. */
    systick_set_frequency(1000000, SYSTEM_CLOCK_FREQUENCY);
    systick_interrupt_enable();
    systick_counter_enable();
}

void delay_us(uint32_t us)
{
    uint32_t start_ticks = _ticks;
    uint32_t ticks = us;
    while ((_ticks - start_ticks) < ticks);
}

void delay_ms(uint32_t ms)
{
    uint32_t start_ticks = _ticks;
    uint32_t ticks = ms * 1000;
    while ((_ticks - start_ticks) < ticks);
}

void sys_tick_handler(void)
{
    _ticks++;
}