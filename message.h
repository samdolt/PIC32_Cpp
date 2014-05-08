/* 
 * File:   message.h
 * Author: doltsa
 *
 * Created on 1. mai 2014, 14:07
 */

#ifndef MESSAGE_H
#define	MESSAGE_H

#include <cstdint>

#include "CRC.h"

union message_data
{
    struct{
        uint8_t speed;
        uint8_t angle;
    };
    uint16_t raw;
};

union message_crc
{
    struct
    {
        uint8_t high;
        uint8_t low;
    };
    uint16_t raw;
};

union message {
    struct {
        uint8_t start;
        union message_data data;
        union message_crc crc;
    };
    struct
    {
        uint8_t raw[5];
    };
};

class Message {
public:
    Message();
    bool validator(void);
    void generate(void);
    void set_message(union message message);
    union message get_message(void);
    void set_angle(uint8_t angle);
    uint8_t get_angle(void);
    void set_speed(uint8_t speed);
    uint8_t get_speed(void);
    void get_raw(uint8_t data[]);
    size_t get_raw_size(void);
    void write(uint8_t data[]);
    virtual ~Message();
private:
    union message m_message;
    CRC16 * M_CRC_GEN;
};

#endif	/* MESSAGE_H */

