#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <IRsend.h>
#include <ArduinoJson.h>
#include <IRremoteESP8266.h>

#define ssid "x" 
#define password "x"
#define mqtt_server "192.168.1.65"
#define mqtt_port 1883
#define state_topic "home/bedroom/tv"
#define MQTT_MAX_PACKET_SIZE 512

const int BUFFER_SIZE = 300;

ESP8266WebServer server(80);
IRsend irsend(4);  // An IR LED is controlled by GPIO pin 4 (D2)

WiFiClient espClient;
PubSubClient client(espClient);

bool processJson(char* message) {
  StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;

  JsonObject& root = jsonBuffer.parseObject(message);

  if (!root.success()) {
    Serial.println("parseObject() failed");
    return false;
  }

  if (root.containsKey("volume")) {
    if (strcmp(root["volume"], "up") == 0) {
      irsend.sendNEC(0x20DF40BF, 32); 
    }
    if (strcmp(root["volume"], "down") == 0) {
      irsend.sendNEC(0x20DFC03F, 32);
    }    
  }
  else if (root.containsKey("power")) {
    if (strcmp(root["power"], "on") == 0) {
      irsend.sendNEC(0x20DF10EF, 32);
    }
  }
  return true;
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  char message[length + 1];
  for (int i = 0; i < length; i++) {
    message[i] = (char)payload[i];
  }
  message[length] = '\0';
  Serial.println(message);

  if (!processJson(message)) {
    return;
  }
}

void setup(void){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  irsend.begin();
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("bedroom-remote")) {
    Serial.println("MDNS responder started");
  }

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop(void){
  if (!client.connected()) {
    // reconnect();
    software_Reset();
  }

  client.loop();
}

void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    if (client.connect("esp8266-1")) {
      Serial.println("MQTT connected");
      client.subscribe(state_topic);
    }
    else {
      Serial.print("MQTT failed, rc = ");
      Serial.print(client.state());
      Serial.println(", trying again in 5 seconds");
      delay(5000);
    }
  }
}

