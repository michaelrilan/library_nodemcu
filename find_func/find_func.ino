#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h> 
#include <WiFiClient.h>
#include <SoftwareSerial.h>

const int LED1 = 16;
const int LED2 = 5;
const int LED3 = 4;
const int LED4 = 0;
const int LED5 = 2;

SoftwareSerial WemosSerial (D1,D2);// declaring wemos RX/TX pins;;
const char* ssid     = "RILAN_ZTE_2.4G";
const char* password = "Escanor_7th";

const char* serverName = "http://192.168.1.2/LIBRARY_SYSTEM/server_api.php";

void setup() {

  
  Serial.begin(115200);
  WemosSerial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
}

void loop() {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
          WiFiClient client;
          HTTPClient http;      
          // Your Domain name with URL path or IP address with path
          http.begin(client, serverName);
    
          // Specify content-type header
          http.addHeader("Content-Type", "application/x-www-form-urlencoded");
          // Data to send with HTTP POST
          String httpRequestData = "led_find";           
          int httpResponseCode = http.POST(httpRequestData);
          String payloadGet = http.getString();
          Serial.print("HTTP Response code: ");
          Serial.println(httpResponseCode);
          Serial.print(payloadGet);
          int payloadGet_int = payloadGet.toInt();
          if(payloadGet_int >=0 && payloadGet_int <= 1000){
            digitalWrite(LED1, HIGH);
            delay(20000);
            digitalWrite(LED1,LOW);
            }
          else if(payloadGet_int >=1001 && payloadGet_int <= 2000){
            digitalWrite(LED2, HIGH);
            delay(20000);
            digitalWrite(LED2,LOW);
            }
          else if(payloadGet_int >=2001 && payloadGet_int <= 3000){
            digitalWrite(LED3, HIGH);
            delay(20000);
            digitalWrite(LED3,LOW);
            }
          else if(payloadGet_int >=3001 && payloadGet_int <= 4000){
            digitalWrite(LED4, HIGH);
            delay(20000);
            digitalWrite(LED4,LOW);
            }
          else if(payloadGet_int >= 4001 && payloadGet_int <= 5000){
            digitalWrite(LED5, HIGH);
            delay(20000);
            digitalWrite(LED5,LOW);
            }
          
    //      
    //      // Free resources
          http.end();
        }
    

    else {
      Serial.println("WiFi Disconnected");
    }
    delay(1000);
}

//      WiFiClient client;
//      HTTPClient http;
//      
//      // Your Domain name with URL path or IP address with path
//      http.begin(client, serverName);
//
//      // Specify content-type header
//      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
//      // Data to send with HTTP POST
//      String httpRequestData = "command";           
//      // Send HTTP POST request
//      int httpResponseCode = http.POST(httpRequestData);
//     String payloadGet = http.getString();
//      Serial.print("HTTP Response code: ");
//      Serial.println(httpResponseCode);
//      Serial.print(payloadGet);
//      
//      // Free resources
//      http.end();
