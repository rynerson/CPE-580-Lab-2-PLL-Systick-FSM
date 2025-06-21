#include "PortAD.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"

// Bit Specific Address macros will be written below

//Think ! Which port requires all the steps, which one not?
void PortA_Init(void){
	//volatile unsigned long delay;
	//Initialize PA2, PA3, and PA4 as outputs
	SYSCTL_RCGCGPIO_R |= 0x01; //activate clock for port a
	while ((SYSCTL_PRGPIO_R & 0x01) ==0){};
	GPIO_PORTA_AMSEL_R &=~0x1C; //disable analog on PA4-2
	GPIO_PORTA_DIR_R |=0x1C; //PA 2,3,4 out // check value checked
	GPIO_PORTA_DEN_R |=0x1C; //enable digital I/O on PA4-2
}
void PortD_Init(void){
	//Initialize PD1 and PD2 as inputs
	
	SYSCTL_RCGCGPIO_R |=0x08; //activate clock for port D
	while ((SYSCTL_PRGPIO_R&0x08)==0){};
	
	GPIO_PORTD_LOCK_R = 0x4C4F434B; //unlock port D
	GPIO_PORTD_AMSEL_R &=~0x06; //disable analog on PD2-1 //check value checked
	GPIO_PORTD_PCTL_R &= 0x00000000;//PCTL GPIO on PD2-1 // check value checked
	GPIO_PORTD_DIR_R &= ~0x06; //PD1, PD2 in
	GPIO_PORTD_AFSEL_R &= ~0x06; //disable alt function on PD1,PD2 //check value
	GPIO_PORTD_PDR_R |= 0x06;
	GPIO_PORTD_DEN_R |= 0x06; //enable digital I/O on PD2-1  //check values
}
// Returns only the state of the buttons connected to PD1 and PD2
// You may change this function if you wish
uint32_t pushbuttons(void){
	return (GPIO_PORTD_DATA_R & 0x06);
	//return 
}
//Add more function here
