#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>
#define SSID "YOUR_WIFI_PIN"
#define PASS "YOUR_WIFI_PASS"

const char* serverAddress = "YOUR_SERVER_ADDRESS";
int serverPort = 80; // Server port, 80 for HTTP and 443 for HTTPS
WiFiClient wifiClient;
HttpClient client = HttpClient(wifiClient, serverAddress, serverPort);
const int pResistor = A0;
int lista[10];
void setup() {
  Serial.begin(115200);
  pinMode(pResistor, INPUT);
	Serial.begin(9600);
  Serial.print("Connecting to ");
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED) {
    // Wait 10 seconds for connection:
    delay(10000);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected.");
}
void loop() {
  int avgSensorValue = 0;
  String sensorValues = "";
  for(int i = 0; i < 10; i++){
    int sensorValue = analogRead(pResistor);
    sensorValues += "\n"+String(sensorValue);
    avgSensorValue += sensorValue;
  }
  String postData = "sensorValue=" + String("Keskiarvo: ") + String(avgSensorValue/10) + String("\n\nKeskiarvon numerot: ") + String(sensorValues);
  client.post("/brightdata.php", "application/x-www-form-urlencoded", postData);
  int statusCode = client.responseStatusCode();
  String response = client.responseBody();
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);
  delay(1000); // Post data every 10 seconds
}
