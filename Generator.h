/* 
 * File:   Generator.h
 * Author: doltsa
 *
 * Created on 15. mai 2014, 15:21
 */

#ifndef GENERATOR_H
#define	GENERATOR_H

#include "Menu.h"

extern int32_t m_data[48];

class Generator {
public:
    Generator();
    void sinus_init(S_ParamGen * data);
    void carre_init(S_ParamGen * data);
    void dds_init(S_ParamGen * data);
    void trian_init(S_ParamGen * data);
    void update(S_ParamGen * data);
    uint16_t get_sample(uint8_t number);
    uint16_t get_timer_reload_value(void);
    virtual ~Generator();
private:
    //int32_t m_data[48];
    S_ParamGen m_current;
    int16_t m_reload;

};

#endif	/* GENERATOR_H */

