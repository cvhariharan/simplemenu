#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>
#include <ListPage.h>

// WelcomePage welcome;
ListPage listPage(NULL, NULL);
Page *currentPage;

U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 14, /* data=*/ 13, /* CS=*/ 2, /* reset=*/ U8X8_PIN_NONE);

long prevTime = 0;

void setup() {
    u8g2.begin();
    prevTime = millis();
    currentPage = &listPage;
}

void loop() {
    u8g2.firstPage();  
    do {
        currentPage->draw(u8g2);
    } while( u8g2.nextPage() );
    delay(100);

    if((millis() - prevTime) > 5000 ) {
        prevTime = millis();
        currentPage = currentPage->update(0);
    }
}