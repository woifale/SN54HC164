/*****************************************/
/** SN54HC164.h                         **/
/*****************************************/

#ifndef SN54HC164_H
#define SN54HC164_H

#include <avr/io.h>
#include <stdbool.h>


/* Erase content of shift register */
void SN54HC164_erase(uint8_t portnumber);

/* Send clock Pulse */
void SN54HC164_clock(uint8_t portnumber);

/* Shift in Bit */
void SN54HC164_bit(bool bit);

/* Shift in Byte */
void SN54HC164_byte(uint8_t byte);



#endif //SN54HC164_H
