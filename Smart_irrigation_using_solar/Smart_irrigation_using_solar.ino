#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <Servo.h>
Servo myservo;
int ms=A0;
int mot=A1;
int x;
int md=0;
//int mot1=A2;
int l1=A4;
int l2=A5;
int kk=0;
void setup() {
lcd.begin(16,2);
lcd.print(" WELCOME");
Serial.begin(9600);
myservo.attach(2);
pinMode(mot,OUTPUT);
//pinMode(mot1,OUTPUT);
pinMode(ms,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);
digitalWrite(mot,0);
}
void loop()
{
int mval=analogRead(ms);
int lv1=analogRead(l1)/10;
int lv2=analogRead(l2)/10;
Serial.println("L1:");
Serial.println(lv1);
Serial.println("L2:");
Serial.println(lv2);
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("L1:");
lcd.setCursor(3,0);
lcd.print(lv1);
lcd.setCursor(8,0);
lcd.print("L2:");
lcd.setCursor(11,0);
lcd.print(lv2);
lcd.setCursor(10,1);
lcd.print("M:");
lcd.setCursor(12,1);
lcd.print(mval);
x=Serial.read();
if(x=='1')
{
md=0;
}
if(md==0)
{
Serial.println("sensor mode");
lcd.setCursor(0,1);
lcd.print("AUTO MODE");
if(mval<600)
{
digitalWrite(mot,0);
}
else
{
digitalWrite(mot,1);
}
}
if(x=='2')
{
Serial.println("Remote mode");
lcd.setCursor(0,1);
lcd.print("MANUAL MODE");
md=1;
}
if(md==1)
{
if(x=='3')
{
digitalWrite(mot,1);
lcd.setCursor(0,1);
lcd.print("MANUAL MODE");
delay(1000);
}
if(x=='4')
{
digitalWrite(mot,0);
lcd.setCursor(0,1);
lcd.print("MANUAL MODE");
delay(1000);
}
}
if(lv1>70 && kk==0)
{
kk=1;
myservo.write(30);
}
if(lv2>70 && kk==1)
{
kk=2;
myservo.write(130);
}
if(lv1<70 && lv2<70 &&kk==2)
{
kk=0;
myservo.write(60);
}
delay(500);
}