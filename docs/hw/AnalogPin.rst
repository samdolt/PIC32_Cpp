**************************************
Gestion des entrées analogiques
**************************************

Les entrées analogique sont implémenté dans le fichier 
hw/AnalogPin.h qu'il faut tous d'abord inclure :

.. code-block:: cpp

    #include "AnalogPin.h"
    
    float value;
    uint16_t value_10bit;
    
    // Déclaration pour la broche RB6
    AnalogPin AI_B6 = AnalogPin(6);
    
    // Lecture de la broche RB6
    value = A<i_B6.read();
    value_10bit = IO_B6.read_raw();

    
Description
============
.. cpp:class:: AnalogPin
    
    .. cpp:function:: AnalogPin(const uint8_t AN_NUMBER )
   
        :param AN_NUMBER: Numéro de la broche analogique sur le port B
      
        Par exemple 1 pour PB1.
        
    .. cpp:function:: uint16_t read_raw(void)
    
        :return: Returne la niveau entre la masse et la tension
        d'alimentation sur 10bits, de 0 à 1024.
        
    .. cpp:function:: uint16_t read(void)
    
        :return: Returne la niveau entre la masse et la tension 
        d'alimentation entre 0 et 1.
      
