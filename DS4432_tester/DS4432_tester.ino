#include <Wire.h>
#include "DS4432_atmega328.h"

DS4432 ds4432;

const int ledPin = 53;
const int sensorPin = A0;

void setup() {
  int error;
  bool ledVal;
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(9, OUTPUT);
  Wire.begin();
  
  error = ds4432.begin();
  if(error != 0){
    Serial.println("DS4432 not found!");
    while(true){
      digitalWrite(ledPin, ledVal);
      ledVal = !ledVal;
      delay(1000);
    }
  }
  digitalWrite(9, HIGH);
  Serial.println("Setup is over.");
  
}

void loop() {
  byte i = 0;
  static bool ledVal;
  int sensorVal;
  ledVal = !ledVal;
  digitalWrite(ledPin, ledVal);
  /*
  sensorVal = 256-analogRead(sensorVal)/4;
  Serial.print(sensorVal);
  Serial.print(", ");
  Serial.println(ds4432.out1set(sensorVal));
  */
  
  for(i=0; i<256; i++)
  { 
    Serial.println(i);
    digitalWrite(ledPin, ledVal);
    ledVal = !ledVal;
    ds4432.out1set(i);
    delay(100);
  }
  
  delay(300);
}
