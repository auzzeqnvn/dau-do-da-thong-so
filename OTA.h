
#ifndef STASSID
#define STASSID "phong dien"
#define STAPSK  "trungtamdien"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;




void pr(String th)
{
 display.fillRect(0,12,125,40,BLACK); // WHITE BLACK  
 display.setTextColor(WHITE);
 display.setCursor(30,12);
 display.setTextSize(3);   
 display.println(th);    
 display.display();   
} 
void OTA_run(void)
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);  
  display.setCursor(5,0);
  display.print("Wifi Program Update");  
  display.display();    
  pr("---");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
     pr("WIFI ER");
    delay(5000);
    ESP.restart();
  }
  //ArduinoOTA.setPort(8266);
  //ArduinoOTA.setHostname("Wifi_1");
  //ArduinoOTA.setPassword("admin");
  ArduinoOTA.onStart([]() 
  {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) 
    {
      type = "sketch";
    } else 
    { 
      type = "filesystem";
    }
    pr("StUpdt");
  }
  );
  ArduinoOTA.onEnd([]() 
  {
    pr("END");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    pr(String(progress / (total / 100)) + "%");
  });
  
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  STT_update = true;
  display.fillRect(0,12,125,40,BLACK); // WHITE BLACK  
 display.setTextColor(WHITE);
  display.setCursor(5,18);
  display.setTextSize(1);   
  display.println(WiFi.localIP());    
  display.display();   
}
