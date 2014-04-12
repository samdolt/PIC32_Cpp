/**
 * Fichier : AnalogPin.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Fonction d'abstraction pour le entrée analogique
 */

#include "AnalogPin.h"

#include <plib.h>

/*****************************************************************
 * REMARQUE : L'adc est configuré dans la fonction init de core.h
 ****************************************************************/

AnalogPin::AnalogPin(const uint8_t AN_NUMBER ) {
    M_ADC_NUMBER = AN_NUMBER;

    // Configure la broche en entrée digitale
    TRISB |= (1<<M_ADC_NUMBER); // Configure la broche en entrée
   
    //Active le mode analogique sur la broche
    AD1PCFG &= ~(1 << M_ADC_NUMBER); 
}

uint16_t AnalogPin::read_raw(void)
{
    // Désactivation du module ADC
    AD1CON1bits.ADON = 0;

    // Séléction de la broche sur l'entrée ADC A positive
    AD1CHS = M_ADC_NUMBER << 16;

    // Réactivation du module ADC
    AD1CON1bits.ADON = 1;

    // Démarrage de la conversion
    AD1CON1bits.SAMP = 1;

    while(!AD1CON1bits.DONE)
    {
        // Wait for ADC to complete
    }
    return ( ADC1BUF0 +(8 *(AD1CON2bits.BUFS & 0x01)) );

}
float AnalogPin::read(void)
{
    return read_raw() / 1023.0;
}

AnalogPin::~AnalogPin(){
    // Désactivation du mode analogique de la broche
    AD1PCFG |= (1 << M_ADC_NUMBER);
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
