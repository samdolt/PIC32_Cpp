/**
 * Fichier : IncrementerEncoder.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Driver pour encodeur rotatif "PEC12"
 */

#include "IncrementalEncoder.h"

IncrementalEncoder::IncrementalEncoder(const char SIGNAL_A[], const char SIGNAL_B[]) {
    strcpy(M_SIGNAL_A, SIGNAL_A);
    M_SIGNAL_A_PORT = pin::get_port(SIGNAL_A);
    M_SIGNAL_A_PIN = pin::get_number(SIGNAL_A);

    strcpy(M_SIGNAL_B, SIGNAL_B);
    M_SIGNAL_B_PORT = pin::get_port(SIGNAL_B);
    M_SIGNAL_B_PIN = pin::get_number(SIGNAL_B);

    m_current_state = 0;
    m_flag = false;

    pin::set_input(M_SIGNAL_A_PORT, M_SIGNAL_A_PIN);
    pin::set_input(M_SIGNAL_B_PORT, M_SIGNAL_B_PIN);
}

void IncrementalEncoder::update(void) {
    bool new_signal_a, new_signal_b;

    new_signal_a = pin::get(M_SIGNAL_A_PORT, M_SIGNAL_A_PIN);
    new_signal_b = pin::get(M_SIGNAL_B_PORT, M_SIGNAL_B_PIN);

    
    
    if(new_signal_a == 0 && m_old_signal_a == 1 && m_old_signal_b == 1)
    {
        // Flan déscendant sur A et B à 1
        m_current_state = 1;
        m_flag = true;
    }
    else if(new_signal_b == 0 && m_old_signal_b == 1 && m_old_signal_a == 1)
    {
        // Flan déscendant sur B et A à 1
        m_current_state = -1;
        m_flag = true;
        
    }

    m_old_signal_a = new_signal_a;
    m_old_signal_b = new_signal_b;
}

bool IncrementalEncoder::has_a_new_state(void)
{
    if(m_flag == true)
    {
        m_flag = false;
        return true;
    }

    return false;
}

int8_t IncrementalEncoder::get_state(void)
{
    return m_current_state;
}

IncrementalEncoder::~IncrementalEncoder() {
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
