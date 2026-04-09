# Power and Signal Flow

## Main point

Power flow and signal flow are not the same thing.

## Signal flow
- sensor values to controller
- controller commands to relay / servo / output

## Power flow
- supply to microcontroller
- supply to actuator
- switching path through relay or driver

## Why this matters

A lot of embedded problems are really power problems:
- brownouts
- resets
- weak actuator behavior
- noise
- ground issues

Good architecture notes should explain both signal path and power path.
