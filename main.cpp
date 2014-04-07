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
    int8_t x = 1;
    int8_t y = 3;

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
            lcd.set_cursor(y,x);
            if(temp != 0)
            {
                switch(temp)
                {
                    case 0x1:
                        lcd << "0";
                        break;
                    case 0x2:
                        lcd << "1";
                        break;
                    case 0x4:
                        lcd << "2";
                        break;
                    case 0x8:
                        lcd << "3";
                        break;
                    case 0x10:
                        lcd << "4";
                        break;
                    case 0x20:
                        lcd << "5";
                        break;
                    case 0x40:
                        lcd << "6";
                        break;
                    case 0x80:
                        lcd << "7";
                        break;
                    case 0x100:
                        lcd << "8";
                        break;
                    case 0x200:
                        lcd << "9";
                        break;
                    case 0x400:
                        lcd << "A";
                        break;
                    case 0x800:
                        lcd << "B";
                        break;
                    case 0x1000:
                        lcd << "C";
                        break;
                    case 0x2000:
                        lcd << "D";
                        break;
                    case 0x4000:
                        lcd << "E";
                        break;
                    case 0x8000:
                        lcd << "F";
                        break;
                    default:
                        break;
                }
                
                lcd.set_cursor(4,2);
                lcd << "         ";
                lcd.set_cursor(4,2);
                lcd << temp;
            }
            else
            {
               lcd.set_cursor(4,2);
               lcd << "         ";
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

        lcd.set_cursor(2,20);
        if(menu5.is_pressed())
        {
            lcd << "x";
        }
        else
        {
            lcd << " ";
        }

        lcd.set_cursor(1,19);
        if(pec12.has_a_new_state())
        {
            if(pec12.get_state() == -1)
            {
                x--;
                lcd << "<-";
            }
            else if(pec12.get_state() == 1)
            {
                x++;
                lcd << "->";
            }

            if(x < 1)
            {
                x =20;
            }
            else if(x > 20)
            {
                x = 20;
            }
        }
        else
        {
            // do nothing
        }
        lcd.set_cursor(y, x);

        lcd.enable_underline_cursor();
        delay::ms(100);
        lcd.disable_underline_cursor();
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