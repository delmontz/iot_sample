#include <Ambient.h>
#include <ESP8266WiFi.h>
#include <Seeed_BMP280.h>
#include <Wire.h>

/* 設定値 (適時変更してください!!) */
char ssid[] = "家のSSID";
char pass[] = "家のネットパスワード";
char writeKey[] = "ライトキー";
unsigned int channelId = 1234; /* チャンネルID */

/* 各種ライブラリ */
BMP280 bmp280;
Ambient ambient;
WiFiClient client;

/* 変数宣言 */
float temp;

void setup() {
  /* シリアルモニタの初期化 */
  Serial.begin(74880);
  
  /* インターネットへの接続 */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("接続中～");
    delay(1000);
  }
  Serial.println("接続成功!");

  /* 温度センサーの初期化 */
  if(!bmp280.init()){
    Serial.println("Device error!");
  }

  /* Ambientの初期化 */
  ambient.begin(channelId, writeKey, &client);
}

void loop() {
  /* 気温計測 */
  temp = bmp280.getTemperature();

  /* ambientへデータ送信 */
  ambient.set(1, temp);
  ambient.send();
  
  /* シリアルモニタに気温表示 */
  Serial.println(temp);
  delay(1000);
}
