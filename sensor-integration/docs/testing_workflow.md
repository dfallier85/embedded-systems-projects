# Testing Workflow

## Step 1
Upload the sketch and open the serial monitor.

Use:
- 115200 baud

## Step 2
Observe raw readings in different conditions.

## Step 3
Record calibration references.

Example:
- dry sensor
- wet sensor

## Step 4
Update calibration constants in code.

## Step 5
Verify the interpreted percent value behaves reasonably.

## Step 6
Verify threshold behavior.

Confirm the output changes when the reading crosses the chosen threshold.

## Good habit

Test the sensor alone before tying it to an actuator.
That keeps debugging much cleaner.
