# Testing Workflow

## Step 1
Upload the sketch and open the serial monitor.

Use:
- 115200 baud

## Step 2
Verify startup message appears.

## Step 3
Send:
- `status`

Confirm the reported relay state matches expectation.

## Step 4
Send:
- `on`
- `off`

Confirm the relay toggles correctly.

## Step 5
Send a timed pulse, for example:
```text
pulse 2000
```

Confirm:
- relay turns on
- relay stays on for about 2 seconds
- relay turns off again

## Step 6
Verify actuator behavior

If a real load is connected, confirm the load responds correctly and safely.

## Good habit

Test the relay alone first.  
Then test the real actuator.  
Do not debug both unknowns at the same time.
