int ledPin = 11;      // Присваиваем имя ledPin цифровому выводу 11, к которому подключен светодиод
int brightness =0;
int fadeValue = 5;    // шаг изменения яркости
int buttonPlus=2;     //  Номер Pin к которому подключена кнопка "+" 
int buttonMinus=3;    //  Номер Pin к которому подключена кнопка "-"
 
void setup()  { 
pinMode(ledPin, OUTPUT);
} 
void loop()  {
  if (digitalRead(buttonPlus) == HIGH) {
    brightness +=  fadeValue;
  }
  if (digitalRead(buttonMinus) == HIGH) {
    brightness -=  fadeValue;
  }
  brightness = constrain(brightness, 0, 255);
  analogWrite(ledPin, brightness);
  delay(50);
}
