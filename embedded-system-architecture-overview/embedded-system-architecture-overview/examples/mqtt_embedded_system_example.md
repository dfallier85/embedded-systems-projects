# MQTT Embedded System Example

## Scenario

An embedded device receives commands over MQTT and reports status back while also controlling local hardware.

## Flow

1. device connects to Wi-Fi
2. device subscribes to command topic
3. device receives command
4. controller updates output
5. device publishes response or status message

## Why this matters

This is a strong example of combining:
- embedded control
- communication
- actuator behavior
- feedback reporting
