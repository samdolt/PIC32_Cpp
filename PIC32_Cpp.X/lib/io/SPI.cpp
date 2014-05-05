/* 
 * File:   SPI.cpp
 * Author: doltsa
 * 
 * Created on 5. mai 2014, 08:30
 */

#include "SPI.h"

#include "settings.h"

SPI::SPI(SpiChannel channel, const char CS[]) {

    M_CHANNEL = channel;
    M_CS = new DigitalPin(CS);
    disable();
    M_CS->set_output();

    configure();
}

void SPI::configure(void)
{
    uint32_t frequency = get_peripheral_clock() / 20000000; // 20MHz
    SpiOpenFlags config = (SpiOpenFlags) (SPI_OPEN_MODE8 | SPI_OPEN_ON | SPI_OPEN_CKP_HIGH |
                    SPI_OPEN_MSTEN) ;

    SpiChnOpen(M_CHANNEL, config, frequency); // 20MHz
}

void SPI::write(uint8_t data)
{

    SpiChnPutC(M_CHANNEL, data);
    bool SpiBusy;
    do {
     SpiBusy =  SpiChnIsBusy(M_CHANNEL) ;
   } while (SpiBusy == 1);
   // while(SpiChnIsBusy(M_CHANNEL))
   // {
   //     // Attente
   // }
}

void SPI::enable(void)
{
    M_CS->set_low();
}

void SPI::disable(void)
{
    M_CS->set_high();
}

void SPI::write(uint16_t data)
{
    uint8_t MSB;
    uint8_t LSB;

    MSB = (data & 0xFF00) >> 8;
    LSB = data & 0x00FF;

    write(MSB);
    write(LSB);
}

SPI::~SPI() {
    delete M_CS;
}