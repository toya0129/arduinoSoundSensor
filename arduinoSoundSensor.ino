#include <FilterDerivative.h>
#include <FilterOnePole.h>
#include <Filters.h>
#include <FilterTwoPole.h>
#include <FloatDefine.h>
#include <RunningStatistics.h>

// sensor
const int Csen = 0;

// sensor state
int Cstate = 0;

float data;
float hz = 3000.0;

static float y[2] = {0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // sensor set
  pinMode(Csen,INPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:

  ReadVoiceSensor();
  RCFilter();
  LowPassFilter();
  Serial.println(data);
 // Serial.println(y[1]);

}

void ReadVoiceSensor(){
  Cstate = (float)analogRead(Csen);
}

void RCFilter(){
  y[1] = 0.8 * y[0] + 0.2 * Cstate;
  y[0] = y[1];

}

void LowPassFilter(){
  FilterOnePole lowpassFilter( LOWPASS, hz );
  data = lowpassFilter.input(Cstate);
}

