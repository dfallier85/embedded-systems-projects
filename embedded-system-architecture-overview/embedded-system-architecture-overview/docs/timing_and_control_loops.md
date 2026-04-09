# Timing and Control Loops

## Main point

An embedded system is also a timing system.

## Common timing concepts

- polling interval
- debounce time
- actuator pulse duration
- sensor read interval
- timeout rules

## Why this matters

Even simple systems behave very differently depending on timing.

Examples:
- relay pulse length
- sensor sample interval
- how often MQTT is serviced
- how fast a servo is moved

Good architecture notes should mention the timing assumptions that shape system behavior.
