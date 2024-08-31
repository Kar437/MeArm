int velocidade = 10;

#include <Servo.h>

// Define os pinos dos joysticks
#define VRx1 A1
#define VRy1 A0
#define VRx2 A2
#define VRy2 A3

// Define os servos
Servo servo1; // Servo controlado pelo eixo X do Joystick 1
Servo servo2; // Servo controlado pelo eixo Y do Joystick 1
Servo servo3; // Servo controlado pelo eixo X do Joystick 2
Servo servo4; // Servo controlado pelo eixo Y do Joystick 2

// Pinos para botão e LED
#define pinBot 13
#define pinLed 10

// Variáveis de controle de ângulo para cada servo
int angulox1 = 90;
int anguloy1 = 90;
int angulox2 = 90;
int anguloy2 = 90;

int tempo = 10;  // Delay para suavizar o movimento
int tempo2 = 500;
int zonaMorta = 70;  // Zona morta para evitar movimentos indesejados

bool automatico = false;

void setup() {
  // Configura os pinos dos joysticks como entrada
  pinMode(VRx1, INPUT);
  pinMode(VRy1, INPUT);
  pinMode(VRx2, INPUT);
  pinMode(VRy2, INPUT);
  
  // Configura os pinos do botão e do LED
  pinMode(pinBot, INPUT);
  pinMode(pinLed, OUTPUT);

  // Anexa os servos aos pinos PWM
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);

  Serial.begin(9600);
}

void loop() {
  int estadoB = digitalRead(pinBot);
  if (estadoB == HIGH) {
    automatico = !automatico;
    digitalWrite(pinLed, automatico);
    delay(300); // Debouncing delay
  }

  if (automatico) {
    moveServoAutomatico();
  } else {
    controleManual();
  }
}

void controleManual() {
  int valorVRx1 = analogRead(VRx1);
  int valorVRy1 = analogRead(VRy1);
  int valorVRx2 = analogRead(VRx2);
  int valorVRy2 = analogRead(VRy2);
  Serial.print("angulox1: ");
  Serial.println(angulox1);
  
  Serial.print("anguloy1: ");
  Serial.println(anguloy1);
  
  Serial.print("angulox2: ");  
  Serial.println(angulox2);
  
  Serial.print("anguloy2: ");
  Serial.println(anguloy2);
  
  Serial.println("-------------------");


  // Controla o eixo X do Joystick 1
  if (valorVRx1 < 512 - zonaMorta) {
    angulox1 -= velocidade;
    if (angulox1 < 0) angulox1 = 0;
    servo1.write(angulox1);
  } else if (valorVRx1 > 512 + zonaMorta) {
    angulox1 += velocidade;
    if (angulox1 > 180) angulox1 = 180;
    servo1.write(angulox1);
    Serial.print("angulox1: ");
  Serial.println(angulox1);
  
  Serial.print("anguloy1: ");
  Serial.println(anguloy1);
  
  Serial.print("angulox2: ");  
  Serial.println(angulox2);
  
  Serial.print("anguloy2: ");
  Serial.println(anguloy2);
  
  Serial.println("-------------------");
  }

  // Controla o eixo Y do Joystick 1
  if (valorVRy1 < 512 - zonaMorta) {
    anguloy1 -= velocidade;
    if (anguloy1 < 0) anguloy1 = 0;
    servo2.write(anguloy1);
  } else if (valorVRy1 > 512 + zonaMorta) {
    anguloy1 += velocidade;
    if (anguloy1 > 180) anguloy1 = 180;
    servo2.write(anguloy1);
    Serial.print("angulox1: ");
  Serial.println(angulox1);
  
  Serial.print("anguloy1: ");
  Serial.println(anguloy1);
  
  Serial.print("angulox2: ");  
  Serial.println(angulox2);
  
  Serial.print("anguloy2: ");
  Serial.println(anguloy2);
  
  Serial.println("-------------------");
  }

  // Controla o eixo X do Joystick 2
  if (valorVRx2 < 512 - zonaMorta) {
    angulox2 -= velocidade;
    if (angulox2 < 0) angulox2 = 0;
    servo3.write(angulox2);
  } else if (valorVRx2 > 512 + zonaMorta) {
    angulox2 += velocidade;
    if (angulox2 > 180) angulox2 = 180;
    servo3.write(angulox2);
    Serial.print("angulox1: ");
  Serial.println(angulox1);
  
  Serial.print("anguloy1: ");
  Serial.println(anguloy1);
  
  Serial.print("angulox2: ");  
  Serial.println(angulox2);
  
  Serial.print("anguloy2: ");
  Serial.println(anguloy2);
  
  Serial.println("-------------------");
  }

  // Controla o eixo Y do Joystick 2
  if (valorVRy2 < 512 - zonaMorta) {
    anguloy2 -= velocidade;
    if (anguloy2 < 0) anguloy2 = 0;
    servo4.write(anguloy2);
  } else if (valorVRy2 > 512 + zonaMorta) {
    anguloy2 += velocidade;
    if (anguloy2 > 180) anguloy2 = 180;
    servo4.write(anguloy2);
    Serial.print("angulox1: ");
  Serial.println(angulox1);
  
  Serial.print("anguloy1: ");
  Serial.println(anguloy1);
  
  Serial.print("angulox2: ");  
  Serial.println(angulox2);
  
  Serial.print("anguloy2: ");
  Serial.println(anguloy2);
  
  Serial.println("-------------------");
  }

  delay(tempo);  // Pequeno delay para suavizar o movimento
}

void moveServoAutomatico() {
  while (automatico) {
    // 1ª posição
    for (int pos = servo1.read(); pos >= 10; pos--) {
      
      verificaBotao();
      servo1.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
      
    }
    for (int pos = servo2.read(); pos <= 110; pos++) {
      
      verificaBotao();
      servo2.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
      
    }
    for (int pos = servo3.read(); pos <= 130; pos++) {
      
      verificaBotao();
      servo3.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
      
    }
    for (int pos = servo4.read(); pos >= 55; pos--) {
      
      verificaBotao();
      servo4.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
      
    }
    delay(tempo2);

    // 2ª posição
    for (int pos = servo1.read(); pos >= 10; pos--) {
      
      verificaBotao();
      servo1.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
    }
    for (int pos = servo2.read(); pos <= 175; pos++) {
      
      verificaBotao();
      servo2.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
      
    }
    for (int pos = servo3.read(); pos >= 65; pos--) {
      
      verificaBotao();
      servo3.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
      
    }
    for (int pos = servo4.read(); pos >= 55; pos--) {
      
      verificaBotao();
      servo4.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
      
    }
    delay(tempo2);

    // 3ª posição
    for (int pos = servo1.read(); pos <= 175; pos++) {
     
      verificaBotao();
      servo1.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
    }
    for (int pos = servo2.read(); pos >= 125; pos--) {
      
      verificaBotao();
      servo2.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
    }
    for (int pos = servo3.read(); pos <= 125; pos++) {
      
      verificaBotao();
      servo3.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
      
    }
    for (int pos = servo4.read(); pos >= 55; pos--) {
      
      verificaBotao();
      servo4.write(pos);
      verificaBotao();
      delay(tempo);
      verificaBotao();
      
    }
    delay(tempo2);
  }
}


// Função que verifica se o botão foi apertado
void verificaBotao() {
  int estadoB = digitalRead(pinBot);
  if (estadoB == HIGH) {
    automatico = false;
    digitalWrite(pinLed, LOW);
    delay(300); 
  }
}