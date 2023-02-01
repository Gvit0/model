#include <SoftSerial.h>     /* Allows Pin Change Interrupt Vector Sharing */
#include <TinyPinChange.h>  /* Ne pas oublier d'inclure la librairie <TinyPinChange> qui est utilisee par la librairie <RcSeq> */

SoftSerial mySerial(2, 4);

int maximum = 368;
int minimum = 354;
int pot;
int signal;
void setup() {
  pinMode(3, INPUT);
  mySerial.begin(9600);
}

void loop() {
  pot = analogRead(3);
  if (pot < minimum){
    signal = 0;
  }
  else if (pot > minimum & pot < maximum) {
    signal = map(pot, minimum, maximum, 0, 200);
  }
  else if (pot > maximum){
    signal = 200;
  }
  mySerial.println(signal);
}
