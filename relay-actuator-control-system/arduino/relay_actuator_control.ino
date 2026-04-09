/*
  relay_actuator_control.ino

  Clean relay / actuator control example for Arduino-style microcontrollers.

  What it does:
  - configures a relay output pin
  - turns the relay on or off from serial commands
  - supports timed activation
  - reports status over serial

  Example use:
  - pump control
  - valve control
  - light / indicator control
  - other on/off actuators

  Commands over serial:
  - on
  - off
  - pulse <milliseconds>
  - status

  IMPORTANT:
  This example assumes an active-HIGH relay module.
  If your relay is active-LOW, invert the ON/OFF logic below.
*/

const int RELAY_PIN = 7;

// Change this if your relay is active-LOW instead of active-HIGH.
const int RELAY_ON = HIGH;
const int RELAY_OFF = LOW;

bool relayState = false;


void setRelay(bool on) {
  relayState = on;
  digitalWrite(RELAY_PIN, on ? RELAY_ON : RELAY_OFF);
}


void printStatus() {
  Serial.print("Relay state: ");
  Serial.println(relayState ? "ON" : "OFF");
}


void handlePulseCommand(long durationMs) {
  if (durationMs <= 0) {
    Serial.println("Invalid pulse duration");
    return;
  }

  Serial.print("Pulsing relay for ");
  Serial.print(durationMs);
  Serial.println(" ms");

  setRelay(true);
  delay(durationMs);
  setRelay(false);

  printStatus();
}


void handleCommand(String cmd) {
  cmd.trim();

  if (cmd == "on") {
    setRelay(true);
    Serial.println("Relay turned ON");
    printStatus();
  }
  else if (cmd == "off") {
    setRelay(false);
    Serial.println("Relay turned OFF");
    printStatus();
  }
  else if (cmd == "status") {
    printStatus();
  }
  else if (cmd.startsWith("pulse ")) {
    String value = cmd.substring(6);
    long durationMs = value.toInt();
    handlePulseCommand(durationMs);
  }
  else {
    Serial.println("Unknown command");
    Serial.println("Valid commands: on, off, pulse <ms>, status");
  }
}


void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  setRelay(false);

  Serial.begin(115200);
  Serial.println("Relay actuator control ready");
  Serial.println("Commands: on, off, pulse <ms>, status");
}


void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    handleCommand(cmd);
  }
}
