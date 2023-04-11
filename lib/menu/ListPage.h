#include "Arduino.h"
#include "Page.h"

#define TOTAL_ITEMS sizeof(items) / sizeof(char *)

class ListPage : public Page {
    public:
        static const char *items[];

        ListPage(Page *_prev, Page *_next, const char *title): Page(_prev, _next, title) {}

        void draw(U8G2 u8g2) {
            u8g2.setFont(u8g_font_profont15);
            int length = 8;
            for(int i = starting; i < starting + maxLength && i < length; i++) {
                u8g2.drawStr(0, 10*(i-starting+1), items[i]);
            }

        }

        Page *update(int event) {
            starting = (starting > 7) ? 0 : (starting + 1);
            return this;
        }

    private:
        int starting = 0;
        int maxLength = 4;
};

const char *ListPage::items[] = {"Home", "Preheat", "Level", "Slot1", "Slot2", "Slot3", "Slot4", "Slot5"};