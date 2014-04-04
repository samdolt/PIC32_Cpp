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
    strcpy(M_LED, LED);
    M_LED_PORT = pin::get_port(LED);
    M_LED_PIN = pin::get_number(LED);
    M_INVERTED = INVERTED;
    set_off();
    pin::set_output(M_LED_PORT, M_LED_PIN);
}

void Led::set_off(void) {
    if(M_INVERTED == false) {
        pin::clear(M_LED_PORT, M_LED_PIN);
    }
    else {
        pin::set(M_LED_PORT, M_LED_PIN);
    }
}

void Led::set_on(void) {
    if(M_INVERTED == false) {
        pin::set(M_LED_PORT, M_LED_PIN);
    }
    else {
        pin::clear(M_LED_PORT, M_LED_PIN);
    }
}

void Led::toggle(void) {
        pin::toggle(M_LED_PORT, M_LED_PIN);
}

Led::~Led() {
}

