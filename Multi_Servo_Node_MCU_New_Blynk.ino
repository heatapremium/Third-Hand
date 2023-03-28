// Chage These Credentials with your Blynk Template credentials
// Chage These Credentials with your Blynk Template credentials 
#define BLYNK_TEMPLATE_ID "TMPL6LtgO0Ypz"
#define BLYNK_TEMPLATE_NAME "Third hand multi servo control"
#define BLYNK_AUTH_TOKEN "yMC0PKZRB_5TsJkPvx0TnwGB15vrV2av"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include<Servo.h>
Servo servo1, servo2, servo3, servo4, servo5;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "SLT-4G_171654"; // Change your Wifi/ Hotspot Name
char pass[] = "248AA9E1"; // Change your Wifi/ Hotspot Password

BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  servo1.write(s0);
  servo2.write(180-s0);
  Blynk.virtualWrite(V3, s0);
}
BLYNK_WRITE(V1)
{
  int s1 = param.asInt(); 
  servo3.write(s1);
  Blynk.virtualWrite(V4, s1);
}
BLYNK_WRITE(V2)
{
  int s2 = param.asInt(); 
  if(s2<30){
    digitalWrite(D6,HIGH);
    digitalWrite(D7,LOW);
  }else if(30<s2<150){
    digitalWrite(D6,LOW);
    digitalWrite(D7,LOW);
  }else if(s2>150){
    digitalWrite(D6,LOW);
    digitalWrite(D7,HIGH);
  }
  Blynk.virtualWrite(V5, s2);
}
/*BLYNK_WRITE(V3)
{
  int s3 = param.asInt(); 
  servo4.write(s3);
  Blynk.virtualWrite(V8, s3);
}
BLYNK_WRITE(V4)
{
  int s4 = param.asInt(); 
  servo5.write(s4);
  Blynk.virtualWrite(V9, s4);
}*/

void setup()
{
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  Serial.begin(9600);
  servo1.attach(D2);
  servo2.attach(D3);
  servo3.attach(D5);
  //servo4.attach(6);
  //servo5.attach(7);
  Blynk.begin(auth, ssid, pass);//Splash screen delay
  while(WiFi.status() != WL_CONNECTED){
  delay(1); 
  Serial.print(".");
  }
  Serial.println("WiFi Connection succesfull!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );
}

void loop() 
{
  Blynk.run();
  Serial.print(V0);
  Serial.print(" ");
  Serial.print(V1);
  Serial.print(" ");
  Serial.println(V2); 
}
