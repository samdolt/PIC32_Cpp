Prise en main avec le starter kit PIC32 de l'ETML-ES
*****************************************************

Utilisation des LEDS
=====================

Pour allumer la led 0, il suffit d'écrir:

.. code-block:: cpp

   led0.set_on();
   
De manière intuitive, pour l'éteindre:

.. code-block:: cpp

   led0.set_off();
   
Et pour inverser son état:

.. code-block:: cpp

   led0.toggle();

   
Utilisation du LCD
===================

Écriture
---------

Pour écrire sur le première ligne du LCD, il faut d'abords position le
curseur en position (1,1),

.. code-block:: cpp

   lcd.set_cursor(1,1);
   lcd << "Hello";
   
Pour la position (1,1), le raccourcis suivant est disponible:

.. code-block:: cpp

   lcd.home();
   

Pour écrire à partir du cinquième caractère de la ligne deux, il
faut écrire:

.. code-block:: cpp

   lcd.set_cursor(2,5);
   lcd << "world";
   
Mot clef et conversion
-----------------------

Le retour à la ligne peut se faire automatique de deux manière:

.. code-block:: cpp

   lcd << endl;
   lcd << '\n'; // Alernative
   
Pour afficher un nombre en héxadécimal, il faut entrer:

.. code-block:: cpp

   lcd << convert::to_hex(125);
   
Éffaçage de l'écran
-------------------

La méthode clear permet d'effacer les caractères afficher.

.. code-block:: cpp

   lcd.clear()


Gestion du rétro-éclairage
---------------------------

Le rétro-éclairage peut être éteint puis rallumer avec le code suivant:

.. code-block:: cpp

   lcd.disable_backlight()
   delay::ms(5000);
   lcd.enable_backlight();

   
Désactivation de l'écran
-------------------------

La méthode disable_display permet de désactiver l'écran sans perdre les
caractères qui y sont affiché. La méthode enable_display remet l'écran
dans sont état normal.

.. code-block:: cpp

   lcd.disable_display();
   delay::ms(5000);
   lcd.enable_display();
   
Gestion du curseur
------------------

Le curseur peut être afficher de deux manière.

Comme un tirait en bas:

.. code-block:: cpp

   lcd.enable_underline_cursor();
   delay::ms(5000);
   lcd.disable_underline_cursor();
   
Avec un carré noir clignottant:

.. code-block:: cpp

   lcd.enable_blinking_cursor();
   delay::ms(5000);
   lcd.disable_blinking__cursor();


   