long value;
Channel active_ch = CH1;
bool blocking = false,stts=false;
MCP3424 adc(PIN_FLOAT,PIN_FLOAT);







static char * errmsg[] = {"", "underflow", "overflow", "i2c", "in progress", "timeout"};

void reset_count_buff()
{
  Countlen_Setpoint= false;
  Countxuong_Setpoint= false;
  Count_Second = false;
  Start_Run = false;
  Start_Pause = false; 
  Start_Next = false;
  Stt_ON=false;
  IDS=false;
  Cnt_Run=0;
  //Int_Status =0;
  temp_Setpoint =0;
  Int_Step=0;
  CNT_backup =0;

  Stt_AP1 = -1;
  Int_AP1 =0;
  dwellTimerSecond = Time_Step =  rampRateSecond =0;
}
void update_sensor (void)
{
 range  = rampRateStep[1] - rampRateStep[0]; // MaxVal - Zerro
 thangdo = dwellTimerStep[1];
 diemgoc = rampRateStep[0];
 heso = rampRateStep[2];//loat-Int, cấp số nhân  
 time_nhaynhay1 =  temperatureStep[2];
 time_nhaynhay2 =  dwellTimerStep[2];    
 data_Alam1 = rampRateStep[3];
 data_Alam2 = temperatureStep[3];   
 saiso = diemgoc - temperatureStep[1];
 if(saiso < 0) saiso =0; 
 //
           
}

void Update_Menu(void)
{
  back_diplay = true;
  clearDisplay();
  Stt_AP1 =-1;
  Stt_AP2=-1;
  Stt_PV1 =-1;
  Stt_PV2=-1;
  Stt_SV =-1;
  Stt_Step=-1;
  Stt_Status= -1;
  a=-1;
  b=-1;
}

void canh_bao (void)
{ 
  if (dustDensity_pirnt >= data_Alam2) Buzzer_keu = 2;
  else if (dustDensity_pirnt >= data_Alam1) Buzzer_keu = 1; 
  else Buzzer_keu =0; 

  if (Buzzer_keu == 1) 
  {
    if (coi > time_nhaynhay1)
    {
      toggle ^= 1;  
      digitalWrite(ledPower,toggle); // kêu liên tục 
      coi=0;
    } 
  }
  else if (Buzzer_keu == 2) 
  {
    digitalWrite(ledPower,HIGH); // kêu liên tục
    coi =0;
  }
  else 
  {
    coi =0;
    toggle =0;
    digitalWrite(ledPower,LOW); // kêu liên tục
  }
}

void read_giatri(int kenh,boolean dos)
{
  if(kenh == 0) active_ch = CH1;
  else if(kenh == 1) active_ch = CH2;
  else if(kenh == 2) active_ch = CH3;
  else if(kenh == 3) active_ch = CH4;
  if(dos == true)
  {
    adc.startNewConversion(active_ch);  
    Serial.print("Start read:");
    Serial.println(active_ch, DEC);
  }
  else
  {
    ConvStatus error = adc.nb_read(active_ch,value);
    if (error == R_OK || error == R_OVERFLOW || error == R_UNDERFLOW) 
    {
      if (error != R_OK) 
      {
          Serial.print("error: ");
          Serial.println(error, DEC);
      } 
      else 
      {
          Serial.print("CH");
          Serial.print(active_ch, DEC);
          Serial.print(": ");
          Serial.println(value, DEC);
          dustDensity_pirnt = value;
      }     
    } 
  }
}
void Read_AMP(void) 
{    
  if( (unsigned long) (millis() - time11) > 1000)
  {  
    coi++;    
    if(Int_Status > 3) Int_Status =0;
    else 
    {
      if(stts == false )
      {
        read_giatri(Int_Status,true); // bắt đầu đo
        stts = true;
      }
      else
      {
        read_giatri(Int_Status,false); // bắt đầu đo
        stts = false;
        Int_Status++;
      }
    }
      
    //if(voMeasured > saiso &&  voMeasured <= diemgoc )
    //{
    //  voMeasured = diemgoc;
    // }
    // if(range ==0 ) range =1;
    // h = (voMeasured - diemgoc) * thangdo;
    // dustDensity_pirnt =  (h * heso)/range ;
    time11 = millis();
  }
}
void Setup_Diplay(void)
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(1);
  display.clearDisplay();
  display.display();
}
void Setup_Ampe(void)
{
  //pinMode(ANL1, INPUT_ANALOG);
}
void Setup_IO (void)
{
  pinMode(ENTER, INPUT_PULLUP); // SET
  pinMode(TANG, INPUT_PULLUP);  // <<
  pinMode(GIAM, INPUT_PULLUP);  // >>
  pinMode(ledPower,OUTPUT);
  digitalWrite(ledPower,HIGH);
  delay(1000);
  digitalWrite(ledPower,LOW);
}

void Print_Diplay_Menu (void)
{
  if(Stt_Status != Int_Status)
  {
    display.setTextSize(1);
    display.fillRect(0,0,120,8,BLACK); // WHITE BLACK
    display.setTextColor(WHITE);
    display.setCursor(25,0);
    if(Int_Status ==1)
    {
      display.print("CO-AF (CO)");
    }
    else if(Int_Status ==2)
    {
      display.print("Oxygen (02)");  
    }
    else if(Int_Status ==3)
    {
      display.print("Hidro (H2)");  
    }
    else if(Int_Status ==0)
    {
      display.print("Methane (CH4)");
    }
    else 
    {
      display.print(WiFi.localIP());             
    }
    display.fillRect(0,12,125,40,BLACK); // WHITE BLACK
    display.setCursor(20,12);
    display.setTextSize(3);

    if(Int_Status ==0) // ch4 
    {
      float ht = dustDensity_pirnt1 /100.0;
      display.print(ht,2);
      display.setTextSize(1);
      display.println(" %");
      display.display();
    }
    else if(Int_Status ==1) // C0 
    {
      display.print(dustDensity_pirnt2,DEC);
      display.setTextSize(1);
      display.println(" ppm");
      display.display();
    }
    else if(Int_Status ==2) // O2 
    {
      float ht = dustDensity_pirnt3 /10.0;
      display.print(ht,1);
      display.setTextSize(1);
      display.println(" %");
      display.display();
    }
    else if(Int_Status ==3) // H2 
    {
      display.print(dustDensity_pirnt4,DEC);
      display.setTextSize(1);
      display.println(" ppm");
      display.display();
    }
    else if(Int_Status ==4) // H2 
    {
      if(WiFi.status() != WL_CONNECTED)
      {
        display.print("Fault");
      }
      else
      {
        display.print("Success");
      }
      display.display();
    }

    display.display();

    Stt_Status = Int_Status; 
  }
}

void run_Menu(void)
{
  if(digitalRead(ENTER) == HIGH && Start_Setup == false ) 
  {
    if(Cnt_B5T < 35000 && Start_pag == true) 
    {
      if( Cnt_B5T == 32500)
      {
        Start_Setup = true;  
      }
      Cnt_B5T ++;
    }
    else
    {
      Cnt_B5T = 32600;
    }
  }
  else
  {
    Start_pag = true; 
    Cnt_B5T = 0;
  }
   
  if(Start_Setup == true)// nếu cờ cài đặt được kích hoạt
  {
    Run_Main_Menu(); // hiển thị chương trình cài đặt
    rampRateStep[4] = voMeasured;
    temperatureStep[4] = calcVoltage * 1000;
    dwellTimerStep[4] = dustDensity_pirnt* 10;
    update_sensor();
  }
  else // vào màn hình chính
  {
    Print_Diplay_Menu();
  }
  canh_bao();  
}
