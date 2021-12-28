// Definindo o servo
#define servo1 7
// Motor 1 
int PinoVelocidade1e2 = 11;
int Entrada1 = 6; 
int Entrada2 = 5;
// Motor 2
int PinoVelocidade3e4 = 10; 
int Entrada3 = 3;
int Entrada4 = 2;
// Sensor ultra sonico
int Trig = 9;
int Eccho = 8;
// Botao
int Botao = 4;
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

void servo0graus();
void servo45graus();
void servo90graus();
void servo180graus();

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
  // Servo
  pinMode(servo1, OUTPUT);  
  // Pegando as informações dos senor ultra sonico
  pinMode(Trig, INPUT);
  pinMode(Eccho, INPUT);
  
  // Colocando o Servo na Posição 0° graus
  for(char i=0;i<100;i++) servo0graus();  
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
      frente();
      for(char i=0;i<100;i++) servo45graus();
      delay(3000);
      for(char i=0;i<100;i++) servo0graus();
     }
    if(botread == LOW) {
      para();
      delay(2000);
      re();
      delay(3000);
      frente();
      for(char i=0;i<100;i++) servo45graus();
      delay(3000);
      for(char i=0;i<100;i++) servo0graus();
     }
  }
  if(5 > cm) {
    if(botread == HIGH) {
      para();
      delay(2000);
      re();
      delay(3000);
      frente();
      for(char i=0;i<100;i++) servo45graus();
      delay(3000);
      for(char i=0;i<100;i++) servo0graus();
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

void servo0graus()              //Posiciona o servo em 0 graus
{
   digitalWrite(servo1, HIGH);  //pulso do servo
   delayMicroseconds(600);      //0.6ms
   digitalWrite(servo1, LOW);   //completa periodo do servo
   for(int i=0;i<32;i++)delayMicroseconds(600);
                               // 20ms = 20000us
                               // 20000us - 600us = 19400us
                               // 19400/600 = ~~32

} //end servo0graus


void servo45graus()
{
  digitalWrite(servo1, HIGH);
  delayMicroseconds(1050);
  digitalWrite(servo1, LOW);
  for(int i=0;i<18;i++)delayMicroseconds(1050);
}


void servo90graus()             //Posiciona o servo em 90 graus
{
   digitalWrite(servo1, HIGH);  //pulso do servo
   delayMicroseconds(1500);     //1.5ms
   digitalWrite(servo1, LOW);   //completa periodo do servo
   for(int i=0;i<12;i++)delayMicroseconds(1500);
                               // 20ms = 20000us
                               // 20000us - 1500us = 18500us
                               // 18500/1500 = ~~12 

} //end servo0graus


void servo180graus()             //Posiciona o servo em 180 graus
{
   digitalWrite(servo1, HIGH);  //pulso do servo
   delayMicroseconds(2400);     //2.4ms
   digitalWrite(servo1, LOW);   //completa periodo do servo
   for(int i=0;i<7;i++)delayMicroseconds(2400);
                               // 20ms = 20000us
                               // 20000us - 2400us = 17600us
                               // 17600/2400 = ~~7

} //end servo0graus
     
