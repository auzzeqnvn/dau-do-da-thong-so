void hienthidep(int r)
{
     display.clearDisplay(); 
     display.fillRect(0,12,125,40,BLACK); // WHITE BLACK
     display.setTextColor(WHITE);
     display.setCursor(10,12);
     display.setTextSize(3);
     if(r == 0) display.print("CH4");     
     else if(r == 1) display.print("CO ");     
     else if(r == 2) display.print("O2 ");     
     else if(r == 3) display.print("H2");     
     display.setTextSize(1); 
     display.print(" Config");                               
     display.display();                                        
                                            
    display.setTextSize(1);
    for(int l=time_nhaynhay2;l>0;l--)
    { 
     display.fillRect(60,0,60,7,BLACK); // WHITE BLACK
     display.setTextColor(WHITE);
     display.setCursor(45,0);  
     display.print("Time:");
     display.print(l,DEC);
     display.display();
     delay(1000);
    }
   display.clearDisplay(); 
   display.display(); 
}
void check_sensor (int das) 
{
  if (das == 29) // ch4
  {
    Int_Status =0;
    hienthidep(0);
  }
  else if (das == 6) // Co
  {
    Int_Status =1;
    //setup_lmp(); 
     hienthidep(1);  
  }
  else if (das == 19) // O2
  {
    Int_Status =2;
    //setup_lmp();   
     hienthidep(2);
  }
  else if (das == 93) // H2
  {
    Int_Status =3;
    //setup_lmp();  
     hienthidep(3); 
  }
}
