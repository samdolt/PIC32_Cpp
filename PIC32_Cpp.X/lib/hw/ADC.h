/* 
 * File:   ADC.h
 * Author: Sam
 *
 * Created on 11. avril 2014, 20:39
 */

#ifndef ADC_H
#define	ADC_H

#include <stdint.h>

class ADC {
public:
    ADC();
    uint16_t read_input(uint8_t input_number);
    virtual ~ADC();
private:

};

#endif	/* ADC_H */

