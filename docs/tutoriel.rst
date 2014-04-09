Introduction
*************

Utilisation d'une entrée sortie digitale avec DigitalPin
=========================================================

Dans votre fichier principal, vérifier que le fichier DigitalPin.h est
inclus.

.. code-block:: cpp

    #include "DigitalPin.h"
    
Initialisation de la classe
---------------------------

Pour utiliser la broche B2, on peux initialiser la classe DigitalPin
de deux manière différente:

.. code-block:: cpp

    DigitalPin broche_b2 = DigitalPin("B2");
    DigitalPin broche_b2 = DigitalPin('B', 2); // Déclaration alternative
    
De manière similaire, pour la broche D15:

.. code-block:: cpp

    DigitalPin broche_d15 = DigitalPin("D15");
    DigitalPin broche_d15 = DigitalPin('D', 15); // Déclaration alternative

    
Lecture de l'état logique
--------------------------

.. note::

   Pour lire l'état d'une broche, il est préférable de la mettre en
   entrée!
   
   .. code-block:: cpp

    broche_b2.set_input();
    broche_b2.set_direction(INPUT); // Alternative

Pour lire l'état logique de la broche B2, il suffis d'appeler sa méthode
read.
    
.. code-block:: cpp

   bool value;
   value = broche_b2.read();
    
Écriture de l'état logique
--------------------------

.. warning::

   Pour imposer un état logique sur une broche, il faut impérativement
   la configurer en sortie:
   
   .. code-block:: cpp

    broche_b2.set_output();
    broche_b2.set_direction(OUTPUT); // Alternative
 
Pour imposer l'état haut, écrire un des codes suivant:
 
 .. code-block:: cpp

   broche_b2.set_high();
   broche_b2.write(HIGH); // Alternative
   
Pour imposer l'état haut, écrire un des codes suivant:
 
 .. code-block:: cpp

   broche_b2.set_high();
   broche_b2.write(HIGH); // Alternative

Pour imposer l'état bas, écrire un des codes suivant:
 
 .. code-block:: cpp

   broche_b2.set_low();
   broche_b2.write(LOW); // Alternative

Pour inverser l'état logique de la broche:
 
 .. code-block:: cpp

   broche_b2.toggle();  

Gestion des temporisations
---------------------------

On peut introduire des temps de délais en secondes, millisecondes ou
microsecondes à l'aide des fonctions du namespace delai. L'exemple 
suivant montre trois manières d'effectuer une temporisation d'une
seconde:

.. code-block:: cpp

    delai::s(1);
    delai::ms(1000);
    delai::us(1000000);
 