/*****************************************/
/** SN54HC164.h                         **/
/*****************************************/

#ifndef SN54HC164_H
#define SN54HC164_H

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>


/** Wait Time in micro seconds **/
#define SN54HC164_CMD_WAIT_CLK_TIME 25
#define SN54HC164_CMD_WAIT_DATA_TIME 30
#define SN54HC164_CMD_WAIT_CLR_TIME 30

/* Erase content of shift register */
void SN54HC164_erase(uint8_t *port, uint8_t pin);

/* Send clock Pulse */
void SN54HC164_clock(uint8_t *data_port, uint8_t clock_pin);

/* Shift in Bit */
void SN54HC164_bit(uint8_t *data_port, uint8_t data_pin, uint8_t clock_pin, bool bit);

/* Shift in Byte */
void SN54HC164_byte(uint8_t *data_port, uint8_t data_pin, uint8_t clock_pin, uint8_t databyte);



#endif //SN54HC164_H
