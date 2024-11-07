#include "Arduino.h"
#ifndef _led_driver_H
#define _ledr_driver_H

const int redLedPinController = 9;
const int greenLedPinController = 10;

void ledInit() {
  pinMode(redLedPinController, OUTPUT);
  pinMode(greenLedPinController, OUTPUT);
}

void redOn(){
  digitalWrite(redLedPinController, HIGH);
}

void redOff(){
  digitalWrite(redLedPinController, LOW);
}

void greenOn(){
  digitalWrite(greenLedPinController, HIGH);
}

void greenOff(){
  digitalWrite(greenLedPinController, LOW);
}

#endif