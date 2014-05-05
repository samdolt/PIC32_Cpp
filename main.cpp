 /*
 * Fichier : main.cpp
 * Auteur  : Samuel Dolt
 *
 * Exemple de projet C++
 */



#include "core.h"
#include "etml-es/SK-PIC32-B.h"
#include "delay.h"

#include <cstdint>
#include "CircularBuffer.h"

#include "CRC.h"
#include "message.h"

/*******************************************************************************
 * FONCTION PRINCIPALE
 ******************************************************************************/
int main (void){

    Message mess = Message();

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
        //unsigned_value = pot1.read() * 100;
        //signed_value = pot2.read() * 200 - 100;
        //lcd << cursor(2,1) << " Vitesse : " << setw(4) << with_sign_plus << signed_value;
        //lcd << cursor(3,1) << " Angle   :  " << setw(3) << without_sign_plus << unsigned_value;

        //mess.set_angle(unsigned_value);
        //mess.set_speed(signed_value);
        //mess.generate();

        //if(mess.validator())
        //{
        //    lcd << cursor(1,1) << "OK";
        //}
        //else
        //{
        //    lcd << cursor(1,1) << "PAS OK";
        //}
        //union message tmp_mess = mess.get_message();
        //serial.write(tmp_mess.start);
        //serial.write(tmp_mess.data.speed);
        //serial.write(tmp_mess.data.angle);
        //serial.write(tmp_mess.crc.high);
        //serial.write(tmp_mess.crc.low);
        //serial.send(mess.get_raw, mess.get_raw_size);
          /*
        if(serial.has_receive_data())
        {
            lcd << hex << serial.get();
        }*/

        char data[25];
        data[0] = 'A';

        serial.read(data, 20);

        //if(data[0] == 'A')
        lcd << "OK";
        //serial << "Bonjour";

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