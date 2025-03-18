#include "../HEADER/ADC.h"

static void (*
ADC_Callback)(void) = NULL;BaseType_t ADC_Init(ADC_config_t *adc){
    if(!adc)return pdFail;
    switch (adc->ref){
        case ADC_REF_AREF:
            ClearBit(ADMUX,REFS0);
            ClearBit(ADMUX,REFS1);
            break;
        case ADC_REF_AVCC:
            SetBit(ADMUX,REFS0);
            ClearBit(ADMUX,REFS1);
            break;
        case ADC_REF_INTERNAL:
            SetBit(ADMUX,REFS0);
            SetBit(ADMUX,REFS1);
            break;
        default:
            return pdFail;
            break;  
    }
    
    ADCSRA|=adc->prescaler;
    if(adc->adjust){
        SetBit(ADMUX,ADLAR);
    }else ClearBit(ADMUX,ADLAR);
    
    ADC_Enable();
    return pdSucsess;
}
void ADC_Enable(void){
    SetBit(ADCSRA,ADEN);
}
void ADC_Disable(void){
    ClearBit(ADCSRA,ADEN);
}
BaseType_t ADC_StartConversion(ADC_pins channel){
    ADMUX = (ADMUX & 0xF8) | (channel & 0x07);
    
    // Start conversion
    SetBit(ADCSRA, ADSC);

    return pdSucsess;
}
uint16_t ADC_Read(void){
    // Wait until conversion is complete
    while (!(ADCSRA&(1<<ADIF)));

    // Clear the ADC interrupt flag
    SetBit(ADCSRA, ADIF);

    // Read and return ADC value
    return ADC;
}
BaseType_t ADC_ReadNonBlocking(uint16_t *result){
     if (!result) return pdFail;  // Check for a valid pointer

    if (ADCSRA & (1 << ADIF)) { // Check if conversion is complete
        *result = ADC; // Read the ADC value
        SetBit(ADCSRA, ADIF); // Clear the interrupt flag
        return pdSucsess;
    }
    return pdFail; 
}
BaseType_t ADC_EnableAutoTrigger(ADC_AutoTriggerSource_t source){
    ADCSRB=source;
    SetBit(ADCSRA,ADATE);
}
BaseType_t ADC_DisableAutoTrigger(void){
    ClearBit(ADCSRA,ADATE);
}
BaseType_t ADC_EnableInterrupt(void (*callback)(void)){
    if(!callback)return pdFail;
    ADC_Callback = callback; // Store the callback function
    SetBit(ADCSRA, ADIE);    // Enable ADC interrupt
    sei();
    return pdSucsess;
}
BaseType_t ADC_DisableInterrupt(void){
    ClearBit(ADCSRA,ADIE);
    ADC_Callback = NULL;    // Clear callback
    return pdSucsess;
}
uint8_t ADC_GetStatus(void) {
    if (!(ADCSRA & (1 << ADEN))) {
        return ADC_STATUS_DISABLED;  // ADC is disabled
    }
    if (ADCSRA & (1 << ADSC)) {
        return ADC_STATUS_BUSY;  // Conversion in progress
    }
    return ADC_STATUS_READY;  // ADC is ready for a new conversion
}
ISR(ADC_vect) {
    if (ADC_Callback) {
        ADC_Callback(); // Call the user-defined function
    }
}



