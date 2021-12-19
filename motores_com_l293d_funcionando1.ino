#include <Servo.h>

//Motor 1 
int PinoVelocidade1e2 = 11;
int Entrada1 = 6; 
int Entrada2 = 5;
// Motor 2
int PinoVelocidade3e4 = 10; 
int Entrada3 = 4;
int Entrada4 = 3;
// Sensor ultra sonico
int Trig = 9;
int Eccho = 8;
// Botao
int Botao = 2;
// Informação do Botao
int botread = 0;
// Velocidade dos motores, o máximo é 255
int Velocidade = 127; 
// Informações da distancia do sensor
int distanceThreshold = 0;
// Medida do sensor ultra sonico
int cm = 0;

// Pegando a informação da distncia dos objetos com o sensor ultra sonico
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Coloca o trigger pin ligado ate 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Ler o echo pin, e devolve o som
  return pulseIn(echoPin, HIGH);
}

Servo servo7;  
 
  void setup() { 
  // Motor 1  
  pinMode(PinoVelocidade1e2, OUTPUT);
  pinMode(Entrada1, OUTPUT);  
  pinMode(Entrada2, OUTPUT);
  // Motor 2
  pinMode(PinoVelocidade3e4, OUTPUT);
  pinMode(Entrada3, OUTPUT);
  pinMode(Entrada4, OUTPUT);
  // Botao
  pinMode(Botao, INPUT);
  // Servo motor
  servo7.attach(7);
  // Pegando as informações dos senor ultra sonico
  pinMode(Trig, INPUT);
  pinMode(Eccho, INPUT);
  
  // Colocando o servo motor na posição certa  
  servo7.write(0);
}  
   
  void loop() { 
  // Lendo se o botao foi pressionado
  botread = digitalRead(Botao);
  // Convertendo a informação do sensor para cm
  cm = 0.01723 * readUltrasonicDistance(Trig, Eccho);
  Serial.println(cm);

  if(5 < cm) {
    if(botread == HIGH) {
      para();
      delay(2000);
      re();
      delay(3000);
      servo7.write(45); // 45 é o angulo que ele vira
      delay(1000);
      frente();
      delay(3000);
      servo7.write(0); // Voltando o servo motor na posição inicial
    }
    if(botread == LOW) {
     para();
      delay(2000);
      re();
      delay(3000);
      servo7.write(45); // 45 é o angulo que ele vira
      delay(1000);
      frente();
      delay(3000);
      servo7.write(0); // Voltando o servo motor na posição inicial
    }
  }
  if(5 > cm) {
    if(botread == HIGH) {
      para();
      delay(2000);
      re();
      delay(3000);
      servo7.write(45); // 45 é o angulo que ele vira
      delay(1000);
      frente();
      delay(3000);
      servo7.write(0); // Voltando o servo motor na posição inicial
    }
    if(botread == LOW) {
      frente();
      }
  }
} 

void frente() {
  // Motor 1
  digitalWrite(Entrada1, HIGH);  
  digitalWrite(Entrada2, LOW);
  analogWrite(PinoVelocidade1e2, Velocidade);
  // Motor 2
  digitalWrite(Entrada3, HIGH);
  digitalWrite(Entrada4, LOW);
  analogWrite(PinoVelocidade3e4, Velocidade);
}
void re() {
  // Motor 1
  digitalWrite(Entrada1, LOW);  
  digitalWrite(Entrada2, HIGH);
  analogWrite(PinoVelocidade1e2, Velocidade);
  // Motor 2
  digitalWrite(Entrada3, LOW);
  digitalWrite(Entrada4, HIGH);
  analogWrite(PinoVelocidade3e4, Velocidade);
}
void para() {
    // Motor 1
  digitalWrite(Entrada1, LOW);  
  digitalWrite(Entrada2, LOW);
  analogWrite(PinoVelocidade1e2, Velocidade);
  // Motor 2
  digitalWrite(Entrada3, LOW);
  digitalWrite(Entrada4, LOW);
  analogWrite(PinoVelocidade3e4, Velocidade);
}
     