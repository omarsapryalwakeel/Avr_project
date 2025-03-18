#include "../HEADER/Timer.h"
uint16_t Tick0;
uint16_t Tick2;
uint16_t Tick1;
static void (*TIMER1_CALLBACK)(void) = NULL;

void Timer0_Init(TimerModes_t mode,TimerPrescaler_t pres ){
    switch (mode){
        case Normal:
            ClearBit(TCCR0A,WGM00);
            ClearBit(TCCR0A,WGM01);
            ClearBit(TCCR0B,WGM02);
            break;
        case CTC:
            ClearBit(TCCR0A,WGM00);
            SetBit(TCCR0A,WGM01);
            ClearBit(TCCR0B,WGM02);
            break;
        case PHASEPWM:
            SetBit(DDRD,PD6);
            SetBit(TCCR0A,WGM00);
            ClearBit(TCCR0A,WGM01);
            ClearBit(TCCR0B,WGM02);
            SetBit(TCCR0A,COM0A1);
            break;
        case FASTPWM:
            SetBit(DDRD,PD6);
            SetBit(TCCR0A,WGM00);
            SetBit(TCCR0A,WGM01);
            ClearBit(TCCR0B,WGM02);
            break;
    }
    
    TCCR0B=(TCCR0B&=~(3<<CS00))|(pres<<CS00);
}
uint16_t Timer0GetTick(void){
    TCCR0B = (1 << CS01) | (1 << CS00);  // Prescaler = 64
    TIMSK0 = (1 << TOIE0);
    sei();
    return Tick0;
}
void Timer0_delay(uint8_t ms){
    TCCR0B=(1<<CS00);
    TIMSK0 = (1 << TOIE0);
    sei();
    uint16_t ticks=(ms*(F_CPU/1000000UL));
    TCNT0=0;
    while(TCNT0<ticks);
}
void Timer0_NONBdelay(uint8_t ms){
    static uint16_t last_time = 0;
    if((Timer0GetTick()-last_time)>=ms){
        last_time=Timer0GetTick();
    }
}
void Timer0_PWM(uint8_t Dety){
    OCR0A=Dety*256/100;
}
ISR(TIMER0_OVF_vect){
    Tick0++;
}

void Timer2_Init(TimerModes_t mode,TimerPrescaler_t pres ){
     switch (mode){
        case Normal:
            ClearBit(TCCR2A,WGM00);
            ClearBit(TCCR2A,WGM01);
            ClearBit(TCCR2B,WGM02);
            break;
        case CTC:
            ClearBit(TCCR2A,WGM00);
            SetBit(TCCR2A,WGM01);
            ClearBit(TCCR2B,WGM02);
            break;
        case PHASEPWM:
            SetBit(DDRB,PB3);
            SetBit(TCCR2A,WGM00);
            ClearBit(TCCR2A,WGM01);
            ClearBit(TCCR2B,WGM02);
            SetBit(TCCR2A,COM0A1);
            break;
        case FASTPWM:
            SetBit(DDRB,PB3);
            SetBit(TCCR2A,WGM00);
            SetBit(TCCR2A,WGM01);
            ClearBit(TCCR2B,WGM02);
            break;
    }
    
    TCCR2B=(TCCR2B&=~(3<<CS20))|(pres<<CS20);
}
uint16_t Timer2GetTick(void){
    TIMSK1 = (1 << TOIE1);
    TCCR2B = (1 << CS01) | (1 << CS00);
    sei();
    return Tick2;
}
void Timer2_delay(uint16_t ms){
    TCCR2B=(1<<CS00);
    uint16_t ticks=(ms*(F_CPU/1000000UL));
    TCNT2=0;
    while(TCNT2<ticks);
}
void Timer2_NONBdelay(uint16_t ms) {
    static uint16_t last_time = 0;
    if((Timer2GetTick()-last_time)>=ms){
        last_time=Timer2GetTick();
    }
}
void Timer2_PWM(uint16_t Dety){
   OCR2A=Dety*256/100; 
}


ISR(TIMER2_OVF_vect){
    Tick2++;
}


void Timer1_Init(TimerModes_t mode,TimerPrescaler_t pres ){
    switch (mode){
        case Normal:
            ClearBit(TCCR1A,WGM10);
            ClearBit(TCCR1A,WGM11);
            ClearBit(TCCR1B,WGM12);
            ClearBit(TCCR1B,WGM13);
            break;
        case CTC:
            ClearBit(TCCR1A,WGM10);
            ClearBit(TCCR1A,WGM11);
            SetBit  (TCCR1B,WGM12);
            ClearBit(TCCR1B,WGM13);
            break;
        case PHASEPWM:
            SetBit(DDRB,PB1);
            SetBit  (TCCR1A,WGM10);
            SetBit  (TCCR1A,WGM11);
            SetBit  (TCCR1B,WGM12);
            ClearBit(TCCR1B,WGM13);
            break;
        case FASTPWM:
            SetBit(DDRB,PB1);
            ClearBit(TCCR1A,WGM10);
            SetBit  (TCCR1A,WGM11);
            SetBit  (TCCR1B,WGM12);
            SetBit  (TCCR1B,WGM13);
            break;
    }
    
    TCCR2B=(TCCR2B&=~(3<<CS20))|(pres<<CS20);
}
uint16_t Timer1GetTick(void){
    TIMSK1 = (1 << TOIE1);
    TCCR2B = (1 << CS01) | (1 << CS00);
    sei();
    return Tick1;
}
void Timer1_delay(uint32_t ms){
    TCCR1B=(1<<CS00);
    uint16_t ticks=(ms*(F_CPU/1000000UL));
    TCNT1=0;
    while(TCNT1<ticks);
}
void Timer1_NONBdelay(uint32_t ms){
    static uint16_t last_time = 0;
    if((Timer1GetTick()-last_time)>=ms){
        last_time=Timer1GetTick();
    }
}
void Timer1_PWM(uint32_t Dety, uint16_t freq){
    uint16_t top = (F_CPU / (2 * 8 * freq)) - 1;
    ICR1 = top;  // Set frequency (TOP value)
    OCR1A = (Dety * top) / 100;  // Set duty cycle
}
void Timer1_Start_cap(uint16_t value){
    OCR1A = value;  // Set compare value
    TIMSK1 |= (1 << OCIE1A);  // Enable Compare Match Interrupt
}
uint32_t Timer1_Get_cap(){
    return ICR1;  // Return captured value
}
void Timer1_SetCallback(void (*callback)(void)){
    TIMER1_CALLBACK = callback;
}
ISR(TIMER1_OVF_vect){
    Tick1++;
}
ISR(TIMER1_COMPA_vect){
    if (TIMER1_CALLBACK) TIMER1_CALLBACK();
}