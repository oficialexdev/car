#include "Motor.h"
#include "Ultrasonic.h"
#include "Infrared.h"

const int BLACK_READ_VALUE = 700;

//A0 to A4

//GLOBALS OBJECTS INSTANCES
//MOTORS
//Left motor in1 8 in2 9 EnA 10
//Right motor in4 13  in3 12  EnB 11
Motor leftMotor(10, 8, 9);
Motor rightMotor(11, 12, 13);

// Ultrasonic ultrasonic(2, 3);

Infrared rightExInfra(A4);
Infrared rightInfra(A3);
Infrared middleInfra(A2);
Infrared leftInfra(A1);
Infrared leftExInfra(A0);

bool s1 = false, s2 = false, s3 = false, s4 = false, s5 = false;

void setup() {
  Serial.begin(9600);
  //
  leftMotor.init();
  rightMotor.init();
  // ultrasonic.init();
  middleInfra.init();
  leftInfra.init();
  leftExInfra.init();
  rightInfra.init();
  rightExInfra.init();
  //
  // runTest();
  // rightMotor.rotate(-255,true);
}

void loop() {
  // setSensorsAndPrint();
  setSensors();
  controll();
}

void runTest() {
  testRightMotor();
  delay(1000);
  stop();
  testLeftMotor();
  delay(1000);
  stop();
}

void setSensorsAnalog(){
  // s1 = !isOnRange(leftExInfra.analog(), BLACK_READ_VALUE * 0.95f, BLACK_READ_VALUE * 1.05f);
  // s2 = !isOnRange(leftInfra.analog(), BLACK_READ_VALUE * 0.95f, BLACK_READ_VALUE * 1.05f);
  // s3 = !isOnRange(middleInfra.analog(), BLACK_READ_VALUE * 0.95f, BLACK_READ_VALUE * 1.05f);
  // s4 = !isOnRange(rightInfra.analog(), BLACK_READ_VALUE * 0.95f, BLACK_READ_VALUE * 1.05f);
  // s5 = !isOnRange(rightExInfra.analog(), BLACK_READ_VALUE * 0.95f, BLACK_READ_VALUE * 1.05f);
}


void setSensors() {
  s1 = !leftExInfra.digital();
  s2 = !leftInfra.digital();
  s3 = !middleInfra.digital();
  s4 = !rightInfra.digital();
  s5 = !rightExInfra.digital();  
}

void setSensorsAndPrint() {
  setSensors();
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);
  delay(200);
}

bool isOnRange(float value, float min, float max) {
  return value <= max && value >= min;
}

void turn90Degress(bool left = true) {
  rightMotor.rotate(left ? 255 : -255);
  leftMotor.rotate(left ? -255 : 255, false);
  delay(500);
  stop();
}

void turnLeft() {
  //30 80
  rightMotor.rotate(30, true);
  leftMotor.rotate(150, false);
}

void turnRight() {
  rightMotor.rotate(150);
  leftMotor.rotate(30, false);
}

void goAhead() {
  rightMotor.rotate(255);
  leftMotor.rotate(255, false);
}

void stop() {
  leftMotor.rotate(0);
  rightMotor.rotate(0);
}

void controll() {
  if (s3) {
    goAhead();
  } else if (s2 || s1) {
    turnLeft();
  } else if (s4 || s5) {
    turnRight();
  } 
  // else if (!s1 && !s2 && !s3 && !s4 && !s5) {
  //   stop();
  // }
}
//TESTS
void testLeftMotor() {
  leftMotor.rotate(255, false);
}
void testRightMotor() {
  rightMotor.rotate(255, true);
}