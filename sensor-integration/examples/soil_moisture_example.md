# Soil Moisture Example

## Scenario

An analog soil moisture sensor is used to estimate whether soil is dry enough to trigger watering logic.

## Flow

1. microcontroller reads raw analog value
2. raw value is mapped to a calibrated percentage
3. percentage is compared to a moisture threshold
4. system decides whether the soil is below threshold

## Why this is useful

This is a strong embedded automation pattern because it naturally leads into:
- relay control
- pump control
- MQTT reporting
- timed watering rules
