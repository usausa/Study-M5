#include <M5StickC.h>
#include "Adafruit_SGP30.h"

Adafruit_SGP30 sgp;

void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.setTextSize(2);

    sgp.begin();
}

void loop() {
    M5.Lcd.fillRect(0, 0, 160, 80, BLACK);
    M5.Lcd.setCursor(0, 0);
    if (sgp.IAQmeasure()) {
        M5.Lcd.printf("TVOC:%4d ppb\n", sgp.TVOC);
        M5.Lcd.printf("eCO2:%4d ppm\n", sgp.eCO2);
    } else {
        M5.Lcd.print("Failed");
    }

    delay(500);
}
