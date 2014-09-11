/**
 * Fichier : SerialPort.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Fonction d'abstraction pour la gestion du port série
 */

#include "MaxSonar.h"
#include "CircularBuffer.h"

#ifndef SYS_FREQ
    #define SYS_FREQ (80000000L)
#endif

CircularBuffer rx_buffer = CircularBuffer(20);

bool MaxSonar_interrupt_handler(UART_MODULE UART);

MaxSonar::MaxSonar() {
    M_UART = UART2;

    UARTConfigure(
       M_UART,
      (UART_CONFIGURATION)(UART_ENABLE_HIGH_SPEED | UART_ENABLE_PINS_TX_RX_ONLY)
    );

    UARTSetFifoMode(
        M_UART,
        (UART_FIFO_MODE)(UART_INTERRUPT_ON_RX_3_QUARTER_FULL)
    );

    UARTSetLineControl(
        M_UART,
        (UART_LINE_CONTROL_MODE) (UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1)
    );

    UARTSetDataRate(M_UART, SYS_FREQ, 9600);

    UARTEnable(
       M_UART,
        (UART_ENABLE_MODE) UART_ENABLE_FLAGS(
            (UART_ENABLE_MODE) (UART_PERIPHERAL | UART_RX)
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

void MaxSonar::update(void)
{
    while(UARTReceivedDataIsAvailable(M_UART))
    {
       rx_buffer.put(UARTGetDataByte(M_UART));
    }

    char data[6];
    bool found = false;

    while(rx_buffer.get_number_of_item() > 5) {
        if(rx_buffer.get_number_of_item() > 5) {
            data[0] = rx_buffer.get();

            if(data[0] == 'R') {
                data[1] = rx_buffer.get();
                data[2] = rx_buffer.get();
                data[3] = rx_buffer.get();
                data[4] = rx_buffer.get();
                data[5] = rx_buffer.get();

                found = true;
            }
        }
    }

    if(found) {

        // Contrôle des valeurs
        if(data[0] != 'R') {
            return;
        }

        for(int i = 1; i < 4 ; i++) {
            if(data[i] < '0' || data[i] > '9') {
                return;
            }
        }

        if(data[5] != '\r') {
            return;
        }

        // Mise à jour de la valeur

        m_value =  (data[1] - '0') * 1000;
        m_value += (data[2] - '0') *  100;
        m_value += (data[3] - '0') *   10;
        m_value += (data[4] - '0') *    1;

        m_new_value = true;
    }


}

int MaxSonar::get_value(void) {
    m_new_value = false;
    return m_value;
}

bool MaxSonar::has_new_value() {
    return m_new_value;
}
bool MaxSonar_interrupt_handler(UART_MODULE UART)
{
    bool error = false;
    UART_LINE_STATUS rx_status;

    rx_status = UARTGetLineStatus(UART);

    if ((rx_status & (UART_PARITY_ERROR | UART_FRAMING_ERROR | UART_OVERRUN_ERROR)) == 0) {

        while (UARTReceivedDataIsAvailable(UART)) {
            rx_buffer.put(UARTGetDataByte(UART));
        }
    }
    else
    {
        error = true;
    }

    return error;

}

extern "C" {

    void __ISR(_UART_2_VECTOR, IPL5SOFT) UART2_isr(void)
    {
        bool rx_have_error;
        bool disable_tx;

        if( INTGetFlag(INT_U2RX) && INTGetEnable(INT_U2RX)) {
            // Gestion de l'interruption de récéption

            rx_have_error = MaxSonar_interrupt_handler(UART2);

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
            // L'interruption Tx ne doit pas être enclenchée
            INTEnable(INT_U2TX, INT_DISABLED);
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
