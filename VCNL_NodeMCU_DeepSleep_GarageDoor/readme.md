This project hooks up an Adafruit VCNL4010 proximity sensor onto a NodeMCU.

The proximity sensor is meant to sense whether a garage door is opened or closed. The VCNL has interrupt control enabled and resets the NodeMCU from Deepsleep. After the reset NodeMCU connects to WLAN and sends proximity data to an MQTT-broker.

An MQTT client can call-up the VCNL proximity data to signal opened or closed garage door.

More on this here(https://github.com/Midgie75/ESP8266-Projects/wiki/%233-VCNL_NodeMCU_DeepSleep_GarageDoor_WatchDog)
