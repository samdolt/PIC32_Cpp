/* 
 * File:   I2CMaster.cpp
 * Author: doltsa
 * 
 * Created on 30. avril 2014, 14:12
 */

#include "I2CMaster.h"

#include <p32xxxx.h>
#include <plib.h>

#include "settings.h"

// Syntaxe a obtenir:

// i2c << ADRESS(0x12458) << 0x45
// i2c >> data
// i2c 
I2CMaster::I2CMaster(enum I2C_PORT PORT) {
    M_PORT = PORT;
}


void I2CMaster::configure(enum I2C_SPEED SPEED){
    M_SPEED = SPEED;

    //uint32_t PB_CLOCK = get_peripheral_clock();



}

I2CMaster::~I2CMaster() {
}

