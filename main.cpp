 /*
 * Fichier : main.cpp
 * Auteur  : Samuel Dolt
 *
 * Exemple de projet C++
 */



#include "core.h"
#include "etml-es/SK-PIC32-B.h"
#include "Delay.h"
#include "PIC32_Cpp.X/lib/io/Led.h"

#include <CircularBuffer.h>


/*******************************************************************************
 * FONCTION PRINCIPALE
 ******************************************************************************/
int main (void){

    uint8_t unsigned_value = 90;
    int8_t signed_value = -90;
    int cpt_s = 0;
    int sonar_value;

    init();
    
    /*
     * Affichage initiale
     * ------------------------- */
    lcd << "Diplome 1403x" << endl ;
    lcd << "Samuel Dolt" << endl;

    delay::s(5);

    lcd.clear();

    
    
    
    while(1){
        if(sonar.has_new_value()) {
            sonar_value = sonar.get_value();
            lcd.set_cursor(1,1);
            lcd.printf("Sonar %4d [mm]", sonar_value);
            
        }
        led0.toggle();



        cpt_s++;
        
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