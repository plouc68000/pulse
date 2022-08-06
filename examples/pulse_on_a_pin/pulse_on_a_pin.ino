/*
 *  pulse on pin demonstrate a non blocking delay activating 
 *  the onboard Led during 5 seconds when a pushbutton is pressed.
 *  
 *  User has not to manipulate millis(), this is done by the Library pulse.h
 *
 * 6/8/2022 plouc68000  
 */
 
#include "pulse.h"

#define button 2 // wire a push button on pin2 and gnd, active closing push button
#define LED2 13 // Arduino on board Led

pin led22(LED2,5000); // led22 = instantiation of pin acting on LED2 with a ON time of 5000 ms



void setup() {

pinMode(button,INPUT_PULLUP); // for pushbutton input, wire push button other side to gnd
pinMode(LED2,OUTPUT); // onboard Led
}



void loop() {
// When pushbutton is pressed, activate LED2
// Putting the Led pin HIGH also starts the non blocking pulse delay
// to deactivate the Led when 5000 ms time is elapsed  

if ((digitalRead(button)==LOW))digitalWrite(LED2,HIGH);

  
// Update checks periodically if 5000 ms time is elapsed
// when time elapsed, it puts the LED pin LOW, this deactivating the pulse delay
// This check runs as fast your loop is
// so don't add blocking delays in your loop(), always replace them with pulse Lib classes, either pin of flag
  
led22.Update(); 
  
}
