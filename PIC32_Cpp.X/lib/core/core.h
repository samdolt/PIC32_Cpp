 /**
 * Fichier :Core.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Initialisation et interruptions du CoreTimer
 */

#ifndef CORE_H
#define	CORE_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <p32xxxx.h>
#include <plib.h>
#include "etml-es/SK-PIC32-B.h"


/*******************************************************************************
 * CONFIGURATION DES FUSIBLES
 ******************************************************************************/


/* Configuration des oscillateurs
 * ------------------------------ */

#pragma config POSCMOD = HS // Oscillateur primaire en mode "HIGH SPEED CRYSTAL"
#pragma config FSOSCEN = OFF // Oscillateur secondaire désactivé
#pragma config IESO = OFF // Internal External Switch Over bit Disable
#pragma config FNOSC = PRIPLL // Oscillateur primaire avec PLL
#pragma config OSCIOFNC = OFF // Désactivation de la sortie sur la pin CLKO
#pragma config FCKSM = CSDCMD // Clock Switching Disabled, Clock Monitoring Disabled


/* Configuration de la PLL avec un quartz externe de 8 MHz
 * ------------------------------------------------------- */
#pragma config FPLLIDIV = DIV_2 // Division de l'oscillateur primaire par 2 ->4MHz
#pragma config FPLLMUL = MUL_20 // Multiplication par 20 -> 80MHz en sortie de la PLL
#pragma config FPLLODIV = DIV_1 // Division par 1 -> 80MHz pour l'horloge système
#define SYS_FREQ (80000000L)    // Constante stockant la valeur de l'horloge système


/* Configuration du chien de garde (WATCHDOG)
 * ------------------------------------------ */
#pragma  config FWDTEN = OFF // Désactivé



/* Configuration du programmeur et du débogueur
 * -------------------------------------------- */
#pragma config ICESEL = ICS_PGx2 // Les pins ICE sont partagée avec PGC2 et PGD2
#pragma config DEBUG = ON // Mode DEBUG enclenché


#define CORE_TIMER_TICK_RATE (SYS_FREQ/2000.0)

#define TIMER1_TICK_PS_8 ((1.0/ (SYS_FREQ / 8)))
#define TIMER1_1MS_PS_8 (0.001 / TIMER1_TICK_PS_8 )


static inline void init(void) {
    /*
     * CONFIGURATION
     * -------------- */
    SYSTEMConfigPerformance(SYS_FREQ); // Cette fonction retourne PB_CLK = 80MHz
    mJTAGPortEnable(0); // Désactivation du JTAG, libère RA0, RA1, RA4 et RA5

    OpenTimer1( T1_ON | T1_SOURCE_INT | T1_PS_1_8, TIMER1_1MS_PS_8 );
    ConfigIntTimer1(T1_INT_ON | T1_INT_PRIOR_4);
    INTEnableSystemMultiVectoredInt ();

    
}



extern "C" {
    void __ISR(_TIMER_1_VECTOR, IPL4AUTO) Timer1Handler(void) {
        mT1ClearIntFlag();
        menu1.update();
        menu2.update();
        menu3.update();
        menu4.update();
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

#endif	/* CORE_H */

