/* 
 * File:   CircularBuffer.h
 * Author: doltsa
 *
 * Created on 10. avril 2014, 10:16
 */

#ifndef CIRCULARBUFFER_H
#define	CIRCULARBUFFER_H

#include <stdint.h>

class CircularBuffer {
public:
    CircularBuffer(const uint8_t BUFFER_SIZE);
    void put(uint8_t data);
    uint8_t get(void);
    uint8_t get_free_size(void);
    uint8_t get_number_of_item(void);
    virtual ~CircularBuffer();
private:
    uint8_t M_BUFFER_SIZE;
    uint8_t * M_BEGIN;
    uint8_t * M_END;
    uint8_t * m_read;
    uint8_t * m_write;
    uint8_t m_number_of_item;
    uint8_t m_free_size;
};

#endif	/* CIRCULARBUFFER_H */

