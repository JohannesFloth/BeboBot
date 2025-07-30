/*
 * Pinout
 * NodeMCU GPIO |  Arduino IDE  |   Usage
 *      1             5 or D1         Geschwindigkeit Motor B
 *      2             4 or D2         Geschwindigkeit Motor A    
 *      3             0 or D3         Drehrichtung Motor A
 *      4             2 or D4         Drehrichtung Motor B
*/

//Pins
const int pwmMotorA = 4;
const int pwmMotorB = 5;
const int dirMotorA = 0;
const int dirMotorB = 2;

int motorSpeed = 255; //Motor Speed (Value of 0-255)
int driveTime = 2000; //On Time for motor
int stopTime = 1000;  //Off Time for motor

void setup() {
  Serial.begin(115200);

  pinMode(pwmMotorA , OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(dirMotorB, OUTPUT);

  Serial.println("Robot is beeing initialized");
  delay(2000);
}

void loop() {
  Serial.println("driving forward!");
  digitalWrite(dirMotorA, HIGH);
  digitalWrite(dirMotorB, HIGH);  
  analogWrite(pwmMotorA, motorSpeed);
  analogWrite(pwmMotorB, motorSpeed);
  delay(driveTime);

  Serial.println("stopping!");
  analogWrite(pwmMotorA, 0);
  analogWrite(pwmMotorB, 0);
  delay(stopTime);

  Serial.println("driving backwards!");
  digitalWrite(dirMotorA, LOW);
  digitalWrite(dirMotorB, LOW);  
  analogWrite(pwmMotorA, motorSpeed);
  analogWrite(pwmMotorB, motorSpeed);
  delay(driveTime);

  Serial.println("stopping!");
  analogWrite(pwmMotorA, 0);
  analogWrite(pwmMotorB, 0);
  delay(stopTime);
}
