/*
 *  Complex timing 2  demonstrate a more complex timing sequence.
 *  with this base of code, any desirable timing sequence can be created, all non blocking (;-)
 *  
 *  Lets do a blinker on the onboard Led, with a ON time of 50 ms and a OFF time of 200ms
 *  
 *  For the non blocking delay of 50 ms sec, a flag instance is used acting on flag1
 *  
 *  For the non blocking delay of 200 ms sec, a flag instance is used acting on flag2
 *  
 *  
 *  
 *  
 *  Code writer have not to know or manipulate millis(), this is done by the Library pulse.h
 *
 * 6/8/2022 plouc68000  
 */
 
#include "pulse.h"


#define LED2 13 // Arduino onboard Led

bool flag1, flag2;

flag flag11(flag1,50);// flag11 = instantiation of flag acting on flag1 variable with a ON time of 50 ms
flag flag22(flag2,200);// flag22 = instantiation of flag acting on flag2 variable with a ON time of 200 ms


void setup() {

pinMode(LED2,OUTPUT); // onboard Led

  flag1 = true; // start a pulse on flag1
  flag2 = false;  
  pinMode(LED2,OUTPUT);
  digitalWrite(LED2,HIGH);
}



void loop() {

// create a blinker with 2 pulsed flags
   if (flag11.Update(flag1)==true) // pulse done on flag1
   {
    digitalWrite(LED2,LOW); // this gives Led ON time
    flag1=false;
    flag2=true; // start pluse on flag2, this gives Led OFF time
   }
   if (flag22.Update(flag2)==true) // pulse done on flag2 ?
   { 
    digitalWrite(LED2,HIGH);
    flag2=false;
    flag1=true; // restart pulse on flag1 to make blinker
   }
   
}
