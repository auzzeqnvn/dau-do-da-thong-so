/*
 * Fimr GP2 wifi
 * coder : Phạm Duy Thiệu
 * 
 */

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "ModbusIP_ESP8266.h" 
#include <EEPROM.h>
#include <Wire.h>
#include "Adafruit_SSD1306.h"
#include "khaibao.h"
#include "Eprom.h"
Adafruit_SSD1306 display(100);
#include "menu.h" 
#include "rs485.h"
#include "MCP3424.h"
#include "phu.h"
#include "check_sensor.h"
#include "OTA.h"


ModbusIP mb;



               
void setup() 
{
  Serial.begin(9600);
  pinMode(16, OUTPUT);
  digitalWrite(16,LOW);
  Setup_IO();
  Setup_Diplay();
  epprom_setup();
  update_sensor();
  Setup_Ampe();
  update_sensor();
  cauhinh_truyenthong(Addr_485,selectedLanguage);
  check_sensor(contrast);  
  adc.generalCall(GC_RESET);
  adc.creg[CH1].bits = { GAINx1, SR18B, ONE_SHOT, CH1, 1 };
  adc.creg[CH2].bits = { GAINx1, SR18B, ONE_SHOT, CH2, 1 };
  adc.creg[CH3].bits = { GAINx1, SR18B, ONE_SHOT, CH3, 1 };
  adc.creg[CH4].bits = { GAINx1, SR18B, ONE_SHOT, CH4, 1 };
  
  if(digitalRead(ENTER) == HIGH )
  {
    OTA_run(); 
  }
  else 
  {
    WiFi.disconnect();
    mb.config("phong dien", "trungtamdien");
    while (WiFi.status() != WL_CONNECTED) 
    {
      display.clearDisplay();
      display.setTextColor(WHITE);
      display.setTextSize(1);  
      display.setCursor(10,0);
      display.display();    
      display.print("Start Wifi Connect");  
      display.setTextColor(WHITE);
      display.setCursor(0,12);
      display.setTextSize(3);   
      display.println("Connect");    
      display.display();    
      delay(500);
    }
    for(int k=0;k<30;k++)
    {
      mb.addHreg(k,k+30);
    }  
  }  
}



void loop() 
{ 
  if(STT_update == true)
  {
    ArduinoOTA.handle();
  }
  else 
  {
    mb.Hreg(0,dustDensity_pirnt1);
    mb.Hreg(1,dustDensity_pirnt2);
    mb.Hreg(2,dustDensity_pirnt3);
    mb.Hreg(3,dustDensity_pirnt4);
    mb.task();
    run_Menu();
    Read_AMP();  
  }
}
