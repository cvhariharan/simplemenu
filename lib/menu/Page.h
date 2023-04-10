#include <U8g2lib.h>

#ifndef PAGE_H
#define PAGE_H

class Page {
    public:
        virtual void draw(U8G2 u8g2) = 0;
        virtual Page *update(int event) = 0;

        Page(Page *_prev, Page *_next) {
            prev = _prev;
            next = _next;
        }

        Page *getPrev() {
            return NULL;
        }

        Page *getNext() {
            return NULL;
        }

        void setPrev(Page *p) {
            prev = p;
        }

        void setNext(Page *p) {
            next = p;
        }
    private:
        Page *prev;
        Page *next;
};

#endif