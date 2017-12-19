#include <ESP8266WiFi.h>

char ssid[] = "test_WiFi"; //SSID  検索した時の名前になります。
char pass[] = "12345678";  //パスワード　必ず８桁以上でないとダメです

void setup() {
  Serial.begin(74880);	
  WiFi.mode(WIFI_AP);              //接続モード設定
  WiFi.softAP(ssid, pass);         //APモードで接続待機　
  Serial.print("IP:");
  Serial.println( WiFi.softAPIP() ); //自分自身のIPアドレスを表示
}

void loop() {
  /* 何もしない*/
}