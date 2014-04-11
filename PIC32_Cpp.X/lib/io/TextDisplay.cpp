/**
 * Fichier : TextDisplay.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Pilote orienté object pour affichage LCD basé sur un circuit
 * Hitachi HD44780 ou compatible
 *
 * Ce code est basé sur:
 *     - Le fichier Mc32DriverLcd.c de Gomes Andres (ETML-ES)
 */

#include "GenericTypeDefs.h"

#include <p32xxxx.h>
#include <cstring>



#include "TextDisplay.h"
#include "Delay.h"
#include "SerialPort.h"



/******************************************************************************
 * CONSTANTE
 ******************************************************************************/
namespace LCD {

    // Commande
    const uint8_t CLEARDISPLAY = 0x01;
    const uint8_t RETURNHOME = 0x02;
    const uint8_t ENTRYMODESET = 0x04;
    const uint8_t DISPLAYCONTROL = 0x08;
    const uint8_t CURSORSHIFT = 0x10;
    const uint8_t FUNCTIONSET = 0x20;
    const uint8_t SETCGRAMADDR = 0x40;
    const uint8_t SETDDRAMADDR = 0x80;

    // Drapeau pour le mode d'affichage
    const uint8_t ENTRYRIGHT = 0x00;
    const uint8_t ENTRYLEFT = 0x02;
    const uint8_t ENTRYSHIFTINCREMENT = 0x01;
    const uint8_t ENTRYSHIFTDECREMENT = 0x00;

    // Drapeau pour la gestion de l'affichage
    const uint8_t DISPLAYON = 0x04;
    const uint8_t DISPLAYOFF = 0x00;
    const uint8_t CURSORON = 0x02;
    const uint8_t CURSOROFF = 0x00;
    const uint8_t BLINKON = 0x01;
    const uint8_t BLINKOFF = 0x00;

    // Drapeau pour les déplacements d'écrane et de curseur
    const uint8_t DISPLAYMOVE = 0x08;
    const uint8_t CURSORMOVE = 0x00;
    const uint8_t MOVERIGHT = 0x04;
    const uint8_t MOVELEFT = 0x00;

    // Drapeau pour l'initialisation
    const uint8_t BIT8MODE = 0x10;
    const uint8_t BIT4MODE = 0x00;
    const uint8_t LINE2 = 0x08;
    const uint8_t LINE1 = 0x00;
    const uint8_t DOTS5x10 = 0x04;
    const uint8_t DOTS5x8 = 0x00;
}


/******************************************************************************
 * FONCTION PUBLIQUE
 ******************************************************************************/

TextDisplay::TextDisplay(const char RS[], const char RW[], const char EN[],
                         const char BL[], const char DB4[], const char DB5[],
                         const char DB6[], const char DB7[]) {

    /**************************************************************************
     * Sauvegarde des paramètres
     **************************************************************************/

    M_RS = new DigitalPin(RS);
    M_RW = new DigitalPin(RW);
    M_EN = new DigitalPin(EN);
    M_BL = new DigitalPin(BL);
    M_DB4 = new DigitalPin(DB4);
    M_DB5 = new DigitalPin(DB5);
    M_DB6 = new DigitalPin(DB6);
    M_DB7 = new DigitalPin(DB7);
    
    /*--------------------------------------------------------*/
    /* Définition du tableau pour l'adresse des lignes
    /*--------------------------------------------------------*/
    M_LINES_ADRESS[0] = 0; // Non utilisé
    M_LINES_ADRESS[1] = 0; // Adresse de la ligne 1
    M_LINES_ADRESS[2] = 64;
    M_LINES_ADRESS[3] = 20;
    M_LINES_ADRESS[4] = 84; // Adresse de la ligne 4

    M_NUMBER_OF_LINE = 4;
    M_NUMBER_OF_COLUMN = 20;

    m_config.width = 0;

    /***************************************************************
     * GESTION DES PIN
     ***************************************************************/
     // On met d'abord toutes les pattes du LCD à 1 sauf le backlight
    M_RS->set_high();
    M_RW->set_high();
    M_EN->set_high();
    M_BL->set_low();

    M_RS->set_output();
    M_RW->set_output();
    M_EN->set_output();
    M_BL->set_output();
    M_DB4->set_output();
    M_DB5->set_output();
    M_DB6->set_output();
    M_DB7->set_output();

     enable_backlight();

    // on va effectuer exactement ce que demande le ks0066
    // on repositionne LCD_E tout pour un démarrage correct
    M_EN->set_low();
    delay::us(1); // si LCD_E était à 1, on attend
    M_RS->set_low();
    M_RW->set_low();

    // suivant comment l'interfaçage avec le LCD s'est arrêté, il faut tout remettre à plat
    // selon les notes d'applications, il faut envoyer 3 fois un nibble 0x3
    // pour lui faire croire que nous sommes en interface8 bits
    // chaque envoi doit être séparé de 5ms!!
    send_nibble(0x03); // correspond à 0x30, interface 8 bits
    delay::ms(5);
    send_nibble(0x03); // correspond à 0x30, interface 8 bits
    delay::ms(5);
    send_nibble(0x03); // correspond à 0x30, interface 8 bits
    delay::ms(5);
    // maintenant, on peut configurer notre LCD en interface 4 bits

    M_RS->set_low();

    send_nibble(2);// 4 bits interface

    command(LCD::DISPLAYCONTROL | LCD::LINE2 | LCD::DISPLAYOFF);
    delay::us(40); //ds0066 demande >39us

    // Initilisation du mode par défaut:
    m_display_control = LCD::DISPLAYON | LCD::CURSOROFF | LCD::BLINKOFF;
    command( LCD::DISPLAYCONTROL | m_display_control);
    delay::us(40); //ds0066 demande >39us

    // Effacage de l'écran
    clear();
    
    // Initilisation du sens du texte
    m_display_mode = LCD::ENTRYLEFT | LCD::ENTRYSHIFTDECREMENT;
    command(LCD::ENTRYMODESET | m_display_mode);

    set_cursor(1,1);
    delay::us(40); //ds0066 demande >39us
}

void TextDisplay::print(const char *ptr_char) {
    int i;

    for(i = 0; ptr_char[i] != '\0' ; i++)
    {
        write(ptr_char[i]);
    }

    if(m_config.width != 0)
    {
        while(i < m_config.width)
        {
            write(' ');
            i++;
        }

        m_config.width == 0;
    }
}

void TextDisplay::print(const int32_t number)
{
    print(convert::to_dec(number));
}

void TextDisplay::print(const convert_s data )
{
        char str[15];
        switch(data.base){
            case 10:
                sprintf(str, "%d", data.number);
                break;
            case 16:
                sprintf(str, "%X", data.number);
                break;
            default:
                str[0] = '\0';
                break;
        }
        print(str);
}

void TextDisplay::print(enum stream_symbol symbol)
{
    switch(symbol){
        case endl:
            write('\n');
            break;
        default:
            break;
    }
}

void TextDisplay::print(lcd_config_s config)
{
    switch(config.update)
    {
        case 'w':
            m_config.width = config.width;
            break;
        default:
            break;
    }
}

void TextDisplay::write(const uint8_t c) {
    switch (c) {
        case '\n':
            set_cursor(m_line + 1, 1);
            break;
        case '\t':
            if(( m_column <= (M_NUMBER_OF_COLUMN - 4) ) && (m_line <= (M_NUMBER_OF_LINE)) ){
                // Caractère de tabulation -> quatre espace blanc
                send_byte(1,' ');
                send_byte(1,' ');
                send_byte(1,' ');
                send_byte(1,' ');
                m_column += 4;
            }
            break;
        default:
            if( (m_column <= (M_NUMBER_OF_COLUMN) ) && (m_line <= (M_NUMBER_OF_LINE)) ){
                // On écrit uniquement si la mise à jour est nécessaire
                if( (uint8_t) read(m_line, m_column) != c)
                {
                    send_byte(1,c);
                }
                m_column++;
            }
            break;
    }

    if(m_column > 20)
    {
        m_column = 21;
    }
}

void TextDisplay::home(void)
{
  command(LCD::RETURNHOME); 
  delay::ms(2);
}

int8_t TextDisplay::set_cursor(uint8_t y, uint8_t x) {
   uint8_t address;

  // Sauvegarde
   m_line = y;
   m_column = x;

   // Validation des valeurs

   if(y > 4)
   {
       m_line = 4;
       m_column = 21;
       return -1;
   }
   else if(y == 0)
   {
       return -1;
   }
   else
   {
       // Ne rien faire
   }

   if(x > 20)
   {
       return -1;
   }
   else if(y == 0)
   {
       return -1;
   }
   else
   {
       // Ne rien faire
   }

   // Traitement
   address = M_LINES_ADRESS[y];
   address+=x-1;
   send_byte(0,0x80|address);


}

int8_t TextDisplay::set_cursor(cursor_s cursor)
{
    set_cursor(cursor.line, cursor.column);
};

cursor_s TextDisplay::get_cursor(void)
{
    cursor_s cursor;
    cursor.column = m_column;
    cursor.line = m_line;

    return cursor;
};

void TextDisplay::enable_backlight(void) {
    M_BL->set_high();
}

void TextDisplay::disable_backlight(void) {
    M_BL->set_low();
}

void TextDisplay::clear( void )
{
    command(LCD::CLEARDISPLAY);
    delay::ms(2);
}

void TextDisplay::clear_line(void)
{
    cursor_s cursor = get_cursor();

    set_cursor(cursor.line, 1);
    print("                    ");
    set_cursor(cursor);
}

void TextDisplay::disable_display(void) {
  m_display_control &= ~LCD::DISPLAYON;
  command( LCD::DISPLAYCONTROL | m_display_control);
}
void TextDisplay::enable_display(void) {
  m_display_control |= LCD::DISPLAYON;
  command( LCD::DISPLAYCONTROL | m_display_control);
}

void TextDisplay::enable_blinking_cursor( void )
{
    m_display_control |= LCD::BLINKON;
    command( LCD::DISPLAYCONTROL | m_display_control);
    delay::ms(2);
}

void TextDisplay::disable_blinking_cursor( void )
{
    m_display_control &= ~LCD::BLINKON;
    command( LCD::DISPLAYCONTROL | m_display_control);
    delay::ms(2);
}

void TextDisplay::disable_underline_cursor(void) {
  m_display_control &= ~LCD::CURSORON;
   command(LCD::DISPLAYCONTROL | m_display_control);
}
void TextDisplay::enable_underline_cursor(void) {
  m_display_control |= LCD::CURSORON;
  command(LCD::DISPLAYCONTROL | m_display_control);
}


// This will 'right justify' text from the cursor
void TextDisplay::enable_autoscroll(void) {
  m_display_mode |= LCD::ENTRYSHIFTINCREMENT;
  command(LCD::ENTRYMODESET | m_display_mode);
}

// This will 'left justify' text from the cursor
void TextDisplay::disable_autoscroll(void) {
  m_display_mode &= ~LCD::ENTRYSHIFTINCREMENT;
  command(LCD::ENTRYMODESET | m_display_mode);
}

// These commands scroll the display without changing the RAM
void TextDisplay::scroll_left(void) {
  command(LCD::CURSORSHIFT | LCD::DISPLAYMOVE | LCD::MOVELEFT);
}
void TextDisplay::scroll_right(void) {
  command(LCD::CURSORSHIFT | LCD::DISPLAYMOVE | LCD::MOVERIGHT);
}

TextDisplay::~TextDisplay() {
    delete M_RS;
    delete M_RW;
    delete M_EN;
    delete M_BL;
    delete M_DB4;
    delete M_DB5;
    delete M_DB6;
    delete M_DB7;
}

/******************************************************************************
 * FONCTION PRIVEE
 ******************************************************************************/

void TextDisplay::command(uint8_t value) {
    send_byte(0, value);
}

void TextDisplay::send_byte(uint8_t address, uint8_t n) {
    M_RS->set_low();

    while ( (read_byte() & 0x80) == 0x80 ){
    };

    M_RS->write(address);

    M_RW->set_low();

    //LCD_E déjà à 0
    send_nibble(n >> 4);
    send_nibble(n & 0xf);
}

void TextDisplay::send_nibble(uint8_t n) {
   UINT8_BITS NibbleToWrite;
   NibbleToWrite.Val = n;
   M_DB7->write(NibbleToWrite.bits.b3);
   M_DB6->write(NibbleToWrite.bits.b2);
   M_DB5->write(NibbleToWrite.bits.b1);
   M_DB4->write( NibbleToWrite.bits.b0);
   delay::us(1);

   M_EN->set_high();
   delay::us(1); // E pulse width min = 450ns pour le 1!
   M_EN->set_low();
   delay::us(1); // E pulse width min = 450ns également pour le 0!
}

/******************************************************************************
 * FONCTION BAS NIVEAU - PRIVE
 ******************************************************************************/

uint8_t TextDisplay::read_byte( void )
{
    UINT8_BITS lcd_read_byte;
    M_DB4->set_input();
    M_DB5->set_input();
    M_DB6->set_input();
    M_DB7->set_input();

    M_RW->set_high();
    delay::us(1); //ds0066 demande 0.5us
    M_EN->set_high();
    delay::us(1); //ds0066 demande 0.5us
    lcd_read_byte.bits.b7 = M_DB7->read();
    lcd_read_byte.bits.b6 = M_DB6->read();
    lcd_read_byte.bits.b5 = M_DB5->read();
    lcd_read_byte.bits.b4 = M_DB4->read();
    M_EN->set_low(); // attention e pulse min = 500ns à 1 et autant à 0
    delay::us(1);
    M_EN->set_high();
    delay::us(1);
    lcd_read_byte.bits.b3 = M_DB7->read();
    lcd_read_byte.bits.b2 = M_DB6->read();
    lcd_read_byte.bits.b1 = M_DB5->read();
    lcd_read_byte.bits.b0 = M_DB4->read();

    M_EN->set_low();
    delay::us(1);

    M_DB4->set_output();
    M_DB5->set_output();
    M_DB6->set_output();
    M_DB7->set_output();

    return(lcd_read_byte.Val);
}

char TextDisplay::read( uint8_t y, uint8_t x)
{
    uint8_t value;
    cursor_s cursor = get_cursor();
    set_cursor(y,x);

    while ( read_byte() & 0x80 ){
    }; // wait until busy flag is low
    M_RS->set_high();
    value = read_byte();
    M_RS->set_low();

    set_cursor(cursor);
    return(value);
}

char TextDisplay::read( cursor_s cursor)
{
    return read(cursor.line, cursor.column);
}


/******************************************************************************
 * GESTION DES CONVERSIONS
 ******************************************************************************/
namespace convert {
    convert_s  to_dec(int32_t number)
    {
        convert_s data;
        data.base = 10;
        data.number = number;
        return data;
    }

    convert_s  to_hex(int32_t number)
    {
        convert_s data;
        data.base = 16;
        data.number = number;
        return data;
    }
}

lcd_config_s setw(uint8_t width)
{
    lcd_config_s config;

    config.width = width;
    config.update = 'w';
    return config;
}
/******************************************************************************
 * LICENSE
 ******************************************************************************/

/*
 * Copyright (c) 2014, Samuel Dolt <samuel@dolt.ch>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */