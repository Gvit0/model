void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(1500); // Wait for 1500 millisecond(s)
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(1500); // Wait for 1500 millisecond(s)
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  delay(1500); // Wait for 1500 millisecond(s)
}
