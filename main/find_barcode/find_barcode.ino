#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h> 
#include <WiFiClient.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
const char* ssid     = "Mico";
const char* password = "12345678";

const char* serverName = "http://192.168.43.25/LIBRARY_SYSTEM/server_api.php";
String message="";
void setup() {
  
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("TUPC LIBRARY SYSTEM");
  
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  

}

void ClearRow(int rowNum)
{
  lcd.setCursor(0, rowNum);
  lcd.print("                     ");
  lcd.setCursor(0,rowNum);
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
    int length1=message.length();
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
          WiFiClient client;
          HTTPClient http;      
          // Your Domain name with URL path or IP address with path
          http.begin(client, serverName);
    
          // Specify content-type header
          http.addHeader("Content-Type", "application/x-www-form-urlencoded");
          // Data to send with HTTP POST
          String httpRequestData = "barcode_find";           
          int httpResponseCode = http.POST(httpRequestData);
          String payloadGet = http.getString();
          Serial.print("HTTP Response code: ");
          Serial.println(httpResponseCode);
          Serial.print(payloadGet);
          payloadGet.trim();
          message = payloadGet;
              for(int i=0;i<length1;i++)
              {
                ClearRow(2);
                lcd.print(message.substring(i,i+20));
                delay(400);
              }
            
          
          http.end();
        }
   
    else {
      Serial.println("WiFi Disconnected");
    }
    delay(1000);
}
