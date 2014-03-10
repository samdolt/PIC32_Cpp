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



/* Configuration du programmeur et du débogueur
 * -------------------------------------------- */
#pragma config ICESEL = ICS_PGx2 // Les pins ICE sont partagée avec PGC2 et PGD2
#pragma config DEBUG = ON // Mode DEBUG enclenché







/*******************************************************************************
 * FONCTION PRINCIPALE
 ******************************************************************************/
int main (void){
    /*
     * CONFIGURATION
     * -------------- */
    SYSTEMConfigPerformance(SYS_FREQ); // Cette fonction retourne PB_CLK = 80MHz
    mJTAGPortEnable(0); // Désactivation du JTAG, libère RA0, RA1, RA4 et RA5

    /*
     * Initialisation des objets
     * ------------------------- */
    TextDisplay lcd = TextDisplay("E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7");

    /*
     * Affichage initiale
     * ------------------------- */
    lcd << "Exemple PIC32 C++" << endl << endl << endl;
    lcd << "Starter Kit ETML-ES" << endl;

    /*
     * LED Clignottante
     * ------------------------- */

    pin::direction("A0", pin::OUTPUT);
    while(1){
        pin::write("A0", pin::HIGH);
        delay::ms(1000);
        pin::write("A0", pin::LOW);
        delay::ms(1000);
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