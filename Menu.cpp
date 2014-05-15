/* 
 * File:   Menu.cpp
 * Author: doltsa
 * 
 * Created on 15. mai 2014, 13:21
 */


#include "Menu.h"

#include "etml-es/SK-PIC32-B.h"


// Texte représentant les formes possibles de signal à générer
const char MENU_VALUE[4][6] = {"CARRE","TRIAN","SINUS","DDS"};

// Incrément, valeur minimale et maximal pour la sélection de la forme
const uint16_t FORME_INCR = 1;
const uint16_t FORME_MIN = 0;
const uint16_t FORME_MAX = 3;

// Incrément, valeur minimale et maximal pour la sélection de la fréquence
const uint16_t FREQUENCY_INCR = 10;
const uint16_t FREQUENCY_MIN = 10;
const uint16_t FREQUENCY_MAX = 990;

// Incrément, valeur minimale et maximal pour la sélection de l'amplitude
const uint16_t AMPLITUDE_INCR = 50;
const uint16_t AMPLITUDE_MIN = 0;
const uint16_t AMPLITUDE_MAX = 10000;

// Incrément, valeur minimale et maximal pour la sélection de l'offset
const uint16_t OFFSET_INCR = 50;
const int16_t OFFSET_MIN = -5000;
const int16_t OFFSET_MAX = 5000;


Menu::Menu() {
    m_mark = '*';
}

// Retourne 1 si le menu est vérouillé
// Retourne 0 si le menu est dévérouillé
bool Menu::is_locked(void)
{
   return m_lock;
}


void Menu::init(S_ParamGen * data){
   // Affichage des parties fixes
   lcd.clear();
   lcd << cursor(1,2) << "Forme       =";
   lcd << cursor(2,2) << "Freq   [Hz] =";
   lcd << cursor(3,2) << "Ampl   [mV] =";
   lcd << cursor(4,2) << "Offset [mV] =";



   // Initialisation de la structure menu
   go_to(0);
   init_value(data);
   set_lock(data);
}

// Vérouille le menu. Si clearPressed vaut 1, annule les modifications sinon elle les enregistres
void Menu::set_lock(S_ParamGen * data, bool clearPressed)
{
	m_lock = true;
	set_mark(LOCK);
	if(clearPressed)
	{
		switch(m_active)
		{
			case FORME:
				data->Forme = (E_FormesSignal) m_old;
				break;
			case FREQ:
				data->Frequence = m_old;
				break;
			case AMPL:
				data->Amplitude = m_old;
				break;
			case OFFSET:
				data->Offset = m_old;
				break;
			default:
				break;
		}
		update_value(0, data );
	}
	else
	{
		// Do nothing
	}

}

// Permet de sélectionner et mettre à jour la marque utilisée pour sélectionner une ligne
void Menu::set_mark(enum menu_mark mark)
{
   m_mark = mark;
   update_mark();
}

enum menu_line Menu::get_active(void)
{
   return m_active;
}

// Met à jour la marque sur la ligne sélectionnée.
void Menu::update_mark(void)
{
// Effacement de menu en cours
   switch(m_active)
   {
      case FORME:
         lcd.set_cursor(1,1);
         break;
      case FREQ:
         lcd.set_cursor(2,1);
         break;
      case AMPL:
         lcd.set_cursor(3,1);
         break;
      case OFFSET:
         lcd.set_cursor(4,1);
         break;
      default:
         break;
   }
   lcd.write(m_mark);
}

// Sélectionne une ligne
void Menu::go_to(int8_t x)
{
   // Effacement de menu en cours
   switch(m_active)
   {
      case FORME:
         lcd.set_cursor(1,1);
         break;
      case FREQ:
         lcd.set_cursor(2,1);
         break;
      case AMPL:
         lcd.set_cursor(3,1);
         break;
      case OFFSET:
         lcd.set_cursor(4,1);
         break;
      default:
         break;
   }

   lcd << " ";

   // Check ifx is valid and go to it
   if(x < FORME)
   {
      m_active = OFFSET;
   }
   else if(x > OFFSET)
   {
      m_active = FORME;
   }
   else
   {
      // Go to menu x
      m_active = (enum menu_line) x;
   }

   // Print symbol befor selected menu
   switch(m_active)
   {
      case FORME:
         lcd.set_cursor(1,1);
         break;
      case FREQ:
         lcd.set_cursor(2,1);
         break;
      case AMPL:
         lcd.set_cursor(3,1);
         break;
      case OFFSET:
         lcd.set_cursor(4,1);
         break;
      default:
         break;
   }
   lcd << setw(1);
   lcd.write(m_mark);
}

// Initialise les valeurs du menu
void Menu::init_value(S_ParamGen * data)
{

   lcd.set_cursor(1,16);
   lcd << setw(5) << MENU_VALUE[data->Forme];

   lcd.set_cursor(2,16);
   lcd << setw(5) << data->Frequence;

   lcd.set_cursor(3,16);
   lcd << setw(5) << data->Amplitude;

   lcd.set_cursor(4,16);
   lcd << setw(5) << data->Offset;
}


// Met à jour la valeur affichée dans le menu en rajoutant un incrément
void Menu::update_value(int8_t incr, S_ParamGen * data )
{
      // Ajout de l'incrément et affichage de la valeur
    switch (m_active) {
        case FORME:
            lcd.set_cursor(1,16);

            if (data->Forme == 0 && incr == -1) {
                data->Forme = (E_FormesSignal) FORME_MAX;
            } else {
                data->Forme = (E_FormesSignal) (data->Forme + incr * FORME_INCR);
            }


            if (data->Forme > FORME_MAX) {
                data->Forme = (E_FormesSignal) FORME_MIN;
            } else {
                // Do nothing
            }
            lcd << cursor(1,16) << setw(5) << MENU_VALUE[data->Forme];
            break;
        case FREQ:
            data->Frequence += FREQUENCY_INCR * incr;

            if (data->Frequence > FREQUENCY_MAX) {
                data->Frequence = FREQUENCY_MIN;
            } else if (data->Frequence < FREQUENCY_MIN) {
                data->Frequence = FREQUENCY_MAX;
            } else {
                // Do nothing
            }
            lcd << cursor(2,16) << setw(5) << data->Frequence;
            break;
        case AMPL:
            data->Amplitude += incr * AMPLITUDE_INCR;

            if (data->Amplitude > AMPLITUDE_MAX) {
                data->Amplitude = AMPLITUDE_MIN;
            } else if (data->Amplitude < AMPLITUDE_MIN) {
                data->Amplitude = AMPLITUDE_MAX;
            } else {
                // Do nothing
            }
            lcd << cursor(3,16) << setw(5) << data->Amplitude;
            break;
        case OFFSET:
            data->Offset += incr * OFFSET_INCR;

            if (data->Offset > OFFSET_MAX) {
                data->Offset = OFFSET_MIN;
            } else if (data->Offset < OFFSET_MIN) {
                data->Offset = OFFSET_MAX;
            } else {
                // Do nothing
            }
            lcd << cursor(4,16) << setw(5) << data->Offset;
            break;
        default:
            break;
    }
}

void Menu::unset_lock(S_ParamGen * data)
{
   m_lock = false;
   set_mark(UNLOCK);
   switch(m_active)
      {
         case FORME:
            m_old = (uint16_t) data->Forme;
            break;
         case FREQ:
            m_old = (uint16_t) data->Frequence;
            break;
         case AMPL:
            m_old = (uint16_t) data->Amplitude;
            break;
         case OFFSET:
            m_old = (uint16_t) data->Offset;
            break;
         default:
            break;
      }
}

void Menu::init_info_char(char line1, char line2, char line3, char line4 )
{
    lcd.set_cursor(1,1);
    lcd.write(line1);

    lcd.set_cursor(2,1);
    lcd.write(line2);

    lcd.set_cursor(3,1);
    lcd.write(line3);

    lcd.set_cursor(4,1);
    lcd.write(line4);
}

// Incrémente la ligne sélectionnée selon la valeur de incr
void Menu::add_to_active(int incr)
{
   go_to(m_active + incr);
}

Menu::~Menu() {
}

