 /**
 * Fichier : Led.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Pilote orienté object pour led
 */

#ifndef LED_H
#define	LED_H

class Led {
public:
    Led(const char LED[], const bool INVERTED = false);
    void set_off(void);
    void set_on(void);
    void toggle(void);
    virtual ~Led();
private:
    int M_LED_PIN;
    char M_LED_PORT;
    char M_LED[5];
    bool M_INVERTED;

};

#endif	/* LED_H */

