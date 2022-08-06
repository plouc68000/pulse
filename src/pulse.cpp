/*  Gr 4/8/22
 *  non blocking pulse
 *   pulse apply on arduino pin
 *   or 
 *   pulse apply on boolean variable
 */
#include "Arduino.h"
#include "pulse.h"


pin::pin(int pin, unsigned long ontime)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _ontime = ontime;
  previousMillis = millis();
  triggered = false;
}


void pin::Update()
  {
    // read current time
    currentMillis = millis();

    // check if trigger condition
    if ((digitalRead(_pin) == HIGH) && (triggered == false))
    {
      triggered = true;
      previousMillis = currentMillis;// arm the timer
    }  

    // check to see if it's time to change the state of the LED    
    if((digitalRead(_pin) == HIGH) && (currentMillis - previousMillis >= _ontime))
    {
      digitalWrite(_pin, LOW);  // Timer elapsed, turn off the Led
      triggered = false; // reset trigger
    }
    
  }



flag::flag(bool flag, unsigned long ontime)
{
  _flag = flag;
  _ontime = ontime;
  previousMillis = millis();
  triggered = false;
}


int flag::Update(bool flag)
  {
    // read current time 
    currentMillis = millis();
    _flag=flag;

    // check if trigger condition
    if ((_flag == true) && (triggered == false))
    {
      triggered = true; // arm trigger
      previousMillis = currentMillis;// arm the timer
    }  

    
    if((_flag == true) && (currentMillis - previousMillis >= _ontime))
    {
      _flag = false;  // Turn flag off
      triggered = false; // reset trigger
      return true; // return indicator time is elapsed
    }
    else
    {
      return false;
    }
  }   
  
