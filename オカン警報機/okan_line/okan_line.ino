#include <ESP8266WiFi.h>

char ssid[]     = "家のSSID";              //適時変更
char pass[]     = "ネットのパスワード";     //適時変更
String mes      = "LINEへの通知メッセージ"; //LINEへ通知したい内容
String token    = "アクセストークン";       //LINE notifyで取得したアクセストークン
byte sensor_pin = 13;                      //人感センサー接続ピン 適時変更

void setup() {
  Serial.begin(74880);
  //人感センサー準備
  pinMode(sensor_pin,INPUT);
  //ネットへ接続
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("connected!");
}

void loop() {
  //人感センサー監視
  if(digitalRead(sensor_pin) == HIGH){
      send_line("オカン接近中　第一次戦闘配置!!",token);
      delay(30000); //連続送信防止　30秒空ける
  }
}

/********************************************************************
 * LINE通知関数
 * 引数: String mes (通知内容)
 *       String token (LINE notifyのアクセストークン)
 * 戻り値:なし
 * *****************************************************************/
void send_line(String message,String token){
  WiFiClientSecure clientSecure;
   //ここからLINEへの送信メッセージ作成
  clientSecure.connect("notify-api.line.me", 443);
  String body = "message=" + message;
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
}

