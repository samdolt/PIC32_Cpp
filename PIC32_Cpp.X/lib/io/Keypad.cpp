/**
 * Fichier : io/Keypad.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Pilote pour clavier matricielle 4x4 touches
 */

#include "Keypad.h"
#include "Port.h"
#include <string.h>
#include "Delay.h"

Keypad::Keypad( const char L1[], const char L2[], const char L3[], const char L4[],
                const char C1[], const char C2[], const char C3[], const char C4[],
                const uint8_t NUMBER) {
    M_NUMBER = NUMBER;
    
    strcpy(M_LINE1, L1);
    M_LINE1_PORT = pin::get_port(L1);
    M_LINE1_PIN = pin::get_number(L1);

    strcpy(M_LINE2, L2);
    M_LINE2_PORT = pin::get_port(L2);
    M_LINE2_PIN = pin::get_number(L2);

    strcpy(M_LINE3, L3);
    M_LINE3_PORT = pin::get_port(L3);
    M_LINE3_PIN = pin::get_number(L3);

    strcpy(M_LINE4, L4);
    M_LINE4_PORT = pin::get_port(L4);
    M_LINE4_PIN = pin::get_number(L4);

    strcpy(M_COLUMN1, C1);
    M_COLUMN1_PORT = pin::get_port(C1);
    M_COLUMN1_PIN = pin::get_number(C1);

    strcpy(M_COLUMN2, C2);
    M_COLUMN2_PORT = pin::get_port(C2);
    M_COLUMN2_PIN = pin::get_number(C2);

    strcpy(M_COLUMN3, C3);
    M_COLUMN3_PORT = pin::get_port(C3);
    M_COLUMN3_PIN = pin::get_number(C3);

    strcpy(M_COLUMN4, C4);
    M_COLUMN4_PORT = pin::get_port(C4);
    M_COLUMN4_PIN = pin::get_number(C4);

    pin::set_input(M_COLUMN1_PORT, M_COLUMN1_PIN);
    pin::set_input(M_COLUMN2_PORT, M_COLUMN2_PIN);
    pin::set_input(M_COLUMN3_PORT, M_COLUMN3_PIN);
    pin::set_input(M_COLUMN4_PORT, M_COLUMN4_PIN);

    pin::set_output(M_LINE1_PORT, M_LINE1_PIN);
    pin::set_output(M_LINE2_PORT, M_LINE2_PIN);
    pin::set_output(M_LINE3_PORT, M_LINE3_PIN);
    pin::set_output(M_LINE4_PORT, M_LINE4_PIN);

    pin::clear(M_LINE1_PORT, M_LINE1_PIN);
    pin::clear(M_LINE2_PORT, M_LINE2_PIN);
    pin::clear(M_LINE3_PORT, M_LINE3_PIN);
    pin::clear(M_LINE4_PORT, M_LINE4_PIN);
}

void Keypad::update(void)
{
    bool K0, K1, K2, K3, K4, K5, K6, K7, K8, K9, K10, K11, K12, K13, K14, K15;


    /* Lecture de la ligne 1*/
    pin::set_output(M_LINE1_PORT, M_LINE1_PIN);
    K0 = !(pin::get(M_COLUMN1_PORT, M_COLUMN1_PIN));
    K1 = !(pin::get(M_COLUMN2_PORT, M_COLUMN2_PIN));
    K2 = !(pin::get(M_COLUMN3_PORT, M_COLUMN3_PIN));
    K3 = !(pin::get(M_COLUMN4_PORT, M_COLUMN4_PIN));
    pin::set_input(M_LINE1_PORT, M_LINE1_PIN);

    /* Lecture de la ligne 2*/
    pin::set_output(M_LINE2_PORT, M_LINE2_PIN);
    K4 = !(pin::get(M_COLUMN1_PORT, M_COLUMN1_PIN));
    K5 = !(pin::get(M_COLUMN2_PORT, M_COLUMN2_PIN));
    K6 = !(pin::get(M_COLUMN3_PORT, M_COLUMN3_PIN));
    K7 = !(pin::get(M_COLUMN4_PORT, M_COLUMN4_PIN));
    pin::set_input(M_LINE2_PORT, M_LINE2_PIN);

    /* Lecture de la ligne 3*/
    pin::set_output(M_LINE3_PORT, M_LINE3_PIN);
    K8 = !(pin::get(M_COLUMN1_PORT, M_COLUMN1_PIN));
    K9 = !(pin::get(M_COLUMN2_PORT, M_COLUMN2_PIN));
    K10 = !(pin::get(M_COLUMN3_PORT, M_COLUMN3_PIN));
    K11 = !(pin::get(M_COLUMN4_PORT, M_COLUMN4_PIN));
    pin::set_input(M_LINE3_PORT, M_LINE3_PIN);

    /* Lecture de la ligne 4*/
    pin::set_output(M_LINE4_PORT, M_LINE4_PIN);
    K12 = !(pin::get(M_COLUMN1_PORT, M_COLUMN1_PIN));
    K13 = !(pin::get(M_COLUMN2_PORT, M_COLUMN2_PIN));
    K14 = !(pin::get(M_COLUMN3_PORT, M_COLUMN3_PIN));
    K15 = !(pin::get(M_COLUMN4_PORT, M_COLUMN4_PIN));
    pin::set_input(M_LINE4_PORT, M_LINE4_PIN);


    m_current_keys = 0;
    m_current_keys |= (K0 << 0);
    m_current_keys |= (K1 << 1);
    m_current_keys |= (K2 << 2);
    m_current_keys |= (K3 << 3);
    m_current_keys |= (K4 << 4);
    m_current_keys |= (K5 << 5);
    m_current_keys |= (K6 << 6);
    m_current_keys |= (K7 << 7);
    m_current_keys |= (K8 << 8);
    m_current_keys |= (K9 << 9);
    m_current_keys |= (K10 << 10);
    m_current_keys |= (K11 << 11);
    m_current_keys |= (K12 << 12);
    m_current_keys |= (K13 << 13);
    m_current_keys |= (K14 << 14);
    m_current_keys |= (K15 << 15);
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
