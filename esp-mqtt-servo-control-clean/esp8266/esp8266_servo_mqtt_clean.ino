/*
  esp8266_servo_mqtt_clean.ino

  Clean ESP8266 servo control over MQTT.

  What it does:
  - connects to Wi-Fi
  - connects to an MQTT broker
  - subscribes to a command topic
  - performs simple servo actions
  - publishes a response message after each action

  Commands:
  - wave
  - center
  - left
  - right

  Update these before uploading:
  - WIFI_SSID
  - WIFI_PASSWORD
  - MQTT_BROKER
  - TOPIC_CMD
  - TOPIC_RESPONSE
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Servo.h>

// -----------------------------
// User settings
// -----------------------------
const char* WIFI_SSID = "ESP32-Hub";
const char* WIFI_PASSWORD = "Tryptol1n3!";
const char* MQTT_BROKER = "192.168.4.1";

const int MQTT_PORT = 1883;
const char* DEVICE_NAME = "esp8266_servo_1";

const char* TOPIC_CMD = "servo/esp8266/cmd";
const char* TOPIC_RESPONSE = "servo/esp8266/response";

// D4 / GPIO2 from your earlier setup
const int SERVO_PIN = 2;

// Servo positions
const int SERVO_CENTER = 90;
const int SERVO_LEFT = 40;
const int SERVO_RIGHT = 140;

// -----------------------------
// Globals
// -----------------------------
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
Servo myServo;

// -----------------------------
// Wi-Fi
// -----------------------------
void connectWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

// -----------------------------
// MQTT
// -----------------------------
void connectMQTT() {
  while (!mqttClient.connected()) {
    if (mqttClient.connect(DEVICE_NAME)) {
      mqttClient.subscribe(TOPIC_CMD);
      mqttClient.publish(TOPIC_RESPONSE, "ESP8266 connected");
    } else {
      delay(1000);
    }
  }
}

// -----------------------------
// Servo actions
// -----------------------------
void moveServoSmooth(int targetAngle) {
  int currentAngle = myServo.read();

  if (currentAngle < targetAngle) {
    for (int pos = currentAngle; pos <= targetAngle; pos++) {
      myServo.write(pos);
      delay(10);
    }
  } else {
    for (int pos = currentAngle; pos >= targetAngle; pos--) {
      myServo.write(pos);
      delay(10);
    }
  }
}

void doWave() {
  for (int i = 0; i < 3; i++) {
    moveServoSmooth(SERVO_LEFT);
    delay(150);
    moveServoSmooth(SERVO_RIGHT);
    delay(150);
  }
  moveServoSmooth(SERVO_CENTER);
}

// -----------------------------
// Command handler
// -----------------------------
void handleCommand(String cmd) {
  cmd.trim();

  if (cmd == "wave") {
    doWave();
    mqttClient.publish(TOPIC_RESPONSE, "ESP8266 wave complete");
  }
  else if (cmd == "center") {
    moveServoSmooth(SERVO_CENTER);
    mqttClient.publish(TOPIC_RESPONSE, "ESP8266 centered");
  }
  else if (cmd == "left") {
    moveServoSmooth(SERVO_LEFT);
    mqttClient.publish(TOPIC_RESPONSE, "ESP8266 moved left");
  }
  else if (cmd == "right") {
    moveServoSmooth(SERVO_RIGHT);
    mqttClient.publish(TOPIC_RESPONSE, "ESP8266 moved right");
  }
  else {
    mqttClient.publish(TOPIC_RESPONSE, "ESP8266 unknown command");
  }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String cmd = "";

  for (unsigned int i = 0; i < length; i++) {
    cmd += (char)payload[i];
  }

  handleCommand(cmd);
}

// -----------------------------
// Setup / loop
// -----------------------------
void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(SERVO_CENTER);

  connectWiFi();

  mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
  mqttClient.setCallback(mqttCallback);
}

void loop() {
  if (!mqttClient.connected()) {
    connectMQTT();
  }

  mqttClient.loop();
}
