#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>
#include <WelcomePage.h>
#include <ListPage.h>
#include <Button.h>

ListPage listPage(NULL, NULL, "listpage");
WelcomePage welcome(NULL, &listPage, "welcomepage");
Page *currentPage;

U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 14, /* data=*/ 13, /* CS=*/ 2, /* reset=*/ U8X8_PIN_NONE);

long prevTime = 0;
Button button(4);

void setup() {
    u8g2.begin();
    prevTime = millis();
    currentPage = &welcome;
    Serial.begin(9600);
}

void loop() {
    int clicks = button.update();
    Serial.println(clicks);
    Serial.println(currentPage->getTitle());
    u8g2.firstPage();      do {
        currentPage->draw(u8g2);
    } while( u8g2.nextPage() );

    if(clicks > 0) {
        currentPage = currentPage->update(clicks);
    }
}