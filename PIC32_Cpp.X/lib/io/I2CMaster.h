/* 
 * File:   I2CMaster.h
 * Author: doltsa
 *
 * Created on 30. avril 2014, 14:12
 */

#ifndef I2CMASTER_H
#define	I2CMASTER_H

#include <cstdint>

enum I2C_PORT {
    I2C_0,
    I2C_1,
};

enum I2C_SPEED {
    I2C_100KHz,
    I2C_400KHz,
    I2C_1MHz
};

class I2CMaster {
public:
    I2CMaster(enum I2C_PORT PORT);
    void configure(enum I2C_SPEED SPEED);
    virtual ~I2CMaster();
private:
    enum I2C_SPEED M_SPEED;
    enum I2C_PORT M_PORT;
};

#endif	/* I2CMASTER_H */

