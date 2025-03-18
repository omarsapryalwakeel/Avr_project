/* 
 * File:   EXTINTERRUPT.h
 * Author: omar
 *
 * Created on March 13, 2025, 10:06 PM
 */

#ifndef EXTINTERRUPT_H
#define	EXTINTERRUPT_H
#include "avr/interrupt.h"
#include "GPIO.h"


#define MaxCallbackFunction  3

typedef enum {
    EXINT_OK,
            EXINT_ERROR_NILL_PTR,
            EXINT_ERROR_INVALID_INT
}EXINT_STATUS_t;
typedef enum {
    EXINT0,
    EXINT1,
}EXIntPin_t;

typedef enum {
    LowLevel,
            AnyLogicChange,
            Falling,
            Raising
}EXIntSense_config;

typedef void(*ISRCallBack)(void);
typedef struct {
    EXIntPin_t pin;
    EXIntSense_config Sense;
    ISRCallBack Function[MaxCallbackFunction];
    uint8_t CallbackCount;
}EXINTConfig_t;
EXINT_STATUS_t EXINTx_Init(EXINTConfig_t *config);
EXINT_STATUS_t EXINT_AddCallbackFUnction(EXIntPin_t EXINTx,ISRCallBack Callback);
EXINT_STATUS_t EXINTx_DEInit(EXINTConfig_t *config);
#endif	/* EXTINTERRUPT_H */

