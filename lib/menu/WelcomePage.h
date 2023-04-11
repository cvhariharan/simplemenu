#include "Arduino.h"
#include "Page.h"

class WelcomePage : public Page {
    public:
        WelcomePage(Page *_prev, Page *_next, const char *title): Page(_prev, _next, title) {}

        void draw(U8G2 u8g2) {
            u8g2.setFont(u8g_font_profont15);
            u8g2.drawStr(0, 10, text);
        }

        Page *update(int event) {
            switch(event) {
                case 1:
                    return getNext();
            }
            return this;
        }

    private:
        const char *text = "Welcome";
};