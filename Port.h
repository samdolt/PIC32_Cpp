/* 
 * File:   Port.h
 * Author: doltsa
 *
 * Created on 7. mars 2014, 16:44
 */

#ifndef PORT_H
#define	PORT_H

static inline uint32_t read_port(const char PORT, const uint32_t MASK)
{
    switch(PORT) {
        case 'A':
            return PORTA & MASK;
        default:
            return 0;
    }
    return 0;
}

static inline uint32_t read_pin(const char PORT, const uint8_t PIN)
{
    switch(PORT) {
        case 'A':
            return PORTA & (1<<PIN);
        default:
            return 0;
    }
    return 0;
}

namespace pin {

    static inline void set(const char PORT, const uint8_t PIN)
    {
        switch(PORT) {
            case 'A':
                LATA |= (1<<PIN);
                break;
            default:
                break;
        }
    }

    static inline void clear(char PORT, const uint8_t PIN)
    {
        switch(PORT) {
            case 'A':
                LATA &= ~(1<<PIN);
                break;
            default:
                break;
        }
    }

    static inline uint32_t read_pin(const char PORT, const uint8_t PIN)
    {
        switch(PORT) {
            case 'A':
                return (PORTA & (1<<PIN)) >> PIN;
        default:
            return 0;
        }
        return 0;
    }
}

#endif	/* PORT_H */

