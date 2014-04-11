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

#include <CircularBuffer.h>



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
    lcd.set_cursor(3,1);
    

    while(1){

        if(keypad.has_a_new_state())
        {
            uint16_t temp = keypad.get_pressed_keys();
            
            if(temp != 0)
            {
                switch(temp)
                {
                    case 0x1:
                        serial << "0";
                        break;
                    case 0x2:
                        serial << "1";
                        break;
                    case 0x4:
                        serial << "2";
                        break;
                    case 0x8:
                        serial << "3";
                        break;
                    case 0x10:
                        serial << "4";
                        break;
                    case 0x20:
                        serial << "5";
                        break;
                    case 0x40:
                        serial << "6";
                        break;
                    case 0x80:
                        serial << "7";
                        break;
                    case 0x100:
                        serial << "8";
                        break;
                    case 0x200:
                        serial << "9";
                        break;
                    case 0x400:
                        serial << "A";
                        break;
                    case 0x800:
                        serial << "B";
                        break;
                    case 0x1000:
                        serial << "C";
                        break;
                    case 0x2000:
                        serial << "D";
                        break;
                    case 0x4000:
                        serial << "E";
                        break;
                    case 0x8000:
                        serial << "F";
                        break;
                    default:
                        break;
                }
                
            }
            else
            {

            }
        }
        
        lcd.set_cursor(3,1);
        char buf[40];
        serial.read(buf, 38);
        lcd <<  buf;
        lcd.set_cursor(3,1);
        lcd << "                        ";
        lcd.set_cursor(3,1);
        lcd << adc.read_input(0);
        lcd.set_cursor(3,10);
        lcd << adc.read_input(1);
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