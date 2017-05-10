int nrStates;
byte states [100];
long delays [100];

void do_state(int state) {
  set_pins(states[state]);
  
  long t = 0;
  while (t < delays[state]) {
    t += do_trigger();
  }  
}

void fire(){
  set_once();
  for (int i = 0; i<nrStates; i++){
    do_state(i);
  }
}
