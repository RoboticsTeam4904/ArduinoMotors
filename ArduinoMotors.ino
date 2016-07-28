#include <Servo.h>

Servo victors;


void setup()
{
  Serial.begin(9600);
  victors.attach(9);  // attaches the servo object to the Victor on pin 9 to the servo object (also controls Victor on pin 10)
  victors.write(91);
}

void loop()
{
  if (Serial.available() > 0) {
    int motorSpeed = Serial.parseInt();
    motorSpeed = map(motorSpeed, -100, 100, -40, 40);
    motorSpeed = motorSpeed + 90;
    if(motorSpeed < 95 && motorSpeed > 85) motorSpeed = 91;
    victors.write(motorSpeed);
    Serial.println(motorSpeed - 90);
  }
  delay(15);
}

