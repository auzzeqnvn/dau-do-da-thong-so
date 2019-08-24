//Adafruit_SSD1306 display(OLED_RESET);
void drawMenu();
void readRotaryEncoder();
void clearDisplay();
void displayIntMenuPage(String menuItem, int value);
void displayMenuItem (String item, int position, boolean selected);
void displayStringMenuPage(String menuItem, String value);
void Update_Menu_1(void)
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
void Run_Main_Menu(void)
   {
    drawMenu();
  readRotaryEncoder();
  if (up && page == 1 ) { 
    up = false;
    up_x2 = false;
    if(menuitem==2 && frame ==2)
    {
       frame--;
    }

     if(menuitem==4 && frame ==4)
    {
      frame--;
    }
      if(menuitem==3 && frame ==3)
    {
      frame--;
    }
    lastMenuItem = menuitem;
    menuitem--;
    if (menuitem==0)
    {
      menuitem=1;
    } 
  }
  else if (up && page == 2 && menuitem==1 ) {
    up = false;
    up_x2 = false;
    contrast++;
  }
  else if (up && page == 2 && menuitem==2 ) {
    up = false;
    if(up_x2){up_x2 = false; Val_Kp =  Val_Kp+10;}
      else Val_Kp++;
   
  }
  else if (up && page == 3 && menuitem==2 ) {
    up = false;
   if(up_x2){up_x2 = false; Val_Ki =  Val_Ki+10;}
      else Val_Ki++;
  }
  else if (up && page == 4 && menuitem==2 ) {
    up = false;
    
   if(up_x2){up_x2 = false; Val_Kd =  Val_Kd+10;}
      else Val_Kd++;
  }
  else if (up && page == 2 && menuitem==3 ) {
    up = false;
    up_x2 = false;
    selectedLanguage++;
    if(selectedLanguage >2)
    {
      selectedLanguage = 0;
    }
  }
  else if (up && page == 3 && menuitem==3 ) {
    up = false;
    up_x2 = false;
    Addr_485++;
    if(Addr_485 > 20)
    {
      Addr_485 = 0;
    }
  }
  else if (up && page <= 4 && menuitem==4 ) 
          {
           if (up && page == 2 && menuitem==4 ) {  // R1
            up = false;
            if(up_x2){up_x2 = false; rampRateStep[0] = rampRateStep[0]+10;}
            else rampRateStep[0]++;
            if(rampRateStep[0] >5000)
            {
              rampRateStep[0] = 0;
            }
          }
          else if (up && page == 3 && menuitem==4 ) { // T1
            up = false;
             if(up_x2){up_x2 = false; temperatureStep[0] = temperatureStep[0]+10;}
             else temperatureStep[0]++;
            if(temperatureStep[0] > 800)
            {
              temperatureStep[0] = 0;
            }
          }
          else if (up && page == 4 && menuitem==4 ) { // D1
           up = false;
           if(up_x2){up_x2 = false; dwellTimerStep[0] = dwellTimerStep[0]+10;}
            else dwellTimerStep[0]++;
            
            if(dwellTimerStep[0] >5000)
            {
              dwellTimerStep[0] = 0;
            }
          }
           } // end STEP 1
  else if (up && page <= 7 && menuitem==4 ) 
          {
           if (up && page == 5 && menuitem==4 ) {  // R2
            up = false;
           if(up_x2){up_x2 = false; rampRateStep[1] = rampRateStep[1]+10;}
            else rampRateStep[1]++;
            if(rampRateStep[1] >5000)
            {
              rampRateStep[1] = 0;
            }
          }
          else if (up && page == 6 && menuitem==4 ) { // T2
            up = false;
            if(up_x2){up_x2 = false; temperatureStep[1] = temperatureStep[1]+10;}
            else temperatureStep[1]++;
          
            if(temperatureStep[1] > 800)
            {
              temperatureStep[1] = 0;
            }
          }
          else if (up && page == 7 && menuitem==4 ) { // D2
            up = false;
            if(up_x2){up_x2 = false; dwellTimerStep[1] = dwellTimerStep[1]+10;}
            else dwellTimerStep[1]++;
            
            if(dwellTimerStep[1] >5000)
            {
              dwellTimerStep[1] = 0;
            }
          }
         } // end STEP 2
  else if (up && page <= 10 && menuitem==4 ) 
          {
           if (up && page == 8 && menuitem==4 ) {  // R3
            up = false;
            if(up_x2){up_x2 = false; rampRateStep[2] = rampRateStep[2]+10;}
            else rampRateStep[2]++;
            if(rampRateStep[2] >5000)
            {
              rampRateStep[2] = 0;
            }
          }
          else if (up && page == 9 && menuitem==4 ) { // T3
            up = false;
           if(up_x2){up_x2 = false; temperatureStep[2] = temperatureStep[2]+10;}
            else temperatureStep[2]++;
          
            if(temperatureStep[2] > 800)
            {
              temperatureStep[2] = 0;
            }
          }
          else if (up && page == 10 && menuitem==4 ) { // D3
            up = false;
            if(up_x2){up_x2 = false; dwellTimerStep[2] = dwellTimerStep[2]+10;}
            else dwellTimerStep[2]++;
            
            if(dwellTimerStep[2] >5000)
            {
              dwellTimerStep[2] = 0;
            }
          }
         } // end STEP 1
  else if (up && page <= 13 && menuitem==4 ) 
          {
           if (up && page == 11 && menuitem==4 ) {  // R4
            up = false;
            if(up_x2){up_x2 = false; rampRateStep[3] = rampRateStep[3]+10;}
            else rampRateStep[3]++;
            if(rampRateStep[3] >5000)
            {
              rampRateStep[3] = 0;
            }
          }
          else if (up && page == 12 && menuitem==4 ) { // T4
            up = false;
            if(up_x2){up_x2 = false; temperatureStep[3] = temperatureStep[3]+10;}
            else temperatureStep[3]++;
          
            if(temperatureStep[3] > 800)
            {
              temperatureStep[3] = 0;
            }
          }
          else if (up && page == 13 && menuitem==4 ) { // D4
            up = false;
            if(up_x2){up_x2 = false; dwellTimerStep[3] = dwellTimerStep[3]+10;}
            else dwellTimerStep[3]++;
            
            if(dwellTimerStep[3] >5000)
            {
              dwellTimerStep[3] = 0;
            }
          }
         } // end STEP 4
  else if (up && page <= 16 && menuitem==4 ) 
          {
           
           if (up && page == 14 && menuitem==4 ) {  // R5
            up = false;
            if(up_x2){up_x2 = false; }//rampRateStep[4] = rampRateStep[4]+10;}
            //else rampRateStep[4]++;
            if(rampRateStep[4] >5000)
            {
             // rampRateStep[4] = 0;
            }
           
          }
          else if (up && page == 15 && menuitem==4 ) { // T5
            up = false;
            if(up_x2){up_x2 = false; }//temperatureStep[4] = temperatureStep[4]+10;}
           // else temperatureStep[4]++;
          
            if(temperatureStep[4] > 800)
            {
            //  temperatureStep[4] = 0;
            }
          }
          else if (up && page == 16 && menuitem==4 ) { // D5
            up = false;
           if(up_x2){up_x2 = false; }//dwellTimerStep[4] = dwellTimerStep[4]+10;}
            else dwellTimerStep[4]++;
            
            if(dwellTimerStep[4] >5000)
            {
             // dwellTimerStep[4] = 0;
            }
          }
         } // end STEP 1
  else if (up && page == 2 && menuitem==6 ) { // T5
            up = false;
            if(up_x2){up_x2 = false; Val_Lock = Val_Lock+10;}
            else Val_Lock++;
            if(Val_Lock > 5000)
            {
              Val_Lock = 0;
            }
          }
          else if (up && page == 3 && menuitem==6 ) { // D5
            up = false;
           
            if(up_x2){up_x2 = false; Val_Reset = Val_Reset+10;}
            else Val_Reset++;
            if(Val_Reset > 5000)
            {
              Val_Reset = 0;
            }
          }
  if (down && page == 1) //We have turned the Rotary Encoder Clockwise
  {

    down = false;
    down_x2 = false;
    if(menuitem==3 && lastMenuItem == 2)
    {
      frame ++;
    }else  if(menuitem==4 && lastMenuItem == 3)
    {
      frame ++;
    }
     else  if(menuitem==5 && lastMenuItem == 4 && frame!=4)
    {
      frame ++;
    }
    lastMenuItem = menuitem;
    menuitem++;  
    if (menuitem==7) 
    {
      menuitem--;
    }
  
  }
  
  else if (down && page == 2 && menuitem==1) {
    down = false;
    down_x2 = false;
    contrast--;
  }
  else if (down && page == 2 && menuitem==2) {
    down = false;
    if(down_x2){down_x2 = false; Val_Kp =  Val_Kp-10;}
    else Val_Kp--;
  }
   else if (down && page == 3 && menuitem==2) {
    down = false;
   if(down_x2){down_x2 = false; Val_Ki =  Val_Ki-10;}
      else Val_Ki--;
  }
   else if (down && page == 4 && menuitem==2) {
    down = false;
    if(down_x2){down_x2 = false; Val_Kd =  Val_Kd-10;}
      else Val_Kd--;
  }
  else if (down && page == 2 && menuitem==3 ) {
    down = false;
    down_x2 = false;
    selectedLanguage--;
    if(selectedLanguage <0)
    {
      selectedLanguage = 2;
    }
  }
  else if (down && page == 3 && menuitem==3 ) {
    down = false;
    down_x2 = false;
    Addr_485--;
    if(Addr_485 < 0)
    {
      Addr_485 = 20;
    }
  }
  else if (down && page <= 4 && menuitem==4 ) 
          {
           if (down && page == 2 && menuitem==4 ) {  // R1
            down = false;
            if(down_x2){down_x2 = false; rampRateStep[0] = rampRateStep[0]-10;}
            else rampRateStep[0]--;
            if(rampRateStep[0] < 0)
            {
              rampRateStep[0] = 5000;
            }
          }
          else if (down && page == 3 && menuitem==4 ) { // T1
            down = false;
            if(down_x2){down_x2 = false; temperatureStep[0] = temperatureStep[0]-10;}
            else temperatureStep[0]--;
          
            if(temperatureStep[0] < 0)
            {
              temperatureStep[0] = 800;
            }
          }
          else if (down && page == 4 && menuitem==4 ) { // D1
            down = false;
            if(down_x2){down_x2 = false; dwellTimerStep[0] = dwellTimerStep[0]-10;}
            else dwellTimerStep[0]--;
            
            if(dwellTimerStep[0] < 0)
            {
              dwellTimerStep[0] = 5000;
            }
          }
         } // end STEP 1
  else if (down && page <= 7 && menuitem==4 ) 
          {
           if (down && page == 5 && menuitem==4 ) {  // R2
            down = false;
             if(down_x2){down_x2 = false; rampRateStep[1] = rampRateStep[1]-10;}
            else rampRateStep[1]--;
            if(rampRateStep[1] < 0)
            {
              rampRateStep[1] = 5000;
            }
          }
          else if (down && page == 6 && menuitem==4 ) { // T2
            down = false;
           if(down_x2){down_x2 = false; temperatureStep[1] = temperatureStep[1]-10;}
            else temperatureStep[1]--;
          
            if(temperatureStep[1] < 0)
            {
              temperatureStep[1] = 800;
            }
          }
          else if (down && page == 7 && menuitem==4 ) { // D2
            down = false;
            if(down_x2){down_x2 = false; dwellTimerStep[1] = dwellTimerStep[1]-10;}
            else dwellTimerStep[1]--;
            
            if(dwellTimerStep[1] < 0)
            {
              dwellTimerStep[1] = 5000;
            }
          }
         } // end STEP 2
  else if (down && page <= 10 && menuitem==4 ) 
          {
           if (down && page == 8 && menuitem==4 ) {  // R3
            down = false;
             if(down_x2){down_x2 = false; rampRateStep[2] = rampRateStep[2]-10;}
            else rampRateStep[2]--;
            if(rampRateStep[2] < 0)
            {
              rampRateStep[2] = 5000;
            }
          }
          else if (down && page == 9 && menuitem==4 ) { // T3
            down = false;
            if(down_x2){down_x2 = false; temperatureStep[2] = temperatureStep[2]-10;}
            else temperatureStep[2]--;
          
            if(temperatureStep[2] < 0)
            {
              temperatureStep[2] = 800;
            }
          }
          else if (down && page == 10 && menuitem==4 ) { // D3
            down = false;
            if(down_x2){down_x2 = false; dwellTimerStep[2] = dwellTimerStep[2]-10;}
            else dwellTimerStep[2]--;
            
            if(dwellTimerStep[2] < 0)
            {
              dwellTimerStep[2] = 5000;
            }
          }
         } // end STEP 1
  else if (down && page <= 13 && menuitem==4 ) 
          {
           if (down && page == 11 && menuitem==4 ) {  // R4
            down = false;
             if(down_x2){down_x2 = false; rampRateStep[3] = rampRateStep[3]-10;}
            else rampRateStep[3]--;
            if(rampRateStep[3] < 0)
            {
              rampRateStep[3] = 5000;
            }
          }
          else if (down && page == 12 && menuitem==4 ) { // T4
            down = false;
            if(down_x2){down_x2 = false; temperatureStep[3] = temperatureStep[3]-10;}
            else temperatureStep[3]--;
          
            if(temperatureStep[3] < 0)
            {
              temperatureStep[3] = 800;
            }
          }
          else if (down && page == 13 && menuitem==4 ) { // D4
            down = false;
            if(down_x2){down_x2 = false; dwellTimerStep[3] = dwellTimerStep[3]-10;}
            else dwellTimerStep[3]--;
            
            if(dwellTimerStep[3] < 0)
            {
              dwellTimerStep[3] = 5000;
            }
          }
         } // end STEP 4
  else if (down && page <= 16 && menuitem==4 ) 
          {
           if (down && page == 14 && menuitem==4 ) {  // R5
            down = false;
            if(down_x2){down_x2 = false; }//rampRateStep[4] = rampRateStep[4]-10;}
            //else rampRateStep[4]--;
            if(rampRateStep[4] < 0)
            {
              //rampRateStep[4] = 5000;
            }
          }
          else if (down && page == 15 && menuitem==4 ) { // T5
            down = false;
            if(down_x2){down_x2 = false; }//temperatureStep[4] = temperatureStep[4]-10;}
            //else temperatureStep[4]--;
          
            if(temperatureStep[4] < 0)
            {
             // temperatureStep[4] = 800;
            }
          }
          else if (down && page == 16 && menuitem==4 ) { // D5
            down = false;
           if(down_x2){down_x2 = false; }//dwellTimerStep[4] = dwellTimerStep[4]-10;}
            //else dwellTimerStep[4]--;
            
            if(dwellTimerStep[4] < 0)
            {
              //dwellTimerStep[4] = 5000;
            }
          }
          
         } // end STEP 1
  else if (down && page == 2 && menuitem==6 ) { // D5
            down = false;
            if(down_x2){down_x2 = false; Val_Lock = Val_Lock-10;}
            else Val_Lock--;
            if(Val_Lock < 0)
            {
              Val_Lock = 5000;
            }
          }
  else if (down && page == 3 && menuitem==6 ) { // D5
            down = false;
           
            if(down_x2){down_x2 = false; Val_Reset = Val_Reset-10;}
            else Val_Reset--;
            if(Val_Reset < 0)
            {
              Val_Reset = 5000;
            }
          }
  if (middle) //Middle Button is Pressed
  {
    middle = false;
    if(Val_Reset == Pass_Reset)
     {
      Val_Reset =0;
      WriteProfile();
      display.clearDisplay();
      display.setCursor(0,12);
      display.setTextSize(3);
      display.print("Reset.");
      display.display();
      delay(1000);
      display.print(".");
      display.display();
      delay(1000); 
      ESP.restart();//nvic_sys_reset();
     }
    else if (Val_Reset == Pass_Exit)
     {
      Serial.println("xinchao");
      Start_Setup = false;
      Start_pag = false; 
      Val_Reset = 0;
      Update_Menu_1();
     }
    if (page == 1 && menuitem==5 && Val_Lock == Pass_Lock) // Backlight Control 
    {
      if (backlight) 
      {
        
        if(Start_Run == false)
                        {
                        }
       }
      else 
      {
        
       if(Start_Run == false)
                        {
                        }
       }
    }
    else if (page == 1 && ( menuitem<4) && Val_Lock == Pass_Lock ) {
      page=2;
      clearDisplay();
    }
    else if(page == 1 && ( menuitem== 4 || menuitem== 6) ) {
      page=2;
      clearDisplay();
    }
    else if (page == 2 && menuitem==2) {
      page=3;
    }
    else if (page == 3 && menuitem==2) {
      page=4;
    }
    //
     else if (page == 2 && menuitem==3) {
      page=3;
    }
     else if (page == 3 && menuitem==3) {
      page=1;
      a=-1;
      b=-1;
    }
    // SÉT NHIỆT R1 L1 D1
   else if (page == 2 && menuitem==4) {
      page=3;
    }
     else if (page == 3 && menuitem==4) {
      page=4;
    }
     else if (page == 4 && menuitem==4) {
      page=5;
    }
    // R2 L2 D2
     else if (page == 5 && menuitem==4) {
      page=6;
    }
     else if (page == 6 && menuitem==4) {
      page=7;
    }
     else if (page == 7 && menuitem==4) {
      page=8;
    }
    // R3 L3 D3
     else if (page == 8 && menuitem==4) {
      page=9;
    }
     else if (page == 9 && menuitem==4) {
      page=10;
    }
     else if (page == 10 && menuitem==4) {
      page=11;
    }
    // R4 L5 D4
     else if (page == 11 && menuitem==4) {
      page=12;
    }
     else if (page == 12 && menuitem==4) {
      page=13;
    }
     else if (page == 13 && menuitem==4) {
      page=14;
    }
    // R5 L5 D5
     else if (page == 14 && menuitem==4) {
      page=15;
    }
     else if (page == 15 && menuitem==4) {
      page=16;
    }
     else if (page == 16 && menuitem==4) {
      page=1;
      clearDisplay();
      a=-1;
      b=-1;
    }
    //
    else if (page == 2 && menuitem==6) {
      page=3;
    }
    else if (page == 3 && menuitem==6) {
      page=1;
      clearDisplay();
      a=-1;
      b=-1;
    }
 
    else if (page == 2 || page == 3 || page == 4 || page == 17) 
    {
      page=1; 
      clearDisplay();
      a=-1;
      b=-1;
    }
   }   
   }
 
  void drawMenu()
  {  
  if (page==1) 
  { 
    if(a != page){  
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(WHITE,BLACK);
    display.setCursor(40, 0);
    display.print("MAIN MENU");
    //display.drawFastHLine(0,10,83,WHITE);
    display.display();
    a= page;
    }
    if(menuitem==1 && frame ==1 && back_diplay)
    { 
      back_diplay = 0;
      displayMenuItem(menuItem1, 8,true);
      displayMenuItem(menuItem2, 17,false);
      displayMenuItem(menuItem3, 25,false);
    }
    else if(menuitem == 2 && frame == 1 && back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem1, 8,false);
      displayMenuItem(menuItem2, 17,true);
      displayMenuItem(menuItem3, 25,false);
    }
    else if(menuitem == 3 && frame == 1&& back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem1, 8,false);
      displayMenuItem(menuItem2, 17,false);
      displayMenuItem(menuItem3, 25,true);
    }
     else if(menuitem == 4 && frame == 2&& back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem2, 8,false);
      displayMenuItem(menuItem3, 17,false);
      displayMenuItem(menuItem4, 25,true);
    }

      else if(menuitem == 3 && frame == 2&& back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem2, 8,false);
      displayMenuItem(menuItem3, 17,true);
      displayMenuItem(menuItem4, 25,false);
    }
    else if(menuitem == 2 && frame == 2&& back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem2, 8,true);
      displayMenuItem(menuItem3, 17,false);
      displayMenuItem(menuItem4, 25,false);
    }
    
    else if(menuitem == 5 && frame == 3&& back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem3, 8,false);
      displayMenuItem(menuItem4, 17,false);
      displayMenuItem(menuItem5, 25,true);
    }

    else if(menuitem == 6 && frame == 4&& back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem4, 8,false);
      displayMenuItem(menuItem5, 17,false);
      displayMenuItem(menuItem6, 25,true);
    }
    
      else if(menuitem == 5 && frame == 4&& back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem4, 8,false);
      displayMenuItem(menuItem5, 17,true);
      displayMenuItem(menuItem6, 25,false);
    }
      else if(menuitem == 4 && frame == 4&& back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem4, 8,true);
      displayMenuItem(menuItem5, 17,false);
      displayMenuItem(menuItem6, 25,false);
    }
    else if(menuitem == 3 && frame == 3&& back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem3, 8,true);
      displayMenuItem(menuItem4, 17,false);
      displayMenuItem(menuItem5, 25,false);
    }
        else if(menuitem == 2 && frame == 2&& back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem2, 8,true);
      displayMenuItem(menuItem3, 17,false);
      displayMenuItem(menuItem4, 25,false);
    }
    else if(menuitem == 4 && frame == 3&& back_diplay)
    {
      back_diplay = 0;
      displayMenuItem(menuItem3, 8,false);
      displayMenuItem(menuItem4, 17,true);
      displayMenuItem(menuItem5, 25,false);
    }   
 
  }
  else if (page==2 && menuitem == 1) 
  {
   displayIntMenuPage(menuItem1_1,contrast);
  }
  else if (page==2 && menuitem == 2) 
  {    
   displayIntMenuPage(menuItem2_Kp,Val_Kp );
  }
  else if (page==3 && menuitem == 2) 
  {    
   displayIntMenuPage(menuItem2_Ki, Val_Ki );
  }
   else if (page==4 && menuitem == 2) 
  {    
   displayIntMenuPage(menuItem2_Kd, Val_Kd );
  }
   else if (page==2 && menuitem == 3) 
  {
   displayStringMenuPage(menuItem3_1, Baud[selectedLanguage]);
  }
   else if (page==3 && menuitem == 3) 
  {
   displayIntMenuPage(menuItem3_2,Addr_485);
  }
  else if (page==2 && menuitem == 4) 
  {
    displayIntMenuPage(menuItem4_2, rampRateStep[0]);
  }
   else if (page==3 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_3,temperatureStep[0]);
  }
   else if (page==4 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_4, dwellTimerStep[0]);
  }
   else if (page==5 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_5, rampRateStep[1]);
  }
   else if (page==6 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_6, temperatureStep[1]);
  }
   else if (page==7 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_7, dwellTimerStep[1]);
  }
   else if (page==8 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_8,rampRateStep[2]);
  }
   else if (page==9 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_9,temperatureStep[2]);
  }
   else if (page==10 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_10,dwellTimerStep[2]);
  }
   else if (page==11 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_11, rampRateStep[3]);
  } else if (page==12 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_12, temperatureStep[3]);
  } else if (page==13 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_13, dwellTimerStep[3]);
  } else if (page==14 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_14,rampRateStep[4]);
   //Serial.println("dd");
  } 
  else if (page==15 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_15,temperatureStep[4]);
  } else if (page==16 && menuitem == 4) 
  {
   displayIntMenuPage(menuItem4_16,dwellTimerStep[4]);
  }
  // 
  else if (page==2 && menuitem == 6) 
  {
   displayIntMenuPage(menuItem6_1,Val_Lock);
  } else if (page==3 && menuitem == 6) 
  {
   displayIntMenuPage(menuItem6_2,Val_Reset);
  }
  }
  void setContrast()
  {
 
  }

void displayIntMenuPage(String menuItem, int value)
{
 if(b != page) {
    clearDisplay();
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(WHITE,BLACK);
    display.setCursor(35, 0);
    display.print(menuItem);
    display.drawFastHLine(0,8,127,WHITE);
    display.setCursor(5,9);
    display.print("Value");
    display.setTextSize(2);
    display.setCursor(35,18);
    display.print(value,DEC);
    display.setTextSize(2);
    display.display();
    b = page;
   }
  if(back_diplay){
    back_diplay = 0;
    display.setTextSize(1); 
    display.fillRect(35,18,50,30,BLACK);
    display.setCursor(5,9);
    display.print("Value");
    display.setTextSize(2);
    display.setCursor(35,18);
    display.print(value,DEC);
    display.setTextSize(2);
    display.display();
  }
}
void clearDisplay()
{
display.clearDisplay();
}
void displayStringMenuPage(String menuItem, String value)
{
  
  if(b != page) {
    clearDisplay();
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(WHITE,BLACK);
    display.setCursor(35, 0);
    display.print(menuItem);
    display.drawFastHLine(0,8,127,WHITE);
    display.setCursor(5,9);
    display.print("Value");
    display.setTextSize(2);
    display.setCursor(35,18);
    display.print(value);
    display.setTextSize(2);
    display.display();
    b = page;
   }
  if(back_diplay){
    back_diplay = 0;
    display.setTextSize(1); 
    display.fillRect(35,18,70,30,BLACK);
    display.setCursor(5,9);
    display.print("Value");
    display.setTextSize(2);
    display.setCursor(35,18);
    display.print(value);
    display.setTextSize(2);
    display.display();
  }
}
void displayMenuItem(String item, int position, boolean selected)
{
    if(selected)
    {
       display.setTextColor(BLACK,WHITE);
    }else
    {
       display.setTextColor(WHITE,BLACK);
     
    }
    display.setCursor(5,position);
    display.print("> "+item);
    display.display();
}

void readRotaryEncoder()
{
  if (digitalRead(TANG) == 1) 
                      {
                       if(Cnt_B1T < 5000) {if(Cnt_B1T==500){up = true;back_diplay =1;}Cnt_B1T++;}
                       else 
                        {
                        Cnt_B1T=4580;
                        back_diplay =1;
                        up = true;
                        up_x2 = true;
                        }  
                      
                      }
 else if (digitalRead(GIAM) == 1) 
                      {
                       if(Cnt_B2T < 5000) {if(Cnt_B2T == 1500){down = true; back_diplay =1;}Cnt_B2T++;}
                       else 
                       {
                        Cnt_B2T=4580;
                        down_x2 = true;
                        down = true;
                        back_diplay =1;
                       }  
                      }
 else if (digitalRead(ENTER) == 1) 
                      {
                       if(Cnt_B10T < 5000) {if(Cnt_B10T == 4050){middle = true; back_diplay =1;}Cnt_B10T++;} // 
                       else 
                       {
                        Cnt_B10T=0;
                        middle = true;
                        back_diplay =1;
                       }
                      }
 else {
        Cnt_B2T=0;
        Cnt_B1T=0;
        Cnt_B10T=0;
       }
 
 
}
