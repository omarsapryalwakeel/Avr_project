/* 
 * File:   AnalogCompare.h
 * Author: omar
 *
 * Created on March 17, 2025, 10:01 PM
 */

#ifndef ANALOGCOMPARE_H
#define	ANALOGCOMPARE_H

#include"../DataTypes.h"
#include "../Maicros.h"
#include<avr/interrupt.h>
#define ACInternal      0 //  Use internal 1.1V as AIN0 reference
#define ACExternal      1 // Use external AIN0 and AIN1

typedef void (*ACInterrup)(void);
typedef enum {
    lower,
    Higher,
}ACRsult;
BaseType_t ACInit(uint8_t Mode);
ACRsult   ACValue(void);
BaseType_t ACEnableInterrupt(ACInterrup *HigherFunction,ACInterrup *LowerFunction);
//uint8_t   ACInterruptValue(void);



#endif	/* ANALOGCOMPARE_H */

