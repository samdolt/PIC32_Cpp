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

    uint8_t unsigned_value = 90;
    int8_t signed_value = -90;

    init();
    
    /*
     * Affichage initiale
     * ------------------------- */
    lcd << "Local Settings" << endl ;
    lcd << "TP2A PWM 2013-2014" << endl;
    lcd << "DOLT Samuel" << endl;
    lcd << "Mailard France" << endl;

    delay::s(5);

    lcd.clear();

    

    while(1){
        unsigned_value = pot1.read() * 100;
        signed_value = pot2.read() * 200 - 100;
        lcd << cursor(2,1) << " Vitesse : " << setw(4) << with_sign_plus << signed_value;
        lcd << cursor(3,1) << " Angle   :  " << setw(3) << without_sign_plus << unsigned_value;
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