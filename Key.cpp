/**
 * Fichier : Key.c
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Fonction d'abstraction pour le entr�e/sortie g�n�rique
 */
#include <cstring>
#include "Port.h"

#include "Key.h"



Key::Key(const char PIN[]) {
    strcpy(M_KEY, PIN);
    M_KEY_PORT = pin::get_port(PIN);
    M_KEY_PIN = pin::get_number(PIN);
    m_counter = 0;
    m_flag = false;

    pin::set_input(M_KEY_PORT, M_KEY_PIN);

    m_last_state = pin::get(M_KEY_PORT, M_KEY_PIN);
    m_state = pin::get(M_KEY_PORT, M_KEY_PIN);
}

void Key::update(void)
{
    uint8_t new_state = pin::get(M_KEY_PORT, M_KEY_PIN);

    if(m_state == new_state )
    {
        // Ne rien faire
    }
    else if(m_last_state == new_state)
    {
        m_counter++;
    }
    else
    {
        m_counter = 0;
    }

    if(m_counter > 25)
    {
        m_counter = 0;
        m_state = new_state;
        m_flag = true;
    }

    m_last_state = new_state;
}

bool Key::has_a_new_state(void)
{
    if(m_flag == true)
    {
        m_flag = false;
        return true;
    }

    return false;
}

Key::~Key() {
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