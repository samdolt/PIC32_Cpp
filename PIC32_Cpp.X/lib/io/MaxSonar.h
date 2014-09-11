/* 
 * File:   MaxSonar.h
 * Author: doltsa
 *
 * Created on 10. septembre 2014, 09:21
 */

#ifndef MAXSONAR_H
#define	MAXSONAR_H

#include <plib.h>

class MaxSonar {
public:
    MaxSonar();
    void update(void);
    int get_value(void);
    bool has_new_value(void);
private:
    UART_MODULE M_UART;
    int m_value;
    bool m_new_value;
};

#endif	/* MAXSONAR_H */

