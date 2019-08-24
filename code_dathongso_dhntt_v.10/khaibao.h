int menuitem = 1;
int frame = 1;
int page = 1;
int toggle =0;
int lastMenuItem = 1;
uint32 tt=0; 
int Val_Volume=0;
#define CS_485 PA1
int Pass_Lock = 3;
int Pass_Reset = 19;
int Pass_Exit  = 9;

String menuItem1   = "Select Sc         "; // Set I 4-20mA  
String menuItem2   = "Set I 4-20mA      ";  //Set Frequency Out  
String menuItem3 =   "Set RS485         "; 
String menuItem4   = "Set Calip user    ";
String menuItem5   = "buzzer: ON        ";
String menuItem6   = "Set Lock And Exit ";


String menuItem1_1= "CO-02-CH4-H2";
#define OLED_RESET PA9

String menuItem2_Kp = "Set Zerro(mA)";
String menuItem2_Ki = "Set Time(s)  ";
String menuItem2_Kd = "Set Full(mA) ";


String menuItem3_1 = "Baud Rate";
String menuItem3_2 = " Address";

// Step 1
String menuItem4_2 = "Zerro     "; // điểm zero
String menuItem4_3 = "Time Zr(s)"; // thời gian lấy mẫu qua nhiêu giây quét
String menuItem4_4 = "Count(l/s)"; // tổng số lần tổng số lần cộng
String menuItem4_5 = "MaxValue  "; // giá trị adc lớn nhất
String menuItem4_6 = "MinValue  "; // giá trị adc bị trôi điểm 0 nhỏ nhất
String menuItem4_7 = "AD SS Max "; // thang đầu đo
String menuItem4_8 = "Float Int ";  // cấp số nhân
String menuItem4_9 = "Time Bz 1 "; // độ nhạy
String menuItem4_10 ="Time Setup"; // hệ số trừ sai số điểm zero 
String menuItem4_11 ="Alam Bz 1 "; // giá trị tổng cổng
String menuItem4_12 ="Alam Bz 2 ";
String menuItem4_13 ="----------";
String menuItem4_14 ="Read ADCn ";
String menuItem4_15 ="Vol Sensor";
String menuItem4_16 ="View SSR  ";



String menuItem6_1 = "Pass Lock";
String menuItem6_2 = "Pass Save";


boolean backlight = true;
boolean Stt_Print = false;
 boolean back_diplay = true;
int Cnt_ReadAmp =0;
String Baud[3] = { "9600","115.2","4800" };
float Val_Ampe2 =0;
float Val_Ampe1 =0;
int Epr_Setpoint =0;
boolean STT_POWER = false;
// biến hiển thị 

int Stt_AP1 =-1,Int_AP1=0,Stt_AP2=-1,Int_AP2=0;
float Stt_PV1 =-1,Int_PV1=0,Temp_Int_PV1=0,Stt_PV2=-1,Temp_Int_PV2=0,Int_PV2=0;
int Stt_SV =-1,Int_SV=0,Stt_Step=-1,ict_Int_Step=0,Int_Step=0;
int Stt_Status= -1,ict_Int_Status =0, Int_Status =-2;
int cnt_PV=0,ict_Setpoint =-1;
// biến cần lưu epprom

int Addr_485 =0; // chọn địa chỉ truyền
int selectedLanguage = 0; // chọn tốc độ baud
long rampRateStep[5]; 
long temperatureStep[5];
long dwellTimerStep[5];
int  Val_Lock =0; // mật khẩu khóa
int  Val_Reset =0; // mật khẩu rest chương trình cài đặt
int  contrast=60; // điều chỉnh độ tương phản màn hình
int Val_Kp; // thông số PID
int Val_Ki; // thông số PID
int Val_Kd; // thông số PID
int ict_Cnt_Run = 0,Cnt_Run =0;
int Count_Control =0;
//
#define ENTER 15
#define TANG  2
#define GIAM  13

#define ANL1 A0
#define ledPower 10

//float error = -0.0;  // Temperature compensation error
int b =-1,a=-1;


boolean up = false,up_x2 = false;
boolean down = false,down_x2 = false;
boolean middle = false;
// mới cài đặt
boolean Start_Setup = false;
boolean ict_Start_Run = false,Start_Run = false;
boolean Start_Next = false;
boolean Start_Pause = false;
boolean Stb_Out1 = false;
boolean Stb_Out2 = false;
boolean STT_K1 = false,Int_STT_K1 = false,Int_STT_K2 = false,STT_K2 = false;
float temp_Setpoint =0;
//
boolean STT_diplay = false;
int16_t last;
int Cnt_B5T =0,Cnt_B6T =0,Cnt_B7T =0,Cnt_B8T =0,Cnt_B9T =0,Cnt_B10T = 0;


// biến tự xóa
boolean ict_Count_Second = false,Count_Second = false;
boolean ict_Countlen_Setpoint = false,Countlen_Setpoint = false;
boolean ict_Countxuong_Setpoint = false,Countxuong_Setpoint = false;
double Epr_time_ss =0,time_ss=0;
float ict_Time_Step =0,Time_Step =0;
boolean ict_Stt_ON = false,Stt_ON= false;
double  rampRateSecond=0,ict_dwellTimerSecond=0,dwellTimerSecond=0;
boolean ict_IDS = false,IDS = false;
int Cnt_B1T=0,Cnt_B2T=0,Cnt_B3T=0,Cnt_B4T=0;
boolean SttTemp1Er = false;
boolean SttTemp2Er = false;
int CNT_backup =0;
long time_1,windowStartTime,time22=0,time_r,time_T,time_ON;
// đo bụi
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;

long voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 000.0;
int dustDensity_pirnt=0,dustDensity_pirnt1 =1,dustDensity_pirnt2=0,dustDensity_pirnt3=203,dustDensity_pirnt4=0;
unsigned long time11,time_in;
long data_vin;
int cntj=0;
boolean Start_pag = false; 
float celsius;
//
int range = 0,thangdo = 0,diemgoc = 0,heso = 0,h = 0;
int time_nhaynhay1=0,time_nhaynhay2=0,coi =0,data_Alam1=0,data_Alam2=0,Buzzer_keu=0;
int saiso =0;

boolean STT_update = false;
