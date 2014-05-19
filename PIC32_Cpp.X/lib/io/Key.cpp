 /**
 * Fichier : Key.c
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Fonction d'abstraction pour le entrée/sortie générique
 */
#include <cstring>

#include "Key.h"



Key::Key(const char PIN[], const uint8_t NUMBER) {

    M_KEY = new DigitalPin(PIN);

    M_NUMBER = NUMBER;
    m_counter = 0;
    m_flag = false;

    M_KEY->set_input();

    m_last_state = M_KEY->read();
    m_state = m_last_state;

    m_pressed_time = 0;
    m_relached_time = 0;
}

void Key::update(void)
{
    uint8_t new_state = M_KEY->read();

    if(new_state == m_last_state) {
        m_counter ++;
    }
    else {
        m_counter = 0;
    }

    if(m_counter >= M_NUMBER)
    {
        m_counter = M_NUMBER;
        if(m_state == new_state) {
            if(is_relached())
            {
                m_relached_time++;
            }
            else
            {
                m_pressed_time++;
            }
        }
        else {
            m_state = new_state;
            m_flag = true;

            if(is_relached())
            {
                m_relached_time = 0;
            }
            else
            {
                m_pressed_time = 0;
            }
        }
    }

    m_last_state = new_state;
}

bool Key::has_been_pressed(void)
{
    if(m_flag == true)
    {
        if(is_pressed())
        {
            m_flag = false;
            return true;
        }
    }

    return false;
}

bool Key::has_been_relached(void)
{
    if(m_flag == true)
    {
        if(is_relached())
        {
            m_flag = false;
            return true;
        }
    }

    return false;
}

uint32_t Key::get_pressed_time(void)
{
    return m_pressed_time;
}

uint32_t Key::get_relached_time(void)
{
    return m_relached_time;
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

bool Key::is_pressed(void)
{
    return !m_state;
};
bool Key::is_relached(void)
{
    return m_state;
};
    
Key::~Key() {
    delete M_KEY;
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