# Topic Map

## ESP32
- `servo/esp32/cmd`
- `servo/esp32/response`

## ESP8266
- `servo/esp8266/cmd`
- `servo/esp8266/response`

## Why this works

Each device family gets:
- one command topic
- one response topic

That keeps the embedded side simple and the test side easy to follow.
