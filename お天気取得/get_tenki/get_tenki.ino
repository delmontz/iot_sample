#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

char ssid[] = "お家のwifi";
char pass[] = "パスワード";

void setup() {
  Serial.begin(74880);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("connected!");

  HTTPClient http;
  http.begin("http://weather.livedoor.com/forecast/webservice/json/v1?city=400040");
  http.GET();
  String result = http.getString();
  http.end();
  Serial.println(result);
  Serial.println("###########################################################################");

  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(result);
  String telop = root["forecasts"][1]["telop"];
  Serial.println(telop);
  if( telop.indexOf("u96e8") == -1){
    Serial.println("not rain!!");
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
