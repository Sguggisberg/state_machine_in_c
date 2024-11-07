#include "l293driver.h"

#ifndef _state_machine_H
#define _state_machine_H

void triggerOpeningState();
void triggerOpenState();
void triggerClosingState();
void triggerClosedState();

typedef enum {
  INIT,
  CLOSED,
  OPEN,
  OPENING,
  CLOSING,
} STATE;

typedef void (*TransisitionFunction)(void);

typedef struct {
  STATE from;
  TransisitionFunction transisitionFunction;
  STATE to;
} Trasnsition;

Trasnsition transisitions[] = {
  { CLOSED, triggerOpeningState, OPENING },
  { OPENING, triggerOpenState, OPEN },
  { OPEN, triggerClosingState, CLOSING },
  { CLOSING, triggerClosedState, CLOSED },
};

#define NUMBER_OF_STATES (sizeof(transisitions))
STATE state;

void stateMachine() {
  switch (state) {
    case CLOSED:
      triggerOpeningState();
      break;

    case OPENING:
      triggerOpenState();
      break;

    case OPEN:
      triggerClosingState();
      break;

    case CLOSING:
      triggerClosedState();
      break;
  }
}

void triggerOpeningState() {
  if (oneIsPressed()) {
    state = OPENING;
  }
}

void triggerOpenState() {
  Serial.println("Opening - please wait!");
  while (!isOpen()) {
    open();
  }
  stopMotor();
  state = OPEN;
  Serial.println("Door is open");
}

void triggerClosingState() {
  if (oneIsPressed()) {
    state = CLOSING;
  }
}

void triggerClosedState() {
  Serial.println("Closing - please wait!");
  while (!isClosed()) {
    close();
  }
  stopMotor();
  state = CLOSED;
  Serial.println("Door is closed");
}

void initStateMachine() {
  state = CLOSED;
}

#endif