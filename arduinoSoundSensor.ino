#include <MsTimer2.h>

// Mic Sensor
#define mic A5
#define LR 10

// Clock Sensor
#define clkA 5
#define clkB 4
#define clkC 3
#define clkST 6

#define clk 3

// sensor state
float Cstate = 0;
float a = 0;

int count = 0;
float test[10];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(2000000);

  MsTimer2::set(0.6,timer); //6kHz まで
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

  pinMode(clk,INPUT);
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
  test[count] = analogRead(mic);
  count++;
  if(count == 10){
    float sum = 0;
    for(int i=0;i<10;i++){
      sum += test[i];
    }
    Serial.println(sum/10);
    count = 0;
  }
}
