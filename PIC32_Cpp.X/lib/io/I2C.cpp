/* 
 * File:   I2C.cpp
 * Author: doltsa
 * 
 * Created on 7. mai 2014, 14:43
 */

#include "I2C.h"

#include "settings.h"

#ifndef I2C_ERROR
    #define I2C_ERROR I2C_MASTER_BUS_COLLISION
#endif

I2C::I2C(I2C_MODULE id) {
    M_PORT = id;
    M_CONFIG = I2C_ENABLE_SLAVE_CLOCK_STRETCHING;
}
void I2C::configure(void)
{
    I2CConfigure( M_PORT, M_CONFIG );
    I2CSetFrequency( M_PORT, get_peripheral_clock(), 100000); // 100Khz
    I2CReceiverEnable(M_PORT, TRUE);
    I2CEnable( M_PORT, TRUE);
    I2CStart( M_PORT);
}

I2C_RESULT I2C::write(uint8_t data)
{
    if(I2CTransmitterIsReady(M_PORT))
    {
        return I2CSendByte(M_PORT, data);
    }
    else
    {
        return I2C_ERROR;
    }
    
}

bool I2C::data_is_available(void)
{
    return (bool) I2CReceivedDataIsAvailable(M_PORT);
}
uint8_t I2C::read(void)
{
    I2CAcknowledgeByte(M_PORT, TRUE);
    return I2CGetByte(M_PORT);
}

I2C::~I2C() {
}

