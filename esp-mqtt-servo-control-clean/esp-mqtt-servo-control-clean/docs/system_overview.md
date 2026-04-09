# System Overview

## Basic flow

```text
[Node-RED / MQTT Publisher]
          ->
      [MQTT Broker]
          ->
   [ESP32 or ESP8266]
          ->
        [Servo]
          ->
 [MQTT Response Message]
```

## Main idea

This project follows a simple embedded control pattern:
- receive command
- perform action
- report result

That same pattern scales well into larger automation systems.
