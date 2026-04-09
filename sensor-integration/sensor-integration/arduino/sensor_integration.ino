/*
  sensor_integration.ino

  Clean sensor integration example for Arduino-style microcontrollers.

  What it does:
  - reads an analog sensor value
  - converts it to a percentage-style value
  - prints readings over serial
  - applies a simple threshold rule
  - reports whether the sensor is below or above threshold

  This is a clean starter example for:
  - soil moisture sensing
  - analog threshold monitoring
  - actuator trigger preparation
  - later MQTT / automation expansion

  Update these values before use:
  - SENSOR_PIN
  - DRY_RAW
  - WET_RAW
  - THRESHOLD_PERCENT
*/

const int SENSOR_PIN = A0;

// Calibration values.
// Change these after testing your real sensor.
const int DRY_RAW = 850;
const int WET_RAW = 350;

// Threshold for simple decision logic.
const int THRESHOLD_PERCENT = 40;

// Read interval
const unsigned long READ_INTERVAL_MS = 1000;

unsigned long lastReadMs = 0;


int clampValue(int value, int minValue, int maxValue) {
  if (value < minValue) return minValue;
  if (value > maxValue) return maxValue;
  return value;
}


int rawToPercent(int rawValue) {
  // Convert raw sensor value into a simple 0-100 scale.
  // Higher % means "wetter" in this example.
  long mapped = map(rawValue, DRY_RAW, WET_RAW, 0, 100);
  return clampValue((int)mapped, 0, 100);
}


void printSensorStatus(int rawValue, int percentValue) {
  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print(" | Percent: ");
  Serial.print(percentValue);
  Serial.print("% | Status: ");

  if (percentValue < THRESHOLD_PERCENT) {
    Serial.println("BELOW THRESHOLD");
  } else {
    Serial.println("OK");
  }
}


void setup() {
  Serial.begin(115200);
  Serial.println("Sensor integration ready");
}


void loop() {
  unsigned long now = millis();

  if (now - lastReadMs >= READ_INTERVAL_MS) {
    lastReadMs = now;

    int rawValue = analogRead(SENSOR_PIN);
    int percentValue = rawToPercent(rawValue);

    printSensorStatus(rawValue, percentValue);
  }
}
