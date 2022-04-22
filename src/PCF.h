#ifndef PCF_h
#define PCF_h
#include "Arduino.h"

class PCF {
    byte end;
    byte pin = 0;
    byte estado=0;
  public:

    PCF(byte n) {
      end = n;
    }
    bool read(byte n) {

      Wire.requestFrom(end, 1);
      delayMicroseconds(1);
      if (Wire.available()) {

        return (bitRead(Wire.read(), n));

      } else {
        return (0);
      }
    }
    void write(byte n,bool e)
    {
      bitWrite(estado,n,e);
      Wire.beginTransmission(end);
      Wire.write(estado+pin);
      Wire.endTransmission();
    }
    void pinout(byte n,bool e) {
       bitWrite(pin,n,e);
    }
};

#endif
