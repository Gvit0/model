const int led =  13;      // пин со светодиодом
int p;
 
void setup() {
  pinMode(led, OUTPUT);     
  pinMode(A0, INPUT);
}
 
void loop()
{
  p = analogRead(A0);
  p = map(p, 0, 255, 100, 2000);
  digitalWrite(led, 1);
  delay(p);
  digitalWrite(led, 0);
  delay(p);
} 
