/*
 * input.h
 *
 *  Created on: 28 Oct 2017
 *      Author: Janus
 */

#ifndef INCLUDE_INPUT_H_
#define INCLUDE_INPUT_H_
#include <avr/io.h>

#include <port.h>

class cInput : public cPort
{
public:
   cInput(uint8_t pin_definition);

   void enablePullUp();
};




#endif /* INCLUDE_INPUT_H_ */
