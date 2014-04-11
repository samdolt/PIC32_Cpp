*****************************************************
Utilisation avec le starter kit PIC32 de l'ETML-ES
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

Remarque: Afin d'éviter le clignottement de l'écran, les caractères sont écrit à l'écran
uniquement s'il n'y était pas déjà. Il est ainsi plus nécessaire de le faire manuellement.
 

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
   
Pour fixer la longueur du prochain paramètre, on utilise setwritemode

.. code-block:: cpp

   lcd << setw(4) << "ABC"; // Avec setw(4), un espace est rajouté après le 'C'
   
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
   
Utilisation des touches
========================

Pour vérifier si une touche est appuyée:

.. code-block:: cpp

   if(menu1.is_pressed())
   {
       lcd << "Touche appuyée";
   }
   
Pour vérifier si une touche est relachée:

.. code-block:: cpp

   if(menu1.is_relached())
   {
       lcd << "Touche relachée";
   }

Pour vérifier si une touche a un nouvel état:

.. code-block:: cpp

   if(menu1.has_a_new_state())
   {
       lcd << "L'état a changé";
   }
  
Utilisation du PEC12
=====================

Pour obtenir la direction de la dernière rotation:

.. code-block:: cpp

   int8_t dir = pec12.get_state();
   
   if(dir == +1)
   {
        lcd << "Rotation de le sens horaire";
   }
   else if(dir == -1)
   {
        lcd << "Rotation de le sens anti-horaire";
   }
   else
   {
       lcd << "Personne a utilisé le PEC12";
   }

Pour vérifier si le PEC a un nouvel état:

.. code-block:: cpp

   if(pec12.has_a_new_state())
   {
       lcd << "Le PEC a bougé";
   }

Utilisation du clavier matriciel
=================================




   