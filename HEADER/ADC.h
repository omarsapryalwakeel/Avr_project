/* 
 * File:   ADC.h
 * Author: omar
 *
 * Created on March 18, 2025, 1:20 AM
 */

#ifndef ADC_H
#define	ADC_H

#include"../DataTypes.h"
#include"../Maicros.h"
#include <avr/interrupt.h>


#define ADC_STATUS_DISABLED  0
#define ADC_STATUS_BUSY      1
#define ADC_STATUS_READY     2

// ADC Reference Voltage Options
typedef enum {
    ADC_REF_AREF = 0,  // AREF, Internal VREF turned off
    ADC_REF_AVCC = 1,  // AVCC with external capacitor at AREF pin
    Rsservd=3,
    ADC_REF_INTERNAL = 4  // Internal 1.1V Reference
} ADC_Reference_t;

// ADC Prescaler Selection
typedef enum {
    ADC_PRESCALER_2   = 1,
    ADC_PRESCALER_4   = 2,
    ADC_PRESCALER_8   = 3,
    ADC_PRESCALER_16  = 4,
    ADC_PRESCALER_32  = 5,
    ADC_PRESCALER_64  = 6,
    ADC_PRESCALER_128 = 7
} ADC_Prescaler_t;

// ADC Auto Trigger Source
typedef enum {
    ADC_FREE_RUNNING = 0,  // Free Running Mode
    ADC_ANALOG_COMP = 1,   // Analog Comparator
    ADC_EXT_INT0 = 2,      // External Interrupt Request 0
    ADC_TIMER0_CMP = 3,    // Timer/Counter0 Compare Match A
    ADC_TIMER0_OVF = 4,    // Timer/Counter0 Overflow
    ADC_TIMER1_CMPB = 5,   // Timer/Counter1 Compare Match B
    ADC_TIMER1_OVF = 6,    // Timer/Counter1 Overflow
    ADC_TIMER1_CAPT = 7    // Timer/Counter1 Capture Event
} ADC_AutoTriggerSource_t;
typedef enum {
    ADC0,
    ADC1,
    ADC2,
    ADC3,
    ADC4,
    ADC5,
    ADC6,
    ADC7,
}ADC_pins;
// ADC Data Adjustment (Left/Right)
typedef enum {
    ADC_RIGHT_ADJUST = 0,
    ADC_LEFT_ADJUST = 1
} ADC_Adjustment_t;

typedef struct{
    ADC_Reference_t ref; 
    ADC_Prescaler_t prescaler;
    ADC_Adjustment_t adjust;
}ADC_config_t;

// Function Prototypes
BaseType_t ADC_Init(ADC_config_t *adc);
void ADC_Enable(void);
void ADC_Disable(void);
BaseType_t ADC_StartConversion(ADC_pins channel);
uint16_t ADC_Read(void);
BaseType_t ADC_ReadNonBlocking(uint16_t *result);
BaseType_t ADC_EnableAutoTrigger(ADC_AutoTriggerSource_t source);
BaseType_t ADC_DisableAutoTrigger(void);
BaseType_t ADC_EnableInterrupt(void (*callback)(void));
BaseType_t ADC_DisableInterrupt(void);
uint8_t ADC_GetStatus(void);


#endif	/* ADC_H */

