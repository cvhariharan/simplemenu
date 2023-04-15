#ifndef HOMINGPAGE_H
#define HOMINGPAGE_H

#include "Arduino.h"
#include "Page.h"

class HomingPage : public Page {
    public:
        HomingPage(Page *_prev, Page **_next, int size, const char *title): Page(_prev, _next, size, title) {}

        void draw(U8G2 u8g2) {
            u8g2.setFont(u8g_font_profont15);
            u8g2.drawStr(0, 10, text);
        }

        Page *update(int event) {
            switch(event) {
                case 1:
                    text = "Homed all axes";
                    break;
                case 2:
                    Page *prev = getPrev();
                    if(prev != NULL) {
                        return prev;
                    }
            }
            return this;
        }

    private:
        const char *text = "Homing";
};

#endif