/**
 * Fichier : board/etml-es/SK-PIC32-B.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Définition des broches d'entrée sortie du Starter Kit PIC32MX775F512L rev. B
 * de l'ETML-ES
 */

#ifndef SK_PIC32_B_H
#define	SK_PIC32_B_H


/*******************************************************************************
 * Affichage et Leds
 ******************************************************************************/

#include "TextDisplay.h"
#include "Led.h"

extern TextDisplay lcd = TextDisplay("E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7");
extern Led led0 = Led("A0");
extern Led led1 = Led("A1");
extern Led led2 = Led("A4");
extern Led led3 = Led("A5");
extern Led led4 = Led("A6");
extern Led led5 = Led("A7");
extern Led led6 = Led("A15");
extern Led led7 = Led("B10");

/*******************************************************************************
 * Touches
 ******************************************************************************/

#include "Key.h"
extern Key menu1 = Key("G13");
extern Key menu2 = Key("G14");
extern Key menu3 = Key("G15");
extern Key menu4 = Key("G12");
extern Key menu5 = Key("D7");

#include "IncrementalEncoder.h"

extern IncrementalEncoder pec12 = IncrementalEncoder("E8","E9");

#include "Keypad.h"

extern Keypad keypad = Keypad("G6","G7","B14","B15", "B2", "B3", "B4", "B5");

/*******************************************************************************
 * Port seriel
 ******************************************************************************/

#include "SerialPort.h"
extern SerialPort serial = SerialPort(1);

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

#endif	/* SK_PIC32_B_H */

