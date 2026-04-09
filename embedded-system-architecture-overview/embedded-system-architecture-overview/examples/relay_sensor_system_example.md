# Relay + Sensor System Example

## Scenario

A sensor value decides whether a relay-controlled actuator should be enabled.

## Flow

1. sensor provides raw reading
2. controller interprets reading
3. logic compares reading to threshold
4. relay output is turned on or off
5. system reports current state

## Why this matters

This is one of the most common small automation patterns in embedded systems.
