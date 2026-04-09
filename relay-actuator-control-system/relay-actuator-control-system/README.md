# Relay / Actuator Control System

A practical GitHub-style guide for controlling an on/off actuator through a relay using a microcontroller.

This repo is useful for projects where a low-power control board needs to switch a higher-power load such as:
- pump
- valve
- light
- motor driver enable
- solenoid
- other simple on/off actuators

It is especially relevant for embedded automation projects where control logic and power switching need to stay clearly separated.

---

## What This Project Covers

- relay-based actuator control from a microcontroller
- serial-command control for testing
- timed pulse activation
- basic status reporting
- wiring and power-separation notes
- relay safety reminders
- reusable project template for future actuator systems

---

## Why This Matters

This is one of the most common real embedded control patterns:

- low-power logic side
- isolated switching side
- controlled on/off output to a load

It is simple, but it is foundational.

A clean implementation of relay control shows that you understand:
- digital outputs
- actuator switching
- power separation
- testing and verification
- practical hardware integration

---

## Folder Structure

```text
relay-actuator-control-system/
├── README.md
├── arduino/
│   └── relay_actuator_control.ino
├── docs/
│   ├── system_overview.md
│   ├── wiring_and_power.md
│   ├── relay_logic_notes.md
│   └── testing_workflow.md
├── examples/
│   └── pump_control_example.md
├── templates/
│   └── actuator_project_template.md
└── .gitignore
```

---

## Example Use Cases

- turn a pump on and off
- pulse a relay for a fixed duration
- test actuator wiring from serial commands
- build a simple automation stage before adding sensors or MQTT

---

## Serial Commands

This starter example supports:
- `on`
- `off`
- `pulse <milliseconds>`
- `status`

Example:
```text
pulse 2000
```

---

## Important Reminder

A relay lets a small controller influence a bigger load, but that does **not** mean every relay setup is automatically safe.

You still need to think about:
- correct supply voltage
- current requirements
- shared or isolated grounds
- flyback protection where relevant
- whether the load is AC or DC
- whether the relay module is active-HIGH or active-LOW

---

## How to Use This Repo

Start with:
- `docs/system_overview.md`
- `docs/wiring_and_power.md`
- `docs/relay_logic_notes.md`
- `docs/testing_workflow.md`

Then upload:
- `arduino/relay_actuator_control.ino`

Read:
- `examples/pump_control_example.md`

Use:
- `templates/actuator_project_template.md`

for future actuator-control writeups.

---

## Author Notes

This repo is intentionally simple and practical.  
It is meant to be a clean starting point for embedded actuator-control projects before adding more advanced triggers, sensors, or networked control.
