#include "l293driver.h"
#include "led_driver.h"
#include "switch_driver.h"
#include "state_machine.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Init finished1");
  initDriver();
  initSwitches();
  ledInit();
  initStateMachine();
  Serial.println("Init finished2");
}

void loop() {
  stateMachine();
}
