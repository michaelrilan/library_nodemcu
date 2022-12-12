#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h> 
#include <WiFiClient.h>
#include <SoftwareSerial.h>

const int LED1 = 16;
const int LED2 = 5;
const int LED3 = 4;
const int LED4 = 0;
const int LED5 = 2;
const int LED6 = 14;
SoftwareSerial WemosSerial (D1,D2);// declaring wemos RX/TX pins;;
const char* ssid     = "Mico";
const char* password = "12345678";

const char* serverName = "http://192.168.43.25/LIBRARY_SYSTEM/server_api.php";



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
  pinMode(LED6,OUTPUT);
}

void res_find_book(){
  WiFiClient client;
          HTTPClient http;      
          // Your Domain name with URL path or IP address with path
          http.begin(client, serverName);
    
          // Specify content-type header
          http.addHeader("Content-Type", "application/x-www-form-urlencoded");
          // Data to send with HTTP POST
          String httpRequestData = "reset_find_book";
                    
          int httpResponseCode = http.POST(httpRequestData);
          http.end();
  }
  void res_bcode_find(){
  WiFiClient client;
          HTTPClient http;      
          // Your Domain name with URL path or IP address with path
          http.begin(client, serverName);
    
          // Specify content-type header
          http.addHeader("Content-Type", "application/x-www-form-urlencoded");
          // Data to send with HTTP POST
          String httpRequestData = "reset_bcode_find";
                    
          int httpResponseCode = http.POST(httpRequestData);
          http.end();
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

          
              //LEGEND:
              
            // 1= PHILOSOPHY
            // 2= HISTORY
            // 3= SOCIAL_SCIENCE
            // 4= ARTS_LITERATURE
            // 5= SCIENCE
            // 6= TECHNOLOGY
          
          if(payloadGet_int == 1){
            digitalWrite(LED1, HIGH);
            delay(20000);
            digitalWrite(LED1,LOW);
            res_find_book();
            delay(2000);
            }
          else if(payloadGet_int == 2){
            digitalWrite(LED2, HIGH);
            delay(25000);
            digitalWrite(LED2,LOW);
            res_find_book();
            delay(2000);
            res_bcode_find();
            }
          else if(payloadGet_int == 3){
            digitalWrite(LED3, HIGH);
            delay(25000);
            digitalWrite(LED3,LOW);
            res_find_book();
            delay(2000);
            res_bcode_find();
            }
          else if(payloadGet_int == 4){
            digitalWrite(LED4, HIGH);
            delay(25000);
            digitalWrite(LED4,LOW);
            res_find_book();
            delay(2000);
            res_bcode_find();
            }
          else if(payloadGet_int == 5){
            digitalWrite(LED5, HIGH);
            delay(25000);
            digitalWrite(LED5,LOW);
            res_find_book();
            delay(2000);
            res_bcode_find();
            }
          else if(payloadGet_int == 6){
            digitalWrite(LED6, HIGH);
            delay(25000);
            digitalWrite(LED6,LOW);
            res_find_book();
            delay(2000);
            res_bcode_find();
            }
          else{
            digitalWrite(LED1,LOW);
            digitalWrite(LED2,LOW);
            digitalWrite(LED3,LOW);
            digitalWrite(LED4,LOW);
            digitalWrite(LED5,LOW);
            digitalWrite(LED6,LOW);
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
