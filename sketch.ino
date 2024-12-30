#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int pirmasuk=8,pirkeluar=9;
const int Bel=A0;
const int Led1=A1,Led2=A2;
int masuk=0,keluar=0,total=0;

void setup() 
{  
  lcd.init(); 
  lcd.backlight(); 
  lcd.print("SELAMAT DATANG");
  lcd.setCursor(2,1);
  lcd.print("SILAHKAN MASUK");
  delay(1000);
  pinMode(pirmasuk, INPUT);
  pinMode(pirkeluar, INPUT);
  pinMode(Bel, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
}

void loop() 
{
 if (digitalRead(pirmasuk))
 {
   total ++;
   masuk = masuk+1;
   delay(4000);
 }
     
 if (digitalRead(pirkeluar))
 {
   total --;
   keluar = keluar+1;      
   delay(4000); 
 }
  
  //indikator banyaknya pengunjung
  //ganti angka count>..... sesuai kebutuhan
   if(total>5){
     digitalWrite(Led1,HIGH);
     digitalWrite(Led2,LOW);
     digitalWrite(Bel,HIGH);
     delay(1000); 
   }
  else
  {
    digitalWrite(Led1,LOW);
    digitalWrite(Bel,LOW);
    digitalWrite(Led2,HIGH);
  } 
   
  lcd.clear();
  
  lcd.setCursor(1,0); //(mengatur lokasi tata letak awal huruf
  lcd.print("Jumlah Visitor");
  
  //lcd.setCursor(5,0);
  lcd.setCursor(0,1); //mengatur Letak huruf
  lcd.print("M:");
  
  lcd.setCursor(2,1);
  lcd.print(masuk); //mengatur letak angka
  
  lcd.setCursor(6,1); //mengatur Letak huruf
  lcd.print("K:");
  
  lcd.setCursor(8,1); //mengatur letak angka
  lcd.print(keluar);
 
  
  lcd.setCursor(11,1); //mengatur Letak huruf
  lcd.print("T:");
  
  lcd.setCursor(13,1); //mengatur letak angka
  lcd.print(total);
  delay(1000); 
}