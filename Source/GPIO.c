
#include "../HEADER/GPIO.h"

BaseType_t GPIO_Init(GPIOConfig_t *GPIO){
    BaseType_t RET;
    if (GPIO ==NULL) {
        RET= pdFail;
    } else {
        RET =pdSucsess;
        if(GPIO->DIR==Input){
            if(GPIO->pull==PULLUP){
                ClearBit(MCUCR,PUD);
                switch (GPIO->GPIOPort){
                    case ddrb:
                        SetBit(PORTB,GPIO->PIN);
                        ClearBit(DDRB,GPIO->PIN);
                        break;
                    case ddrc:
                        SetBit(PORTC,GPIO->PIN);
                        ClearBit(DDRC,GPIO->PIN);
                        break;
                    case ddrd:
                        SetBit(PORTD,GPIO->PIN);
                        ClearBit(DDRD,GPIO->PIN);
                        break;
                    default:       
                        RET= pdFail;
                }
            }else{
                switch (GPIO->GPIOPort){
                    case ddrb:
                        ClearBit(PORTB,GPIO->PIN);
                        ClearBit(DDRB,GPIO->PIN);
                        break;
                    case ddrc:
                        ClearBit(PORTC,GPIO->PIN);
                        ClearBit(DDRC,GPIO->PIN);
                        break;
                    case ddrd:
                        ClearBit(PORTD,GPIO->PIN);
                        ClearBit(DDRD,GPIO->PIN);
                        break;
                    default:       
                        RET= pdFail;
                }
            }
        }else{
            switch (GPIO->GPIOPort){
                    case ddrb:
                        SetBit(DDRB,GPIO->PIN);
                        break;
                    case ddrc:
                        SetBit(DDRC,GPIO->PIN);
                        break;
                    case ddrd:
                        SetBit(DDRD,GPIO->PIN);
                        break;
                    default:       
                        RET= pdFail;
                }
        }
    }
    return RET;
}
BaseType_t GPIO_Set_pin(GPIOConfig_t *GPIO,GPIO_PIN_STATE_t GPIO_PIN_STATE){
    BaseType_t RET;
    if (GPIO ==NULL) {
        RET= pdFail;
    } else {
        RET =pdSucsess;
        switch (GPIO->GPIOPort){
            case ddrb:
                if (GPIO_PIN_STATE==HIGH)SetBit(PORTB,GPIO->PIN);
                if (GPIO_PIN_STATE==LOW)ClearBit(PORTB,GPIO->PIN);
                break;
            case ddrc:
                if (GPIO_PIN_STATE==HIGH)SetBit(PORTC,GPIO->PIN);
                if (GPIO_PIN_STATE==LOW)ClearBit(PORTC,GPIO->PIN);
                break;
            case ddrd:
                if (GPIO_PIN_STATE==HIGH)SetBit(PORTC,GPIO->PIN);
                if (GPIO_PIN_STATE==LOW)ClearBit(PORTC,GPIO->PIN);
                break;
            
        }
    }
   return RET; 
}

BaseType_t GPIO_Toggle_pin(GPIOConfig_t *GPIO){
    BaseType_t RET;
    if (GPIO ==NULL) {
        RET= pdFail;
    } else {
        RET =pdSucsess;
        switch (GPIO->GPIOPort){
            case ddrb:
                ToggleBit(PORTB,GPIO->PIN);
                
                break;
            case ddrc:
                ToggleBit(PORTC,GPIO->PIN);
                break;
            case ddrd:
                ToggleBit(PORTC,GPIO->PIN);
                break;
        }
    }
   return RET; 
}
BaseType_t GPIO_Read_PIN(GPIOConfig_t *GPIO,GPIO_PIN_STATE_t *PIN){
    BaseType_t RET;
    if (GPIO ==NULL) {
        RET= pdFail;
    } else {
        RET =pdSucsess;
        switch (GPIO->GPIOPort){
            case ddrb:
            *PIN = (PINB & (1 << GPIO->PIN)) ? HIGH : LOW;
            break;
        case ddrc:
            *PIN = (PINC & (1 << GPIO->PIN)) ? HIGH : LOW;
            break;
        case ddrd:
            *PIN = (PIND & (1 <<GPIO-> PIN)) ? HIGH : LOW;
            break;
        }
    }
   return RET;
}