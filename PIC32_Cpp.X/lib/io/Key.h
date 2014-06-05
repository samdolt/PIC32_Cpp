 /**
 * Fichier : Key.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Fonction d'abstraction pour le entrée/sortie générique
 */

#ifndef KEY_H
#define	KEY_H

#include <cstdint>
#include "DigitalPin.h"

class Key {
public:
    Key(const char PIN[], uint8_t NUMBER = 5);
    void update(void);
    bool has_a_new_state(void);
    bool is_pressed(void);
    bool is_relached(void);
    bool has_been_pressed(void);
    bool has_been_relached(void);
    uint32_t get_pressed_time(void);
    uint32_t get_relached_time(void);
    uint32_t reset_timer(void);
    virtual ~Key();
private:
    DigitalPin * M_KEY;
    uint8_t M_NUMBER;
    uint32_t m_counter;
    bool m_last_state;
    bool m_state;
    bool m_flag;
    uint32_t m_pressed_time;
    uint32_t m_relached_time;
};

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

#endif	/* KEY_H */

