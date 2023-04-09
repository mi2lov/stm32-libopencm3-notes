#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include "uart.h"

void uart_init(uint32_t baudrate)
{
    /* Enable clocks for USART2 */
    rcc_periph_clock_enable(RCC_USART2);

    /* Setup GPIO pins for USART2 transmit (PA2) and receive (PA3) */
    gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2 | GPIO3);
    gpio_set_af(GPIOA, GPIO_AF7, GPIO2 | GPIO3);

    /* Setup USART2 parameters */
    usart_set_baudrate(USART2, baudrate);
    usart_set_databits(USART2, 8);
    usart_set_stopbits(USART2, USART_STOPBITS_1);
    usart_set_mode(USART2, USART_MODE_TX_RX);
    usart_set_parity(USART2, USART_PARITY_NONE);
    usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);

    /* Enable USART2 */
    usart_enable(USART2);
}

void uart_send_blocking(uint32_t usart, uint8_t *data, uint32_t len)
{
    uint32_t i;
    for (i = 0; i < len; i++) {
        usart_send_blocking(usart, data[i]);
    }
}