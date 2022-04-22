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

    void pinout(byte n) {
      pin+=pinToBin(n);
    }
    
    byte pinToBin(byte n) {
      switch (n) {
        case 0:
          return 1;
          break;
        case 1:
          return 2;
          break;
        case 2:
          return 4;
          break;
        case 3:
          return 8;
          break;
        case 4:
          return 16;
          break;
        case 5:
          return 32;
          break;
        case 6:
          return 64;
          break;
        case 7:
          return 128;
          break;
      }
    }

};

#endif
