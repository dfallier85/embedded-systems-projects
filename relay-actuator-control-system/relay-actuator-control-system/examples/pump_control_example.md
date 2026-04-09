# Pump Control Example

## Scenario

A small DC pump is controlled through a relay module.

## Typical flow

1. microcontroller command turns relay on
2. relay closes switching path
3. pump receives external power
4. pump runs until command turns relay off

## Why this is useful

This is a common first actuator-control stage in automation projects because it is:
- easy to test
- easy to explain
- expandable later with sensors and timing logic

## Good future upgrades

- moisture or level sensor trigger
- MQTT command input
- timed dosing logic
- safety timeout
- manual override input
