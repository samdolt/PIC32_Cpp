﻿Définition du fichier SK-PIC32-B.h
************************************

Le fichier SK-PIC32-B.h initialise l'ensemble des périphériques
supportés afin de permettre la création rapide de programme en C++.

Emplacement
============

La figure suivante montre la relation entre les noms des instances et
les éléments hardware qui s'y rapporte.

.. figure:: ../_static/ETML-ES-SK-PIC32-B.svg

Définitions
============

Les objets définits sont les suivants:

.. cpp:member:: TextDisplay lcd
   
   Affichage LCD 4x20 charactères
   

   
.. cpp:member:: Key menu1
   
   Bouton "SEscMenu"

.. cpp:member:: Key menu2
   
   Bouton "S+"

.. cpp:member:: Key menu3
   
   Bouton "S-"

.. cpp:member:: Key menu4

   Bouton "S_Ok"

.. cpp:member:: Key menu5
   
   Bouton du PEC12 (PEC12_PB)
  
.. cpp:member:: IncrementalEncoder pec12

   Gestion des rotations du PEC12
   
.. cpp:member:: Led led0

   Led D6
   
.. cpp:member:: Led led1

   Led D10
   
.. cpp:member:: Led led2

   Led D7
   
.. cpp:member:: Led led3

   Led D11
   
.. cpp:member:: Led led4

   Led D8
   
.. cpp:member:: Led led5

   Led D12

.. cpp:member:: Led led6

   Led D9
   
.. cpp:member:: Led led7

   Led D13
   
.. cpp:member:: Keypad keypad

   Clavier matriciel, touche S10 à S22
