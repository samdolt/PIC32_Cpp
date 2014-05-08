/* 
 * File:   message.cpp
 * Author: doltsa
 * 
 * Created on 1. mai 2014, 14:07
 */

#include "message.h"

Message::Message() {
    M_CRC_GEN = new CRC16(CRC16_CCITT);
}

bool Message::validator(void)
{
    bool no_error = true;
    
    if(m_message.start != 0xAA)
    {
        no_error = false;
    }
    
    // Check CRC
    if(M_CRC_GEN->check(m_message.raw, 3, m_message.crc.raw))
    {
        // OK
    }
    else
    {
        no_error = false;
    }
        
    return no_error;
}


void Message::generate(void)
{
    m_message.start = 0xAA;
    m_message.crc.raw = M_CRC_GEN->generate(m_message.raw, 3);
}

void Message::set_message(union message message)
{
    m_message = message;
}

union message Message::get_message(void)
{
    return m_message;
}
void Message::set_angle(uint8_t angle)
{
    m_message.data.angle = angle;
}
uint8_t Message::get_angle(void)
{
    return m_message.data.angle;
}
void Message::set_speed(uint8_t speed)
{
    m_message.data.speed = speed;
}
uint8_t Message::get_speed(void)
{
    return m_message.data.speed;
}

void Message::get_raw(uint8_t data[])
{
    data[0] = m_message.start;
    data[1] = m_message.data.speed;
    data[2] = m_message.data.angle;
    data[3] = m_message.crc.low;
    data[4] = m_message.crc.high;
}


void Message::write(uint8_t data[])
{
    m_message.start = data[0];
    m_message.data.speed = data[1];
    m_message.data.angle = data[2];
    m_message.crc.low = data[3];
    m_message.crc.high = data[4];
}

size_t Message::get_raw_size(void)
{
    return sizeof(m_message.raw);
}

Message::~Message() {
    delete M_CRC_GEN;
}

