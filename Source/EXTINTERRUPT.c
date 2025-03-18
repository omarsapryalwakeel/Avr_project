

#include "../HEADER/EXTINTERRUPT.h"

static EXINTConfig_t EXConfig[MaxCallbackFunction]={
    {EXINT0,Falling,{NULL},0},
    {EXINT1,Falling,{NULL},0}
};

EXINT_STATUS_t EXINTx_Init(EXINTConfig_t *config){
    if(!config)return EXINT_ERROR_NILL_PTR;
    sei();
    EXINTConfig_t *intconfig=&EXConfig[config->pin];
    intconfig->Sense=config->Sense;
    uint8_t i;
    for (i = 0; i < config->CallbackCount; i++) {
        EXINT_AddCallbackFUnction(config->pin,config->Function[i]);
    }
    
    switch(config->pin){
        case EXINT0:
            EICRA=(EICRA &=~(3<<ISC00))|(config->Sense<<ISC00);
            SetBit(EIMSK,INT0);
            break;
        case EXINT1:
            EICRA=(EICRA &=~(3<<ISC10))|(config->Sense<<ISC10);
            SetBit(EIMSK,INT1);
            break;
        default:
            return EXINT_ERROR_INVALID_INT;
            
    }
    return EXINT_OK;
}
EXINT_STATUS_t EXINT_AddCallbackFUnction(EXIntPin_t EXINTx,ISRCallBack Callback){
    if(!Callback)return EXINT_ERROR_NILL_PTR;
    EXINTConfig_t *intconfig=&EXConfig[EXINTx];
    if(intconfig->CallbackCount>=MaxCallbackFunction)return EXINT_ERROR_INVALID_INT;
    intconfig->Function[intconfig->CallbackCount++]=Callback;
     if (intconfig->Function[intconfig->CallbackCount - 1] == Callback) {
        // Function stored successfully
         
    } else {
        // Error storing function
    }
    return EXINT_OK;
}
EXINT_STATUS_t EXINTx_DEInit(EXINTConfig_t *config){
    if(!config)return EXINT_ERROR_NILL_PTR;
    switch(config->pin){
        case EXINT0:
            ClearBit(EIMSK,INT0);
            return EXINT_OK;
        case EXINT1:
            ClearBit(EIMSK,INT1);
            return EXINT_OK;
        default:
            return EXINT_ERROR_INVALID_INT;
            
    }
}

ISR(INT0_vect){
    for (int i = 0; i < EXConfig[EXINT0].CallbackCount; i++) {
        if (EXConfig[EXINT0].Function[i]) {
            EXConfig[EXINT0].Function[i]();
            
        }
    }
    EIFR |= (1 << INTF0);  // Writing 1 clears the flag
}

ISR(INT1_vect){
    for(int i = 0; i < EXConfig[EXINT1].CallbackCount; i++){
        if(EXConfig[EXINT1].Function[i]) EXConfig[EXINT1].Function[i]();
    }
}
