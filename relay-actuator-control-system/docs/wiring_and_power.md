# Wiring and Power

## Typical wiring concept

### Microcontroller to relay module
- digital output pin -> relay input
- ground -> relay ground
- logic supply -> relay logic supply (if required by module)

### Relay switching side
- external supply -> relay common / load path
- relay output -> actuator
- actuator return -> external supply return

## Important reminder

Do not assume the microcontroller should directly power the load.

Relays are used because the load side often needs:
- higher current
- a separate supply
- electrical isolation or at least switching separation

## Common real-world issue

Many relay modules are:
- active-HIGH
or
- active-LOW

Check the module behavior before assuming the code is wrong.

## Another reminder

If the load is inductive:
- pump
- solenoid
- motor-related device

you may need proper protection and careful wiring.
