#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

byte led_pin = 14; //LEDのピン番号 適時変更!

char ssid[] = "test_led";
char pass[] = "12345678";

ESP8266WebServer server(80); //WEBサーバライブラリ宣言

void led_on(){
  digitalWrite(led_pin,HIGH);                 //LED点灯
  server.send(200, "text/plain", "LED ON!!"); //ブラウザに文字表示
  Serial.println("LED ON!!");
}

void led_off(){
  digitalWrite(led_pin,LOW);                   //LED消灯
  server.send(200, "text/plain", "LED OFF!!"); //ブラウザに文字表示
  Serial.println("LED OFF!!");
}


void setup() {
  Serial.begin(74880);
  pinMode(led_pin,OUTPUT);           //Lチカ準備	
  WiFi.mode(WIFI_AP);                //接続モード設定
  WiFi.softAP(ssid, pass);           //APモードで接続待機
  Serial.print("IP Address:");
  Serial.println( WiFi.softAPIP() ); //自分自身のIPアドレスを表示
  server.on("/LED_ON",led_on);       //LED点灯用URL作成
  server.on("/LED_OFF",led_off);     //LED消灯用URL作成
  server.begin();                    //WEBサーバ起動
}

void loop() {
  server.handleClient();             //WEBサーバ処理
}
