/* 
 * File:   Menu.h
 * Author: doltsa
 *
 * Created on 15. mai 2014, 13:21
 */

#ifndef MENU_H
#define	MENU_H

#include <cstdint>

typedef enum  { SignalCarre = 0 , SignalTriangle = 1, SignalSinus = 2 , SignalDentDeScie =3 } E_FormesSignal;

enum menu_line {FORME = 0, FREQ = 1, AMPL = 2, OFFSET = 3};
enum menu_mark {LOCK = '*', UNLOCK = '>'};

typedef struct {
      E_FormesSignal Forme;
      int16_t Frequence;
      int16_t Amplitude;
      int16_t Offset;
      uint32_t Magic;
} S_ParamGen;


class Menu {
public:
    Menu();
    bool is_locked(void);
    void init(S_ParamGen * data);
    void init_value(S_ParamGen * data);
    void init_info_char(char line1, char line2, char line3, char line4 );
    void add_to_active(int incr);
    void update_mark(void);
    char get_mark(void);
    void set_mark(menu_mark mark);
    enum menu_line get_active(void);
    void go_to(int8_t x);
    void update_value(int8_t incr, S_ParamGen * data );
    void set_lock(S_ParamGen * data, bool clearPressed = false);
    void unset_lock(S_ParamGen * data);
    virtual ~Menu();
private:
    enum menu_line m_active;
    bool m_lock;
    char m_mark;
    uint16_t m_old;

};

#endif	/* MENU_H */

