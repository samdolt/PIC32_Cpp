/**
 * Fichier : Port.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Fonction d'abstraction pour le entr�e/sortie g�n�rique
 *
 * Ce pilote est destin� au circuit "Starter-kit PIC32" de l'ETML-ES
 */

#ifndef PORT_H
#define	PORT_H

#include <stdint.h>



namespace port {
    uint32_t read(const char PORT);

    void write(const char PORT, const uint32_t value);
}

namespace pin {

    const uint8_t LOW = 0;
    const uint8_t HIGH = 1;
    const uint8_t OUTPUT = 0;
    const uint8_t INPUT = 1;

    void set(const char PORT, const uint8_t PIN);

    void clear(const char PORT, const uint8_t PIN);

    uint8_t get(const char PORT, const uint8_t PIN);

    uint8_t read(const char PIN[]);

    void write(const char PIN[], uint8_t VALUE);

    void direction(const char PIN[], uint8_t VALUE);

    void set_input(const char PORT, const uint8_t PIN);

    void set_output(const char PORT, const uint8_t PIN);
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
#endif	/* PORT_H */

