// commands

const byte SET_TRIGGER_WIDTH = 0x01;
const byte GET_TRIGGER_WIDTH = 0x02;

const byte SET_TRIGGER_PERIOD = 0x03;
const byte GET_TRIGGER_PERIOD = 0x04;

const byte SET_TRIGGER_OUT_PINS = 0x05;
const byte GET_TRIGGER_OUT_PINS = 0x06;

const byte SET_ONCE_OUT_PINS = 0x07;
const byte GET_ONCE_OUT_PINS = 0x08;

const byte SET_NR_STATES = 0x09;
const byte GET_NR_STATES = 0x0A;

const byte SET_STATE = 0x0B;
const byte GET_STATE = 0x0C;

const byte RESET_ONCE = 0x0D;

const byte FIRE = 0x0E;
const byte FIRE_N = 0x0F;

void setup_serial() {
  Serial.begin(9600);
}

void process_command(byte cmd) {
  switch (cmd) {
    case SET_TRIGGER_WIDTH:
      Serial.println("OK");
      trigWidth = Serial.parseInt();
      //trigWidth = 0;
      //trigWidth += Serial.read() << 8;
      //trigWidth += Serial.read();
      Serial.println("OK");
      break;
    case GET_TRIGGER_WIDTH:
      Serial.print("OK ");
      Serial.println(trigWidth);
      break;
    case SET_TRIGGER_PERIOD:
      Serial.println("OK");
      trigPeriod = Serial.parseInt();
      Serial.println("OK");
      break;
    case GET_TRIGGER_PERIOD:
      Serial.print("OK ");
      Serial.println(trigPeriod);
      break;
    case SET_TRIGGER_OUT_PINS:
      Serial.println("OK");
      triggers = Serial.parseInt();
      Serial.println("OK");
      break;
    case GET_TRIGGER_OUT_PINS:
      Serial.print("OK ");
      Serial.println(triggers);
      break;
    case SET_ONCE_OUT_PINS:
      Serial.println("OK");
      setOnce = Serial.parseInt();
      Serial.println("OK");
      break;
    case GET_ONCE_OUT_PINS:
      Serial.print("OK ");
      Serial.println(setOnce);
      break;
    case SET_NR_STATES:
      Serial.println("OK");
      nrStates = Serial.parseInt();
      Serial.println("OK");
      break;
    case GET_NR_STATES:
      Serial.print("OK ");
      Serial.println(nrStates);
      break;
    case SET_STATE:
      {
        Serial.println("OK");
        int state = Serial.parseInt();
        Serial.println("OK");
        states[state] = Serial.parseInt();
        Serial.println("OK");
        delays[state] = Serial.parseInt();
        Serial.println("OK");
      }
      break;
    case GET_STATE:
      {
        Serial.println("OK ");
        int state = Serial.parseInt();
        Serial.print("OK ");
        Serial.print(states[state]);
        Serial.print(" ");
        Serial.println(delays[state]);
      }
      break;
    case RESET_ONCE:
      reset_once();
      Serial.println("OK");
      break;
    case FIRE:
      {
        Serial.println("OK ");
        byte first = Serial.parseInt();
        Serial.println("OK ");
        byte last = Serial.parseInt();
        Serial.println("OK ");
        fire(first, last);
        Serial.println("OK");
      }
      break;
    case FIRE_N:
      {
        Serial.println("OK ");
        int n = Serial.parseInt();
        Serial.println("OK ");
        byte first = Serial.parseInt();
        Serial.println("OK ");
        byte last = Serial.parseInt();
        Serial.println("OK ");
        fire_n(n, first, last);
        Serial.println("OK");
      }
      break;
    default:
      Serial.println("ERROR");
      break;
  }
}
