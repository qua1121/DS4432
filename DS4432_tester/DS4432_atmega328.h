#ifndef DS4432_h
#define DS4432_h

#include "Arduino.h"
#include <Wire.h>

class DS4432
{
    public:
      DS4432();
      byte begin();
      byte out1set(int val);
      byte out2set(int val);
    private:
      int _val;
};

#endif
