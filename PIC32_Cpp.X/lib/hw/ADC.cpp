/* 
 * File:   ADC.cpp
 * Author: Sam
 * 
 * Created on 11. avril 2014, 20:39
 */

#include "ADC.h"

#include <plib.h>

// Define setup parameters for OpenADC10 function
// Turn module on | Ouput in integer format | Trigger mode auto | Enable autosample
#define config1     ADC_FORMAT_INTG | ADC_CLK_AUTO | ADC_AUTO_SAMPLING_ON
// ADC ref external | Disable offset test | Disable scan mode | Perform 2 samples | Use dual buffers | Use alternate mode
#define config2     ADC_VREF_AVDD_AVSS | ADC_OFFSET_CAL_DISABLE | ADC_SCAN_OFF | ADC_SAMPLES_PER_INT_2 | ADC_ALT_BUF_ON | ADC_ALT_INPUT_ON
// Use ADC internal clock | Set sample time
#define config3     ADC_CONV_CLK_INTERNAL_RC | ADC_SAMPLE_TIME_15
#define configport  ENABLE_AN0_ANA | ENABLE_AN1_ANA      // Nouveau
// Do not assign channels to scan
#define configscan  SKIP_SCAN_ALL

ADC::ADC() {
    // Init des entrées analogiques correspondant aux pot
    // AN0 et AN1 PortB RB0 et RB1
    PORTSetPinsAnalogIn(IOPORT_B, BIT_0 | BIT_1);
    CloseADC10();
    // Configure to sample AN0 & AN1
    // Use ground as neg ref for A | use AN0 for input A | use ground as neg ref for A | use AN1 for input B
    SetChanADC10( ADC_CH0_NEG_SAMPLEA_NVREF | ADC_CH0_POS_SAMPLEA_AN0 |  ADC_CH0_NEG_SAMPLEB_NVREF | ADC_CH0_POS_SAMPLEB_AN1);

    OpenADC10( config1, config2, config3, configport, configscan );

    EnableADC10();
}

uint16_t ADC::read_input(uint8_t input_number) {
    unsigned int offset; // Buffer offset to point to the base of the idle buffer

    ConvertADC10();
    while (BusyADC10()) {
        // Attente de la conversion
    };

    // Determine which buffer is idle and create an offset
    offset = 8 * ((~ReadActiveBufferADC10() & 0x01));

    // Lecture résultat de la conversion  "from the idle buffer"
    return ReadADC10(offset + input_number);
}


ADC::~ADC() {
}

