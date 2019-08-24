void loadProfile()
{
 delay(1);
   rampRateStep[0] = EEPROM.read(0)*256 +  EEPROM.read(1) ;
 delay(1);
   rampRateStep[1] = EEPROM.read(2)*256 + EEPROM.read(3);
 delay(1); 
   rampRateStep[2] = EEPROM.read(4)*256 + EEPROM.read(5);
   delay(1);
   rampRateStep[3] = EEPROM.read(8)*256 + EEPROM.read(9);
  delay(1);
  
  dwellTimerStep[0] = EEPROM.read(12)*256 + EEPROM.read(13);
 delay(1);
  dwellTimerStep[1] = EEPROM.read(14)*256 + EEPROM.read(15);
  delay(1);
  dwellTimerStep[2] = EEPROM.read(16)*256 + EEPROM.read(17);
  delay(1);
  dwellTimerStep[3] = EEPROM.read(18)*256 + EEPROM.read(19);
  delay(1);
  
  temperatureStep[0] = EEPROM.read(22)*256 + EEPROM.read(23);
  delay(1);
  temperatureStep[1] = EEPROM.read(24)*256 + EEPROM.read(25);
  delay(1);
  temperatureStep[2] = EEPROM.read(26)*256 + EEPROM.read(27);
  delay(1);
  temperatureStep[3] = EEPROM.read(28)*256 + EEPROM.read(29);
  delay(1);

  Addr_485 =  1; //EEPROM.read(32);
  delay(1);
  selectedLanguage = 1; //EEPROM.read(34);
  delay(1);
  contrast= 0;// EEPROM.read(36);
  delay(1);
  Val_Kp = EEPROM.read(38);
  delay(1);
  Val_Ki = EEPROM.read(40);
  delay(1);
  Val_Kd = EEPROM.read(42);
  if(Addr_485 > 254 && contrast  > 254 && selectedLanguage > 254)
  {
    for(int i =0;i<50;i++)
    {
    EEPROM.write(i,0);
    delay(10);
    }
    EEPROM.commit();
    Serial.println ("reload");
    delay(1000);
    ESP.restart();///
   }
}
void WriteProfile ()
{
 EEPROM.write(0,rampRateStep[0]/256);
 delay(1);
 EEPROM.write(1,rampRateStep[0]%256);
 delay(1);
 EEPROM.write(2,rampRateStep[1]/256);
 delay(1);
 EEPROM.write(3,rampRateStep[1]%256);
 delay(1);
 EEPROM.write(4,rampRateStep[2]/256);
 delay(1);
 EEPROM.write(5,rampRateStep[2]%256);
 delay(1);
 EEPROM.write(8,rampRateStep[3]/256);
 delay(1);
 EEPROM.write(9,rampRateStep[3]%256);
 delay(1);
 
 EEPROM.write(12,dwellTimerStep[0]/256);
 delay(1);
 EEPROM.write(13,dwellTimerStep[0]%256);
 delay(1);
 EEPROM.write(14,dwellTimerStep[1]/256);
 delay(1);
 EEPROM.write(15,dwellTimerStep[1]%256);
 delay(1);
 EEPROM.write(16,dwellTimerStep[2]/256);
 delay(1);
 EEPROM.write(17,dwellTimerStep[2]%256);
 delay(1);
 EEPROM.write(18,dwellTimerStep[3]/256);
 delay(1);
 EEPROM.write(19,dwellTimerStep[3]%256);
 delay(1);
 
 EEPROM.write(22,temperatureStep[0]/256);
 delay(1);
 EEPROM.write(23,temperatureStep[0]%256);
 delay(1);
 EEPROM.write(24,temperatureStep[1]/256);
 delay(1);
 EEPROM.write(25,temperatureStep[1]%256);
 delay(1);
 EEPROM.write(26,temperatureStep[2]/256);
 delay(1);
 EEPROM.write(27,temperatureStep[2]%256);
 delay(1);
 EEPROM.write(28,temperatureStep[3]/256);
 delay(1);
 EEPROM.write(29,temperatureStep[3]%256);
 delay(1);
 

 EEPROM.write(32, Addr_485);  // địa chỉ truyền
 delay(1);
 EEPROM.write(34,selectedLanguage); // tốc độ truyền
 delay(1);
 EEPROM.write(36,contrast);  // chọn loại đầu đo gì
  delay(1);
 EEPROM.write(38,Val_Kp);    // tham số chưa cần thiết
  delay(1);
 EEPROM.write(40,Val_Ki);    // tham số chưa cần thiết
  delay(1);
 EEPROM.write(42,Val_Kd);    // tham số chưa cần thiết
 delay(10);
 EEPROM.commit();
}
void epprom_setup (void)
  { 
  EEPROM.begin(512);
  loadProfile();    
  }
