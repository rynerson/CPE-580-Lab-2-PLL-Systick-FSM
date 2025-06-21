# CPE-580-Lab-2-PLL-Systick-FSM
What:
Part A: 
Part 1: 
In the first part of this project, I created a circuit consisting of two switches, a red, blue and green led, and three resistors. When no switch is pressed, the green led turns on. When switch one is pressed, the green led turns off. When switch two is pressed, this RGB pattern occurs (Red on –Red off and Green On –
Green off and Blue On – all LEDs off - Repeat. The delay between each on/off should be 1 second). 
Part B:
Part 2:
The second part of the lab involved implementing another RGB pattern (At the beginning all three LEDs turn on at the same time, but Red LED: 1 second on- 1 second off- repeat, Green LED: 1 second on- 2 seconds off - repeat, and Blue LED: 1 second on- 3 seconds off- repeat.
Part 3:
During the third part of the lab, I implemented a Moore Finite State Machine based sequence detector for the binary "1101". I implemented two versions, with and without sequence detection.
Why: The main goals of the lab was to learn how to set up PLL, set up the inbuilt Systick Timer, and to explore Interrupts. Another goal was to explore abstraction through state machine design.
How: 
Part A:
Part 1:
I setup a circuit consisting of two switches, a red, blue, and green led, and several resistors. The schematic for the setup is in the lab report. I used some of the pins in Port A for the leds, so I initialized that port in my code. I also initialized Port D for the switches. I initialized the Systick timer, and I wrote functions to create a 100 microsecond and a 1 second delay using the 16Mhz clock. I used the 1 second delay to control how often the leds lit up.
Part 2:
I first changed the SysDiv value to 15 to obtain a 25Mhz clock. I initialized the interrupts, and used interrupts to implement the RGB pattern requested in the lab report.
Part 3:
In part 3, I created a finite state machine to emit a green led when the pattern 1101 was found. Switch 1 represented a 0 and Switch two represented a 1. I used delays to mitigate switch bouncing. I implemented to versions, with and without overlap.
Tools Used:
•	Laptop
•	Keil
•	TIVA-C-TM4C123 Launchpad
•	PA2 template
•	Embedded Systems – Shape The World
•	Lecture 4 (PLL, Systick, Interrupt)
•	2 Push Button Switches
•	2 10k resistors
•	3 1k resistors
•	Wires
•	3 leds (Red, Green, Blue)
How to Run:
You will need to create the circuits outlined in each part of the lab report. You will need a laptop and a Tiva-C tm4c123gh6pm Launchpad. You will need to change the Lab_Part to whatever part you are currently on. When you have everything set up, hit build and load within the Keil IDE to run the program.
