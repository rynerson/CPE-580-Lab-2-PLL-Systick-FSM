// Programming Assignment 2: PortAD-SysTick- PLL-FSM
// Student name: 
// Due Date: Sept 19, 2024

#include "PortAD.h"
#include "SysTick.h"
#include "PLL.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"

// Change this number to the current part of the lab you are working on
#define LAB_PART 4    // 1 for Part2A, 2 for Part 2B, 3 for Part 3 (Without overlapping), and 4 for Part 3 (With overlapping) 




int main(){
	
	// call the port initialization function
	PortA_Init();
	PortD_Init();
	
	if(LAB_PART==1){
		// This should demonstrate the functionality for Part 2A
		SysTick_Init();                   // Function to initialize the SysTick
		#define PA2 (*((volatile uint32_t *)0x40004010)) // red
    #define PA3 (*((volatile uint32_t *)0x40004020)) // blue
		#define PA4 (*((volatile uint32_t *)0x40004040)) // green
		#define PD2 (*((volatile uint32_t *)0x40007010)) //switch 2
    #define PD1 (*((volatile uint32_t *)0x40007008)) //switch 1
		while(1){

			//switch connected to PD1 pushed
			if((GPIO_PORTD_DATA_R)&0x02){
				PA4 = 0x00;
			}
			//switch connected to PD2 pushed
			else if((GPIO_PORTD_DATA_R)&0x04){
				PA4 = 0x00;
				PA2=0xF; //turn red led on
				SysTick_Delay1s_16MHz();
				PA2 = 0x0; //turn red led off
				SysTick_Delay1s_16MHz();
				PA4=0xFF; //turn green led on
				SysTick_Delay1s_16MHz();
				PA4 =0x0; //turn green led off
				SysTick_Delay1s_16MHz();
			  PA3 = 0xF; //turn blue led on
				SysTick_Delay1s_16MHz();
			  PA3 = 0x0; //turn blue led off
				SysTick_Delay1s_16MHz();
				
			}
			//both pushed
			else{
				PA4 =0xFF;
			}
		}
	}
	
	else if(LAB_PART==2){

		// This should demonstrate the functionality for Part 2B
		PLL_Init();
		SysTick_Init_Interrupts();
		
		while(1){
			// Do nothing except wait for a SysTick Interrupt and action taken care at interrupt handler routine
			
		}
	}
	
	
	else if(LAB_PART==3){
		PLL_Init();
		SysTick_Init();
		// This should demonstrate the functionality for Part 3
		// Write the code below for "1101" Sequence detectror - without overalapping
				#define PA2 (*((volatile uint32_t *)0x40004010)) // red
				#define PA4 (*((volatile uint32_t *)0x40004040)) // green
				#define PA3 (*((volatile uint32_t *)0x40004020)) // blue
				PA2 = 0xFF;
				
		int state = 0, button = 0;
		while (1){
			button = (GPIO_PORTD_DATA_R & 0x0F);
			PA3 = 0xFF;
			SysTick_Delay1s_16MHz();
				
		switch(state){
			case 0:
					//if switch 1 is pressed
					PA2 = 0xFF;
					PA4 = 0x00;
					if(button == 0x02){
						state = 1;
						PA3 = 0x00;	
						
					}
					else if(button == 0x06){
						state = 0;
						PA3 = 0x00;
					}
					//else state in state 0
					else{
						state = 0;
					}
				break;
					
			case 1:
					PA4 = 0x00;
					PA2 = 0xFF;
					//if switch 1 is pressed
					if(button == 0x02){
						state = 2;
						PA3 = 0x00;	
					}
					// if both are pressed
					else if(button == 0x06){
						PA3 = 0x00;
						state = 0;	
					}
				//else stay in state 1
				else{
				  
					state = 1;
				}
				break;
				
			 case 2:
					PA4 = 0x00;
					PA2 = 0xFF;
					//if switch 2 is pressed
					if(button == 0x04){
						state = 3;
						PA3 = 0x00;							
						}
					//if both are pressed
					else if(button == 0x06){
						PA3 = 0x00;
						state = 0;					
					}
					//else stay in state 2
				else{
					state = 2;		
				}
				break;
				
			 case 3:
				 PA2 = 0xFF;
				 PA4 = 0x00;
				 //if switch 1 is pressed
				 if(button == 0x02){
					 state = 4; 
					 PA3 = 0x00;	
				 }
				 //if both are pressed
				 else if(button == 0x06){
					 PA3 = 0x00;
					 state = 0;
				 }
				 //else stay in state 3
				 else{
					 state = 3;
				 }
				 break;
				 
			 case 4:
				 //output green
				 PA2 =0x00;
				 PA4 = 0xFF;
				 //if button 1 is pressed, go back to the beginning
				 if(button == 0x02){
			   state = 0;
				 }
				 
			 break;				
		}
		SysTick_Delay1s_16MHz();
	}
}
		
		else if(LAB_PART==4){
		// This should demonstrate the functionality for Part 3
		// Write the code below for "1101" Sequence detectror - with overalapping
			PLL_Init();
		SysTick_Init();
		// This should demonstrate the functionality for Part 3
		// Write the code below for "1101" Sequence detectror - without overalapping
				#define PA2 (*((volatile uint32_t *)0x40004010)) // red
				#define PA4 (*((volatile uint32_t *)0x40004040)) // green
				#define PA3 (*((volatile uint32_t *)0x40004020)) // blue
				PA2 = 0xFF;
				
		int state = 0, button = 0;
		while (1){
			button = (GPIO_PORTD_DATA_R & 0x0F);
			PA3 = 0xFF;
			SysTick_Delay1s_16MHz();
				
		switch(state){
			case 0:
					//if switch 1 is pressed
					PA2 = 0xFF;
					PA4 = 0x00;
					if(button == 0x02){
						state = 1;
						PA3 = 0x00;	
						
					}
					//if both are pressed
					else if(button == 0x06){
						state = 0;
						PA3 = 0x00;
					}
					//else state in state 1
					else{
						state = 0;
					}
				break;
					
			case 1:
					PA2 = 0xFF;
					PA4 = 0x00;
					//if switch 1 is pressed
					if(button == 0x02){
						state = 2;
						PA3 = 0x00;	
					}
					//if both are pressed
					else if(button == 0x06){
						PA3 = 0x00;
						state = 0;	
					}
				//else stay in state 1
				else{
				  
					state = 1;
				}
				break;
				
			 case 2:
					PA2 = 0xFF;
					PA4 = 0x00;
					//if switch 2 is pressed
					if(button == 0x04){
						state = 3;
						PA3 = 0x00;							
						}
					//if both are pressed
					else if(button == 0x06){
						PA3 = 0x00;
						state = 0;					
					}
					//else state in state 2
				else{
					state = 2;		
				}
				break;
				
			 case 3:
				 PA2 = 0xFF;
				 PA4 = 0x00;
			 //if switch 1 is pressed
				 if(button == 0x02){
					 state = 4; 
					 PA3 = 0x00;	
				 }
				 //if both are pressed
				 else if(button == 0x06){
					 PA3 = 0x00;
					 state = 0;
				 }
				 //else stay in state 3
				 else{
					 state = 3;
				 }
				 break;
				 
			 case 4:
				 PA2 =0x00;
				 PA4 = 0xFF;
				 //if switch 2 is pressed
				 if(button == 0x04){
			   state = 0;
				 PA3 = 0;
				 }
				 //if switch 1 is pressed
				 else if(button == 0x02){
					 state = 2;
					 PA3 = 0;
				 }
				 
			 break;				
		}
		SysTick_Delay1s_16MHz();
	}
}
	// Shouldn't reach unless you set an incorrect value for LAB_PART
	else return 0;
}
