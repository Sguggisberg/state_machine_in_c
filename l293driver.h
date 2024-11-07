#include "potentiometer_driver.h"
#include "switch_driver.h"

#ifndef _l293driver_H
#define _l293driver_H

const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 11;

int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;  // 1= opening, 0= closing

void startMotor();
void stopMotor();

void initDriver() {
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void open() {
  if (!isOpen()) {
    motorSpeed = getMotorSpeed();
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    startMotor();
  } 
}

void close() {
  if (!isClosed()) {
    motorSpeed = getMotorSpeed();
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
    startMotor();
  } 
}

bool isClosing() {
  return motorDirection == 0;
}

bool isOpenin() {
  return motorDirection == 1;
}

void stopMotor() {
  analogWrite(enablePin, 0);
}

void startMotor() {
  analogWrite(enablePin, motorSpeed);
}

void motorObservable() {
  motorSpeed = getMotorSpeed();
}

#endif