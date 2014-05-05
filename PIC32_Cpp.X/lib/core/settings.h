/* 
 * File:   settings.h
 * Author: doltsa
 *
 * Created on 30. avril 2014, 14:25
 */

#ifndef SETTINGS_H
#define	SETTINGS_H

#include <cstdint>

#include <p32xxxx.h>
#include <plib.h>


void clock_init(uint32_t SYS_FREQ);
uint32_t get_peripheral_clock(void);
uint32_t get_system_clock(void);



#endif	/* SETTINGS_H */

