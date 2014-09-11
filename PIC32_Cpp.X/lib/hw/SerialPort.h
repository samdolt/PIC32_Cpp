/**
 * Fichier : SerialPort.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Fonction d'abstraction pour la gestion du port série
 */
#ifndef SERIALPORT_H
#define	SERIALPORT_H

#include <stdint.h>
#include <CircularBuffer.h>
#include <string>
#include <stdarg.h>

#include <plib.h>

enum handshaking {
    SOFTWARE,
    HARDWARE,
    DISABLED
};

class SerialPort {
public:
    SerialPort(UART_MODULE UART);
//    config(uint32_t speed, const char * CONFIG=NULL  );

    void write(char data);
    void print(const char data[]);
    char get(void);
    void update(void);
    void read(char buf[], int buf_size);
    void printf(const char * format, ...);
    virtual ~SerialPort();
private:
    uint32_t M_SPEED;
    bool M_9_BITS_SERIAL;
    char M_PARITY_TYPE;
    uint8_t M_STOP_BITS;
    UART_MODULE M_UART;
    CircularBuffer * M_TX_BUFFER;
    CircularBuffer * M_RX_BUFFER;
};

/******************************************************************************
 * STREAM SUPPORT
 ******************************************************************************/

/* Template générique, redirige l'opérateur serial << vers serial.print pour
 * tous les type
 */
template<class T>
inline SerialPort &operator <<(SerialPort &stream, const T data)
{ stream.print(data); return stream; }


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

#endif	/* SERIALPORT_H */

