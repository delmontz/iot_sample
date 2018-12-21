#include "Seeed_BMP280.h"
#include <Wire.h>

/* ���C�u�����錾 */
BMP280 bmp280;

void setup()
{
  Serial.begin(74880);
  if(!bmp280.init()){
    Serial.println("�f�o�C�X�G���[!?");
  }
}

void loop()
{
  /* �C���\�� */
  Serial.print("�C��: ");
  Serial.print(bmp280.getTemperature());
  Serial.println("��");
  
  /* �C���\�� */
  float pressure;
  Serial.print("�C��: ");
  Serial.print(pressure = bmp280.getPressure());
  Serial.println("Pa");
  
 /* ���x�\�� */
  Serial.print("���x: ");
  Serial.print(bmp280.calcAltitude(pressure));
  Serial.println("m");

  Serial.println("================================");

  delay(1000);
}