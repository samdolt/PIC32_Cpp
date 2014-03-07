/**
 * Fichier : Delay.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Gestion des temporisations à l'aide du CoreTime
 * Les délais s'adapte à la fréquence du processeur
 */


#include <plib.h>
#include "Delay.h"

#ifndef SYS_FREQ
    #define SYS_FREQ (80000000L)    //80 MHz
#endif

namespace delay {
    void ms(uint32_t delay)
    {
        uint32_t time_to_wait;
        WriteCoreTimer(0);
        time_to_wait = SYS_FREQ / 2000.0 * delay;
        while(ReadCoreTimer() < time_to_wait){
            // Waiting
        };
    }

    void us(uint32_t delay)
    {
        uint32_t time_to_wait;
        WriteCoreTimer(0);
        time_to_wait = SYS_FREQ / 2000000.0 * delay;
        while(ReadCoreTimer() < time_to_wait){
            // Waiting
        };
    }
    void ns(uint32_t delay)
    {
        uint32_t time_to_wait;
        WriteCoreTimer(0);
        time_to_wait = SYS_FREQ / 2000000000.0 * delay;
        while(ReadCoreTimer() < time_to_wait){
            // Waiting
        };
    }
}

/******************************************************************************
 * LICENSE
 ******************************************************************************/

/*
 * Copyright (c) 2014, École supérieur de l'ETML <www.etml-es.ch>
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