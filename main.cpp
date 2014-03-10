/*
 * Fichier : main.cpp
 * Auteur  : Samuel Dolt
 *
 * Exemple de projet C++
 */

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>

#include "Port.h"
#include "Delay.h"
#include "TextDisplay.h"



/*******************************************************************************
 * CONFIGURATION DES FUSIBLES
 ******************************************************************************/


/* Configuration des oscillateurs
 * ------------------------------ */

#pragma config POSCMOD = HS // Oscillateur primaire en mode "HIGH SPEED CRYSTAL"
#pragma config FSOSCEN = OFF // Oscillateur secondaire désactivé
#pragma config IESO = OFF // Internal External Switch Over bit Disable
#pragma config FNOSC = PRIPLL // Oscillateur primaire avec PLL
#pragma config OSCIOFNC = OFF // Désactivation de la sortie sur la pin CLKO
#pragma config FCKSM = CSDCMD // Clock Switching Disabled, Clock Monitoring Disabled


/* Configuration de la PLL avec un quartz externe de 8 MHz
 * ------------------------------------------------------- */
#pragma config FPLLIDIV = DIV_2 // Division de l'oscillateur primaire par 2 ->4MHz
#pragma config FPLLMUL = MUL_20 // Multiplication par 20 -> 80MHz en sortie de la PLL
#pragma config FPLLODIV = DIV_1 // Division par 1 -> 80MHz pour l'horloge système
#define SYS_FREQ (80000000L)    // Constante stockant la valeur de l'horloge système



/* Configuration du chien de garde (WATCHDOG)
 * ------------------------------------------ */
#pragma  config FWDTEN = OFF // Désactivé



/* Configuration du programmeur
 * ------------------------------------------ */
#pragma config ICESEL = ICS_PGx2 // ICE pins are shared with PGC2, PGD2

// Set debug bit
#pragma config DEBUG = ON // Enabled







//=====================================----------------------------------------
// fonction main
//=====================================----------------------------------------
int main (void){
  // disable JTAG port to free RA0, RA1, RA4 et RA5
  mJTAGPortEnable(0);

  // memory wait states fine tuning
  // TO BE CHECKED
  SYSTEMConfigPerformance(SYS_FREQ); // Cette fonction retourne PB_CLK
  // Etablit PB_CLOCK = à SYSCLK

  TextDisplay lcd = TextDisplay("E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7");

  lcd << "LCD C++ avec Stream" << endl;
  lcd << "Hex : " << convert::to_hex(3452) << endl;
  lcd << "Dec : " << 3452 << endl;
  lcd << "brochage variable" << endl;

  while(1){
    // Ne rien faire (juste un comptage)
      pin::set_output('A', 0);
      pin::set('A', 0);
      delay::ms(1000);
      pin::clear('A', 0);
      delay::ms(1000);
  }

  return 0; // Le C++ oblige un retour de valeur pour la fonction main
}


extern "C"
{
    // Les interruptions doivent être inclus ici
}