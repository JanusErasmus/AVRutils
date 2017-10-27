#include <stdio.h>
#include <avr/io.h>

#include "mystdio.h"

static int putch(char ch, FILE *s)
{
	while (!(UCSRA & _BV(UDRE0)));

	if(ch == '\n')
	{
		UDR = '\r';
		while (!(UCSRA & _BV(UDRE0)));
	}

	UDR = ch;

	return 0;
}

static FILE mystdout = FDEV_SETUP_STREAM(putch, NULL, _FDEV_SETUP_WRITE);

void mystdio_init()
{
	stdout = &mystdout;
}
