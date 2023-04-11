#include <U8g2lib.h>

#ifndef PAGE_H
#define PAGE_H

class Page {
    public:
        virtual void draw(U8G2 u8g2) = 0;
        virtual Page *update(int event) = 0;

        Page(Page *_prev, Page *_next, const char *_title) {
            prev = _prev;
            next = _next;
            title = _title;
        }

        const char* getTitle() {
            return title;
        }

        Page *getPrev() {
            return prev;
        }

        Page *getNext() {
            return next;
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
        const char* title;
};

#endif