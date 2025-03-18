/* 
 * File:   GPIO.h
 * Author: omar
 *
 * Created on March 12, 2025, 11:23 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#include <avr/io.h>
#include "../DataTypes.h"
#include "../Maicros.h"
typedef enum {
    ddrb,
    ddrc,
    ddrd,
}PortConfig_t;

typedef enum {
    Input,
    Output
}DiectionConfig_t;
typedef enum {
    NON,
    PULLUP
}PullUpConfig_t;

typedef enum {
    LOW,
    HIGH,
}GPIO_PIN_STATE_t;

typedef enum {
    P0,
    P1,
    P2,
    P3,
    P4,
    P5,
    P6,
    P7,
}PinConfig_t;
typedef struct {
    PortConfig_t GPIOPort;
    PinConfig_t PIN;
    DiectionConfig_t DIR;
    PullUpConfig_t pull;
}GPIOConfig_t;

BaseType_t GPIO_Init(GPIOConfig_t *GPIO);
BaseType_t GPIO_Set_pin(GPIOConfig_t *GPIO,GPIO_PIN_STATE_t GPIO_PIN_STATE);
BaseType_t GPIO_Toggle_pin(GPIOConfig_t *GPIO);
BaseType_t GPIO_Read_PIN(GPIOConfig_t *GPIO,GPIO_PIN_STATE_t *PIN);
#endif	/* GPIO_H */

