#ifndef PAGE_H
#define PAGE_H

#include <U8g2lib.h>

class Page {
    public:
        virtual void draw(U8G2 u8g2) = 0;
        virtual Page *update(int event) = 0;

        Page(Page *_prev, Page **_next, int _size, const char *_title) {
            prev = _prev;
            next = _next;
            nextSize = _size;
            title = _title;
        }

        const char* getTitle() {
            return title;
        }

        Page *getPrev() {
            return prev;
        }

        Page *getNext(int i) {
            if(i > nextSize) {
                return NULL;
            }
            return *(next + i);
        }

        void setPrev(Page *p) {
            prev = p;
        }

        void setNext(Page **p) {
            next = p;
        }
    private:
        Page *prev;
        Page **next;
        int nextSize;
        const char* title;
};

#endif