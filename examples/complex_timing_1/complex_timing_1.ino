/*
 *  Complex timing 1  demonstrate a more complex timing sequence.
 *  with this base of code, any desirable timing sequence can be created, all non blocking (;-)
 *  
 *  When pusbutton is pressed, the onboard Led is activated for 1 sec after a delay of 3 sec
 *  
 *  For the non blocking delay of 3 sec, a flag instance is used acting on flag1
 *  Then a pin instance is activated programmatically based on the state of flag1 to steer the onboard Led for 1 sec.
 *  
 *  
 *  
 *  Code writer have not to know or manipulate millis(), this is done by the Library pulse.h
 *
 * 6/8/2022 plouc68000  
 */
 
#include "pulse.h"

#define button 2 // wire a push button on pin2 and gnd, active closing push button
#define LED2 13 // Arduino onboard Led

bool flag1;

flag flag11(flag1,3000);// flag11 = instantiation of flag acting on flag1 variable with a ON time of 3000 ms
pin led22(LED2,1000); // led22 = instantiation of pin acting on LED2 with a ON time of 1000 ms


void setup() {

pinMode(button,INPUT_PULLUP); // for pushbutton input, wire push button other side to gnd
pinMode(LED2,OUTPUT); // onboard Led
}



void loop() {
// When pushbutton is pressed, flag1 gets true
// Putting flag1 true also starts the non blocking pulse delay
// to activate the Led when 3000 ms time is elapsed  

if ((digitalRead(button)==LOW)) flag1=true;

  
// Update checks periodically if 3000 ms time is elapsed
// when time is elapsed, Update() returns true, user has to 
// set flag1 false to stop the timing and set LED2 to activate pin timing
// This check runs as fast your loop is
// so don't add blocking delays in your loop(), always replace them with pulse Lib classes, either pin of flag
  
if (flag11.Update(flag1)==true){
  flag1=false; // stop the flag1 timing
  digitalWrite(LED2,HIGH); // put LED2 on and start the pin timing
 }

led22.Update(); // stop the pin timing when time 1000 ms elapsed and put pin LED2 LOW

}
