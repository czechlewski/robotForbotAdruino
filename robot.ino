#define L_PWM 5
#define L_DIR 4
#define R_PWM 6
#define R_DIR 9
#define PWM_MAX 165

#define R_LIGHT_SENSOR A0
#define L_LIGHT_SENSOR A1
#define BUZZER 10
void setup() {
//Konfiguracja pinow od mostka H
  pinMode(L_DIR, OUTPUT);
  pinMode(R_DIR, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_PWM, OUTPUT);
  
  Serial.begin(9600);
}
void loop() {
    int odczytLewy = analogRead(L_LIGHT_SENSOR);    
    int odczytPrawy = analogRead(R_LIGHT_SENSOR);
 
    Serial.print("Lewa strona: ");
    Serial.print(odczytLewy);
    Serial.print(" | ");
    Serial.print("Prawa strona: ");
    Serial.println(odczytPrawy);
    delay(1000);
}

void leftMotor(int V){
    if (V>0){
        V = map(V, 0, 100, 0, PWM_MAX);
        digitalWrite(L_DIR, 0);
        analogWrite(L_PWM, V);
    } 
    else
    {
    V = abs(V); 
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(L_DIR, 1);
    analogWrite(L_PWM, V); 
    }
} 
void rightMotor(int V){
    if (V>0){
        V = map(V, 0, 100, 0, PWM_MAX);
        digitalWrite(R_DIR, 0);
        analogWrite(R_PWM, V);
    } 
    else
    {
    V = abs(V); 
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(R_DIR, 1);
    analogWrite(R_PWM, V); 
    }
} 
void stopMotors(){
    analogWrite(L_PWM, 0);
    analogWrite(R_PWM, 0);
}