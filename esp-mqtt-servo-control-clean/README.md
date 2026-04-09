# ESP MQTT Servo Control (Clean Version)

A practical GitHub-style guide for controlling servos on ESP32 and ESP8266 boards over MQTT.

This repo is a clean embedded-systems version of the project. It focuses on:
- Wi-Fi connection
- MQTT command handling
- servo motion control
- response publishing
- simple testing from Node-RED

---

## What This Project Covers

- ESP32 MQTT servo control
- ESP8266 MQTT servo control
- clear command / response topic structure
- simple servo action set
- Node-RED test flow
- wiring notes and power reminders
- reusable template for future microcontroller projects

---

## Why This Matters

This is a strong embedded portfolio piece because it combines:
- microcontroller programming
- network messaging
- actuator control
- command / response feedback
- practical system testing

It also mirrors the same design patterns used in larger automation systems:
- command topic
- action execution
- completion response

---

## Folder Structure

```text
esp-mqtt-servo-control-clean/
├── README.md
├── esp32/
│   └── esp32_servo_mqtt_clean.ino
├── esp8266/
│   └── esp8266_servo_mqtt_clean.ino
├── docs/
│   ├── system_overview.md
│   ├── wiring_and_power.md
│   ├── topic_map.md
│   └── testing_workflow.md
├── nodered/
│   └── flow.json
├── templates/
│   └── embedded_project_template.md
└── .gitignore
```

---

## Commands

### ESP32
- `wave`
- `center`
- `left`
- `right`

### ESP8266
- `wave`
- `center`
- `left`
- `right`

---

## Topics

### ESP32
- command: `servo/esp32/cmd`
- response: `servo/esp32/response`

### ESP8266
- command: `servo/esp8266/cmd`
- response: `servo/esp8266/response`

---

## Libraries Needed

### ESP32
- `PubSubClient`
- `ESP32Servo`

### ESP8266
- `PubSubClient`
- `Servo`

---

## How to Use This Repo

Start with:
- `docs/system_overview.md`
- `docs/wiring_and_power.md`
- `docs/topic_map.md`
- `docs/testing_workflow.md`

Then upload:
- `esp32/esp32_servo_mqtt_clean.ino`
- or `esp8266/esp8266_servo_mqtt_clean.ino`

Import:
- `nodered/flow.json`

Use:
- `templates/embedded_project_template.md`

for future project writeups.

---

## Author Notes

This repo is intentionally simple and readable. It is meant to be the clean starting point for the Embedded_Microcontrollers section.
