/* 
 * File:   Generator.cpp
 * Author: doltsa
 * 
 * Created on 15. mai 2014, 15:21
 */

#include "Generator.h"

#include "cmath"
#include "cstring"

int32_t m_data[48];

#define SYS_FREQ 80000000L
#define TIMER2_TICK_PS_4 ((1.0/ (SYS_FREQ / 4)))


#include "plib.h"

#include "cmath"

#ifndef M_PI
 #define M_PI 3.14159265358979323846
#endif

Generator::Generator() {
}

// Calcul des échantillons pour un signal sinus

void Generator::sinus_init(S_ParamGen * data) {

    uint8_t i;
   const float incr = (2 * M_PI ) / 48.0;

   for(i = 0; i < 48; i++)
   {
       m_data[i] = (32759 * (1 + ((sin(incr * i) * (data->Amplitude / 10000.0) ))) ) - ((data->Offset/1000.0) * (32759/5.0));
   }
}


// Calcul des échantillons pour un signal carré

void Generator::carre_init(S_ParamGen * data) {

    // m_current = *data;

    uint8_t i;

    for (i = 0; i < 24; i++) {
        m_data[i] = 32759 + (32759 * (data->Amplitude / 10000.0)) - ((data->Offset / 1000.0) * (32759 / 5.0));
    }
    for (i = 0; i < 24; i++) {
        m_data[i + 24] = 32759 - (32759 * (data->Amplitude / 10000.0)) - ((data->Offset / 1000.0) * (32759 / 5.0));
    }
}

// Calcul des échantillons pour un signal dent de scie

void Generator::dds_init(S_ParamGen * data) {
    int8_t i;
    for (i = 0; i < 48; i++) {
        m_data[i] = 32759 - ((32759.0 * (i - 24) / 48.0) * 2 * (data->Amplitude / 10000.0)) - ((data->Offset / 1000.0) * (32759 / 5.0));
    }
}

// Met à jour les échantillons en les recalculant

void Generator::update(S_ParamGen * data) {
    int i;

    if (memcmp(&m_current, data, sizeof (S_ParamGen)) != 0) {
        memcpy(&m_current, data, sizeof (S_ParamGen));
       PR2 =  ( (1.0 /(data->Frequence * 48)) / TIMER2_TICK_PS_4 );
       // m_reload = 65536 - ((double) ((double) 1.0 / (uint32_t) (data->Frequence * 40.0)*1000000) / (double) 0.0833333333333333333333333333);

        // Appel des fonctions de calcul des échantillons propre à la forme demandée
        switch (data->Forme) {
            case SignalSinus:
                sinus_init(data);
                break;
            case SignalCarre:
                carre_init(data);
                break;
            case SignalDentDeScie:
                dds_init(data);
                break;
            case SignalTriangle:
                trian_init(data);
                break;
            default:
                break;
        }

        // Gestion des débordements
        for (i = 0; i < 48; i++) {
            if (m_data[i] > 65518) {
                m_data[i] = 65518;
            } else if (m_data[i] < 0) {
                m_data[i] = 0;
            }
        }
    }

}




// Calcul des échantillons pour un signal triangle

void Generator::trian_init(S_ParamGen * data) {
    int8_t i;
    for (i = 0; i < 24; i++) {
        m_data[i] = 32759 - ((32759.0 * (i - 12) / 24.0) * 2 * (data->Amplitude / 10000.0)) - ((data->Offset / 1000.0) * (32759 / 5.0));
    }
    for (i = 0; i < 24; i++) {
        m_data[i + 24] = 32759 + ((32759.0 * (i - 12) / 24.0) * 2 * (data->Amplitude / 10000.0)) - ((data->Offset / 1000.0) * (32759 / 5.0));
    }
}

uint16_t Generator::get_sample(uint8_t number)
{
    return m_data[number];
}

uint16_t Generator::get_timer_reload_value(void)
{
    return m_reload;
}

Generator::~Generator() {
}

