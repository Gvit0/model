int led = 13; #пин со светодиодом
int tempd = 10; #сколько раз в секунду
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, 1);
  delay(1000 / tempd);
  digitalWrite(led, 0);
  delay(1000 / tempd);
}
