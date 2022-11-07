// C++ code
//
void setup()
{
  pinMode(2, OUTPUT); //устанавливаем 2 пин (красный цвет) как выход 
  pinMode(3, OUTPUT); //устанавливаем 3 пин (жёлтый цвет) как выход
  pinMode(4, OUTPUT);//устанавливаем 4 пин (зелёный цвет) как выход
}

void loop()
{
  digitalWrite(2, HIGH); // включаем красный цвет
  delay(3000); //задержка 3 секунды
  digitalWrite(2, LOW); // выключаем красный цвет
  digitalWrite(4, HIGH); // включаем  зелёный цвет
  delay(3000); //задержка 3 секунды
  digitalWrite(4, LOW); // выключаем зелёный цвет
  delay(500); 
  digitalWrite(4, HIGH); 
  delay(500);
  digitalWrite(4, LOW);
  delay(500);
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  delay(500);
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  delay(500);
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);
}
