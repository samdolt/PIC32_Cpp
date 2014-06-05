**************************************
Gestion des entrées/sorties digitales
**************************************

Les entrées/sorties numériques sont implémenté dans le fichier 
hw/DigitalPin.h qu'il faut tous d'abord inclure :

.. code-block:: cpp

    #include "DigitalPin.h"
    
    // Mise à l'état au de la broche RB6
    DigitalPin IO_B6 = DigitalPin("B6");
    IO_B6.set_direction(OUTPUT);
    IO_B6.write(LOW);
    
    // Lecture de la broche RB6
    DigitalPin IO_B7 = DigitalPin("B7");
    bool value;
    
    IO_B6.set_direction(INPUT);
    value = IO_B6.read();   

    
Description
============
.. cpp:class:: DigitalPin
    
    .. cpp:function:: DigitalPin(const char PIN[])
   
        :param PIN: Chaîne décrivant la broche utilisée
      
        La broche doit être dans un chaîne du type "A1" ou "B12". Elles
        signifies port A, broche 1 et port B broche 12.
      
    .. cpp:function:: DigitalPin(const char PORT, uint16_t PIN_NUMBER)
   
        :param PORT: Caractère nommant le port, par exemple 'B'
        :param PIN_NUMBER: Numéro de la pin dans le port
        
    .. cpp:function:: void set_direction(enum direction)
    
        Configure la broche en entrée ou en sortie
        
        :param direction: INPUT ou OUTPUT
  
    .. cpp:function:: void set_input(void)
    
        Configure la broche en entrée
        
    .. cpp:function:: void set_output(void)
    
        Configure la broche en sortie
    
    .. cpp:function:: void write(enum state STATE)
    
        Met la broche à l'état indiqué.
        
        :param STATE: HIGH ou LOW
        
    .. cpp:function:: void write(bool STATE)
    
        Met la broche à l'état indiqué.
        
        :param STATE: 0 pour état bas, 1 pour état haut
        
    .. cpp:function:: void set_low(void)
    
        Met la broche à l'état bas
        
    .. cpp:function:: void set_high(void)
    
        Met la broche à l'état haut

    .. cpp:function:: void toggle(void)     

        Inverse la sortie.
        
    .. cpp:function:: bool read(void)
    
        Lis l'état du port
        
        :return: 0 pour l'état bas, 1 pour l'état haut
      
