/*
 * File name            : delay.c
 * Compiler             : MDK-Lite
 * IDE                  : Keil uVision V5
 * Author               : Etiq Technologies
 * Processor            : LPC1768
 * Created on           : June 09, 2017, 9:44 AM
 * Description          : Delay Main File
 */
#include "delay.h"

void delay(int cnt)
{
    int i;
    for(i=0;i<cnt;i++);
}

void delay_ms(unsigned int ms)
{
    unsigned int i,j;

    for(i=0;i<ms;i++)
        for(j=0;j<20000;j++);
}
