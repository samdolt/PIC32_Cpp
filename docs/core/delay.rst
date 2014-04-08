Fichier Delay.h
****************

La bibliothèque Delay permet d'utiliser des temporisations et des 
temps d'attente. Pour se faire, la bibliothèque utilise le CoreTimer
du PIC32.

Fonctions
==========

.. cpp:function:: void delay::s(uint32_t delay)
    
   :param uint32_t delay: Nombre de s à attendre
    
.. cpp:function:: void delay::ms(uint32_t delay)

   :param uint32_t delay: Nombre de ms à attendre
    
.. cpp:function:: void delay::us(uint32_t delay)

   :param uint32_t delay: Nombre de µs à attendre