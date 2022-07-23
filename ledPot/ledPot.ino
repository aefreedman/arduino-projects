const int ledPin = 9;
int analogValue = 0;
int brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  analogValue = analogRead(A0);
  brightness = analogValue / 4;
  analogWrite(ledPin, brightness);
  Serial.println(brightness);
}
