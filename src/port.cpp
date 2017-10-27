#include "port.h"


#if defined(__AVR_ATmega2560__)
const volatile uint8_t* DDRn[] =
{
		&DDRA,
		&DDRB,
		&DDRC,
		&DDRD,
		&DDRE,
		&DDRF,
		&DDRG,
		&DDRH,
		&DDRJ,
};

const volatile uint8_t* PORTn[] =
{
		&PORTA,
		&PORTB,
		&PORTC,
		&PORTD,
		&PORTE,
		&PORTF,
		&PORTG,
		&PORTH,
		&PORTJ,
};

const volatile uint8_t* PINn[] =
{
		&PINA,
		&PINB,
		&PINC,
		&PIND,
		&PINE,
		&PINF,
		&PING,
		&PINH,
		&PINJ,
};
#elif defined(__AVR_ATmega328P__)
const volatile uint8_t* DDRn[] =
{
        0,
        &DDRB,
        &DDRC,
        &DDRD
};

const volatile uint8_t* PORTn[] =
{
        0,
        &PORTB,
        &PORTC,
        &PORTD
};

const volatile uint8_t* PINn[] =
{
        0,
        &PINB,
        &PINC,
        &PIND
};
#else
#warning "AVR not supported"
const volatile uint8_t* DDRn[] =
{
      0
};

const volatile uint8_t* PORTn[] =
{
      0
};

const volatile uint8_t* PINn[] =
{
       0
};
#endif

cPort::cPort(uint8_t pin_definition) : mPinDefinition(pin_definition)
{
}
uint8_t cPort::PORTindex()
{
	return ((mPinDefinition & 0xF0) >> 4);
}

volatile uint8_t* cPort::DDRn_reg()
{
	uint8_t portIdx = PORTindex();
	return (volatile uint8_t *)DDRn[portIdx];
}

volatile uint8_t* cPort::PORTn_reg()
{
	uint8_t portIdx = PORTindex();
	return (volatile uint8_t *)PORTn[portIdx];
}

volatile uint8_t* cPort::PINn_reg()
{
	uint8_t portIdx = PORTindex();
	return (volatile uint8_t *)PINn[portIdx];
}

void cPort::setDDRn()
{
	volatile uint8_t *port = DDRn_reg();
	*port |= 1 << (mPinDefinition & 0x0F);
}

void cPort::clearDDRn()
{
	volatile uint8_t *port = DDRn_reg();
	*port &= ~(1 << (mPinDefinition & 0x0F));
}

void cPort::setPORTn()
{
	volatile uint8_t *port = PORTn_reg();
	*port |= 1 << (mPinDefinition & 0x0F);
}

void cPort::clearPORTn()
{
	volatile uint8_t *port = PORTn_reg();
	*port &= ~(1 << (mPinDefinition & 0x0F));
}


bool cPort::get()
{
	 volatile uint8_t *port = PINn_reg();

	 if( *port & (1 << (mPinDefinition & 0x0F)))
		 return true;

	 return false;
}

cPort::~cPort()
{
}

