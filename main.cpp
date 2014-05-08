 /*
 * Fichier : main.cpp
 * Auteur  : Samuel Dolt
 *
 * Exemple de projet C++
 */


bool timer_flag;

#include "core.h"
#include "etml-es/SK-PIC32-B.h"
#include "delay.h"

#include <cstdint>
#include "CircularBuffer.h"

#include "CRC.h"
#include "message.h"



/*--------------------------------------------------------*/
/* Ponts en H
/*--------------------------------------------------------*/
#define STBY_HBRIDGE	LATBbits.LATB8
#define AIN1_HBRIDGE	LATDbits.LATD12
#define AIN2_HBRIDGE	LATDbits.LATD13
#define PWMA_HBRIDGE	LATDbits.LATD1
#define BIN1_HBRIDGE	LATCbits.LATC1
#define BIN2_HBRIDGE	LATCbits.LATC2
#define PWMB_HBRIDGE	LATDbits.LATD2



/*******************************************************************************
 * FONCTION PRINCIPALE
 ******************************************************************************/
int main (void){

    init();
    /*--------------------------------------------------------*/
	/* Pont en H
	/*--------------------------------------------------------*/
	// Par sécurité, on met tout en entrée au départ
	TRISCbits.TRISC13 = 0; //STBY_HBRIDGE en entrée
	TRISDbits.TRISD12 = 0; //AIN1_HBRIDGE en entrée
	TRISDbits.TRISD13 = 0; //AIN2_HBRIDGE en entrée
	TRISDbits.TRISD1 = 0; //PWMA_HBRIDGE en entrée
	TRISCbits.TRISC1 = 0; //BIN1_HBRIDGE en entrée
	TRISCbits.TRISC2 = 0; //BIN2_HBRIDGE en entrée
	TRISDbits.TRISD2 = 0; //PWMB_HBRIDGE en entrée


    timer_flag = false;
    Message mess_rx = Message();
    Message mess_tx = Message();

    int8_t pwm_speed = 0;
    int8_t pwm_angle = 0;

    int8_t pot_speed = 0;
    int8_t pot_angle = 0;

    uint8_t unsigned_value = 90;
    int8_t signed_value = -90;
    char c;

    int no_mess_cpt = 0;
    bool local_mode = false;

    	

    
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

        lcd << cursor(2,1) << " Vitesse : " << setw(4) << with_sign_plus << pwm_speed;
        lcd << cursor(3,1) << " Angle   :  " << setw(4) << with_sign_plus << pwm_angle;

        if(local_mode)
        {
            lcd << cursor(1,20) << "<"  ;
        }
        else
        {
             lcd << cursor(1,20) << ">"  ;
        }
        


        if(timer_flag == true)
        {
            /****************************************************************
             * Gestion cyclique chaque 25ms
             ***************************************************************/
            pot_angle = pot2.read() * 180 - 90;
            pot_speed = pot1.read() * 198 - 99; //line 2
            
            /****************************************************************
             * PWM
             ***************************************************************/


            // Calcul valeur du duty cycle pour Moteur
            SetDCOC2PWM(abs(pwm_speed) * ((25 * 80) / 100));

            STBY_HBRIDGE = 1;
            if (pwm_speed < 0)
            {
                AIN1_HBRIDGE = 1; // RD12
                AIN2_HBRIDGE = 0; // RD13
            }
            else
            {
                AIN2_HBRIDGE = 1;
                AIN1_HBRIDGE = 0;
            }

            // Calcul pour angle
            SetPulseOC3((7000-(abs(pwm_angle)*10+600))/T3_TICK, 0);
            /****************************************************************
             * RS232
             ***************************************************************/
            timer_flag = false;
            led0.toggle();

            mess_tx.set_angle(pot_angle);
            mess_tx.set_speed(pot_speed);
            mess_tx.generate();

            uint8_t data[5];
            mess_tx.get_raw(data);
            serial.write(data[0]);
            serial.write(data[1]);
            serial.write(data[2]);
            serial.write(data[3]);
            serial.write(data[4]);

            lcd << cursor(1,1) << "TX : " <<  hex << data[0] << data[1] << data[2] << data[3] << data[4]  << dec;

            if(serial.number_of_bytes() >= 5)
            {
                uint8_t read_data[5];
                read_data[0] = 0;
                no_mess_cpt =0;
                local_mode = false;

                do
                {
                    read_data[0] = serial.get();
                } while(read_data[0] != 0xAA && serial.number_of_bytes() >= 5);

                if(read_data[0] == 0xAA)
                {
                    for(int i = 1; i < 5 ; i++)
                    {
                        read_data[i] = serial.get();
                    }

                    // Gestion de la récéption
                    mess_rx.write(read_data);

                    lcd << cursor(4,1) << "RX : " <<  hex << read_data[0] << read_data[1] << read_data[2] << read_data[3] << read_data[4]  << dec;
                    if(mess_rx.validator())
                    {
                        // Le message est valide
                        pwm_speed = mess_rx.get_speed();
                        pwm_angle = mess_rx.get_angle();
                        
                    }

                }
            }
            else
            {
                no_mess_cpt++;

                if(no_mess_cpt++ > 3)
                {
                    local_mode = true;
                    pwm_speed = pot_speed;
                    pwm_angle = pot_angle;
                }
            }
        }


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