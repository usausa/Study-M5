#include <M5StickC.h>
#include <Adafruit_NeoPixel.h>

#define PIN        32
#define NUMPIXELS  3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int i = 0, j = 1, k = 2;

void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);
    
    pixels.begin();
}

void loop() {
    pixels.setPixelColor(i++, pixels.Color(255, 0, 0));
    pixels.setPixelColor(j++, pixels.Color(0, 255, 0));
    pixels.setPixelColor(k++, pixels.Color(0, 0, 255));
    pixels.show();

    if (i == 3) i = 0;
    else if (j == 3) j = 0;
    else if (k == 3) k = 0;

    delay(500);
}
