#include "SysTick.h"
#include "tm4c123gh6pm.h"
#include "stdint.h"

// Used in part 2B
volatile uint32_t g_handler_calls;

//Initialize Systick
void SysTick_Init(void){
NVIC_ST_CTRL_R = 0x00; //1) Disable Systick during setup
NVIC_ST_RELOAD_R =0x00FFFFFF; //2) maximum reload value
NVIC_ST_CURRENT_R =0x00; //3) any value to current clears it
NVIC_ST_CTRL_R =0x00000005; //4) enable Systick with core clock
}


// Configure SysTick to generate an interrupt priodically, used in part 2B
// Assume 16 MHz clock
void SysTick_Init_Interrupts(void){
	g_handler_calls = 0; //Initialize counter as 0
  NVIC_ST_RELOAD_R =0x000; //Disable Systick During Setup
	NVIC_ST_RELOAD_R = 0x3D08F; //ticks = (25E6)(10E-3) -1 in hex
	NVIC_ST_CURRENT_R = 0; //any write to current clears it
	NVIC_ST_CTRL_R =0x007; //enable Systick with core clock and interrupts
	
}


// Clock speed is 16 MHz
static void SysTick_Delay100us_16MHz(void){
	//Use the Systick Timer to generate a 0.1ms delay
	NVIC_ST_RELOAD_R = 0x63F; //tick = ([16E6][100E-6])-1 HEX

	
	NVIC_ST_CURRENT_R = 0; // Any value written to write clears it
	while((NVIC_ST_CTRL_R&0x00010000)==0){} // Wait for count flag
}


// Write code to generate a 1 sec delay
// Your code should call SysTick_Delay100us_16MHz()
void SysTick_Delay1s_16MHz(void){
int i = 0;
for (i = 0; i<10000;i++){
	SysTick_Delay100us_16MHz();
}
} 

	


// 
// Interrupt handling routine should be writtne here
void SysTick_Handler(void){
		#define PA2 (*((volatile uint32_t *)0x40004010)) // red
    #define PA3 (*((volatile uint32_t *)0x40004020)) // blue
		#define PA4 (*((volatile uint32_t *)0x40004040)) // green
	
		
	
		
	
	if(g_handler_calls%100 == 0){
		PA2 = 0xFF;
		PA3 = 0xFF;
		PA4 = 0xFF;

	}
	if(g_handler_calls%200 == 0){
		PA2 = 0x00;
	}
	if(g_handler_calls%300 == 0){
		PA3 = 0x00;
	}
	if(g_handler_calls%400 == 0){
		PA4 = 0x00;
	}

	g_handler_calls++;
}
