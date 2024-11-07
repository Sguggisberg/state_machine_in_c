#ifndef _potentiometer_driver_H
#define _potentiometer_driver_H
const int potPin = A0;

int getMotorSpeed() {
  return analogRead(potPin) / 4;
}

#endif