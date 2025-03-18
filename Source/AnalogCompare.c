# include "../HEADER/AnalogCompare.h"
static uint8_t IntEnb=0;
static ACRsult INTVALUE;
static ACInterrup HigherCallBack=NULL;
static ACInterrup LowerCallBack=NULL;
BaseType_t ACInit(uint8_t Mode){
    ACSR &= ~(1 << ACD);  // Enable Comparator
    if (Mode==ACInternal) {
        ACSR |= (1 << ACBG);  // Use 1.1V internal reference
        return pdSucsess;
    }else if (Mode==ACExternal) {
        ACSR &= ~(1 << ACBG);
        return pdSucsess;
    }else{
        return pdFail;
    }

}
ACRsult   ACValue(void){
    if (IntEnb==0){
        if(ACSR & (1 << ACO)){
            return lower;
        }else{ return Higher;}
    }
    else return INTVALUE;
}
BaseType_t ACEnableInterrupt(ACInterrup *HigherFunction,ACInterrup *LowerFunction){
    if (!HigherFunction||!LowerFunction) {
        ACSR |= (1 << ACIE); // Enable Interrupt
        sei();
        return pdSucsess;
    }
    else{
        IntEnb=1;
        HigherCallBack = HigherFunction;
        LowerCallBack = LowerFunction;
        ACSR |= (1 << ACIE); // Enable Interrupt
        sei();    // Enable global interrupts
        return pdSucsess;
    }
}
//uint8_t   ACInterruptValue(void);
/*
ISR(ANALOG_COMP_vect) {
    if (ACSR & (1 << ACO)) {
        if (HigherCallBack) HigherCallBack(); // Rising edge
        INTVALUE=lower;
    } else {
        INTVALUE=Higher;
        if (LowerCallBack) LowerCallBack(); // Falling edge
    }
    
}*/