#ifndef Infrared_h
#define Infrared_h

#include "Arduino.h"

class Infrared {
public:
  //DEFINE ANALOG AND DIGITAL PINS
  Infrared(byte analogPin);
  //DEFINE PINS MODE
  void init();
  //READ IN ANALOG MODE
  int analog();
  int digital();
private:
  byte analogPin;
};

#endif