#include <ESP8266WiFi.h>

WiFiClientSecure clientSecure;

char ssid[] = "家のSSID";               //適時変更
char pass[] = "ネットのパスワード";      //適時変更
String mes = "LINEへの通知メッセージ";   //LINEへ通知したい内容
String token = "アクセストークン";       //LINE notifyで取得したアクセストークン

void setup() {
  Serial.begin(74880);
  //ネットへ接続
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("connected!");
  
  //ここからLINEへの送信メッセージ作成
  clientSecure.connect("notify-api.line.me", 443);
  String body = "message=" + mes;
  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + token + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: ESP8266\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(body.length()) + "\r\n";
  req += "\r\n";
  req += body;
  //ここまで
  clientSecure.print(req);  //送信実行
  Serial.println("送信しました！");
}

void loop() {
  /* 何もしない */
}
