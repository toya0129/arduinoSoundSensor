#include <MsTimer2.h>

// Mic Sensor
#define mic 13
#define LR 10

// Clock Sensor
#define clkA 5
#define clkB 4
#define clkC 3
#define clkST 6

// sensor state
float Cstate = 0;
float a = 0;
float c = 0;
float low = 0;
float hz = 1000.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  MsTimer2::set(0.00001,timer);
  MsTimer2::start();

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
  
  //a = digitalRead(mic);
  //LowPassFilter(a);
  
  //Serial.println(a);
  //Serial.println(Cstate);

}

void timer(){
  a = digitalRead(mic);
  Serial.println(a);
}

