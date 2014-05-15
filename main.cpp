 /*
 * Fichier : main.cpp
 * Auteur  : Samuel Dolt
 *
 * Exemple de projet C++
 */



#include "core.h"
#include "etml-es/SK-PIC32-B.h"
#include "delay.h"

#include "Menu.h"
#include "Generator.h"

Generator gen_sig = Generator();

Menu menu = Menu();

float data = 0.0;

S_ParamGen generator;
S_ParamGen RemoteGenerator;
S_ParamGen OldGeneratorValue;
S_ParamGen SendGenerator;

const uint32_t PROGMEM_MAGIC = 0x10;
uint8_t EchNb;      // No de l'échantillon

bool local_flag = true;

void initial_display(void)
{
    lcd << "TP3A GenSig PIC32" << endl ;
    lcd << "SLO2 2013/2014" << endl;
    lcd << "DOLT Samuel" << endl;
    delay::s(5);
    lcd.clear();
}

void param_init(void)
{
   // Initilisation des paramètres
   generator.Forme = (E_FormesSignal) SignalSinus;
   generator.Frequence = 100;
   generator.Amplitude = 10000;
   generator.Offset = 0;
   generator.Magic = PROGMEM_MAGIC;
   RemoteGenerator.Forme = (E_FormesSignal) SignalSinus;
   RemoteGenerator.Frequence = 100;
   RemoteGenerator.Amplitude = 10000;
   RemoteGenerator.Offset = 0;
   RemoteGenerator.Magic = PROGMEM_MAGIC;

   OldGeneratorValue = RemoteGenerator;
   SendGenerator = generator;

};

void key_management(void)
{
    if(pec12.has_a_new_state())
    {

        if(pec12.get_state() == +1)
        {
            // "Rotation de le sens horaire";
            if (menu.is_locked()) {
                // Sélectionne la ligne inférieur du menu
                menu.add_to_active(+1);
            } else {
                // Incrémente d'un saut la valeur de la ligne sélectionnée
                menu.update_value(+1, &generator);
            }
        }
        else
        {
            // "Rotation de le sens anti-horaire";
            if (menu.is_locked()) {
                // Sélectionne la ligne supérieur du menu
                menu.add_to_active(-1);
            } else {
                // Décrémente d'un saut la valeur de la ligne sélectionnée
                menu.update_value(-1, &generator);
            }
        }
    }
    else
    {
        // Si aucune touche n'est préssée, ne rien faire
    }

    if(menu3.has_a_new_state())
    {
        if(menu3.is_pressed())
        {
            if(menu.is_locked())
            {
                // Dévérouille le menu pour permettre l'édition
                menu.unset_lock(&generator);
            }
            else
            {
                // Vérouille le menu et met à jour la table des échantillons
                menu.set_lock(&generator, 0);


                if(local_flag == 0)
                {
                SendGenerator = generator;
                }
                else
                {
                gen_sig.update(&generator);
                }
            }
         }
    }

    if(menu4.has_a_new_state())
    {
        if(menu4.is_pressed())
        {
            if(menu.is_locked())
        {
            // Do nothing
        }
        else
        {
            menu.set_lock(&generator,  1);
        }

        }
    }

}



#define TIMER2_TICK_PS_16 ((1.0/ (SYS_FREQ / 16)))
#define TIMER2_10MS_PS_16 (0.01 / TIMER2_TICK_PS_16 )


/*******************************************************************************
 * FONCTION PRINCIPALE
 ******************************************************************************/
int main (void){

    init();

    
    
    dac.set_channel(0);
   
    initial_display();

    param_init();

     // Initilisation du signal
    generator.Forme = (E_FormesSignal) SignalSinus;
    generator.Frequence = 100;
    generator.Amplitude = 10000;
    generator.Offset = 0;
    generator.Magic = 0x0;


    menu.init(&generator);
    gen_sig.update(&generator);
    dac.reset();
    
    OpenTimer2( T2_ON | T2_SOURCE_INT | T2_PS_1_16, TIMER2_10MS_PS_16 );
    ConfigIntTimer2(T2_INT_ON | T2_INT_PRIOR_4);
    

    while(1){
        key_management();


    }

    return 0;
}

/*******************************************************************************
 * VECTEURS D'INTERRUPTIONS
 ******************************************************************************/

extern "C"
{
    // Les vecteurs d'interruption doivent être compilé en "mode" C


    // Réponse à l'interruption du Timer 0
    // Cycle échantillonage variable

    void __ISR(_TIMER_2_VECTOR, IPL6AUTO) Timer2Handler (void) {
        mT2ClearIntFlag();
        led0.set_off();
        //output_high(LIGNE3); // marque début

        // recharge Timer0
        //PR2 = gen_sig.get_timer_reload_value();
        //set_timer0(Timer0Reload);

        // traitement d'un échantillon
        // ---------------------------

        // Test du dac (a remplacer par la suite)
        // 1394 * 47 = 65518 poroche du max (65535)
        //WriteDac(1394 * EchNb, 0);      // sur canal 0
        dac.set_channel(0);
        //dac.write_raw(m_data[EchNb]); // sur canal 0
        dac << channel(0) << data;
        EchNb++;
        EchNb = EchNb % 48;

        data += 0.1;

        if(data > 1.1)
        {
            data == -1.0;
        }

        led0.set_on();

        //output_low(LIGNE3); // marque fin
    } // sampling_isr


}