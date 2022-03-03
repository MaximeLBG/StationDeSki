#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "boards.h"
#include "utilities.h"
  
const char* ssid = "wireless_cdf";
const char* password =  "1A2B3C4D5E";

IPAddress staticIP(192,168,1,50);
IPAddress gateway(192, 168, 1, 254);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 1, 254);

//Your Domain name with URL path or IP address with path
const char* serverName = "http://192.168.1.110/step5V3/vent/new";

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

    LoRa.setPins(RADIO_CS_PIN, RADIO_RST_PIN, RADIO_DI0_PIN);
    if (!LoRa.begin(LoRa_frequency)) {
        Serial.println("Starting LoRa failed!");
        while (1);
    }
}
    
void loop(){
  float temp = 20.4;
  float dirvent = 142.2;
  float vitesse = 10.4;
  float idCapteur = 1;
  String output="";

        StaticJsonDocument<96> doc;
    
        doc["idCapteur"] = idCapteur;
        doc["vitesse"] = vitesse;
        doc["dirvent"] = dirvent;
        doc["temp"] = temp;
        
        serializeJson(doc, output);
        
if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
  
   HTTPClient http;   

   Serial.println(output);
  
   http.begin(serverName);  //Specify destination for HTTP request
   http.addHeader("Content-Type", "text/plain");             //Specify content-type header
  
   int httpResponseCode = http.POST(output);   //Send the actual POST request
  
   if(httpResponseCode>0){
  
    String response = http.getString();                       //Get the response to the request
  
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
  
   }else{
  
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
  
   }
  
   http.end();  //Free resources
  
 }else{
  
    Serial.println("Error in WiFi connection");   
  
 }
  
  delay(10000);  //Send a request every 10 seconds
}
