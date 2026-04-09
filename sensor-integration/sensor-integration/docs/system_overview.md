# System Overview

## Basic flow

```text
[Sensor]
   ->
[Microcontroller Input]
   ->
[Raw Reading]
   ->
[Interpretation / Threshold Logic]
   ->
[Output / Control Decision]
```

## Main idea

A sensor project is not just about reading a pin.

It should answer:
- what does the value mean?
- how is it interpreted?
- what happens when it crosses a meaningful threshold?

That is the difference between raw data and usable control logic.
