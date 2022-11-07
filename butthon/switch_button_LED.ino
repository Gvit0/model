int LED = 13;
int but = 2;
bool lig = false;
void setup() {
  pinMode(but, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

}

void loop() {
  int sensorVal = digitalRead(but);
  if (sensorVal == 0) {
  	lig = !lig;
  }
  if (lig == true){
  	digitalWrite(LED, 1);
  }
  else if (lig == false){
  	digitalWrite(LED, 0);
  }
  
}