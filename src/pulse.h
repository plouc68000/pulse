/*  Gr 4/8/22
 *  non blocking pulse
 *   pulse apply on arduino pin, use class pin
 *   or 
 *   pulse apply on boolean variable, use class flag
 */
#ifndef pulse_h
#define pulse_h

#include "Arduino.h"



class pin
{
  public:
    pin(int pin, unsigned long ontime);
    void Update();
  
  private:
    int _pin;
    unsigned long _ontime;
    unsigned long previousMillis;
    unsigned long currentMillis;
    bool triggered;
};



class flag
{
  public:
    flag(bool flag, unsigned long ontime);
    int Update(bool flag);
  
  private:
    bool _flag;
    unsigned long _ontime;
    unsigned long previousMillis;
    unsigned long currentMillis;
    bool triggered;

};



#endif
