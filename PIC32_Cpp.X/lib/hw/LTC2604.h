/* 
 * File:   LTC2604.h
 * Author: doltsa
 *
 * Created on 5. mai 2014, 09:02
 */

#ifndef LTC2604_H
#define	LTC2604_H

#include <cstdint>
#include <plib.h>
#include "SPI.h"
#include "DigitalPin.h"

struct dac_channel {
    uint8_t channel;
};

struct dac_volt {
    float volt;
};

struct dac_volt volt(float data_in);
struct dac_channel channel(uint8_t data_in);

class LTC2604 {
public:
    LTC2604(SpiChannel channel, const char CS[], const char CLEAR[]);
    void reset(void);
    void set_channel(uint8_t channel);
    void write(float data);
    void write(struct dac_volt data);
    void write(struct dac_channel data);
    void write_raw( uint16_t data);
    virtual ~LTC2604();
private:
    SPI * M_SPI;
    DigitalPin * M_CLEAR;
    uint8_t m_channel;
};


/******************************************************************************
 * STREAM SUPPORT
 ******************************************************************************/

/* Template générique, redirige l'opérateur lcd << vers lcd.print pour tous les
 * type
 */
template<class T>
inline LTC2604 &operator <<(LTC2604 &stream, const T data)
{ stream.write(data); return stream; }

#endif	/* LTC2604_H */

