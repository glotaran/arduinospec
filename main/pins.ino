const int pins[] = {5, 6, 7, 8, 9, 10, 11, 12};
byte triggers = 0;
int setOnce = 0;
unsigned int trigWidth = 1;
unsigned long trigPeriod = 5;

void setup_pins() {
  for (int i; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void set_pins(byte state) {
  for (int i; i < 8; i++) {
    if (bitRead(triggers, i) || bitRead(setOnce, i)) {
      continue;
    }
    if (bitRead(state, i)) {
      digitalWrite(pins[i], HIGH);
    } else {
      digitalWrite(pins[i], LOW);
    }
  }
};

void reset_once() {
  for (int i; i < 8; i++) {
    if (bitRead(setOnce, i)) {
      digitalWrite(pins[i], LOW);
    }
  }
}

void set_once() {
  for (int i; i < 8; i++) {
    if (bitRead(setOnce, i)) {
      digitalWrite(pins[i], HIGH);
    }
  }
}

long do_trigger() {
  for (int i; i < 8; i++) {
    if (bitRead(triggers, i)) {
      digitalWrite(pins[i], HIGH);
    }
  }
  delay(trigWidth);
  for (int i; i < 8; i++) {
    if (bitRead(triggers, i)) {
      digitalWrite(pins[i], LOW);
    }
  }
  delay(trigPeriod - trigWidth);
  return trigPeriod;
}
