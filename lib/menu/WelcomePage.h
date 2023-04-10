#include "Arduino.h"
#include "Page.h"

class WelcomePage : public Page {
    public:
        WelcomePage() {
            text = "Welcome";
        }

        WelcomePage(Page *_prev, Page *_next): Page(_prev, _next) {
            prev = _prev;
            next = _next;
        }

        void draw(U8G2 u8g2) {
            u8g2.setFont(u8g_font_profont15);
            u8g2.drawStr(0, 10, text);
        }

        Page *update(int event) {
            text = "Welcome Back";
            return this;
        }

    private:
        char *text;
};