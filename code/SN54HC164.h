/*****************************************/
/* SN54HC164.h                           */
/*****************************************/

/**
\mainpage SN54HC164.h Routines for usage of SN54HC164 8-bit shift register.

This file provides functions for usage of serial 8-bit shift register SN54HC164.
In addition a sample (main.c) is included to show how to use it. This sample is based on an ATmega328P micro controller.

Datasheets can be found here:

<a href="../datasheets/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf">ATmega328P</a>
<br>
<a href="../datasheets/164445-da-01-en-CMOS_IC_SN74HC164N_DIP14_TID.pdf">SN54HC164</a>

Breadboard:
<center><img src="../fritzing/SN54HC164_breadboard.png"></center>
*/


/**
  @file SN54HC164.h
  @author Woifale
  @date 26 July 2017
  @brief Functions for Shift Register SN54HC164
 
  This file contains header functions to work with Shift Register SN54HC164.
  SN54HC164 is a serial 8bit Shift register which immediately writes out data
 */

#ifndef SN54HC164_H
/** avoids double processing of this include */
#define SN54HC164_H

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>


/** Wait Time in micro seconds.
According to specifiction this is the minimal time the IC needs to recognize the Clock signal. */
#define SN54HC164_CMD_WAIT_CLK_TIME 25

/** Wait time in micro seconds. 
    According to specification this is the minimal time the IC needs to recognize data signal. */
#define SN54HC164_CMD_WAIT_DATA_TIME 30

/** Wait time in micro seconds.
    According to specification this is the minimal time the IC needs to recognize the clear signal. */
#define SN54HC164_CMD_WAIT_CLR_TIME 30

/** @brief  Erase content of shift register 

@param[in] *port is the reference - an 8 bit address -  to the data port of the micro controller where the data port of the shift register is connected to. Please make sure to use an leading @& in case of handing over a macro definition like PORTD.

@param[in] pin the number of the microcontroller's pin of port handed over above (eg. PD4) where the erase line of the shift register is connected to the micro controller.

The function set the CLR line to low for the periode specified in SN54HC164_CMD_WAIT_CLR_TIME. By doing this the content of the shift register is set to zeros.
*
This function requires the include <util/delay.h>
*
Usage:
@code
#include <avr/io.h>
#include <util/delay.h>

#define SHIFT_REG_DATA_PORT PORTD
#define SHIFT_REG_CLR_PIN   PD3
#define SN54HC164_CMD_WAIT_CLR_TIME 30
...
SN54HC164_erase(&SHIFT_REG_DATA_PORT, SHIFT_REG_CLR_PIN);
...
@endcode
*/
void SN54HC164_erase(uint8_t *port, uint8_t pin);

/** @brief  Send clock Pulse to shift register

@param[in] *data_port *port is the reference - an 8 bit address -  to the data port of the micro controller where the data port of the shift register is connected to. Please make sure to use an leading @& in case of handing over a macro definition like PORTD.
@param[in] clock_pin the number of the microcontroller's pin of port handed over above (eg. PD4) where the clock line of the shift register is connected to the micro controller.

The function set the line given by combination of data_port and clock_pin to high. This level is held for the periode specified in macro SN54HC164_CMD_WAIT_CLK_TIME. Default value is set to minimum time according spec.
* 
This function requires the include <util/delay.h>

Usage:
@code
#include <avr/io.h>
#include <util/delay.h>

#define SHIFT_REG_DATA_PORT PORTD
#define SHIFT_REG_CLK_PIN   PD4
#define SN54HC164_CMD_WAIT_CLK_TIME 25
...
SN54HC164_clock(&SHIFT_REG_DATA_PORT, SHIFT_REG_CLK_PIN);
...
@endcode
*/
void SN54HC164_clock(uint8_t *data_port, uint8_t clock_pin);

/** @brief  Shift single bit into shift register 

@param [in] *data_port *port is the reference - an 8 bit address -  to the data port of the micro controller where the data port of the shift register is connected to. Please make sure to use an leading @& in case of handing over a macro definition like PORTD.
@param [in] data_pin the number of the microcontroller's pin of port handed over above (eg. PD3) where the data line of the shift register is connected to the micro controller.
@param [in] clock_pin the number of the microcontroller's pin of port handed over above (eg. PD3) where the clock line of the shift register is connected to the micro controller.
@param [in] bit is an boolean set to either true or false. Whereby true represents 1 and false 0.

The function set the line given by combination of data_port and data_pin to value according to parameter bit (true or false - whereby true = high and false = low). This level is held for the periode specified in macro SN54HC164_CMD_WAIT_DATA_TIME. Default value is set to minimum time according spec.
* 
After setting the data line the function @func SN54HC164_clock is called to instruct the shift register to take over the state given on data line.
*
This function requires the include <util/delay.h>
*
Usage:
@code
#include <avr/io.h>
#include <util/delay.h>

#define SHIFT_REG_DATA_PORT PORTD
#define SHIFT_REG_CLK_PIN   PD3
#define SHIFT_REG_DATA_PIN  PD2
#define SN54HC164_CMD_WAIT_CLK_TIME 25
#define SN54HC164_CMD_WAIT_DATA_TIME 30
...
SN54HC164_bit(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN,SHIFT_REG_CLK_PIN, true);
...
@endcode
*/
void SN54HC164_bit(uint8_t *data_port, uint8_t data_pin, uint8_t clock_pin, bool bit);

/** @brief Shift whole byte into shift register 
@param [in] *data_port *port is the reference - an 8 bit address -  to the data port of the micro controller where the data port of the shift register is connected to. Please make sure to use an leading @& in case of handing over a macro definition like PORTD.
@param [in] data_pin the number of the microcontroller's pin of port handed over above (eg. PD3) where the data line of the shift register is connected to the micro controller.
@param [in] clock_pin the number of the microcontroller's pin of port handed over above (eg. PD3) where the clock line of the shift register is connected to the micro controller.
@param [in] databyte a byte of data which will be shifted into the register.

The function set the line given by combination of data_port and data_pin to value according to parameter databyte. Therfore the function SN54HC164_bit is called for each bit of databyte. 
*
This function requires the include <util/delay.h>
*
Usage:
@code
#include <avr/io.h>
#include <util/delay.h>

#define SHIFT_REG_DATA_PORT PORTD
#define SHIFT_REG_CLK_PIN   PD3
#define SHIFT_REG_DATA_PIN  PD2
#define SN54HC164_CMD_WAIT_CLK_TIME 25
#define SN54HC164_CMD_WAIT_DATA_TIME 30
...
SN54HC164_byte(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, 0b10101010);
...
@endcode

*/
void SN54HC164_byte(uint8_t *data_port, uint8_t data_pin, uint8_t clock_pin, uint8_t databyte);



#endif //SN54HC164_H
