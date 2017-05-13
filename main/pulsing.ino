unsigned int nrStates = 0;
byte states [100];
long delays [100];
const byte triggerBit = 7;

void do_state(int state) {
  set_pins(states[state]);

  if (bitRead(states[state], triggerBit)) {
    long t = 0;
    while (t < delays[state]) {
      t += do_trigger();
    }
  } else {
    delay(delays[state]);
  }
}

void fire(byte first, byte last) {
  set_once();
  for (int i = first; i <= last; i++) {
    do_state(i);
  }
  set_pins(0);
}

void fire_n(int n, byte first, byte last) {
  for (int i = 0; i < n; i++) {
    fire(first, last);
  }
}
