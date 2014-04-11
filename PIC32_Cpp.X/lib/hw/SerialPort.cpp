/**
 * Fichier : SerialPort.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Fonction d'abstraction pour la gestion du port série
 */

#include "SerialPort.h"

#include <iostream>

#include "CircularBuffer.h"

/*
 * Le code est presque pret pour être compatible avec tous les UART, seul
 * les parties concernant les buffers circulaires et les interruptions doivent
 * être adaptées
 */

#ifndef SYS_FREQ
    #define SYS_FREQ (80000000L)
#endif

bool rx_interrupt_handler(UART_MODULE UART);
bool tx_interrupt_handler(UART_MODULE UART);


CircularBuffer tx_buffer1 = CircularBuffer(20);
CircularBuffer rx_buffer1 = CircularBuffer(20);

CircularBuffer tx_buffer2 = CircularBuffer(20);
CircularBuffer rx_buffer2 = CircularBuffer(20);

CircularBuffer tx_buffer3 = CircularBuffer(20);
CircularBuffer rx_buffer3 = CircularBuffer(20);

CircularBuffer tx_buffer4 = CircularBuffer(20);
CircularBuffer rx_buffer4 = CircularBuffer(20);

CircularBuffer tx_buffer5 = CircularBuffer(20);
CircularBuffer rx_buffer5 = CircularBuffer(20);


SerialPort::SerialPort(UART_MODULE UART)
{
    M_UART = UART;

    UARTConfigure(
       M_UART,
      (UART_CONFIGURATION)(UART_ENABLE_HIGH_SPEED | UART_ENABLE_PINS_TX_RX_ONLY)
    );

    UARTSetFifoMode(
        M_UART,
        (UART_FIFO_MODE)(UART_INTERRUPT_ON_TX_BUFFER_EMPTY | UART_INTERRUPT_ON_RX_3_QUARTER_FULL)
    );
    
    UARTSetLineControl(
        M_UART,
        (UART_LINE_CONTROL_MODE) (UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1)
    );

    UARTSetDataRate(M_UART, SYS_FREQ, 9600);

    UARTEnable(
       M_UART,
        (UART_ENABLE_MODE) UART_ENABLE_FLAGS(
            (UART_ENABLE_MODE) (UART_PERIPHERAL | UART_TX | UART_RX)
       )
    );

   INTEnable(
            (INT_SOURCE) INT_SOURCE_UART_RX(M_UART),
            INT_ENABLED
    );

    INTSetVectorPriority(
        (INT_VECTOR) INT_VECTOR_UART(M_UART),
        INT_PRIORITY_LEVEL_5
    );

    INTSetVectorSubPriority(
            (INT_VECTOR) INT_VECTOR_UART(M_UART),
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
    tx_buffer1.put(data);
   
    if(tx_buffer1.get_number_of_item() != 0 )
    {
        INTEnable(INT_U1TX, INT_ENABLED);
    }
};


char SerialPort::get(void)
{
     return rx_buffer1.get();
}

void SerialPort::read(char buf[], int buf_size)
{

    update();
    int i = 0;
    while( (rx_buffer1.get_free_size() > 0) && (i < (buf_size - 1)) ) // On laisse une place pour \0
    {
        buf[i] = rx_buffer1.get();
        i++;
    }
    buf[i] = '\0';
}

void SerialPort::update(void)
{
    while(UARTReceivedDataIsAvailable(M_UART))
    {
       rx_buffer1.put(UARTGetDataByte(M_UART));
    }
}
SerialPort::~SerialPort()
{
}

bool rx_interrupt_handler(UART_MODULE UART)
{
    bool error = false;
    UART_LINE_STATUS rx_status;

    rx_status = UARTGetLineStatus(UART);

    if ((rx_status & (UART_PARITY_ERROR | UART_FRAMING_ERROR | UART_OVERRUN_ERROR)) == 0) {

        while (UARTReceivedDataIsAvailable(UART)) {
            rx_buffer1.put(UARTGetDataByte(UART));
        }
    }
    else
    {
        error = true;
    }

    return error;

}

bool tx_interrupt_handler(UART_MODULE UART)
{
    bool disable_tx = false;
    bool tx_ready;
    uint8_t tx_size;
    uint8_t tx_data;

    tx_ready = UARTTransmitterIsReady(UART);
    tx_size = tx_buffer1.get_number_of_item();

    if ((tx_size > 0) && tx_ready) {
        do {
            tx_data = tx_buffer1.get();

            UARTSendDataByte(UART, tx_data);

            tx_size = tx_buffer1.get_number_of_item();

            tx_ready = UARTTransmitterIsReady(UART);

        } while ((tx_size > 0) && tx_ready);
    }
    else
    {
        disable_tx = true;
    }

    return disable_tx;
}


extern "C" {

    void __ISR(_UART_1_VECTOR, IPL5SOFT) UART1_isr(void)
    {
        bool rx_have_error;
        bool disable_tx;

        if( INTGetFlag(INT_U1RX) && INTGetEnable(INT_U1RX)) {
            // Gestion de l'interruption de récéption

            rx_have_error = rx_interrupt_handler(UART1);

            if(rx_have_error)
            {
                UART1ClearAllErrors();
            }
            else
            {
                INTClearFlag(INT_U1RX);
            }
        } 

        if(INTGetFlag(INT_U1TX) && INTGetEnable(INT_U1TX))
        {
            // Gestion de l'interruption de transmission
            disable_tx = tx_interrupt_handler(UART1);

            if(disable_tx)
            {
                INTEnable(INT_U1TX, INT_DISABLED);
            }
            else
            {
                INTClearFlag(INT_U1TX);
            } 
        }
    } // UART1_isr

    void __ISR(_UART_2_VECTOR, IPL5SOFT) UART2_isr(void)
    {
        bool rx_have_error;
        bool disable_tx;

        if( INTGetFlag(INT_U2RX) && INTGetEnable(INT_U2RX)) {
            // Gestion de l'interruption de récéption

            rx_have_error = rx_interrupt_handler(UART2);

            if(rx_have_error)
            {
                UART2ClearAllErrors();
            }
            else
            {
                INTClearFlag(INT_U2RX);
            }
        }

        if(INTGetFlag(INT_U2TX) && INTGetEnable(INT_U2TX))
        {
            // Gestion de l'interruption de transmission
            disable_tx = tx_interrupt_handler(UART2);

            if(disable_tx)
            {
                INTEnable(INT_U2TX, INT_DISABLED);
            }
            else
            {
                INTClearFlag(INT_U2TX);
            }
        }
    } // UART2_isr



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
