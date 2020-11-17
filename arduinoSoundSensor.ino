#include <TimerOne.h>
#include <FlexiTimer2.h>

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
  Serial.begin(115200);

  // pin data initialize
  PinSet();
  SensorSet();

  // read data
  FlexiTimer2::stop();
  FlexiTimer2::set(1, 1.0/5000, ReadSensor); // 1s = 5000
  FlexiTimer2::start();
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

}

void ReadSensor(){
  SensorState[count] = analogRead(mic);
  count++;
  if(count == 200){ 
    count = 0;
    SendPC(SensorState);
  }
}

void SendPC(double *data){
  for(int a = 0;a < 200; a++){
    Serial.println(data[a]);
  }
  delay(10);
}
