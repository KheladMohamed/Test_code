/*
* GPIO_Test.c
*
* Created: 9/26/2021 8:09:47 PM
* Author : Khelad Mohamed
*/

#include "main.h"

seven_segment_t sev_seg={
	.port_name=PORTA_INDEX
};

keypad_t keypad_1={
	.keypad_rows[0].port_name=PORTD_INDEX,
	.keypad_rows[1].port_name=PORTD_INDEX,
	.keypad_rows[2].port_name=PORTD_INDEX,
	.keypad_rows[3].port_name=PORTD_INDEX,
	.keypad_rows[0].pin_number=PIN_0,
	.keypad_rows[1].pin_number=PIN_1,
	.keypad_rows[2].pin_number=PIN_2,
	.keypad_rows[3].pin_number=PIN_3,
	.keypad_columns[0].port_name=PORTD_INDEX,
	.keypad_columns[1].port_name=PORTD_INDEX,
	.keypad_columns[2].port_name=PORTD_INDEX,
	.keypad_columns[3].port_name=PORTD_INDEX,
	.keypad_columns[0].pin_number=PIN_4,
	.keypad_columns[1].pin_number=PIN_5,
	.keypad_columns[2].pin_number=PIN_6,
	.keypad_columns[3].pin_number=PIN_7,
};



void initialize_function(void);
uint8_t value =0 ;
int main(void)
{
	initialize_function();
	
	while (1)
	{	
		value=HAL_KEYPAD_READ_VALUE(&keypad_1);
		HAL_SEVEN_SEGMENT_WRITE_VAL(&sev_seg,value); 
		
	}
}

void initialize_function(void){
   HAL_SEVEN_SEGMENT_INITIAIZE(&sev_seg);
   HAL_KEYPAD_INITIALIZE(&keypad_1);
}
















/*
* GPIO_Test.c
*
* Created: 9/26/2021 8:09:47 PM
* Author : Khelad Mohamed
*/

#include "main.h"


led_t led_0={
	.port_name=PORTA_INDEX,
	.pin_name=PIN_0
};

external_interrupt_t int_0={
	.sourse=EXTERNAL_INT0,
	.control=INT_CON_RISING
};

uint8_t val ;
int main(void)
{
	initialize_function();
	val = MCAL_EEPROM_READ_VALUE(0x0030);
	while (1)
	{	
		if (val==0x50)
		{
			HAL_LED_TURN_OFF(&led_0);
			
		}else{
			HAL_LED_TURN_ON(&led_0);
		}
		
		
	}
}

void initialize_function(void){
	sei();
	SET_BIT(EECR,EERIE);

   HAL_LED_INITIALIZE(&led_0);
   MCAL_EXTERNAL_INTTERUPT_INITIALIZE(&int_0);
   MCAL_EEPROM_WRITE_VALUE(0x0030,0x50);
}

ISR(EE_RDY_vect){
	HAL_LED_TURN_ON(&led_0);
	_delay_ms(2000);
	CLR_BIT(EECR,EERIE);
}












/*
* GPIO_Test.c
*
* Created: 9/26/2021 8:09:47 PM
* Author : Khelad Mohamed
*/

#include "main.h"


led_t led_0={
	.port_name=PORTA_INDEX,
	.pin_name=PIN_0
};

external_interrupt_t int_0={
	.sourse=EXTERNAL_INT0,
	.control=INT_CON_RISING
};

int main(void)
{
	initialize_function();
	
	while (1)
	{	
		
		HAL_LED_TURN_OFF(&led_0);
	}
}

void initialize_function(void){
   HAL_LED_INITIALIZE(&led_0);
   MCAL_EXTERNAL_INTTERUPT_INITIALIZE(&int_0);
}

ISR(INT0_vect){
	HAL_LED_TURN_ON(&led_0);
	_delay_ms(1000);
}

