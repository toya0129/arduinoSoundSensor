#include <FilterDerivative.h>
#include <FilterOnePole.h>
#include <Filters.h>
#include <FilterTwoPole.h>
#include <FloatDefine.h>
#include <RunningStatistics.h>

// sensor
#define data 5
#define clk 4

// sensor state
float Cstate = 0;
int a ;

//test
const int maxloop = 100;
const int maxdac = 4095;
const int maxrate = 2000 / maxloop;
const int maxset = maxdac / 2;
const int outloop = 10000 / maxloop;
int count = 0;
long c,b;

float highdata;
float lowdata;
float hz = 20000.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // sensor set
  pinMode(data,INPUT);
  pinMode(clk,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

//  while(1){
//
//  for(int i= 0;i< outloop;i++){
//    count = 0;
//    for(int a = 0;a< maxloop;a++){
//      digitalWrite(clk,LOW);
//      c++;
//      b++;
//      if(digitalRead(data) == HIGH){
//        count++;
//      }else{
//        count--;
//      }
//      if(a < maxloop - 1){
//        digitalWrite(clk,HIGH);
//        digitalWrite(clk,HIGH);
//      }
//    }
//    count = count * maxrate + maxset;
//  }
//  Serial.println(count);
//  }

  

//  digitalWrite(clk,LOW);

  

  Cstate = analogRead(data);
  //LowPassFilter(Cstate);
  Serial.println(Cstate);
  //delay(100);
}

//void ReadVoiceSensor(){
//  Cstate = analogRead(Csen);
//  data = (float)Cstate;
//}

void LowPassFilter(float in){
  FilterOnePole lowpassFilter( LOWPASS, hz );
  Cstate = lowpassFilter.input(in);
}

