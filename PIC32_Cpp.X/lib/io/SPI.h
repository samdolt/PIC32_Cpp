/* 
 * File:   SPI.h
 * Author: doltsa
 *
 * Created on 5. mai 2014, 08:30
 */

#ifndef SPI_H
#define	SPI_H

#include <cstdint>
#include <plib.h>

#include "DigitalPin.h"


class SPI {
public:
    SPI(SpiChannel channel, const char CS[]);
    void configure(void);
    void enable(void);
    void disable(void);
    void write(uint8_t data);
    void write(uint16_t data);
    virtual ~SPI();
private:
    SpiChannel M_CHANNEL;
    DigitalPin * M_CS;

};

#endif	/* SPI_H */