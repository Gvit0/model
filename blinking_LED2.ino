int led = 13; #пин со светодиодом
int led2 = 7; #пин со 2 светодиодом
int tempd = 10; #сколько раз в секунду
void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led, 1);
  digitalWrite(led2, 1);
  delay(1000 / tempd);
  digitalWrite(led, 0);
  digitalWrite(led2, 0);
  delay(1000 / tempd);
}
