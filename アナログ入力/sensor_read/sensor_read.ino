void setup() {
    Serial.begin(74880);
}

void loop() {
    short sensor_data = analogRead(A0);
    Serial.println(sensor_data);
    delay(1000);  
}