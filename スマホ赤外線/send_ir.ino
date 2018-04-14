#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

byte led_pin = 14; //LEDのピン番号 適時変更!

#define IR_LED 4  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
char ssid[] = "test_led";
char pass[] = "12345678";

ESP8266WebServer server(80); //WEBサーバライブラリ宣言
IRsend irsend(IR_LED);  // Set the GPIO to be used to sending the message.

uint16_t onData[71] = {9002, 4510, 558, 600, 554, 600, 554, 598, 556, 600, 554, 602, 554, 600, 556, 600, 554, 1676, 558, 1674, 556, 1674, 558, 1674, 556, 1676, 556, 1674, 556, 1674, 556, 1676, 554, 600, 554, 602, 552, 1676, 554, 604, 552, 602, 552, 1678, 554, 604, 552, 602, 554, 600, 554, 1678, 552, 604, 656, 1574, 554, 1678, 554, 626, 524, 1678, 556, 1676, 556, 1674, 554, 39390, 9000, 2252, 554}; // NEC 1FE48B7
                        
uint16_t offData[71] = {8994, 4496, 562, 592, 562, 592, 564, 590, 562, 592, 564, 590, 562, 590, 564, 590, 562, 1666, 562, 1666, 564, 1666, 562, 1664, 564, 1664, 566, 1662, 564, 1664, 562, 1666, 564, 590, 562, 590, 566, 1638, 562, 618, 562, 1666, 564, 1664, 562, 592, 564, 590, 562, 592, 562, 1666, 562, 590, 562, 1670, 560, 592, 562, 590, 564, 1666, 564, 1666, 562, 1666, 562, 39334, 8996, 2216, 560};

void led_on(){
  irsend.sendRaw(onData, 71, 38);  // Send a raw data capture at 38kHz.
  server.send(200, "text/plain", "LED ON!!"); //ブラウザに文字表示
  Serial.println("LED ON!!");
}

void led_off(){
  irsend.sendRaw(offData, 71, 38);  // Send a raw data capture at 38kHz.
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
  irsend.begin();
}

void loop() {
  server.handleClient();             //WEBサーバ処理
}
