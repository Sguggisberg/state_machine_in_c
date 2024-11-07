#ifndef _switch_driver_H
#define _switch_driver_H

// Micro switches
const int s1Pin = 13;
const int s2Pin = 12;

// Human buttons
const int number1 = 8;
const int number2 = 6;
const int number3 = 7;
const int number4 = 5;
const int number5 = 4;

int s1 = 0;
int s2 = 0;

void initSwitches() {
  pinMode(s1Pin, INPUT);
  pinMode(s2Pin, INPUT);
  pinMode(number1, INPUT);
  pinMode(number2, INPUT);
  pinMode(number3, INPUT);
  pinMode(number4, INPUT);
  pinMode(number5, INPUT);

  s1 = digitalRead(s1Pin);
  s2 = digitalRead(s2Pin);
}

bool isOpen() {
  return digitalRead(s1Pin) == HIGH;
}

bool isClosed() {
  return digitalRead(s2Pin) == HIGH;
}

bool oneIsPressed() {
  return digitalRead(number1);
}

bool twoIsPressed() {
  return digitalRead(number2);
}

bool threeIsPressed() {
  return digitalRead(number3);
}

bool fourIsPressed() {
  return digitalRead(number4);
}

bool starIsPressed() {
  return digitalRead(number5);
}

#endif