#include <Servo.h>


int PinoVelocidade1e2 = 13;
int PinoVelocidade3e4 = 12;  
int Entrada1 = 8; 
int Entrada2 = 9;
int Entrada3 = 10;
int Entrada4 = 11;

int Botao = 2;

int BotRead = 0;
int Velocidade = 127; 
int distanceThreshold = 0;
int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_5;

void setup()  
{  
  //Define os pinos como saida  
  pinMode(PinoVelocidade1e2, OUTPUT);
  pinMode(PinoVelocidade3e4, OUTPUT);
  pinMode(Entrada1, OUTPUT);  
  pinMode(Entrada2, OUTPUT);
  pinMode(Entrada3, OUTPUT);
  pinMode(Entrada4, OUTPUT);
  pinMode(Botao, INPUT);
  servo_5.attach(5);
}  
   
void loop()  
{  
  BotRead = digitalRead(Botao); 
  cm = 0.01723 * readUltrasonicDistance(13, 12);
  Serial.println(cm);
  
  if(5.5 < cm) {
    if(BotRead == HIGH) {
      parado();
      delay(1000);
      re();}
  }
  
 }


void frente() {
  digitalWrite(Entrada1, HIGH);  
  digitalWrite(Entrada2, LOW);
  digitalWrite(Entrada3, HIGH);
  digitalWrite(Entrada4, LOW);
  analogWrite(PinoVelocidade1e2, Velocidade);
  analogWrite(PinoVelocidade3e4, Velocidade);
}

void re(){
  digitalWrite(Entrada1, LOW);  
  digitalWrite(Entrada2, HIGH);
  digitalWrite(Entrada3, LOW);
  digitalWrite(Entrada4, HIGH); 
  analogWrite(PinoVelocidade1e2, Velocidade);
  analogWrite(PinoVelocidade3e4, Velocidade);
}

void parado() {
  digitalWrite(Entrada1, LOW);
  digitalWrite(Entrada2, LOW);
  digitalWrite(Entrada3, LOW);
  digitalWrite(Entrada4, LOW);
  analogWrite(PinoVelocidade1e2, Velocidade);
  analogWrite(PinoVelocidade3e4, Velocidade);
}
     