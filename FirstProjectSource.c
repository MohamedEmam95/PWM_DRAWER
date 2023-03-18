/*
 * FirstProjectSource.c

 *
 *  Created on: Dec 23, 2022
 *      Author: dell
 */

#include "TIMERS.h"
#include "MACROS.h"
#include <stdlib.h>
#include "LCD_Driver.h"


int main() {
	LCD_Init();
	Ti2_Init(T2_PWM);
	Ti2_PWM(10);
	ICU_Init();
	Ti2_Start();

	while(1) {}
}


/*
#include <stdio.h>
#include <util\delay.h>
#include "macros.h"
#include "std_types.h"
//#include "MCU.h"
#include "DIO.h"
#include "lcd.h"
#include "dio_types1.h"
#include <avr\io.h>
#include <avr\interrupt.h>
#include "Interrupt_0.h"
#include "FirstProjectSource.h"
#include "timer0.h"
#include "IIC.h"
#define LED0 Dio_Channel_C2
uint8 key=0;
uint8 address=0x80;
u32 counter_timer0 = 0;
int main(){
	/*Init_Timer0();
	DDRC = 0b10000010;
	PORTC = 0b00000000;
	DDRD = 0b00001000;
	PORTD = 0b00001000;
	ptr[0] =fun1;
	ptr[1] =fun2;
	ptr[2] =fun3;
	while(1);*/

	// I2C code
   /* u8 ptr;
	I2C_slave_init(0b00000001);
	setbit(DDRC,7);
	clearbit(PORTC,7);
	while(1){
		I2C_Match();
		read_data(&ptr);
		if (ptr == 'A'){
			togglebit(PORTC,7);
			_delay_ms(1000);
		}
	}*/
	//SPI code
	/*
    Init_SPI();
    u8 ptr;
    setbit(DDRC,7);
    clearbit(PORTC,7);
	while(1){
		slaveRead(&ptr);
		if(ptr == 'A'){
			setbit(PORTC,7);
		}
	}//End of SPI code
	*/
	// UART code
	/*
	Init_UART(103);
	while(1)
	{
	Transmit('A');
	}
	//End of UART cod
	 */
	//DC motor code
	/*setbit(DDRD,4);
	setbit(PORTD,4);
	setbit(DDRD,5);
	setbit(PORTD,5);
	setbit(DDRC,3);
	setbit(DDRC,4);
	setbit(DDRC,5);
	setbit(DDRC,6);
	setbit(PORTC,3);
	setbit(PORTC,4);
	setbit(PORTC,5);
	setbit(PORTC,6);
	while(1){

	}*/
	//End of DC motor code

	//PWM_code_2
	/*setbit(SREG,7);
	setbit(DDRB,6);
    setbit(PORTB,6);
		Init_Timer0();
		while(1){

		}*/
	//End of PWM_code_2
	//PWM_code_1
	/*Init_PWM();
	OCR0 = 12;
	while(1){
		_delay_ms(1000);
		OCR0 = 25;
		_delay_ms(1000);
		OCR0 = 12;
	}*/
	//End of PWM_code_!

	//timer0 code
	/*setbit(SREG,7);
	DDRC = 0b10000000;
	PORTC = 0b00000000;
	Init_Timer0();
	while(1){

	}
	//End of timer0 code

	//ADC code
	/*char String[5];
		int value;
		DDRC = DDRC = 0b10000000;
		PORTC = 0b00000000;

		ADC_Init();
		LCD_Init();			// Initialization of LCD
		LCD_String("ADC value");	// Write string on 1st line of LCD

		while(1)
		{

			LCD_Command(0xc4);	// LCD16x2 cursor position
			value=ADC_Read(1);	// Read ADC channel 0
			itoa(value,String,10);	// Integer to string conversion
			LCD_String(String);
			LCD_String("  ");
			if (value >500){
				PORTC = 0b00000000;
			}
			else{
				PORTC = 0b10000000;
			}

		}

// End of code ADC
 */
	/*DDRC = 0b10000000;
	PORTC = 0b00000000;
	ADMUX = 0b01100001;
	setbit(ADCSRA,5);
	clearbit(SFIOR,5);
	clearbit(SFIOR,6);
	clearbit(SFIOR,7);
	clearbit(ADCSRA,0);
	setbit(ADCSRA,1);
	setbit(ADCSRA,2);
	setbit(ADCSRA,7);





	while(1){
		setbit(ADCSRA,6);
		if (getbit(ADCSRA,ADIF)==0){
			setbit(ADCSRA,ADIF);
			u16 result = (ADCH << 2);

			u32 Voltage = (result * 5000)/1024;
			if (Voltage <=2000){
				PORTC = 0b10000000;
			}
			else if(Voltage <=5000 && Voltage >2000)
			{
				PORTC = 0b00000000;
			}
		}
	}*/
	//Interrupt code
	/*DIO_vSetPinDirection(PORTCC,7,1);
	DIO_vSetPinValue(PORTCC,7,0);
	setbit(SREG,7);
	setbit(GICR,6);
	setbit(MCUCR,0);
	setbit(MCUCR,1);
	EXTI0_Callback(INT0_Function);

	while(1){
	}//End of Interrupt code
	 */

	//Assignment LCD_Keypad
	/*
	Dio_init();
	Dio_WritePort(Dio_Port_C,0x78);
	LCD_Init();
	LCD_Clear();
	int number1 = 0;
	int number2 = 0;
	int result = 0;
	int counter = 0;
	char operation = '0';

	while(1){

		key=GetKeypressed();
		_delay_ms(10);
		if( (key!=KEY_RELEASE)){
			if (counter == 0){
				number1 = key - '0';
				LCD_Char(key);
				key=KEY_RELEASE;
				_delay_ms(100);
				Dio_WriteChannel(LED0,STD_high);
				_delay_ms(1000);
				counter++;
				continue;
			}
			if (counter == 1){
				operation = key;
				LCD_Char(key);
				key=KEY_RELEASE;
				_delay_ms(100);
				Dio_WriteChannel(LED0,STD_high);
				_delay_ms(1000);
				counter++;
				continue;
			}
			if (counter == 2){
				number2 = key - '0';
				LCD_Char(key);
				switch(operation){
				case '+' : result = number1+number2;break;
				case '-' : result = number1-number2;break;
				case '*' : result = number1*number2;break;
				case '/' : result = number1/number2;break;
				case '%' : result = number1%number2;break;
				}
				LCD_Char('=');
				LCD_Char(result + '0');
				key=KEY_RELEASE;
				_delay_ms(100);
				Dio_WriteChannel(LED0,STD_high);
				_delay_ms(1000);
				counter++;
				continue;
			}

			LCD_Char(key);
			key=KEY_RELEASE;
			_delay_ms(100);
			Dio_WriteChannel(LED0,STD_high);
			_delay_ms(1000);


		}//if
		else if(address>0x8F){
			address=0x80;
			Dio_WriteChannel(LED0,STD_low);
			_delay_ms(100);

		}//else

	}//while
	 */
	//End of Assignment LCD_Keypad


	//Assignment hatefdel tnwwar we awwel ma sheel edi el led ttfi
	/*while(1){
		DIO_vSetPinDirection(PORTDD,2,0);
		DIO_vSetPinValue(PORTDD,2,0);
		DIO_vSetPinDirection(PORTCC,2,1);
		DIO_vSetPinValue(PORTCC,2,1);
		if(DIO_u8GetPinValue(PORTDD,2) == 1){
			DIO_vSetPinValue(PORTCC,2,0);
		}
	}
	//End of Assignment hatefdel tnwwar we awwel ma sheel edi el led ttfi
	 */

	//Keypad

	/*Dio_init();
		//Dio_WritePort(Dio_Port_B,0xF0);
		Dio_WritePort(Dio_Port_C,0x78);
	//DIO_vSetPortDirection(PORTDD,0b00001000);
	//DIO_vSetPinValue(PORTDD,3,0);

		while(1){

		key=GetKeypressed();
		_delay_ms(10);
		if(key=='7'){
				Dio_WriteChannel(LED0,STD_high);
				_delay_ms(100);
				Dio_WriteChannel(LED0,STD_low);
				_delay_ms(100);
			}//if
			else{
				Dio_WriteChannel(LED0,STD_low);
						_delay_ms(100);
				}//else
			}//while
	 */
	//LCD Assignment display flashing name

	/*
	LCD_Init();			// Initialization of LCD
	char name[] = "Mohamed";
	u8 length = strlen(name);
	switch(length){
	case 1:
		for(u8 times = 0; times < 16; times++){
			u8 number = (times) * length;
			LCD_String_xy(0,number,name);
			_delay_ms(1000);
			LCD_Clear();
		}break;

	case 2:
		for(u8 times = 0; times < 8; times++){
			u8 number = (times) * length;
			LCD_String_xy(0,number,name);
			_delay_ms(1000);
			LCD_Clear();
		}break;
	case 3:
		for(u8 times = 0; times < 5; times++){
			u8 number = (times) * length;
			LCD_String_xy(0,number,name);
			_delay_ms(1000);
			LCD_Clear();
		}break;
	case 4:
		for(u8 times = 0; times < 4; times++){
			u8 number = (times) * length;
			LCD_String_xy(0,number,name);
			_delay_ms(1000);
			LCD_Clear();
		}break;
	case 5:
		for(u8 times = 0; times < 3; times++){
			u8 number = (times) * length;
			LCD_String_xy(0,number,name);
			_delay_ms(1000);
			LCD_Clear();
		}break;
	case 6:
		for(u8 times = 0; times < 2; times++){
			u8 number = (times) * length;
			LCD_String_xy(0,number,name);
			_delay_ms(1000);
			LCD_Clear();
		}break;
	case 7:
		for(u8 times = 0; times < 2; times++){
			u8 number = (times) * length;
			LCD_String_xy(0,number,name);
			_delay_ms(1000);
			LCD_Clear();
		}break;
	case 8:
		for(u8 times = 0; times < 2; times++){
			u8 number = (times) * length;
			LCD_String_xy(0,number,name);
			_delay_ms(1000);
			LCD_Clear();
		}break;
	default:
		LCD_String(name);
		_delay_ms(1000);
		LCD_Clear();
		break;
	}
	while(1);*/
	//End of Assignment display flashing name


	//LCD_Init();
	//Init_KeyPad();
	//LCD_Char('A');
	//_delay_ms(1000);/* Write string on 1st line of LCD*/
	//LCD_Clear();
	//LCD_Char('B');
	//_delay_ms(1000);/* Write string on 1st line of LCD*/
	//LCD_Clear();
	//LCD_String('C'); /* Write string on 2nd line*/
	//_delay_ms(3000);
	//LCD_Clear();
	//while(1);


	//My code
	/*Init2();
	while(1){
		//u8* word = "Ahmed";
		//goTo(LINE_TWO,4);
		write_character('A');
		_delay_ms(3000);
		clear();
		_delay_ms(3000);
	}*/
	/*char * word = "ABCDEF";
	for (int i = 0; i < 6; i++)
	write_character(word[i]);*/
	//code to show a number
	/*Init();
	show();*/

	//code to count from 0 to 60 for one minute
	/*Init();
		u8 displayValue = 0;
		u8 displayValue2;

		while(1){
			if (displayValue == 6)
				displayValue = 0;
			for(displayValue2 = 0; displayValue2 < 10 ; displayValue2++){
				for(int i = 0; i < 450; i++){
					en1();
					DIO_vSetPortValue(PORTAA,displayValue2 << 4);
					_delay_ms(1);
					dis1();
					en2();
					DIO_vSetPortValue(PORTAA,displayValue << 4);
					_delay_ms(1);
					dis2();
				}

			}
			displayValue++;
		}*/

	//code to count from 0 to 99
	/*Init();
	u8 displayValue = 0;
	u8 displayValue2;

	while(1){
		if (displayValue == 10)
			displayValue = 0;
		for(displayValue2 = 0; displayValue2 < 10 ; displayValue2++){
			for(int i = 0; i < 500; i++){
				en1();
				DIO_vSetPortValue(PORTAA,displayValue2 << 4);
				_delay_ms(1);
				dis1();
				en2();
				DIO_vSetPortValue(PORTAA,displayValue << 4);
				_delay_ms(1);
				dis2();
			}

		}
		displayValue++;
	}*/

	/*while(1){
	DDRD = 0b00000000;
	DDRC = 0b00000100;
	//PORTC = 0b00000000;
	//PORTD = 0xff;
	if((PIND & (1<<2)) == 1){
		PORTC = 0b00000100;
	}
	}

	return 0;
    DDRC = 0b10000100;
	DDRD = 0B00001000;
	while(1){
		PORTC = 0b00000000;
		PORTD = 0b00000000;
		_delay_ms(500);
		PORTC = 0b00000100;
		_delay_ms(500);
		PORTC = 0b00000000;
		PORTC = 0b10000000;
		_delay_ms(500);
		PORTC = 0b00000000;
		PORTD = 0b00001000;
		_delay_ms(500);
		PORTC = 0b10000100;
		PORTD = 0b00001000;
		_delay_ms(500);
	}

	return 0;
}
/*
ISR(INT0_vect){
	//PORTC ^= 0b10000000;
	//_delay_ms(100);
	GPTR();
}
*/

/*
void INT0_Function(void){
	DIO_vSetPinValue(PORTCC,7,1);
}

*/
