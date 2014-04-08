/**
 * Fichier : DigitalPin.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Gestion d'une broche digitale
 */

#include "DigitalPin.h"
#include "Port.h"

DigitalPin::DigitalPin(const char PIN[]) {
    // PIN[0] => Caractère indiquant le port
    // PIN[1:2] => Numéro de la PIN dans le port
    M_PORT = pin::get_port(PIN);
    M_PIN_NUMBER = pin::get_number(PIN);
}

DigitalPin::DigitalPin(const char PORT, uint16_t PIN_NUMBER) {
    M_PORT = PORT;
    M_PIN_NUMBER = PIN_NUMBER;
}

void DigitalPin::set_direction(enum direction DIRECTION) {
    switch (DIRECTION) {
        case INPUT:
            set_input();
            break;
        case OUTPUT:
            set_output();
            break;
        default:
            break;
    }
}

void DigitalPin::set_input(void) {
    // Mettre à 1 le bit dans TRISx
            switch(M_PORT) {
            case 'A':
                TRISA |= (1<<M_PIN_NUMBER);
                break;
            case 'B':
                TRISB |= (1<<M_PIN_NUMBER);
                break;
            case 'C':
                TRISC |= (1<<M_PIN_NUMBER);
                break;
            case 'D':
                TRISD |= (1<<M_PIN_NUMBER);
                break;
            case 'E':
                TRISE |= (1<<M_PIN_NUMBER);
                break;
            case 'F':
                TRISF |= (1<<M_PIN_NUMBER);
                break;
            case 'G':
                TRISG |= (1<<M_PIN_NUMBER);
                break;
            default:
                break;
        }

}

void DigitalPin::set_output(void) {
            // Mise à 0 du bit dans TRISx
        switch(M_PORT) {
            case 'A':
                TRISA &= ~(1<<M_PIN_NUMBER);
                break;
            case 'B':
                TRISB &= ~(1<<M_PIN_NUMBER);
                break;
            case 'C':
                TRISC &= ~(1<<M_PIN_NUMBER);
                break;
            case 'D':
                TRISD &= ~(1<<M_PIN_NUMBER);
                break;
            case 'E':
                TRISE &= ~(1<<M_PIN_NUMBER);
                break;
            case 'F':
                TRISF &= ~(1<<M_PIN_NUMBER);
                break;
            case 'G':
                TRISG &= ~(1<<M_PIN_NUMBER);
                break;
            default:
                break;
        }

}

void DigitalPin::set_low(void) {
            switch(M_PORT) {
            case 'A':
                LATA &= ~(1<<M_PIN_NUMBER);
                break;
            case 'B':
                LATB &= ~(1<<M_PIN_NUMBER);
                break;
            case 'C':
                LATC &= ~(1<<M_PIN_NUMBER);
                break;
            case 'D':
                LATD &= ~(1<<M_PIN_NUMBER);
                break;
            case 'E':
                LATE &= ~(1<<M_PIN_NUMBER);
                break;
            case 'F':
                LATF &= ~(1<<M_PIN_NUMBER);
                break;
            case 'G':
                LATG &= ~(1<<M_PIN_NUMBER);
                break;
            default:
                break;
        }

}

void DigitalPin::set_high(void) {
            switch(M_PORT) {
            case 'A':
                LATA |= (1<<M_PIN_NUMBER);
                break;
            case 'B':
                LATB |= (1<<M_PIN_NUMBER);
                break;
            case 'C':
                LATC |= (1<<M_PIN_NUMBER);
                break;
            case 'D':
                LATD |= (1<<M_PIN_NUMBER);
                break;
            case 'E':
                LATE |= (1<<M_PIN_NUMBER);
                break;
            case 'F':
                LATF |= (1<<M_PIN_NUMBER);
                break;
            case 'G':
                LATG |= (1<<M_PIN_NUMBER);
                break;
            default:
                break;
        }

}

void DigitalPin::toggle(void) {
                    switch(M_PORT) {
            case 'A':
                LATA ^= (1<<M_PIN_NUMBER);
                break;
            case 'B':
                LATB ^= (1<<M_PIN_NUMBER);
                break;
            case 'C':
                LATC ^= (1<<M_PIN_NUMBER);
                break;
            case 'D':
                LATD ^= (1<<M_PIN_NUMBER);
                break;
            case 'E':
                LATE ^= (1<<M_PIN_NUMBER);
                break;
            case 'F':
                LATF ^= (1<<M_PIN_NUMBER);
                break;
            case 'G':
                LATG ^= (1<<M_PIN_NUMBER);
                break;
            default:
                break;
        }
}

bool DigitalPin::read(void) {
            switch(M_PORT) {
            case 'A':
                return ((PORTA & (1<<M_PIN_NUMBER))) >> M_PIN_NUMBER;
            case 'B':
                return ((PORTB & (1<<M_PIN_NUMBER))) >> M_PIN_NUMBER;
            case 'C':
                return ((PORTC & (1<<M_PIN_NUMBER))) >> M_PIN_NUMBER;
            case 'D':
                return ((PORTD & (1<<M_PIN_NUMBER))) >> M_PIN_NUMBER;
            case 'E':
                return ((PORTE & (1<<M_PIN_NUMBER))) >> M_PIN_NUMBER;
            case 'F':
                return ((PORTF & (1<<M_PIN_NUMBER))) >> M_PIN_NUMBER;
            case 'G':
                return ((PORTG & (1<<M_PIN_NUMBER))) >> M_PIN_NUMBER;
        default:
            return 0;
        }

        return 0;

}

void DigitalPin::write(const bool STATE) {
    if(STATE == LOW)
    {
        set_low();
    }
    else
    {
        set_high();
    }
}

DigitalPin::~DigitalPin() {

}


/******************************************************************************
 * LICENSE
 ******************************************************************************
 *
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

