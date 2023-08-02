#include "Arduino.h"
#include <Wire.h>
#include "DS4432_atmega328.h"

//#define DS4432Address   0x90
#define DS4432Address   0x48
#define out0Address     0xF8
#define out1Address     0xF9

DS4432::DS4432()
{
  
}

byte DS4432::begin()
{
    byte error;
    Wire.begin();
    Wire.beginTransmission(DS4432Address);
    error = Wire.endTransmission();
    return error;
    // if error = 0, device found DS4432.
}

byte DS4432::out1set(int val)
{
    byte signBit;
    byte data;
    byte wVal;
    if(val == 256){
      val = 255;
    }
    _val = val;

    if(val<128){
      signBit = 0;
      data = 128 - val;
    }else{
      signBit = 1;
      data = val - 128;
    }
    bitWrite(wVal, 7, signBit);
    wVal = wVal + data;

    Wire.beginTransmission(DS4432Address);
    Wire.write(out0Address);
    Wire.write(wVal);
    Wire.endTransmission();
    return(wVal);
}

byte DS4432::out2set(int val)
{
    byte signBit;
    byte data;
    byte wVal;
    _val = val;

    if(val<128){
        signBit = 0;
        data = 128 - val;
    }else{
        signBit = 1;
        data = val - 128;
    }
    bitWrite(wVal, 8, signBit);
    wVal = wVal + data;

    Wire.beginTransmission(DS4432Address);
    Wire.write(out1Address);
    Wire.write(wVal);
    Wire.endTransmission();
    return(wVal);
}
