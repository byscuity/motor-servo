#include <Servo.h>

Servo servo1;
Servo servo2;

const int led1Pin = 2;
const int led2Pin = 3;

int posAnteriorS1 = 90;
int posAnteriorS2 = 90;

void setup() {
  Serial.begin(9600);
  
  servo1.attach(9);
  servo2.attach(10);
  
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  
  servo1.write(90);
  servo2.write(90);
  
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    String dados = Serial.readStringUntil('\n');
    dados.trim();

    if (dados.startsWith("S1:")) {
      int angulo = dados.substring(3).toInt();
      
      if (angulo != posAnteriorS1) {
        digitalWrite(led1Pin, HIGH); // Acende o LED quando o servo se move
        servo1.write(angulo);
        posAnteriorS1 = angulo;
        delay(150);
        digitalWrite(led1Pin, LOW);  // Apaga o LED após o movimento
      }
    } 
    else if (dados.startsWith("S2:")) {
      int angulo = dados.substring(3).toInt();
      
      if (angulo != posAnteriorS2) {
        digitalWrite(led2Pin, HIGH); // Acende o LED quando o servo se move
        servo2.write(angulo);
        posAnteriorS2 = angulo;
        delay(150);
        digitalWrite(led2Pin, LOW);  // Apaga o LED após o movimento
      }
    }
  }
}
