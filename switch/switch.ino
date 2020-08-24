#include <Servo.h> //include servo library

//declare servo objects
Servo on;
Servo off;

void setup() {
  Serial.begin(9600); //begin serial for debugging
  on.attach(9); //attach the "on" servo to pin D9
  off.attach(8); //attach the "off" servo to pin D8
  pinMode(7, INPUT); //declare the sound sensor pin to INPUT

  on.write(180);
  off.write(0);
  delay(1000);
  off.write(30); 
}

void loop() {

}
