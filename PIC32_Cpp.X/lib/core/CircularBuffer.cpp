/* 
 * File:   CircularBuffer.cpp
 * Author: doltsa
 * 
 * Created on 10. avril 2014, 10:16
 */

#include "CircularBuffer.h"

#include <stdlib.h>

CircularBuffer::CircularBuffer(const uint8_t BUFFER_SIZE)
{
    M_BUFFER_SIZE = BUFFER_SIZE;
    M_BEGIN = new uint8_t [M_BUFFER_SIZE];
    M_END = M_BEGIN + (M_BUFFER_SIZE - 1);
    m_read = M_BEGIN;
    m_write = M_BEGIN;
    m_free_size = M_BUFFER_SIZE;
    m_number_of_item = 0;
}

void CircularBuffer::put(uint8_t data)
{
    if( get_free_size() != 0)
    {
        *m_write = data;
        m_free_size--;
        m_number_of_item++;

        if(m_write == M_END)
        {
            m_write = M_BEGIN;
        }
        else
        {
            m_write++;
        }
    }
    else
    {
        // Il n'y a plus de place pour écrire
    }
}

uint8_t CircularBuffer::get(void)
{
    uint8_t data = 0;

    if( get_number_of_item() > 0 )
    {
        data = *m_read;
        m_free_size++;
        m_number_of_item--;

        if(m_read == M_END)
        {
            m_read = M_BEGIN;
        }
        else
        {
            m_read++;
        } 
    }
    else
    {
        // Il n'y a plus rien à lire
    }
    return data;
}

uint8_t CircularBuffer::get_free_size(void)
{
    return m_free_size;
}

uint8_t CircularBuffer::get_number_of_item(void)
{
    return m_number_of_item;
}

CircularBuffer::~CircularBuffer() {
    delete M_BEGIN;
}

