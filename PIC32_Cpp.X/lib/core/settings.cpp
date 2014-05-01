/* 
 * File:   settings.cpp
 * Author: doltsa
 * 
 * Created on 30. avril 2014, 14:25
 */

#include "settings.h"

uint32_t SYS_CLOCK;
uint32_t PB_CLOCK;

void clock_configure(uint32_t SYS_FREQ)
{
    SYS_CLOCK = SYS_FREQ;
    //PB_CLOCK = SYSTEMConfigPerformance(SYS_FREQ); // Cette fonction retourne PB_CLK = 80MHz
}

uint32_t get_system_clock(void)
{
    return SYS_CLOCK;
}

uint32_t get_peripheral_clock(void)
{
    return PB_CLOCK;
}