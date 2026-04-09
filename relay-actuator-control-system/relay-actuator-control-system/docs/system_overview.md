# System Overview

## Basic flow

```text
[Microcontroller Output]
         ->
     [Relay Module]
         ->
       [Actuator]
```

## Main idea

The microcontroller does not power the actuator directly.

Instead, it controls the relay, and the relay switches power to the actuator.

That separation is important because:
- the logic side stays simple
- the load side can use a different power path
- the system becomes easier to reason about

## Typical examples

- pump
- solenoid
- valve
- lamp
- motor enable line
