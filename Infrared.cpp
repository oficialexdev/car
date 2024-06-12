#include "Arduino.h"
#include "Infrared.h"

Infrared::Infrared(byte analogPin) {
  this->analogPin = analogPin;
}

void Infrared::init() {
  pinMode(analogPin, INPUT);
}

int Infrared::analog() {
  return analogRead(analogPin);
}

int Infrared::digital() {
  return digitalRead(analogPin);
}