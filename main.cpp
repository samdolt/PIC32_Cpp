/*
 * Fichier : main.cpp
 * Auteur  : Samuel Dolt
 *
 * Exemple de projet C++
 */



#include "core.h"
#include "etml-es/SK-PIC32-B.h"
#include "Port.h"
#include "Delay.h"
#include "TextDisplay.h"
#include "Key.h"


#include <plib.h>
#include <p32xxxx.h>
#include <peripheral/adc10.h>

/*******************************************************************************
 * FONCTION PRINCIPALE
 ******************************************************************************/
int main (void){

    init();
    
    /*
     * Affichage initiale
     * ------------------------- */
    lcd << "Exemple PIC32 C++" << endl ;
    lcd << "Starter Kit ETML-ES" << endl;
    lcd.set_cursor(2,1);

    /*
     * LED Clignottante
     * ------------------------- */

    while(1){
        led1.toggle();
        led2.toggle();
        led3.toggle();
        led4.toggle();
        led5.toggle();
        led6.toggle();
        led7.toggle();
        delay::ms(10);

        if(keypad.has_a_new_state())
        {
            uint16_t temp = keypad.get_pressed_keys();
            if(temp != 0)
            {
                lcd.set_cursor(3,1);
                lcd << "         ";
                lcd.set_cursor(3,1);
                lcd << temp;
            }
        }
        

        lcd.set_cursor(4,1);
        if(menu1.is_pressed())
        {
            lcd << "x";
        }
        else
        {
            lcd << " ";
        }

        lcd.set_cursor(4,1);
        if(menu1.is_pressed())
        {
            lcd << "x";
        }
        else
        {
            lcd << " ";
        }

        lcd.set_cursor(4,7);
        if(menu2.is_pressed())
        {
            lcd << "x";
        }
        else
        {
            lcd << " ";
        }

        lcd.set_cursor(4,14);
        if(menu3.is_pressed())
        {
            lcd << "x";
        }
        else
        {
            lcd << " ";
        }

        lcd.set_cursor(4,20);
        if(menu4.is_pressed())
        {
            lcd << "x";
        }
        else
        {
            lcd << " ";
        }

        delay::ms(100);
    }

    return 0;
}

/*******************************************************************************
 * VECTEURS D'INTERRUPTIONS
 ******************************************************************************/

extern "C"
{
    // Les vecteurs d'interruption doivent être compilé en "mode" C


}