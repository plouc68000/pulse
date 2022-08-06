/*
 *  pulse on flag demonstrate a non blocking delay activating 
 *  the boolean variable flag1 during 5 seconds when a pushbutton is pressed.
 *  the variable flag1 can be monitored in the serial monitor
 *  
 *  Pulsing on a bool variable avoids to use a Arduino pin when you like to
 *  include a logical delay in your code
 *  
 *  User has not to manipulate millis(), this is done by the Library pulse.h
 *
 * 6/8/2022 plouc68000  
 */
 
#include "pulse.h"

#define button 2 // wire a push button on pin2 and gnd, active closing push button

bool flag1;

flag flag11(flag1,5000);// flag11 = instanciation of flag acting on flag1 variable with a ON time of 5000 ms


void setup() {

pinMode(button,INPUT_PULLUP); // for pushbutton input, wire push button other side to gnd
Serial.begin(9600); // to monitor flag1
}



void loop() {
// When pushbutton is pressed, flag1 gets true
// Putting flag1 true also starts the non blocking pulse delay
// to deactivate the Led when 5000 ms time is elapsed  

if ((digitalRead(button)==LOW)) flag1=true;

  
// Update checks periodically if 5000 ms time is elapsed
// when time is elapsed, Update() returns true, user has to set flag1 false to stop the timing
// This check runs as fast your loop is
// so don't add blocking delays in your loop(), always replace them with pulse Lib classes, either pin of flag
  
if (flag11.Update(flag1)==true) flag1=false;

Serial.print(flag1); // monitor flag1
delay(50); // slowdown the loop() a bit for less demanding monitor printing
}
