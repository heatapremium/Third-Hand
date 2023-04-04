#define enA 9
#define in1 8
#define in2 7
#define in3 10
#define in4 11
#include <Servo.h>

Servo myservo;
int speed = A0;
int dci = A1;
int servoctrl = A2;
int val2;
int val1;
int val;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  myservo.attach(2);
  Serial.begin(9600);
  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {
  directioncontol_input();
  //servocontrol_input();
  speedcontrol();
  myservo.write(val2);
  Serial.print(val);  
  Serial.print(" ");
  Serial.print(val1);
  Serial.print(" ");
  Serial.println(val2);
  
  if(val<50){
    directioncontrolccw();
  }
  else if(50<val && val<130){
    directioncontrolstop();
  }
  else if(130<val){
    directioncontrolcw();
  }
  if(val1<50){
    directioncontrolccw2();
  }
  else if(50<val1 && val1<130){
    directioncontrolstop2();
  }
  else if(130<val1){
    directioncontrolcw2();
  }
}

//contrilling the speed of the motor
void speedcontrol(){ 
  val1 = analogRead(speed);
  val1 = map(val1, 0, 1024, 0, 180);
  //analogWrite(enA,val1);  //set motor speed
  //delay(20); 
}

void directioncontrolccw(){
  //Turn on the motor A
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  //delay(2000);
}

void directioncontrolcw(){
  //Turn on the motor A
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  //delay(2000);
}

void directioncontrolstop(){
  //Turn on the motor A
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
}

void directioncontrolccw2(){
  //Turn on the motor A
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  //delay(2000);
}

void directioncontrolcw2(){
  //Turn on the motor A
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
  //delay(2000);
}

void directioncontrolstop2(){
  //Turn on the motor A
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

/*void servocontrol_input(){
  val2 = analogRead(servoctrl);
  val2 = map(val2, 0, 1024, 0, 180);
}*/

void directioncontol_input(){
  val = analogRead(dci);
  val = map(val, 0, 1024, 0, 180);
}

