/*********************************************************/
/** main.c                                              **/
/*********************************************************/


#include <avr/io.h>

#define SHIFT_REG_DATA_PORT PD2
#define SHIFT_REG_CLK_PORT  PD4
#define SHIFT_REG_CLR_PORT  PD3


void main(void){

  // Set data direction for Shift regs
  // DDD2 Data Port out
  // DDD3 Clear Port out
  // DDD4 Clock Port out
  DDRD = (1<<DDD2) | (1<<DDD3) | (1<<DDD4);

  // Setting Clear Port to High
  PORTD = (1<<SHIFT_REG_CLR_PORT);


  // Erase content of Shift Register
  SN54HC164_erase(SHIFT_REG_CLR_PORT);

  
  while(1){

    
  }

  
}
