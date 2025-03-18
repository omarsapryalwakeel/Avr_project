/* 
 * File:   Mai.c
 * Author: omar
 *
 * Created on March 13, 2025, 2:31 AM
 */

#include "HEADER/GPIO.h"
#include "HEADER/EXTINTERRUPT.h"
#include "HEADER/Timer.h"
#include "HEADER/SPI.h"
#include "avr/delay.h"
#include "HEADER/I2C.h"
#include "HEADER/AnalogCompare.h"
#include "HEADER/ADC.h"

uint16_t adcValue;
ADC_config_t adcConfig = {ADC_REF_AVCC, ADC_PRESCALER_128, ADC_RIGHT_ADJUST};
int main(int argc, char** argv) {
    // Initialize ADC
    ADC_Init(&adcConfig);
    while (1) {
        ADC_StartConversion(0);  // Start conversion on Channel 0
        adcValue = ADC_Read();
    }

    return (EXIT_SUCCESS);
}
