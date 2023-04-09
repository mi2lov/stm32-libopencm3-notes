#ifndef UART_H
#define UART_H

#include <libopencm3/stm32/usart.h>

/// @brief Инициализация UART
/// @param baudrate Бод
void uart_init(uint32_t baudrate);
void uart_send_blocking(uint32_t usart, uint8_t *data, uint32_t len);

#endif /* UART_H */
