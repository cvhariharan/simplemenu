#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>
#include <WelcomePage.h>
#include <ListPage.h>
#include <HomingPage.h>
#include <Button.h>
#include <Encoder.h>

ListPage listPage(NULL, NULL, 0, "listpage");
WelcomePage welcome(NULL, (Page *[]){&listPage}, 1, "welcomepage");
HomingPage homingPage(NULL, NULL, 0, "homingPage");
Page *currentPage;

// U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 14, /* data=*/ 13, /* CS=*/ 2, /* reset=*/ U8X8_PIN_NONE);
U8G2_ST7920_128X64_F_HW_SPI u8g2(U8G2_R0, 2);
Button button(4);
Encoder encoder(14,12);

void setup() {
    u8g2.begin();
    u8g2.setBusClock(950000);
    static Page *listNextItems[] = {&homingPage};
    listPage.setNext(listNextItems);
    currentPage = &welcome;
    Serial.begin(9600);
}

void loop() {
    int clicks = button.update();
    Serial.println(clicks);

    u8g2.firstPage();
    do {
        currentPage->draw(u8g2);
    } while(u8g2.nextPage());
    

    if(clicks > 0) {
        currentPage = currentPage->update(clicks);
    }
}