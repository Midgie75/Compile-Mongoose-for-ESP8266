
/*
 ESP8266 connected to Adafruit VCNL4010 proximity sensor via I2C.
 
 Sends readouts via MQTT based on basic ESP8266 MQTT example from pubsub library
*/

// Sensor part

#include <Wire.h>                 //start I2C
#include "Adafruit_VCNL4010.h"

Adafruit_VCNL4010 vcnl;

#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
   #define Serial SerialUSB
#endif

// MQTT Example
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "****";
const char* password = "****";
const char* mqtt_server = "****";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
int i = 0;

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  digitalWrite(BUILTIN_LED, HIGH);   // Turn the LED off
  pinMode(14, OUTPUT);
  digitalWrite(14, LOW);
  pinMode(2, INPUT);
  Serial.begin(115200);
  
  // Sensor part
  Wire.begin(5,4);          //SDA on pin2=GPIO2 , SCL on pin0=GPIO0 on ESP8266-S01
  Serial.println("VCNL4010 test");

  if (! vcnl.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  }
  Serial.println("Found VCNL4010");
  //
  
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  IPAddress ip(192, 168, 178, 73); // this 3 lines for a fix IP-address
  IPAddress gateway(192, 168, 178, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(ip, gateway, subnet); // before or after Wifi.Begin(ssid, password);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  Serial.print("Attempting MQTT connection");
  while (!client.connected()) {
     Serial.print(".");
     client.connect("VCNLPub");
     delay(1000);
  }
  Serial.println("connected");
}
void loop() {
  if (!client.connected()) {
     reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 1000) {
    lastMsg = now;
    value = int(vcnl.readAmbient());
    snprintf (msg,75, "%ld", value);
    Serial.print("VCNL/Ambient: ");
    Serial.println(value);
    //Serial.println(msg);
    client.publish("VCNL/Ambient", msg);
    value = int(vcnl.readProximity());
    snprintf (msg,75, "%ld", value);
    Serial.print("VCNL/Proximity: ");
    Serial.println(value);
    //Serial.println(msg);
    client.publish("VCNL/Proximity", msg);
    i+=1;  
    //Serial.println(i);
    if (digitalRead(2)==HIGH) {
       Serial.println("Pin2 is HIGH");
       digitalWrite(14,HIGH);
       //delay(1000);
       //digitalWrite(14, HIGH);
    }
    else {
       Serial.println("Pin2 is LOW");
       digitalWrite(14, LOW);
       //delay(1000);
    }
  }
  if (i > 5) {
     Serial.println("Going into deep sleep for 20 seconds");
     client.disconnect();
     ESP.deepSleep(20e6); // 20e6 is 20 microseconds
  }

}
