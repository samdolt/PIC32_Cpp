/**
 * Fichier : IncrementerEncoder.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Driver pour encodeur rotatif "PEC12"
 */

#ifndef INCREMENTALENCODER_H
#define	INCREMENTALENCODER_H

#include <stdint.h>
#include "DigitalPin.h"
#include "Key.h"

class IncrementalEncoder {
public:
    IncrementalEncoder(const char SIGNAL_A[], const char SIGNAL_B[], const char KEY[]);
    void update(void);
    bool has_a_new_state(void);
    int8_t get_state(void);

    bool has_been_turned_clockwise(void);
    bool has_been_turned_cw(void);
    bool has_been_turned_counterclockwise(void);
    bool has_been_turned_ccw(void);
    virtual ~IncrementalEncoder();
    Key key;
private:

    DigitalPin * M_SIGNAL_A;
    DigitalPin * M_SIGNAL_B;

    bool m_flag;
    int8_t m_current_state;

    bool m_old_signal_a;
    bool m_old_signal_b;

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

#endif	/* INCREMENTALENCODER_H */

