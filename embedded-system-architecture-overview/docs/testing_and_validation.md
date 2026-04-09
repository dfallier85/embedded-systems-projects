# Testing and Validation

## Goal

Prove that the embedded system behaves correctly, not just that code uploads.

## Good validation topics

- input reads correctly
- calibration values make sense
- threshold logic changes state correctly
- outputs drive correctly
- power behavior is stable
- communication reports expected results
- safe default state works after reset

## Good habit

Test each layer separately:
1. input only
2. output only
3. communication only
4. full integrated behavior

That is usually much cleaner than debugging everything at once.
