/*
 *  scan a push button every 200ms gives a good deboucing
 *  
 *  for this, we use a pulse on flag1 infinitely repeating
 *  
 *  
 *  User has not to manipulate millis(), this is done by the Library pulse.h
 *
 * 6/8/2022 plouc68000  
 */
 
#include "pulse.h"

#define button 2 // wire a push button on pin2 and gnd, active closing push button
#define LED2 13 // Arduino onboard Led

bool flag1;

flag flag11(flag1,200);// flag11 = instanciation of flag acting on flag1 variable with a ON time of 200 ms


void setup() {

pinMode(button,INPUT_PULLUP); // for pushbutton input, wire push button other side to gnd
pinMode(LED2,OUTPUT); // onboard Led

flag1 = true; // start pulse on flag1
}



void loop() {

// pulse on flag will restart infinitely, since flag1 is not reset by the code
if (flag11.Update(flag1)==true) {
  if ((digitalRead(button)==LOW))digitalWrite(LED2,HIGH);
  else digitalWrite(LED2,LOW);
 }
}
