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

    char get_port(const char PIN[])
    {
        return PIN[0];
    }
    
    uint8_t get_number(const char PIN[])
    {
        uint8_t return_data = 0;
        for(uint8_t i = 0; PIN[i] != '\0'; i++)
        {
            if(i == 0)
            {
                // Ne rien faire, information sur le port
            }
            else if(i==1)
            {
                return_data = PIN[i] - '0';
            }
            else if(i == 2)
            {
                // Le num�ro de pin est sup�rieur � 9:
                return_data *= 10;
                return_data += PIN[i] - '0';
            }
            else
            {
                // Ne rien faire
            }
        }
        return return_data;
    }

    uint8_t read(const char PIN[])
    {
        return get(PIN[0], get_number(PIN));
    }

    void write(const char PIN[], uint8_t VALUE)
    {
        switch(VALUE)
        {
            case HIGH:
                set(PIN[0], get_number(PIN));
                break;
            case LOW:
                clear(PIN[0], get_number(PIN));
                break;
            default:
                break;
        }

    }

    void direction(const char PIN[], uint8_t VALUE)
    {
        switch(VALUE)
        {
            case INPUT:
                set_input(PIN[0], get_number(PIN));
                break;
            case OUTPUT:
                set_output(PIN[0], get_number(PIN));
                break;
            default:
                break;
        }

    }

    void set_input(const char PORT, const uint8_t PIN)
    {
        // INPUT => 1
        switch(PORT) {
            case 'A':
                TRISA |= (1<<PIN);
                break;
            case 'B':
                TRISB |= (1<<PIN);
                break;
            case 'C':
                TRISC |= (1<<PIN);
                break;
            case 'D':
                TRISD |= (1<<PIN);
                break;
            case 'E':
                TRISE |= (1<<PIN);
                break;
            default:
                break;
        }

    }

    void set_output(const char PORT, const uint8_t PIN)
    {
        // OUTPUT => 0
        switch(PORT) {
            case 'A':
                TRISA &= ~(1<<PIN);
                break;
            case 'B':
                TRISB &= ~(1<<PIN);
                break;
            case 'C':
                TRISC &= ~(1<<PIN);
                break;
            case 'D':
                TRISD &= ~(1<<PIN);
                break;
            case 'E':
                TRISE &= ~(1<<PIN);
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
            case 'B':
                LATB |= (1<<PIN);
                break;
            case 'C':
                LATC |= (1<<PIN);
                break;
            case 'D':
                LATD |= (1<<PIN);
                break;
            case 'E':
                LATE |= (1<<PIN);
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
            case 'B':
                LATB &= ~(1<<PIN);
                break;
            case 'C':
                LATC &= ~(1<<PIN);
                break;
            case 'D':
                LATD &= ~(1<<PIN);
                break;
            case 'E':
                LATE &= ~(1<<PIN);
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
            case 'B':
                return (PORTB & (1<<PIN)) >> PIN;
            case 'C':
                return (PORTC & (1<<PIN)) >> PIN;
            case 'D':
                return (PORTD & (1<<PIN)) >> PIN;
            case 'E':
                return (PORTE & (1<<PIN)) >> PIN;
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
