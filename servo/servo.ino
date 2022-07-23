#include <Arduino.h>
#include <Servo.h>

Servo servoMotor;
int servoPin = 3;

void setup() {
    Serial.begin(9600);
    servoMotor.attach(servoPin);
}

void loop() {
    int analogValue = analogRead(A0);
    Serial.println(analogValue);

    int servoAngle = map(analogValue, 0, 1023, 0, 179);
    servoMotor.write(servoAngle);
}
