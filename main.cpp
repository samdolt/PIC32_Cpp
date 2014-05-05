 /*
 * Fichier : main.cpp
 * Auteur  : Samuel Dolt
 *
 * Exemple de projet C++
 */



#include "core.h"
#include "etml-es/SK-PIC32-B.h"
#include "delay.h"

#include <CircularBuffer.h>


/*******************************************************************************
 * FONCTION PRINCIPALE
 ******************************************************************************/
int main (void){

    float output;

    init();
    
    /*
     * Affichage initiale
     * ------------------------- */
    lcd << "Reglage TP6" << endl ;
    lcd << "Moteur PIC32" << endl;
    lcd << "DOLT Samuel" << endl;
    lcd << "PALMARI Claudio" << endl;

    delay::s(5);

    lcd.clear();

    
    //
    //DigitalPin pin = DigitalPin("D10");
    //pin.set_output();
    
    while(1){
             output = pot2.read() * 2 - 1;

        lcd << cursor(2,1) << "Tension : " << setw(4) << with_sign_plus << output * 10 ;
        dac << channel(0) << output;

       // pin.set_high();
        //delay::ms(1);
        //pin.set_low();
        //delay::ms(1);

        
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