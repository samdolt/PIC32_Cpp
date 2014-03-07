/*
 * Fichier : main.cpp
 * Auteur  : Samuel Dolt
 *
 * Exemple de projet C++
 *
 * Ce projet est destin� au circuit "Starter-kit PIC32" de l'ETML-ES
 */

#include <GenericTypeDefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <tgmath.h>

#include "SK32MX795F512L.h"
#include "Mc32Delays.h"
#include "TextDisplay.h"

//=====================================----------------------------------------
// Fuses configuration
//=====================================----------------------------------------
// Set configuration fuses (but only once)

// Set clock configuration
// Input clock = HS 20MHz
#pragma POSCMOD = HS // Primary Oscillator mode = HS
#pragma FSOSCEN = OFF // Secondary Oscillator Disable
#pragma IESO = OFF // Internal External Switch Over bit Disable
#pragma FNOSC = PRIPLL // Primary oscillator (XT, HS, EC) w/ PLL  
#pragma OSCIOFNC = OFF // Disabled output on clko pin
#pragma FCKSM = CSDCMD // Clock Switching Disabled, Clock Monitoring Disabled  

//Set system PLL configuration (Quartz 8 MHz)
// #pragma FPLLIDIV = DIV_5 // Divide by 5 clock for input to pll ->4MHz
#pragma FPLLIDIV = DIV_2 // Divide by 2 clock for input to pll ->4MHz
#pragma FPLLMUL = MUL_20 // Multiply by 20 -> pll output = 80MHz
#pragma FPLLODIV = DIV_1 // System clock = pll Divide by 1 = 80MHz

// Set peripheral clk div
#pragma FPBDIV = DIV_8 // Divide by 8 

// Set power up timer
#pragma PUT = ON

// set USB
#pragma FVBUSONIO = OFF // VBUS_ON pin is controlled by the Port Function  
#pragma FUSBIDIO = OFF // USBID pin is controlled by the Port Function  

// Set CAN
#pragma FCANIO = ON // Default CAN IO Pins  

// Set Ethernet
#pragma FETHIO = ON // Default Ethernet IO Pins  
#pragma FMIIEN = ON // MII enabled  

// set watchdog
#pragma  FWDTEN = OFF // Disabled  

// Set code protect
#pragma CP = OFF // Disabled  

// Set boot flash code protect
#pragma BWP = OFF // Disabled  

// Set ICD3 channel
#pragma ICESEL = ICS_PGx2 // ICE pins are shared with PGC2, PGD2  

// Set debug bit
#pragma DEBUG = ON // Enabled  



//=====================================----------------------------------------
// d�finitions pour les Timers
//=====================================----------------------------------------

#define SYS_FREQ (80000000L)    //80 MHz
#define PB_DIV 8
// #define PB_FREQ (SYS_FREQ / PB_DIV)
#define PB_FREQ (4000000L)

#define PRESCALE 256
#define T1_TICK ((1000000.0 * PRESCALE)/PB_FREQ) // en us
// 25 ms => 25'000 us
#define VAL_PR1 (25000 / T1_TICK)

#define PRESCALE_4 1
#define T4_TICK ((1000000.0 * PRESCALE_4)/PB_FREQ) // en us
// 40 us
#define VAL_PR4 (40.0 / T4_TICK)


//=====================================----------------------------------------
// fonction main
//=====================================----------------------------------------
int main (void){
  // disable JTAG port to free RA0, RA1, RA4 et RA5
  mJTAGPortEnable(0);

  // memory wait states fine tuning
  // TO BE CHECKED
  SYSTEMConfigPerformance(SYS_FREQ);
  // Etablit PB_CLOCK � 4 MHz
   
  // Default SK32MX775F512L i/os config and values
  SK32MX795F512L_IO_Default();  
 

  TextDisplay lcd = TextDisplay();

  lcd << "LCD C++ avec Stream" << endl;
  lcd << "Hex : " << convert::to_hex(3452) << endl;
  lcd << "Dec : " << 3452 << endl;

  while(1){
    // Ne rien faire (juste un comptage)
  }

  return 0; // Le C++ oblige un retour de valeur pour la fonction main
}


extern "C"
{
    // Les interruptions doivent �tre inclus ici
}