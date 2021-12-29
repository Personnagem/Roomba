// Definindo o servo
#define servo1 7
//Motor 1 
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
{ // Abre a leitura do sensor
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
}// Fecha a leitura do sensor

void servo0graus(); // Servo motor movendo para 0° graus
void servo45graus(); // Servo motor movendo para 45° graus
void servo90graus(); // Servo motor movendo para 90° graus
void servo180graus(); // Servo motor movendo para 180° graus

  void setup() { // Abre setup 
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
  
  // Coloca o Servo na Posição 0° graus
  for(char i=0;i<100;i++) servo0graus();  
} // Fecha setup  
   
  void loop() { // Abrindo loop
  // Lendo se o botao foi pressionado
  botread = digitalRead(Botao);
  // Converte a informação do sensor para cm
  cm = 0.01723 * readUltrasonicDistance(Trig, Eccho);
  Serial.println(cm);

  if(5 < cm) { // Abre if.1
    if(botread == HIGH) { // Abre if.1.1
      // Para os motores 1 e 2
      para();
      // Delay de 2 sec
      delay(2000);
      // Inverte a polaridade dos motores 1 e 2
      re();
      // Delay de 3 sec
      delay(3000);
      // Joga energia para os motores 1 e 2
      frente();
      // Move o servo motor para a posição de 45° graus
      for(char i=0;i<100;i++) servo45graus();
      // Delay de 3 sec
      delay(3000); 
      // Move o servo motor para a posição de 0° graus
      for(char i=0;i<100;i++) servo0graus(); 
     } // Fecha if.1.1
    if(botread == LOW) { // Abrindo if.1.2
      // Para os motores 1 e 2
      para();
      // Delay de 2 sec
      delay(2000);
      // Inverte a polaridade dos motores 1 e 2
      re();
      // Delay de 3 sec
      delay(3000);
      // Joga energia para os motores 1 e 2
      frente();
      // Move o servo motor para a posição de 45° graus
      for(char i=0;i<100;i++) servo45graus();
      // Delay de 3 sec
      delay(3000); 
      // Move o servo motor para a posição de 0° graus
      for(char i=0;i<100;i++) servo0graus(); 
     } // Fecha if.1.2
  } // Fecha if.1
  if(5 > cm) { // Abrindo if.2
    if(botread == HIGH) { // Abre if.2.1
      // Para os motores 1 e 2
      para();
      // Delay de 2 sec
      delay(2000);
      // Inverte a polaridade dos motores 1 e 2
      re();
      // Delay de 3 sec
      delay(3000);
      // Joga energia para os motores 1 e 2
      frente();
      // Move o servo motor para a posição de 45° graus
      for(char i=0;i<100;i++) servo45graus();
      // Delay de 3 sec
      delay(3000); 
      // Move o servo motor para a posição de 0° graus
      for(char i=0;i<100;i++) servo0graus(); 
    } // Fecha if.2.1
    if(botread == LOW) { // Abrindo if.2.2
      // Joga energia para os motores 1 e 2
      frente();
      } // Fecha if.2.2.
  } // Fecha if.2
} // Fecha loop

void frente() { // Abre frente
  // Motor 1
  digitalWrite(Entrada1, HIGH);  
  digitalWrite(Entrada2, LOW);
  analogWrite(PinoVelocidade1e2, Velocidade);
  // Motor 2
  digitalWrite(Entrada3, HIGH);
  digitalWrite(Entrada4, LOW);
  analogWrite(PinoVelocidade3e4, Velocidade);
} // Fecha frente
void re() { // Abre re
  // Motor 1
  digitalWrite(Entrada1, LOW);  
  digitalWrite(Entrada2, HIGH);
  analogWrite(PinoVelocidade1e2, Velocidade);
  // Motor 2
  digitalWrite(Entrada3, LOW);
  digitalWrite(Entrada4, HIGH);
  analogWrite(PinoVelocidade3e4, Velocidade);
} // Fech re
void para() { // Abre para
    // Motor 1
  digitalWrite(Entrada1, LOW);  
  digitalWrite(Entrada2, LOW);
  analogWrite(PinoVelocidade1e2, Velocidade);
  // Motor 2
  digitalWrite(Entrada3, LOW);
  digitalWrite(Entrada4, LOW);
  analogWrite(PinoVelocidade3e4, Velocidade);
} // Fecha para

void servo0graus()              // Posiciona o servo em 0 graus
{ // Abre servo0graus
   digitalWrite(servo1, HIGH);  // Pulso do servo
   delayMicroseconds(600);      // 0.6ms
   digitalWrite(servo1, LOW);   // Completa periodo do servo
   for(int i=0;i<32;i++)delayMicroseconds(600);
                               // 20ms = 20000us
                               // 20000us - 600us = 19400us
                               // 19400/600 = ~~32

} // Fecha servo0graus


void servo45graus()				// Posiciona o servo em 45 graus
{ // Abre servo45graus
  digitalWrite(servo1, HIGH);	// Pulso do servo
  delayMicroseconds(1050);		// 1.05ms
  digitalWrite(servo1, LOW);	// Completa periodo do servo
  for(int i=0;i<18;i++)delayMicroseconds(1050);
  								// 20ms = 20000us
  								// 20000us - 1050us = 18950us
  								// 18950/1050 = ~~18
} // Fecha servo45graus


void servo90graus()             // Posiciona o servo em 90 graus
{ // Abre servo90graus
   digitalWrite(servo1, HIGH);  // Pulso do servo
   delayMicroseconds(1500);     // 1.5ms
   digitalWrite(servo1, LOW);   // Completa periodo do servo
   for(int i=0;i<12;i++)delayMicroseconds(1500);
                               // 20ms = 20000us
                               // 20000us - 1500us = 18500us
                               // 18500/1500 = ~~12 

} // Fecha servo0graus


void servo180graus()            // Posiciona o servo em 180 graus
{ // Abre servo180graus
   digitalWrite(servo1, HIGH);  // Pulso do servo
   delayMicroseconds(2400);     // 2.4ms
   digitalWrite(servo1, LOW);   // Completa periodo do servo
   for(int i=0;i<7;i++)delayMicroseconds(2400);
                               // 20ms = 20000us
                               // 20000us - 2400us = 17600us
                               // 17600/2400 = ~~7

} // Fecha servo0graus
     