/* Code written by Hung Che.
 * This is the code for my "Touch less, Do more" challenge submission
 */
 
#include <Servo.h> //include servo library

//declare servo objects
Servo on;
Servo off;

int light_switch = 0; //light status: 0 = on, 1 = off

void setup() {
  Serial.begin(9600); //begin serial for debugging
  on.attach(9); //attach the "on" servo to pin D9
  off.attach(8); //attach the "off" servo to pin D8
  pinMode(7, INPUT); //declare the sound sensor pin to INPUT

  //set the initial positions of the servos
  off.write(0);
  delay(5) ;
  on.write(180);
}

void loop() {
  int sensor = digitalRead(7); //obtain data from the sensor port
  if(sensor == 1){ // if sound is detected ...
    
    if(light_switch == 0){ // ...and if the light is on...
      
      Serial.println("off"); //print "off" the the serial monitor
      on.write(180);
      //move servos
      delay(5);
      off.write(30);
      delay(2000);

      light_switch ++; //change status to "off"
      
    }else if(light_switch==1){ // ... and if the light is off...
       Serial.println("on"); //print "on" the the serial monitor
       off.write(0);
       delay(5);
       on.write(150);
       delay(2000);
       light_switch = 0; //change status to "on"
    }
  }
}
