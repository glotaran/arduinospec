void setup() {
  setup_pins();
  setup_serial();
}

void loop() {
  if (Serial.available()) {
    process_command(Serial.read());
  }
}
