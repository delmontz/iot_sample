void setup() {
    //IO14ピンを出力に設定する
    pinMode(14,OUTPUT);
}
    
void loop() {
    //LEDを光らせる
    digitalWrite(14,HIGH);
    //一秒待つ（1000ミリ秒）
    delay(1000);
    //LEDを消す
    digitalWrite(14,LOW);
    //一秒待つ
    delay(1000);
}
