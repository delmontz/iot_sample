byte spkPin = 14;//適時修正してください
short Do = 523;
short Re = 587;
short Mi = 659;
short Fa = 698;

void setup() {
    /*何もしない*/
}

void loop() {
  tone(spkPin,Do,1000);//ド
  delay(1000);
  tone(spkPin,Re,1000);//レ
  delay(1000);
  tone(spkPin,Mi,1000);//ミ
  delay(1000);
  tone(spkPin,Fa,1000);//ファ
  delay(1000);
}