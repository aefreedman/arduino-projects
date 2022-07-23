int outputPin = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int rawVoltage = analogRead(outputPin);
  float millivolts = (rawVoltage / 1024.0) * 5000;
  float celcius = millivolts / 10;

  Serial.print(celcius);
  Serial.print(" deg C\n");

}
