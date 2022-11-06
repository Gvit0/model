#include <OneButton.h>
#include <DigiKeyboard.h>

#include "EEPROM.h"

#define BUTTON_PIN 0
#define ledPin 1      // the number of the LED pin

char usesSymb[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!#$%^&*-+";
const byte sizePW=12;
int ytr = 11;
char newPW[sizePW];
char curPW[sizePW];

char* myPW[]={"Sch1747_2_312", "1747", "Vasia-rules"};
byte qMyPW=3;// количество собственных паролей
byte mode=0;//текущий режим
byte qMode=qMyPW+1; //общее количество режимов

OneButton button = OneButton(
  BUTTON_PIN,  // Input pin for the button
  false,       // Button is active high
  false        // Disable internal pull-up resistor
);

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);

  // link the myClickFunction function to be called on a click event.   
  button.attachClick(myClickFunction);

  // link the doubleclick function to be called on a doubleclick event.   
  button.attachDoubleClick(myDoubleClickFunction);

  // link the doubleclick function to be called on a doubleclick event.   
  button.attachLongPressStart(myLongPressFunction);

  //debouncing time. Default is 50 msec.
  button.setDebounceTicks(40);
  
  //Timeout used to distinguish single clicks from double clicks.
  button.setClickTicks(800);
  
  //Duration to hold a button to trigger a long press.
  button.setPressTicks(1000); 

  EEPROM.get(0, curPW);
}

char* createNewPW (){
    for (byte i=0;i<sizePW;i++){
         newPW[i]=usesSymb[random(strlen(usesSymb))];
    }
  
    EEPROM.put(0, newPW);
    return newPW; 
}

void myClickFunction() {
 if (mode==0){
   if (strlen(curPW)==0){
      strcpy(curPW,createNewPW());
   }
   DigiKeyboard.print(curPW);
 }
 else {
     for (byte i=0;i<strlen(myPW[mode-1]);i++){
      for(int x = 1;i<13;i++){
        DigiKeyboard.sendKeyStroke(KEY_DELETE);
      }
      for(int x = 1;i<ytr;i++){
        DigiKeyboard.print(usesSymb[random(strlen(usesSymb))]);
        DigiKeyboard.sendKeyStroke(KEY_DELETE);
      }      
      DigiKeyboard.print(myPW[mode-1][i]);
      DigiKeyboard.sendKeyStroke(KEY_DELETE);
      for(int x = 1;i<ytr;i++){
        DigiKeyboard.print(usesSymb[random(strlen(usesSymb))]);
        DigiKeyboard.sendKeyStroke(KEY_DELETE);
      } 
    }
 }
}

void myLongPressFunction() {
  if (mode==0){
    strcpy(curPW,createNewPW());
    DigiKeyboard.print(curPW);
  }
}

void myDoubleClickFunction() {
  mode++;
  if (mode>=qMode){
      mode=0;
  }

  for (byte i=0;i<mode;i++){
      digitalWrite(ledPin, LOW);
      delay (500);
      digitalWrite(ledPin, HIGH);
      delay (500);
  }

  if (mode==0){
      digitalWrite(ledPin, LOW);
  }
} 

void loop() {
  // put your main code here, to run repeatedly:
  button.tick();
  DigiKeyboard.sendKeyStroke(0);
}
