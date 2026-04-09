# Wiring and Power

## Basic wiring

### Servo
- signal -> microcontroller GPIO
- power -> suitable 5V supply
- ground -> shared ground

### ESP boards
- power normally from USB or regulated source
- share ground with servo power

## Important reminder

Do not assume a servo should be powered directly from the microcontroller board.

Common servo issues are really power issues:
- jitter
- brownouts
- resets
- weak movement

## Example pin used here

- GPIO2 / D4 style pin
