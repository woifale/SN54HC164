/***********************************/
/** SN54HC164.c                   **/
/***********************************/

/**
  @file SN54HC164.c
  @author Woifale
  @date 26 July 2017
  @brief Functions for Shift Register SN54HC164
 
  This file contains functions to work with Shift Register SN54HC164.
  SN54HC164 is a serial 8bit Shift register which immediately writes out data
 */

#include "SN54HC164.h"



/* Erase content of shift register */
void SN54HC164_erase(uint8_t *port, uint8_t pin){

  // Set clear bit to low
  *port &= ~(1<<pin);

  //Wait minimum time
  _delay_us(SN54HC164_CMD_WAIT_CLR_TIME);

  // Pull up CLR line again
  *port |= (1<<pin);
  
}



/* Send clock Pulse */
void SN54HC164_clock(uint8_t *data_port, uint8_t clock_pin){

  // set clk pin to high
  *data_port |= (1<<clock_pin);
  
  // give chip a chance to process
  _delay_us(SN54HC164_CMD_WAIT_CLK_TIME);

  // set clk pin to low
  *data_port &= ~(1<<clock_pin);
  
}



/* Shift in bit */
void SN54HC164_bit(uint8_t *data_port, uint8_t data_pin, uint8_t clock_pin, bool bit){

  // initialize data pin with000 1
  *data_port |= (1<<data_pin);
  
  // delete if not true
  if (bit == false){
      *data_port &= ~(1<<data_pin);
  }

  // put data on pin and wait according spec
  _delay_us(SN54HC164_CMD_WAIT_DATA_TIME);
  
  // Pulse the clock
  SN54HC164_clock(data_port, clock_pin);

  // set data pin to low
  *data_port &= ~(1<<data_pin);
}



/* Shift in Byte */
void SN54HC164_byte(uint8_t *data_port, uint8_t data_pin, uint8_t clk_pin, uint8_t databyte){
  uint8_t  i;
  
  for (i=0;i<8;i++){
    if (bit_is_set(databyte, i)){
      SN54HC164_bit(data_port, data_pin, clk_pin, true);
    }
    else {
      SN54HC164_bit(data_port, data_pin, clk_pin, false);
    }
  }
  
}
