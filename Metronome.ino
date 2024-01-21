
#include <Servo.h> // include library 

int lastButtonState;

const int LIGHT_SENSOR_PIN = A0;  //Light sensor 
const int SERVO_PIN = 9;          //Servo 
const int AVERAGE_INTERVAL = 30000;  // Calculate average every 30 seconds

//Light Sensor triggers Servo ref: https://arduinogetstarted.com/tutorials/arduino-light-sensor-triggers-servo-motor

Servo servo;  // servo object to control a servo
unsigned long lastAverageTime = 0;  // Variable storing the last time average was calculated
int average = 0; 

void setup() {
  servo.attach(SERVO_PIN);  // attaches the servo on pin 9 to the servo object
  servo.write(0);
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // button 
  lastButtonState = digitalRead(2); //record the button state
}

void loop() {
  int buttonState = digitalRead(2); 

  if (buttonState != lastButtonState) {
    lastButtonState = buttonState; // last button state is the current button state 
  }
//checks if button has been pressed
  if (buttonState == LOW) {
//once button is released run the code
  
  int analogValue = analogRead(LIGHT_SENSOR_PIN);  // read the input on analog pin

 //Average ref:https://forum.arduino.cc/t/calculating-average-of-analog-read-values/427104/3 

 //Calculates the average of light sensor readings
  if (millis() - lastAverageTime >= AVERAGE_INTERVAL) {
    lastAverageTime = millis();
    average = 0;
    for (int i = 0; i < 20; i++) {
      average = average + analogRead(LIGHT_SENSOR_PIN);
    }
    average = average / 20; //20 number of readings to average 
    Serial.print("Light: ");
    Serial.println(average);
  }

//Checks the light sensor values and moves the servo accordingly 
//The smaller the value (less light), the greater the delay
//If there is less light the slower the tempo
  if (analogValue < 300) { // the lowest value I recieved from the sensor 
    servo.write(0);
    delay(2000);
    servo.write(90);
    delay(2000);
  }

  if (analogValue < 350) {
    servo.write(0);
    delay(1800);
    servo.write(90);
    delay(1800);
  }

  if (analogValue < 400) {
    servo.write(0);
    delay(1600);
    servo.write(90);
    delay(1600);
   }

   if (analogValue < 450) {
    servo.write(0);
    delay(1400);
    servo.write(90);
    delay(1400);
   }

    if (analogValue < 500){
    servo.write(0);
    delay(1200);
    servo.write(90);
    delay(1200);
}
    if (analogValue < 550){
    servo.write(0);
    delay(1000);
    servo.write(90);
    delay(1000);
}
   if (analogValue < 600){
    servo.write(0);
    delay(800);
    servo.write(90);
    delay(800);
}
   if (analogValue < 650){
    servo.write(0);
    delay(600);
    servo.write(90);
    delay(600);
}
   if (analogValue < 700){ // the highest value I recieved
    servo.write(0);
    delay(400);
    servo.write(90);
    delay(400);
}
}}






