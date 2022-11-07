const int ledPin =  13;      // пин со светодиодом
int ledState = LOW;             // этой переменной устанавливаем состояние светодиода
long previousMillis = 0;        // храним время последнего переключения светодиода
 
long interval = 1000;           // интервал между включение/выключением светодиода (1 секунда)
 
void setup() {
  pinMode(ledPin, OUTPUT);     
  pinMode(A0, INPUT);
}
 
void loop()
{
  interval = analogRead(A0);
  interval = map(interval, 0, 255, 100, 2000);
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis; 
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(ledPin, ledState);
  }
}
