#include <M5StickC.h>

int lastValue1 = 0, lastValue2 = 0;

void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);

    pinMode(33, INPUT);
    pinMode(32, INPUT);
}

void loop() {
    int value1 = digitalRead(33);
    int value2 = digitalRead(32);
  
    if (value1 != lastValue1) {
        M5.Lcd.fillRect(0, 0, 80, 80, value1 == 0 ? BLUE : BLACK);
        lastValue1 = value1;
    }

    if (value2 != lastValue2) {
        M5.Lcd.fillRect(80, 0, 80, 80, value2 == 0 ? RED : BLACK);
        lastValue2 = value2;
    }

    delay(10);
}
