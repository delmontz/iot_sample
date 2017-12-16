short beat = 300; // 音の長さを指定
byte spkPin = 14;  // 圧電スピーカを接続したピン番号

void setup() {
 /* 何もしない */
}
void loop() {
  tone(spkPin,740,beat) ; // ファ#
  delay(beat) ;
  tone(spkPin,587,beat) ; // レ
  delay(beat) ;
  tone(spkPin,440,beat) ; // ラ
  delay(beat) ;
  tone(spkPin,587,beat) ; // レ
  delay(beat) ;
  tone(spkPin,659,beat) ; // ミ
  delay(beat) ;
  tone(spkPin,880,beat) ; // ラ
  delay(600) ;
  tone(spkPin,880,beat) ; // ラ
  delay(beat) ;
  tone(spkPin,659,beat) ; // ミ
  delay(beat) ;
  tone(spkPin,740,beat) ; // ファ#
  delay(beat) ;
  tone(spkPin,659,beat) ; // ミ
  delay(beat) ;
  tone(spkPin,440,beat) ; // ラ
  delay(beat) ;
  tone(spkPin,587,beat) ; // レ
  delay(2000);
}