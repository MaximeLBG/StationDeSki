#include <WiFi.h>
#include <HTTPClient.h>
#include "boards.h"
#include "utilities.h"
  
const char* ssid = "wireless_cdf";
const char* password =  "1A2B3C4D5E";

IPAddress staticIP(192,168,1,50);
IPAddress gateway(192, 168, 1, 254);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 1, 254);

//Your Domain name with URL path or IP address with path
const char* serverName = "http://192.168.1.60:80/MVC/ProjetStationDeSki/step5V3/vent/new";

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;

void setup(){
  Serial.begin(115200);
 
  if (WiFi.config(staticIP, gateway, subnet, dns, dns) == false) {
    Serial.println("Configuration failed.");
  }
    
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting...\n\n");
  }
 
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("DNS 1: ");
  Serial.println(WiFi.dnsIP(0));
  Serial.print("DNS 2: ");
  Serial.println(WiFi.dnsIP(1));
}
    
void loop(){
  //Send an HTTP POST request every 10 minutes
   Serial.println("Posting JSON data to server...");
  // Block until we are able to connect to the WiFi access point
  if (WiFi.status() == WL_CONNECTED) {
     
    HTTPClient http;   
     
    http.begin("https://httpbin.org/anything");  
    http.addHeader("Content-Type", "application/json");   

    char json[] = "{\"hello\":\"world\"}";
        
    int httpResponseCode = http.POST(json);
 
    if(httpResponseCode>0){
       
      String response = http.getString();                       
       
      Serial.println(httpResponseCode);   
      Serial.println(response);
     
    }
    else {
     
      Serial.printf("Error occurred while sending HTTP POST ");
       
    }
  }
}
