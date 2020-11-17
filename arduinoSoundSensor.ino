#include <TimerOne.h>
#include <FlexiTimer2.h>
#include <SoftwareSerial.h>

//Serial Raspberry
SoftwareSerial rasPi(2,3); // rx tx

// Mic Sensor
#define mic A5
#define LR 13


// Clock Sensor
#define clkA 15 // A1
#define clkB 16 // A2
#define clkC 17 // A3
#define clkST 14 // A0

// Out Data
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define A 9
#define B 10
#define C2 11

// Initialize
int count = 0;
double SensorState[200];
String sendData = "";

void setup() {
  // put your setup code here, to run once:

  //Serial.begin(9600);
  Serial.begin(115200);
  //rasPi.begin(115200);

  FlexiTimer2::stop();
  FlexiTimer2::set(1, 1.0/5000, ReadSensor); // 1s = 5000
  FlexiTimer2::start();

//  Timer1.initialize(10000);
//  Timer1.attachInterrupt(sendPC);
  
  rasPi.println("aa");
  rasPi.println("aa");

  PinSet();
  SensorSet();
}

void PinSet(){
  pinMode(mic,INPUT);
  pinMode(LR,OUTPUT);

  pinMode(clkA,OUTPUT);
  pinMode(clkB,OUTPUT);
  pinMode(clkC,OUTPUT);
  pinMode(clkST,OUTPUT);

  pinMode(C,INPUT);
  pinMode(D,INPUT);
  pinMode(E,INPUT);
  pinMode(F,INPUT);
  pinMode(G,INPUT);
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  pinMode(C2,INPUT);
}

void SensorSet(){
  digitalWrite(LR,HIGH);
  digitalWrite(clkA,HIGH);
  digitalWrite(clkB,LOW);
  digitalWrite(clkC,LOW);
  digitalWrite(clkST,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //sendPC();
  //delay(1000);
}

void ReadSensor(){
  SensorState[count] = analogRead(mic);
  count++;
  if(count == 200){ 
    count = 0;
    SendRaspberry(SensorState);
  }
}

void SendRaspberry(double *data){
  rasPi.listen();
  for(int a = 0;a < 200; a++){
    //rasPi.println(data[a]);
    Serial.println(data[a]);
    //Serial.print("\n");
  }
  delay(10);
}

void sendPC(){
  if(digitalRead(C) == HIGH){
    sendData = "CC";
  }
  else if(digitalRead(D) == HIGH){
    sendData = "DD";
  }
  else if(digitalRead(E) == HIGH){
    sendData = "EE";
  }
  else if(digitalRead(F) == HIGH){
    sendData = "FF";
  }
  else if(digitalRead(G) == HIGH){
    sendData = "GG";
  }
  else if(digitalRead(A) == HIGH){
    sendData = "AA";
  }
  else if(digitalRead(B) == HIGH){
    sendData = "BB";
  }
  else if(digitalRead(C2) == HIGH){
    sendData = "C2";
  }

  //if(sendData != ""){
    Serial.println(sendData);
    sendData = "";
  //}
}
