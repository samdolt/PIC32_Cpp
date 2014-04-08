/**
 * Fichier : io/Keypad.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Pilote pour clavier matricielle 4x4 touches
 */

#include "Keypad.h"
#include <string.h>
#include "Delay.h"

Keypad::Keypad( const char L1[], const char L2[], const char L3[], const char L4[],
                const char C1[], const char C2[], const char C3[], const char C4[],
                const uint8_t NUMBER) {
    M_NUMBER = NUMBER;
    
    M_LINE1 = new DigitalPin(L1);
    M_LINE2 = new DigitalPin(L2);
    M_LINE3 = new DigitalPin(L3);
    M_LINE4 = new DigitalPin(L4);

    M_COLUMN1 = new DigitalPin(C1);
    M_COLUMN2 = new DigitalPin(C2);
    M_COLUMN3 = new DigitalPin(C3);
    M_COLUMN4 = new DigitalPin(C4);

    M_LINE1->set_input();
    M_LINE2->set_input();
    M_LINE3->set_input();
    M_LINE4->set_input();
    M_COLUMN1->set_input();
    M_COLUMN2->set_input();
    M_COLUMN3->set_input();
    M_COLUMN4->set_input();

    M_LINE1->set_low();
    M_LINE2->set_low();
    M_LINE3->set_low();
    M_LINE4->set_low();


    m_last_keys = 0;
    m_counter = 0;
    m_flag = false;
}

void Keypad::update(void)
{
    bool K0, K1, K2, K3, K4, K5, K6, K7, K8, K9, K10, K11, K12, K13, K14, K15;
    uint16_t new_keys;

    /* Lecture de la ligne 1*/
    M_LINE1->set_output();
    K0 = !(M_COLUMN1->read());
    K1 = !(M_COLUMN2->read());
    K2 = !(M_COLUMN3->read());
    K3 = !(M_COLUMN4->read());
    M_LINE1->set_input();

    /* Lecture de la ligne 2*/
    M_LINE2->set_output();
    K4 = !(M_COLUMN1->read());
    K5 = !(M_COLUMN2->read());
    K6 = !(M_COLUMN3->read());
    K7 = !(M_COLUMN4->read());
    M_LINE2->set_input();

    /* Lecture de la ligne 3*/
    M_LINE3->set_output();
    K8 = !(M_COLUMN1->read());
    K9 = !(M_COLUMN2->read());
    K10 = !(M_COLUMN3->read());
    K11 = !(M_COLUMN4->read());
    M_LINE3->set_input();

    /* Lecture de la ligne 4*/
    M_LINE4->set_output();
    K12 = !(M_COLUMN1->read());
    K13 = !(M_COLUMN2->read());
    K14 = !(M_COLUMN3->read());
    K15 = !(M_COLUMN4->read());
    M_LINE4->set_input();

    new_keys = 0;
    new_keys |= (K0 << 0);
    new_keys |= (K1 << 1);
    new_keys |= (K2 << 2);
    new_keys |= (K3 << 3);
    new_keys |= (K4 << 4);
    new_keys |= (K5 << 5);
    new_keys |= (K6 << 6);
    new_keys |= (K7 << 7);
    new_keys |= (K8 << 8);
    new_keys |= (K9 << 9);
    new_keys |= (K10 << 10);
    new_keys |= (K11 << 11);
    new_keys |= (K12 << 12);
    new_keys |= (K13 << 13);
    new_keys |= (K14 << 14);
    new_keys |= (K15 << 15);
    
    if(new_keys == m_last_keys) {
        m_counter ++;
    }
    else {
        m_counter = 0;
    }

    if(m_counter >= M_NUMBER)
    {
        m_counter = M_NUMBER;
        if(m_current_keys == new_keys) {
            // Do nothing
        }
        else {
            m_current_keys = new_keys;
            m_flag = true;
        }
    }

    m_last_keys = new_keys;
}

bool Keypad::has_a_new_state(void)
{
    if(m_flag == true)
    {
        m_flag = false;
        return true;
    }

    return false;
}

uint16_t Keypad::get_pressed_keys(void)
{
    return m_current_keys;
}




Keypad::~Keypad() {
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
