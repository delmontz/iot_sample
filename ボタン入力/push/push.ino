byte ledPin = 14;　//LEDを繋げたIO番号、適時変更してください
byte buttonPin = 16;  //スイッチを繋げたIO番号

void setup() {
  //LED用に出力に設定
  pinMode(ledPin,OUTPUT);
  //ボタン用に入力に設定（プルダウン抵抗を有効）
  pinMode(buttonPin,INPUT_PULLDOWN_16);
}

void loop(){
  byte state;    //読み取った状態を格納する変数を宣言
  state = digitalRead(buttonPin);   //入力ポートを読み取る
  //読み取った状態がHIGHならLEDを光らせる
  if(state == HIGH){
    digitalWrite(ledPin,HIGH);
  }
  //読み取った状態がLOWならLEDを消す
  if(state == LOW){
    digitalWrite(ledPin,LOW);
  }
}