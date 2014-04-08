 /**
 * Fichier : Led.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Pilote orienté object pour led
 */

#ifndef LED_H
#define	LED_H

#include "DigitalPin.h"

class Led {
public:
    Led(const char LED[], const bool INVERTED = false);
    void set_off(void);
    void set_on(void);
    void toggle(void);
    virtual ~Led();
private:
    DigitalPin * M_IO;
    bool M_INVERTED;

};

#endif	/* LED_H */

