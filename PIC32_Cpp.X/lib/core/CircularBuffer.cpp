/**
 * Fichier : CircularBuffer.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Buffer circulaire de taille variable
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

/******************************************************************************
 * LICENSE
 ******************************************************************************/

/*
 * Copyright (c) 2014, Samuel Dolt <samuel@dolt.ch>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */