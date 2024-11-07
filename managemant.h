#include "l293driver.h"
#include "led_driver.h"
#include "switch_driver.h"
#include "state_machine.h"

#ifndef _management_H
#define _management_H

void initManagement() {
  initDriver();
  initSwitches();
  ledInit();
  initStateMachine();
}

void managemantLoop() {
 
}

#endif