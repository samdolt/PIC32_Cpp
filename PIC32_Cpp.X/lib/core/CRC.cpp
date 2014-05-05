/* 
 * File:   CRC.cpp
 * Author: doltsa
 * 
 * Created on 1. mai 2014, 11:16
 */

#include "CRC.h"

CRC16::CRC16(enum CRC16_TYPE TYPE) {
    M_TYPE = TYPE;
}

bool CRC16::check(uint8_t * data, size_t size, uint16_t crc)
{
    uint8_t crc_low = (crc & 0x0F);
    uint8_t crc_high = (crc & 0xF0) >> 8;

    generate(data, size);
    update(crc_low);
    update(crc_high);

    if(m_crc == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int CRC16::generate(uint8_t * data, size_t size)
{
    m_crc = 0;

    for(int i = 0; i < size ; i++ )
    {
        update(data[i]);
    }

    return m_crc;
}

void CRC16::update(uint8_t data)
{
    switch(M_TYPE)
    {
        case CRC16_CCITT:
            CCITT_update(data);
            break;
        default:
            break;
    }
}

void CRC16::CCITT_update(uint8_t data)
{
    uint8_t crc_low = (m_crc & 0x0F);
    uint8_t crc_high = (m_crc & 0xF0) >> 8;

    data ^= crc_low;
    data ^= data << 4;

    m_crc = ((((uint16_t)data << 8) | crc_high) ^ (uint8_t)(data >> 4)
                ^ ((uint16_t)data << 3));
}

CRC16::~CRC16() {
}

