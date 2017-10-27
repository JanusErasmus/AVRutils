#ifndef MYSTDIO_H_
#define MYSTDIO_H_

#if defined(__AVR_ATmega2560__)
#define UCSRA           UCSR1A
#define UCSRB           UCSR1B
#define UCSRC           UCSR1C
#define UBRRL           UBRR1L
#define UDR             UDR1
#define USART_RX_VECT   USART1_RX_vect
#endif

#if defined(__AVR_ATmega328P__)
#define UCSRA           UCSR0A
#define UCSRB           UCSR0B
#define UCSRC           UCSR0C
#define UBRRL           UBRR0L
#define UDR             UDR0
#define USART_RX_VECT   USART0_RX_vect
#endif

#ifndef UCSRA
#warning "AVR not supported"
#endif
#ifdef __cplusplus
extern "C" {
#endif

void mystdio_init();

#ifdef __cplusplus
}
#endif
#endif /* MYSTDIO_H_ */
