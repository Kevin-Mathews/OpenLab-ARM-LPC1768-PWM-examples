/*
 * File name            : main.c
 * Compiler             : MDK-Lite
 * IDE                  : Keil uVision V5
 * Author               : Etiq Technologies
 * Processor            : LPC1768
 * Created on           : June 15, 2017, 9:44 AM
 * Description          : PWM Test Program
 */


#include <lpc17xx.h>
#include "delay.h"

/* REGISTER DEFINITIONS */
#define Timer_Counter				LPC_PWM1->TCR				
#define Prescaler						LPC_PWM1->PR 				
#define Match_Control_Reg		LPC_PWM1->MCR				
#define Pin_Select4					LPC_PINCON->PINSEL4	
#define Latch_EN_Reg				LPC_PWM1->LER				
#define PWM_Control					LPC_PWM1->PCR

/* MATCH REGISTER DEFINITIONS */
#define Match_Reg0			LPC_PWM1->MR0		
#define Match_Reg1			LPC_PWM1->MR1		
#define Match_Reg2			LPC_PWM1->MR2		
#define Match_Reg3			LPC_PWM1->MR3		
#define Match_Reg4			LPC_PWM1->MR4		
#define Match_Reg5			LPC_PWM1->MR5		
#define Match_Reg6			LPC_PWM1->MR6		

#define PWMMR0R		   	 1

/* PCR REGISTER DEFINITIONS */
#define Count_EN     	 0 
#define PWM_EN	     	 3

/* LER REGISTER DEFINITIONS */
#define Latch_EN0      0
#define Latch_EN1      1
#define Latch_EN2      2
#define Latch_EN3      3
#define Latch_EN4      4
#define Latch_EN5      5
#define Latch_EN6      6

/* PCR REGISTER DEFINITIONS */
#define PWM_EN1			   9
#define PWM_EN2			   10
#define PWM_EN3		  	 11
#define PWM_EN4			   12
#define PWM_EN5			   13
#define PWM_EN6			   14

/* PINSEL4 REGISTER DEFINITIONS */
#define PWM_1          0 
#define PWM_2          2 
#define PWM_3          4 
#define PWM_4          6 
#define PWM_5          8 
#define PWM_6          10 



int main(void)
{
    int D_Cycle;
    SystemInit();

		Pin_Select4 &= ~0x00000FFF;			//Clear any previous values
		Pin_Select4 |= (1<<PWM_1);			//Selecting PWM1.1
	
		Match_Control_Reg = (1<<PWMMR0R);  

    Match_Reg0 = 100;               // Full Cycle = On Time + Off Time = 100
	
    Latch_EN_Reg = (1<<Latch_EN0);

		Timer_Counter &= ~0x0000000F;		// Clear any previous values
		Timer_Counter |= ((1<<PWM_EN)|(1<<Count_EN));
		Prescaler  =  0x00;

    PWM_Control = (1<<PWM_EN1);			// Enable PWM1 Output

    while(1)
    {
			/* FOR LOOPS TO CREATE A SMOOTH LED TRANSITION PWM OUTPUT*/
			
        for(D_Cycle=0; D_Cycle<100; D_Cycle++)
        {
            Match_Reg1 = D_Cycle;
						Latch_EN_Reg = (1<<Latch_EN1); 
            delay_ms(5);
        }

        for(D_Cycle=99; D_Cycle>1; D_Cycle--)
        {
            Match_Reg1 = D_Cycle;
						Latch_EN_Reg = (1<<Latch_EN1);
            delay_ms(5);
        }
    }
} 