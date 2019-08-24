
 
 
void hienthideep(int r,int p)
{
     display.clearDisplay(); 
     display.setTextSize(1);
     display.fillRect(60,0,60,7,BLACK); // WHITE BLACK
     display.setTextColor(WHITE);
     display.setCursor(45,0);  
     if(r == 0) display.print("Adrres");     
     else if(r == 1) display.print(" Baud");
     else if(r == 2) display.print("Alam1");  
     else if(r == 3) display.print("Alam2");
     else if(r == 4) display.print("Al1 Time"); 
     else if(r == 5) display.print("Fix Zero");    
     //
     display.fillRect(0,12,125,40,BLACK); // WHITE BLACK
     display.setTextColor(WHITE);
     display.setCursor(10,12);
     display.setTextSize(1); 
     display.print("Config ");            
     display.setTextSize(3);
     display.print(p,DEC);                            
     display.display();
     
   delay(100);
   display.clearDisplay(); 
   display.display(); 
}

void cauhinh_truyenthong(int Addrr,int burd)
{
  int bus =0;
  if(Addrr > 255 ) Addrr =0; 
  
  if(burd == 0 )
  {
   bus = 9600;  
  }
  else if(burd == 1 )
  {
   bus = 115200;  
  }
  else if(burd == 2 )
  {
   bus = 4800;  
  }
  //mb.config(&Serial2,bus,SERIAL_8N1,CS_485);
  //mb.setSlaveId(Addrr);
 
  hienthideep(0,Addrr);
  hienthideep(1,bus);
  hienthideep(2,data_Alam1);
 hienthideep(3,data_Alam2);
 hienthideep(4,time_nhaynhay1);
 hienthideep(5,saiso);
}
