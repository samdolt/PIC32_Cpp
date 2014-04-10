/**
 * Fichier : SerialPort.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Fonction d'abstraction pour la gestion du port série
 */

#include "SerialPort.h"
#include <p32xxxx.h>
#include <plib.h>

#include <iostream>




#ifndef SYS_FREQ
    #define SYS_FREQ (80000000L)
#endif

CircularBuffer * tx_buffer = new CircularBuffer(20);
CircularBuffer * rx_buffer = new CircularBuffer(20);

SerialPort::SerialPort(const uint8_t PORT_NUMBER)
{
    M_PORT_NUMBER = PORT_NUMBER;

   // M_TX_BUFFER = tx_buffer;
   // M_RX_BUFFER = rx_buffer;

    UARTConfigure(
       UART1,
      (UART_CONFIGURATION)(UART_ENABLE_HIGH_SPEED | UART_ENABLE_PINS_TX_RX_ONLY)
    );

    UARTSetFifoMode(
        UART1,
        (UART_FIFO_MODE)(UART_INTERRUPT_ON_TX_BUFFER_EMPTY | UART_INTERRUPT_ON_RX_3_QUARTER_FULL)
    );
    UARTSetLineControl(
        UART1,
        (UART_LINE_CONTROL_MODE) (UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1)
    );

    UARTSetDataRate(UART1, SYS_FREQ, 9600);

    UARTEnable(
       UART1,
        (UART_ENABLE_MODE) UART_ENABLE_FLAGS(
            (UART_ENABLE_MODE) (UART_PERIPHERAL | UART_TX | UART_RX)
       )
    );

   INTEnable(
            (INT_SOURCE) INT_SOURCE_UART_RX(UART1),
            INT_ENABLED
    );

    INTSetVectorPriority(
        (INT_VECTOR) INT_VECTOR_UART(UART1),
        INT_PRIORITY_LEVEL_5
    );

    INTSetVectorSubPriority(
            (INT_VECTOR) INT_VECTOR_UART(UART1),
            INT_SUB_PRIORITY_LEVEL_0
    );
    
}

void SerialPort::print(const char data[])
{
    
    int i = 0;

    while(data[i] != '\0') {
        write( data[i] );
        i++;
    } 
}


void SerialPort::write(char data)
{
    
    tx_buffer->put(data);
   
    if(tx_buffer->get_number_of_item() != 0 )
    {
        INTEnable(INT_U1TX, INT_ENABLED);
    }
};


char SerialPort::get(void)
{
     return rx_buffer->get();
}

void SerialPort::read(char buf[], int buf_size)
{

    update();
    int i = 0;
    while( (rx_buffer->get_free_size() > 0) && (i < (buf_size - 1)) ) // On laisse une place pour \0
    {
        buf[i] = rx_buffer->get();
        i++;
    }
    buf[i] = '\0';
}

void SerialPort::update(void)
{
    while(UARTReceivedDataIsAvailable(UART1))
    {
       rx_buffer->put(UARTGetDataByte(UART1));
    }
}
SerialPort::~SerialPort()
{
}


extern "C" {

    void __ISR(_UART_1_VECTOR, IPL5SOFT) UART1_isr(void)
    {
        bool tx_ready;
        uint8_t tx_size;
        uint8_t tx_data;

        UART_LINE_STATUS rx_status;

         //mPORTAToggleBits(BIT_5); // LED3

        if( INTGetFlag(INT_U1RX) && INTGetEnable(INT_U1RX)) {
            // Gestion de l'interruption de récéption

            rx_status = UARTGetLineStatus(UART1);

            if( ( rx_status & ( UART_PARITY_ERROR | UART_FRAMING_ERROR | UART_OVERRUN_ERROR)) == 0)
            {

                while(UARTReceivedDataIsAvailable(UART1))
                {
                    rx_buffer->put(UARTGetDataByte(UART1));
                }

                INTClearFlag(INT_U1RX);
            }
            else
            {
                UART1ClearAllErrors();
            }
        } 

        if(INTGetFlag(INT_U1TX) && INTGetEnable(INT_U1TX))
        {
            tx_ready = UARTTransmitterIsReady(UART1);
            tx_size = tx_buffer->get_free_size();
            if( (tx_size > 0) && tx_ready )
            {
                do {
                    tx_data = tx_buffer->get();
                    UARTSendDataByte(UART1, tx_data);

                    tx_size = tx_buffer->get_free_size();
                    tx_ready = UARTTransmitterIsReady(UART1);

                } while( (tx_size > 0) && tx_ready );
                INTClearFlag(INT_U1TX);

            }
            else
            {
                INTEnable(INT_U1TX, INT_DISABLED);
            }
           // Gestion de l'interruption de récéption
            
        }

    } // UART_isr

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
