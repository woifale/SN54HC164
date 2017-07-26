/*********************************************************/
/** main.c                                              **/
/*********************************************************/


#include <avr/io.h>
#include "SN54HC164.h"

#define SHIFT_REG_DATA_PIN     PD2
#define SHIFT_REG_CLR_PIN      PD3
#define SHIFT_REG_CLK_PIN      PD4
#define SHIFT_REG_DATA_PORT    PORTD
#define SHIFT_REG_DATA_DIR_REG DDRD
#define SHIFT_REG_DIR_DAT_PIN  DDD2
#define SHIFT_REG_DIR_CLR_PIN  DDD3
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
		 
		   
    
  }

  
}
