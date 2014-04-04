 /**
 * Fichier : TextDisplay.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Pilote orienté object pour affichage LCD basé sur un circuit
 * Hitachi HD44780 ou compatible
 *
 * Ce code est basé sur:
 *     - Le fichier t Mc32DriverLcd.c de Gomes Andres (ETML-ES)
 */

#ifndef TEXTDISPLAY_H
#define	TEXTDISPLAY_H

#include <cstdint>
#include <cstdio>

/*
 * Structure permettant de définir un nombre et la base dans lequel on
 * veut l'afficher
 */
typedef struct{
    uint8_t base;
    int32_t number;
}convert_s;

/*
 * Permet l'utilisation du code endl
 */
enum stream_symbol {
    endl
};

enum lcd_type_e
{
    LCD2X16,
    LCD4X20
};

/*
 * Classe représentant l'écran LCD. Pour l'instant la classe se base
 * sur le brochage définit dans le fichier SK32MX795F512L.h
 *
 * Pour l'instant, la classe gère uniquement des écrans de 4 lignes
 */

class TextDisplay{
public:

    /**
     * @brief Constructeur de TextDisplay
     *
     * @param RS Chaîne représentant une broche
     * @param RW Chaîne représentant une broche
     * @param E Chaîne représentant une broche
     * @param BL Chaîne représentant une broche
     * @param DB4 Chaîne représentant une broche
     * @param DB5 Chaîne représentant une broche
     * @param DB6 Chaîne représentant une broche
     * @param DB7 Chaîne représentant une broche
     */
    TextDisplay(const char RS[], const char RW[], const char E[],
                const char BL[], const char DB4[], const char DB5[],
                const char DB6[], const char DB7[]);

    /*
     * print permet d'afficher une chaine de caractère à l'écran
     * Aucun formatage n'est effectué
     */
    void print(const char *ptr_char);
    void print(const int32_t number);
    void print(const convert_s data );
    void print(enum stream_symbol symbol);

    /*
     *  write écrit un caractère sur l'écran
     */
    void write(const uint8_t c);

    /*
     * Déplace le curseur en position 1,1
     */
    void home(void);

    /*
     * Déplace le curseur à la position donné en paramètre
     * - x : N° de ligne de 1 à 4
     * - y : N° de colonne de 1 à 24
     */
    int8_t set_cursor(uint8_t x, uint8_t y);

    /*
     * Active le rétroéclairage de l'écran
     */
    void enable_backlight(void);

    /*
     * Désactive le rétroéclairage de l'écran
     */
    void disable_backlight(void);

    /*
     * Efface le contenu de l'écran
     */
    void clear( void );

    /*
     * Désactive l'affichage sans effacer son contenu
     */
    void disable_display(void);

    /*
     * Active l'affichage (réaffiche son contenu)
     */
    void enable_display(void);

    /*
     * Active l'affichage du curseur "clignotant"
     */
    void enable_blinking_cursor( void );

    /*
     * Désactive l'affichage du curseur "clignotant"
     */
    void disable_blinking_cursor( void );

    /*
     * Active l'affichage du curseur "souligné"
     */
    void disable_underline_cursor(void);

    /*
     * Désactive l'affichage du curseur "souligné"
     */
    void enable_underline_cursor(void);


    void enable_autoscroll(void);
    void disable_autoscroll(void);

    /*
     * Décalage à droite de l'affichage
     */
    void scroll_right(void);

    /*
     * Décalage à gauche de l'affichage
     */
    void scroll_left(void);

    /*
     * Destructeur
     */
    virtual ~TextDisplay();
private:
    /*
     * Lecture d'un caractère
     */
    char read( uint8_t x, uint8_t y);

    /*
     * Envoi d'un caractère
     */
    void send_byte(uint8_t address, uint8_t n);
    void send_nibble(uint8_t n);
    uint8_t read_byte( void );

    /*
     * Envoi d'une commande
     */
    void command(uint8_t value);

    /*
     * Stockage des broches utilisée
     */
    char M_RS[4]; // Utilisation de 4 caractère, exemple "A12\0"
    char M_RW[4];
    char M_EN[4];
    char M_BL[4];


    char M_RS_PORT, M_RW_PORT, M_EN_PORT, M_BL_PORT;
    int M_RS_PIN, M_RW_PIN, M_EN_PIN, M_BL_PIN;

    char M_DB4[4];
    char M_DB5[4];
    char M_DB6[4];
    char M_DB7[4];

    char M_DB4_PORT, M_DB5_PORT, M_DB6_PORT, M_DB7_PORT;
    int M_DB4_PIN, M_DB5_PIN, M_DB6_PIN, M_DB7_PIN;

    /*
     * Tableau contenant les adresses de ligne
     */
    uint8_t M_LINES_ADRESS[5];

    /*
     * Taille de l'écran
     */
    uint8_t M_NUMBER_OF_LINE;
    uint8_t M_NUMBER_OF_COLUMN;

    /*
     * Paramètres de control actuel
     */
    uint8_t m_display_control;

    /*
     * Mode d'affichage actuel
     */
    uint8_t m_display_mode;

    /*
     * Colonne actuelle
     */
    uint8_t m_column;

    /*
     * Ligne actuelle
     */
    uint8_t m_line;

};

/******************************************************************************
 * STREAM SUPPORT
 ******************************************************************************/

/* Template générique, redirige l'opérateur lcd << vers lcd.print pour tous les
 * type
 */
template<class T>
inline TextDisplay &operator <<(TextDisplay &stream, const T data)
{ stream.print(data); return stream; }

/******************************************************************************
 * GESTION DES CONVERSIONS
 ******************************************************************************/

namespace convert {
    convert_s to_dec(int32_t number);
    convert_s to_hex(int32_t number);
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

#endif	/* TEXTDISPLAY_H */