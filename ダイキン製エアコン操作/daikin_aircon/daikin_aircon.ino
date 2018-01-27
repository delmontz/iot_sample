#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Daikin.h>

IRDaikinESP dakinir(5);  // An IR LED is controlled by GPIO pin 4 (D2)

void setup() {
  dakinir.begin();
  Serial.begin(115200);
  Serial.println("Sending...");

  // Set up what we want to send. See ir_Daikin.cpp for all the options.
  //dakinir.on();
  //dakinir.setFan(DAIKIN_FAN_AUTO);
  //dakinir.setMode(DAIKIN_HEAT);
  //dakinir.setTemp(25);
  //dakinir.setSwingVertical(0);
  // Now send the IR signal.
  //dakinir.send();
  dakinir.off();
  dakinir.send();
}


void loop() {
}
