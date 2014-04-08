 /*
 * Fichier : Led.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Pilote orienté object pour led
 */

#include "Led.h"
#include "Port.h"

Led::Led(const char LED[],  const bool INVERTED) {
    M_IO = new DigitalPin(LED);
    M_INVERTED = INVERTED;
    set_off();
    M_IO->set_output();
}

void Led::set_off(void) {
    if(M_INVERTED == false) {
        M_IO->set_low();
    }
    else {
        M_IO->set_high();
    }
}

void Led::set_on(void) {
    if(M_INVERTED == false) {
        M_IO->set_high();
    }
    else {
        M_IO->set_low();
    }
}

void Led::toggle(void) {
        M_IO->toggle();
}

Led::~Led() {
    delete M_IO;
}

