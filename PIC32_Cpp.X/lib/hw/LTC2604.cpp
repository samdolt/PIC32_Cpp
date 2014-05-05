/* 
 * File:   LTC2604.cpp
 * Author: doltsa
 * 
 * Created on 5. mai 2014, 09:02
 */

#include "LTC2604.h"
#include "Delay.h"

struct dac_volt volt(float data_in)
{
    struct dac_volt data_out;
    data_out.volt = data_in;
    return data_out;
}

struct dac_channel channel(uint8_t data_in)
{
    struct dac_channel data_out;
    data_out.channel = data_in;
    return data_out;
}


LTC2604::LTC2604(SpiChannel channel, const char CS[], const char CLEAR[]) {
    M_SPI = new SPI(channel, CS);

    M_CLEAR = new DigitalPin(CLEAR);
    M_CLEAR->set_output();
    reset();
}

void LTC2604::reset(void)
{
    M_CLEAR->set_low();
    delay::us(500);
    M_CLEAR->set_high();
}

void LTC2604::set_channel(uint8_t channel)
{
    m_channel = channel;
}

// -1 => -10V et +1 => 10V
void LTC2604::write(float data)
{
    uint16_t data16;

    data16 = 32767.5 - (data * 32767.5);

    // 65535 => -10V
    // 32767 =>   0V
    // 0     => +10V
    
    write_raw(data16);
}



void LTC2604::write(struct dac_volt data)
{
    write(data.volt / 10.0);
}

void LTC2604::write(struct dac_channel data)
{
    m_channel = data.channel;
}

void LTC2604::write_raw( uint16_t data)
{
    M_SPI->enable();
    M_SPI->write((uint8_t) (m_channel + 0x30));
    M_SPI->write(data);
    M_SPI->disable();
}

LTC2604::~LTC2604() {
    delete M_SPI;
}


//DAC << channel(0) << volt(5);


