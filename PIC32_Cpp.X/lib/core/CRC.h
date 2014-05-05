/* 
 * File:   CRC.h
 * Author: doltsa
 *
 * Created on 1. mai 2014, 11:16
 */

#ifndef CRC_H
#define	CRC_H

#include <cstddef>
#include <cstdint>

enum CRC16_TYPE {
    CRC16_CCITT, 
};

class CRC16 {
public:
    CRC16(enum CRC16_TYPE TYPE);
    void update(uint8_t data);
    bool check(uint8_t * data, size_t size, uint16_t crc);
    int generate(uint8_t * data, size_t size);
    void CCITT_update(uint8_t data);
    virtual ~CRC16();
private:
    uint16_t m_crc;
    enum CRC16_TYPE M_TYPE;
};

#endif	/* CRC_H */

