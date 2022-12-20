// отправь s для опускания 

 // отправь w для подёма 

 // отправь d для остоновки 

  

 #define CLK 7 

 #define DT 8 

 #define SW 9 

  

 #include <GyverStepper.h> 

 GStepper<STEPPER2WIRE> stepper(200, 2, 3); 

  

 int bu = 4; 

 bool ku = false; 

 int bd = 5; 

 bool kd = false; 

 int size = 0; 

  

 void setup() { 

   Serial.begin(9600); 

   pinMode(bd, INPUT_PULLUP); 

   pinMode(bu, INPUT_PULLUP); 

   stepper.setRunMode(KEEP_SPEED); // режим поддержания скорости 

   calibration();  

 } 

  

 void loop() { 

   stepper.tick(); 

   //Serial.println("Tick"); 

   if (digitalRead(bu) == 0 && ku == false){ 

     ku = true; 

     //Serial.println("Up datchik Eneble Stop Motor"); 

     stepper.brake(); 

   } 

   if (digitalRead(bd) == 0 && kd == false){ 

     kd = true; 

      //Serial.println("Down datchik Eneble Stop Motor"); 

     stepper.brake(); 

   } 

   if (digitalRead(bu) == 1){ 

      //Serial.println("Up datchik DONT Eneble"); 

     ku = false; 

   } 

   if (digitalRead(bd) == 1){ 

     //Serial.println("Down datchik DONT Eneble"); 

     kd = false; 

   } 

   otladka(); 

   serial(); 

 } 

  

 void serial(){ 

   if (Serial.available()) { 

     char ch = Serial.read(); 

     if (ch == 'd') stepper.brake(); 

     if (ch == 'w'  && ku == false){  

       stepper.setSpeed(25); 

     } 

     if (ch == 's' && kd == false ) { 

       stepper.setSpeed(-25); 

     } 

   } 

 } 

 void otladka(){ 

   Serial.print(kd); 

   Serial.print("            "); 

   Serial.print(ku); 

   Serial.print("            "); 

   Serial.println(size); 

 } 

 void calibration(){ 

   stepper.setSpeed(250);   

   while (digitalRead(bu) == 1){ 

     stepper.tick(); 

     Serial.println(size); 

   } 

   stepper.setSpeed(-250);   

   while (digitalRead(bd) == 1){ 

     stepper.tick(); 

     size++; 

     Serial.println(size); 

   } 

 }
