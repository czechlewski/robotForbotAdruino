#define L_PWM 5
#define L_DIR 4
#define R_PWM 6
#define R_DIR 9
#define PWM_MAX 165

#define R_LIGHT_SENSOR A0
#define L_LIGHT_SENSOR A1
#define ROZNICA_MIN -400
#define ROZNICA_MAX 400

#define DIODE 13
#define BUZZER 10
void setup() {
//H bridge configuration 
  pinMode(L_DIR, OUTPUT);
  pinMode(R_DIR, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_PWM, OUTPUT);

  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, 0);

  pinMode(DIODE, OUTPUT);
  digitalWrite(DIODE, 0);
}
void loop() {
    int odczytLewy = analogRead(L_LIGHT_SENSOR);    
    int odczytPrawy = analogRead(R_LIGHT_SENSOR);
    int roznica = odczytLewy - odczytPrawy;
    if (roznica < ROZNICA_MIN) { 
    roznica = ROZNICA_MIN; 
  } else if (roznica > ROZNICA_MAX) { 
    roznica = ROZNICA_MAX; 
  }
  int zmianaPredkosci = map(roznica, ROZNICA_MIN, ROZNICA_MAX, -20, 20);        
  leftMotor(30+zmianaPredkosci);
  rightMotor(30-zmianaPredkosci);
}
//motor Functions
void leftMotor(int V){
    if (V>0){
        V = map(V, 0, 100, 0, PWM_MAX);
        digitalWrite(L_DIR, 1);
        analogWrite(L_PWM, V);
    } 
    else
    {
    V = abs(V); 
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(L_DIR, 0);
    analogWrite(L_PWM, V); 
    }
} 
void rightMotor(int V){
    if (V>0){
        V = map(V, 0, 100, 0, PWM_MAX);
        digitalWrite(R_DIR, 1);
        analogWrite(R_PWM, V);
    } 
    else
    {
    V = abs(V); 
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(R_DIR, 0);
    analogWrite(R_PWM, V); 
    }
} 
void stopMotors(){
    analogWrite(L_PWM, 0);
    analogWrite(R_PWM, 0);
}
void moveForward(int V){
    leftMotor(V);
    rightMotor(V);
}
void turnLeft(int V){
    leftMotor(-V);
    rightMotor(V);
}
void turnRight(int V){
    leftMotor(V);
    rightMotor(-V);
}
//buzzer 
void buzzer(int t, int n){
    for (int i = 0; i < n; i++)
    {
    digitalWrite(BUZZER, 1);
    delay(t);
    digitalWrite(BUZZER,0);
    }
}
//diode 13    
void diode13(int t, int n){
    for (int i = 0; i < n; i++)
    {
    digitalWrite(DIODE,1);
    delay(t);
    digitalWrite(DIODE,0);
    }
}