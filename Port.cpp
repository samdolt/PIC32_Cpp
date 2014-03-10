/**
 * Fichier : Port.c
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Fonction d'abstraction pour le entr�e/sortie g�n�rique
 *
 * Ce pilote est destin� au circuit "Starter-kit PIC32" de l'ETML-ES
 */

#include "Port.h"
#include <p32xxxx.h>

namespace port {
    uint32_t read(const char PORT)
    {
        switch(PORT) {
            case 'A':
                return PORTA;
            default:
                return 0;
        }
    }

    void write(const char PORT, const uint32_t value)
    {
        switch(PORT) {
            case 'A':
                PORTA = value;
                break;
            default:
                break;
        }
    }

}

namespace pin {

    uint8_t read(const char PIN[])
    {
        return get(PIN[0], PIN[1] - '0');
    }

    void write(const char PIN[], enum value_e VALUE)
    {
        switch(VALUE)
        {
            case HIGH:
                set(PIN[0], PIN[1] - '0');
                break;
            case LOW:
                clear(PIN[0], PIN[1] - '0');
                break;
            default:
                break;
        }

    }


    void set(const char PORT, const uint8_t PIN)
    {
        switch(PORT) {
            case 'A':
                LATA |= (1<<PIN);
                break;
            default:
                break;
        }
    }

    void clear(const char PORT, const uint8_t PIN)
    {
        switch(PORT) {
            case 'A':
                LATA &= ~(1<<PIN);
                break;
            default:
                break;
        }
    }

    uint8_t get(const char PORT, const uint8_t PIN)
    {
        switch(PORT) {
            case 'A':
                return (PORTA & (1<<PIN)) >> PIN;
        default:
            return 0;
        }

        return 0;
    }
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
