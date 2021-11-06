#include <M5StickC.h>

#define JOY_ADDR 0x52 // Joystick I2C address

char data[100];

void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);
    Wire.begin(32, 33);
}

void loop() {
    Wire.requestFrom(JOY_ADDR, 3);
    if (Wire.available()) {
        static uint8_t x, y, button;
        x = Wire.read();
        y = Wire.read();
        button = Wire.read();
        
        M5.Lcd.setCursor(1, 30, 2);
        M5.Lcd.printf("x %03d, y %03d, button %d", x, y, button);
    }
    
    delay(200);
}
