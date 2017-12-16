#include <Adafruit_NeoPixel.h>

byte ledPin = 14; //繋いでいるピン
byte ledNum = 1;  //LEDの数
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(ledNum, ledPin, NEO_RGB + NEO_KHZ800);

void setup() {
  pixels.begin();
  delay(1); //beginの後は少し待たないとうまく動かないらしい?
}

void loop() {
  pixels.setPixelColor(0, pixels.Color(255,0,0));  //赤
  pixels.show();
  delay(1000);
  pixels.setPixelColor(0, pixels.Color(0,255,0)); //緑
  pixels.show();
  delay(1000);
  pixels.setPixelColor(0, pixels.Color(0,0,255)); //青
  pixels.show();
  delay(1000);
}