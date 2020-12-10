 #define LED 13
 #define BUZZER 10
 #define BUTTON 2
void setup() {
    //Konfiguracja wyjsc
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  //Konfiguracja wyjscia
  pinMode(BUTTON, INPUT_PULLUP); 
 
  //Wylaczenie diody i buzzera
  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);
 
  //Testowe migniecia LED
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}
}
void loop() {
}