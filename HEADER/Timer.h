/* 
 * File:   Timer.h
 * Author: omar
 *
 * Created on March 14, 2025, 2:35 AM
 */

#ifndef TIMER_H
#define	TIMER_H

#include "GPIO.h"
#include "EXTINTERRUPT.h"




typedef enum {
    Normal,
    CTC,
    FASTPWM,
    PHASEPWM
}TimerModes_t;

typedef enum{
    NOSOURCE,
    CLK_No,
    CLK_8,
    CLK_64,
    CLK_256,
    CLK_1024,
    TFalling,
    TRaising
}TimerPrescaler_t;
void Timer0_Init(TimerModes_t mode,TimerPrescaler_t pres );
uint16_t Timer0GetTick(void);
void Timer0_delay(uint8_t ms);
void Timer0_NONBdelay(uint8_t ms);
void Timer0_PWM(uint8_t Dety);

void Timer2_Init(TimerModes_t mode,TimerPrescaler_t pres );
uint16_t Timer2GetTick(void);
void Timer2_delay(uint16_t ms);
void Timer2_NONBdelay(uint16_t ms);
void Timer2_PWM(uint16_t Dety);

void Timer1_Init(TimerModes_t mode,TimerPrescaler_t pres );
uint16_t Timer1GetTick(void);
void Timer1_delay(uint32_t ms);
void Timer1_NONBdelay(uint32_t ms);
void Timer1_PWM(uint32_t Dety, uint16_t freq);
void Timer1_SetCompare(uint16_t value);
void Timer1_SetCallback(void (*callback)(void));
void Timer1_Start_cap(uint16_t value);
uint32_t Timer1_Get_cap();

 


#endif	/* TIMER_H */

