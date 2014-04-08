/**
 * Fichier : DigitalPin.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Gestion d'une broche digitale
 */

#ifndef DIGITALPIN_H
#define	DIGITALPIN_H

#include <stdint.h>
#include <p32xxxx.h>

enum direction {
    INPUT,
    OUTPUT
};

enum state {
    HIGH = 1,
    LOW = 0
};

class DigitalPin {
    public:
        DigitalPin(const char PIN[]);
        DigitalPin(const char PORT, uint16_t PIN_NUMBER);
        void set_direction(enum direction);
        void set_input(void);
        void set_output(void);
        void set_low(void);
        void set_high(void);
        void toggle(void);
        bool read(void);
        void write(const bool STATE);
        virtual ~DigitalPin();
    private:
        char M_PORT;
        uint8_t M_PIN_NUMBER;
};

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

#endif	/* DIGITALPIN_H */

