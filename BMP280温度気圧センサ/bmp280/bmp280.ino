#include "Seeed_BMP280.h"
#include <Wire.h>

/* ライブラリ宣言 */
BMP280 bmp280;

void setup()
{
  Serial.begin(74880);
  if(!bmp280.init()){
    Serial.println("デバイスエラー!?");
  }
}

void loop()
{
  /* 気温表示 */
  Serial.print("気温: ");
  Serial.print(bmp280.getTemperature());
  Serial.println("℃");
  
  /* 気圧表示 */
  float pressure;
  Serial.print("気圧: ");
  Serial.print(pressure = bmp280.getPressure());
  Serial.println("Pa");
  
 /* 高度表示 */
  Serial.print("高度: ");
  Serial.print(bmp280.calcAltitude(pressure));
  Serial.println("m");

  Serial.println("================================");

  delay(1000);
}