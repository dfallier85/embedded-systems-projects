# System Layers

## Main idea

An embedded system usually contains several layers working together.

## Common layers

### 1. Input layer
- sensors
- buttons
- incoming network commands

### 2. Interpretation / logic layer
- thresholds
- decisions
- state handling
- filtering

### 3. Output layer
- relays
- servos
- LEDs
- pumps
- valves

### 4. Communication layer
- serial status
- MQTT messages
- external controller interaction

### 5. Power layer
- logic supply
- actuator supply
- grounding and switching considerations

## Why this matters

You design and troubleshoot better when you know which layer owns which behavior.
