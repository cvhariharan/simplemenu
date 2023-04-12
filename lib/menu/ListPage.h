#include "Arduino.h"
#include "Page.h"

#define TOTAL_ITEMS sizeof(items) / sizeof(char *)

class ListPage : public Page {
    public:
        static const char *items[];

        ListPage(Page *_prev, Page **_next, int size, const char *title): Page(_prev, _next, size, title) {}

        void draw(U8G2 u8g2) {
            u8g2.setFont(u8g_font_profont15);
            int length = 8;
            for(int i = starting; i < starting + maxLength && i < length; i++) {
                u8g2.drawStr(10, 10*(i-starting+1), items[i]);
            }
            u8g2.drawRFrame(0, 0, 128, 10, 5);
        }

        Page *update(int event) {
            switch(event) {
                case 1:
                    // Scroll
                    starting = (starting > 7) ? 0 : (starting + 1);
                    break;
                case 2:
                    if(starting == 0) {
                        // Homing Page
                        return getNext(0);
                    }
                    return getPrev();
                    break;
            }
            
            return this;
        }

    private:
        int starting = 0;
        int maxLength = 4;
};

const char *ListPage::items[] = {"Home", "Preheat", "Level", "Slot1", "Slot2", "Slot3", "Slot4", "Slot5"};