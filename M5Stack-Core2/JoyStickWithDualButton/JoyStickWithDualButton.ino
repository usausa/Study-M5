#include <M5Core2.h>

#define JOY_ADDR 0x52

int lastValue1;
int lastValue2;

void setup() {
    M5.begin();

    Wire.begin(32, 33, 400000); // Port.A
    pinMode(36, INPUT); // Port.B
    pinMode(26, INPUT);

    dacWrite(25, 0);

    M5.Lcd.setCursor(0, 0, 4);
    M5.Lcd.println("Joystick & Dual Button");
}

void loop() {
    Wire.requestFrom(JOY_ADDR, 3);
    if (Wire.available()) {
        // TODO 補正
        int x = Wire.read();
        int y = Wire.read();
        byte button = Wire.read();
        
        M5.Lcd.setCursor(0, 40, 4);
        M5.Lcd.printf("x %03d, y %03d, button %d", x, y, button);
    }

    int value1 = digitalRead(36);
    int value2 = digitalRead(26);
    if (value1 != lastValue1) {
        M5.Lcd.fillRect(0, 80, 80, 80, value1 == 0 ? BLUE : BLACK);
        lastValue1 = value1;
    }

    if (value2 != lastValue2) {
        M5.Lcd.fillRect(80, 80, 80, 80, value2 == 0 ? RED : BLACK);
        lastValue2 = value2;
    }

    delay(20);
}
