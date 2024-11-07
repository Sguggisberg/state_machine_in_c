#include "switch_driver.h"
#include <stdio.h>
#include <string.h>

#ifndef _code_hdnler_H
#define _code_hdnler_H

char enteredPin[2];
char pin[2] = "12";
bool codeOk = false;
bool isAnyButtonPressed() {
  return starIsPressed() || oneIsPressed() || twoIsPressed() || threeIsPressed() || fourIsPressed();
}

bool isCodeOk() {
  return codeOk;
}

void reset() {
  codeOk = false;
}

bool readCode() {
  Serial.println("Read pin");
  bool reading = true;
  while (reading) {
    if (!isAnyButtonPressed()) {
      if (oneIsPressed()) {
        char ch = '1';
        strncat(enteredPin, &ch, 1);
        Serial.println("One is pressed");
      }
      else if (twoIsPressed()) {
        char ch = '2';
        strncat(enteredPin, &ch, 1);
        Serial.println("Two is pressed");
      }
      else if (threeIsPressed()) {
        char ch = '3';
        strncat(enteredPin, &ch, 1);
        Serial.println("Three is pressed");
      }
      else if (fourIsPressed()) {
        char ch = '4';
        strncat(enteredPin, &ch, 1);
        Serial.println("Four is pressed");
      }
      else if (starIsPressed()) {
        Serial.println("Pin entered");
        Serial.println(enteredPin);
        if (strcmp(pin, enteredPin) == 0) {
          Serial.println("Pin ok");
          codeOk = true;
          reading = false;
        } else {
          Serial.println("Pin wrong!");
          reading = false;
        }
      }
    }

  }
}

#endif