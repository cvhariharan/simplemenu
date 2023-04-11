#ifndef BUTTON_H
#define BUTTON_H

#define DEBOUNCE_DELAY 50
#define CLICK_INTERVAL 150

class Button {
    public:
        Button(int pin);
        int update();
    private:
        int _pin;
        unsigned long _lastUpdate;
        int _numClicks;
        int _lastState;
};

#endif