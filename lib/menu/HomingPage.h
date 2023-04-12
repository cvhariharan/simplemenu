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
                    return this;
            }
            return this;
        }

    private:
        const char *text = "Homing";
};