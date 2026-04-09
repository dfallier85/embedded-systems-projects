# Relay Logic Notes

## Main point

A relay-controlled system needs one very clear answer:

- what output state means ON?

Some relay boards turn ON when the pin is HIGH.  
Some turn ON when the pin is LOW.

## Why this matters

If you get this wrong:
- your relay behaves backwards
- boot behavior may be wrong
- your "off" state may energize the load

## Good practice

Define constants clearly, such as:
- `RELAY_ON`
- `RELAY_OFF`

Then use those everywhere instead of scattering HIGH / LOW assumptions through the code.
