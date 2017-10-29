/*
 * input.cpp
 *
 *  Created on: 28 Oct 2017
 *      Author: Janus
 */
#include "input.h"

cInput::cInput(uint8_t pin_definition) : cPort(pin_definition)
{

}

void cInput::enablePullUp()
{
   setPORTn();
}
