/*********************************************************/
/* main.c                                                */
/*********************************************************/

/**
  @file main.c
  @author Woifale
  @date 26 July 2017
  @brief Usage demonstration of Shift Register SN54HC164 (SN54HC164.h)

  This file shows how functions of SN54HC164.h can be used. It's based on microcontroller ATmega328PU.

 */

#include <avr/io.h>
#include "SN54HC164.h"

/** Defines are based on ATmega328P */

/** Defines Pin number for Data line*/
#define SHIFT_REG_DATA_PIN     PD2

/** Defines pin number for Clear pin*/
#define SHIFT_REG_CLR_PIN      PD3

/** Defines pin number for Clock pin*/
#define SHIFT_REG_CLK_PIN      PD4

/** Defines data port used in this sample */
#define SHIFT_REG_DATA_PORT    PORTD

/** Defines data direction register according to data port */
#define SHIFT_REG_DATA_DIR_REG DDRD

/** Defines data direction for data line */
#define SHIFT_REG_DIR_DAT_PIN  DDD2

/** Defines data direction for clear line*/
#define SHIFT_REG_DIR_CLR_PIN  DDD3

/** Defines data direction for clock line*/
#define SHIFT_REG_DIR_CLK_PIN  DDD4


void main(void){

  // Set data direction for Shift regs
  SHIFT_REG_DATA_DIR_REG = (1<<SHIFT_REG_DIR_DAT_PIN) | (1<<SHIFT_REG_DIR_CLR_PIN) | (1<<SHIFT_REG_DIR_CLK_PIN);

  // Setting Clear Port to High
  SHIFT_REG_DATA_PORT = (1<<SHIFT_REG_CLR_PIN);
  
  // Erase content of Shift Register
  SN54HC164_erase(&SHIFT_REG_DATA_PORT, SHIFT_REG_CLR_PIN);
  
  
  while(1){
    
    for(int i=1; i< 16; i++){
      //shift a bit into the register
      SN54HC164_bit(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, true);

      // warten
      _delay_ms(500);

      //shift a zero into the register
      SN54HC164_bit(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, false);

      //warten
      _delay_ms(500);
    }
   
    SN54HC164_erase(&SHIFT_REG_DATA_PORT, SHIFT_REG_CLR_PIN);

    SN54HC164_byte(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, 0b00000001);
    _delay_ms(500);
    SN54HC164_byte(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, 0b00000010);
    _delay_ms(500);
    SN54HC164_byte(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, 0b00000100);
    _delay_ms(500);
    SN54HC164_byte(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, 0b00001000);
    _delay_ms(500);
    SN54HC164_byte(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, 0b00010000);
    _delay_ms(500);
    SN54HC164_byte(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, 0b00100000);
    _delay_ms(500);
    SN54HC164_byte(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, 0b01000000);
    _delay_ms(500);
    SN54HC164_byte(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, 0b10000000);
    _delay_ms(500);
		 
    for(int i=0;i<255;i++){
      SN54HC164_byte(&SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN, SHIFT_REG_CLK_PIN, i);
      _delay_ms(500);
    }
    
  }

  
}
