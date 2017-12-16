byte ledPin = 14;//適時変更

void setup() {
    /*何もしない*/
}

void loop() {
  analogWrite(ledPin,1023); //最大値
  delay(1000);
  analogWrite(ledPin,511);  //輝度1/2
  delay(1000);
  analogWrite(ledPin,255);  //輝度1/4
  delay(1000);
  analogWrite(ledPin,0);    //最小値
  delay(1000);
}