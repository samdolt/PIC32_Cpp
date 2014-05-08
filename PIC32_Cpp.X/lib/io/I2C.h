/* 
 * File:   I2C.h
 * Author: doltsa
 *
 * Created on 7. mai 2014, 14:43
 */

#ifndef I2C_H
#define	I2C_H

#include <cstdint>
#include <plib.h>

class I2C {
public:
    I2C(I2C_MODULE id);
    void configure(void);
    bool data_is_available(void);
    I2C_RESULT write(uint8_t data);
    uint8_t read(void);
    virtual ~I2C();
private:
    I2C_MODULE M_PORT;
    I2C_CONFIGURATION M_CONFIG;

};

#endif	/* I2C_H */

