# Testing Workflow

## Step 1
Confirm the broker is reachable.

## Step 2
Upload the firmware after updating:
- SSID
- password
- broker IP

## Step 3
Subscribe to the response topic.

Examples:
```bash
mosquitto_sub -h <BROKER_IP> -t servo/esp32/response
mosquitto_sub -h <BROKER_IP> -t servo/esp8266/response
```

## Step 4
Publish commands manually or use Node-RED.

Examples:
```bash
mosquitto_pub -h <BROKER_IP> -t servo/esp32/cmd -m "wave"
mosquitto_pub -h <BROKER_IP> -t servo/esp8266/cmd -m "center"
```

## Step 5
Verify:
- servo moves correctly
- response message is returned
- reconnection works if power is cycled
