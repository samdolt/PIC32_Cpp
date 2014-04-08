/**
 * Fichier : io/Keypad.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Pilote pour clavier matricielle 4x4 touches
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#include <stdint.h>
#include "DigitalPin.h"

class Keypad {
public:
    Keypad(const char L1[], const char L2[], const char L3[], const char L4[],
           const char C1[], const char C2[], const char C3[], const char C4[],
           const uint8_t NUMBER = 5);
    void update(void);
    uint16_t get_pressed_keys(void);
    bool has_a_new_state(void);
    virtual ~Keypad();
private:
    DigitalPin * M_LINE1;
    DigitalPin * M_LINE2;
    DigitalPin * M_LINE3;
    DigitalPin * M_LINE4;

    DigitalPin * M_COLUMN1;
    DigitalPin * M_COLUMN2;
    DigitalPin * M_COLUMN3;
    DigitalPin * M_COLUMN4;

    uint16_t m_current_keys;
    uint16_t m_last_keys;
    uint8_t m_counter;

    bool m_flag;
    uint8_t M_NUMBER;
};

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

#endif	/* KEYPAD_H */

