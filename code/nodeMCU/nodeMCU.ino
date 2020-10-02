
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "functions.h"

//char* ssid = "Night King";
//char* password = "121212qq";

char* ssid = "Eng-Student";
char* password = "3nG5tuDt";
const char* mqtt_server = "10.30.15.0";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

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
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Subscribe
      //client.subscribe("esp32/output");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void setup() {
  // put your setup code here, to run once:
  pin_setup();
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  //client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  get_count();

  publish_to_broker(0, 0, vehicle_count[0]);
  publish_to_broker(0, 1, vehicle_count[2]);
  Serial.println("Published");
  Serial.printf("lane_0 = %d, lane_1 = %d\n", vehicle_count[0], vehicle_count[2]);


}

void publish_to_broker(int road_number, int lane_number, int count) {
  //  char message[30] = "road_" + String(road_number) + "/" + "lane_" + String(lane_number);
  //  client.publish(message, String(count));

  char msg[20];
  sprintf(msg, "road_%d/lane_%d", road_number, lane_number);
  char c[20];

  String(count).toCharArray(c, 20);
  client.publish(msg, c);
  delay(100);
}
