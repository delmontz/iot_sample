#include <ESP8266WiFi.h>

char ssid[] = "家のSSID";
char pass[] = "家のネットパスワード";

void setup() {
  Serial.begin(74880);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("接続中～");
    delay(1000);
  }
  Serial.println("接続成功!");
}

void loop() {
  /* 何もしない */
}