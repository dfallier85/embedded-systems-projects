# Communication Paths

## Common communication paths

Embedded systems often communicate through:
- serial
- MQTT
- I2C
- SPI
- UART
- GPIO signaling

## Why this matters

The architecture should explain:
- what data comes in
- what data goes out
- who consumes it
- whether communication is optional or required

## Example

A system may:
- receive MQTT commands
- read local sensors
- drive outputs
- report status back over serial or MQTT
