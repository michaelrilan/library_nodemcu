#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h> 
#include <WiFiClient.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
const char* ssid     = "RILAN_ZTE_2.4G";
const char* password = "Escanor_7th";

const char* serverName = "http://192.168.1.5/LIBRARY_SYSTEM/server_api.php";

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
          String httpRequestData = "barcode_find";           
          int httpResponseCode = http.POST(httpRequestData);
          String payloadGet = http.getString();
          Serial.print("HTTP Response code: ");
          Serial.println(httpResponseCode);
          Serial.print(payloadGet);
          
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("TUPC LIBRARY SYSTEM");
          lcd.setCursor(0,1);
          lcd.print("TITLE");
          lcd.setCursor(0,2);
          lcd.print(payloadGet);

          delay(5000);
          
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("TUPC LIBRARY SYSTEM");


          http.end();
        }
   
    else {
      Serial.println("WiFi Disconnected");
    }
    delay(5000);
}
