#include <AFMotor.h>

#include <Servo.h>

// Pines del sensor ultrasónico

const int trigPin = A0;

const int echoPin = A1;

// Motores en el shield

AF_DCMotor motorLeft(1);

AF_DCMotor motorRight(2);

// Servo (en SERVO1 → pin 10 del shield)

Servo servo;

// Variables

int distanciaCentro, distanciaIzquierda, distanciaDerecha;

void setup() {

Serial.begin(9600);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

servo.attach(10);

servo.write(90); // Centra el servo

delay(1000);

motorLeft.setSpeed(200);

motorRight.setSpeed(200);

}

void loop() {

servo.write(90);

distanciaCentro = medirDistancia();

Serial.print("Centro: ");

Serial.println(distanciaCentro);

if (distanciaCentro > 20) {

avanzar();

} else {

frenar();

retroceder();

delay(500);

frenar();



// Mirar a la izquierda

servo.write(0);

delay(600);

distanciaIzquierda = medirDistancia();

Serial.print("Izquierda: ");

Serial.println(distanciaIzquierda);



// Mirar a la derecha

servo.write(180);

delay(600);

distanciaDerecha = medirDistancia();

Serial.print("Derecha: ");

Serial.println(distanciaDerecha);



// Volver al centro

servo.write(90);

delay(300);



// Elegir el lado más libre

if (distanciaIzquierda > distanciaDerecha) {

  girarIzquierda();

  delay(500);

} else {

  girarDerecha();

  delay(500);

}

frenar();

}

}

// -------- FUNCIONES DE MOVIMIENTO --------

void avanzar() {

motorLeft.run(FORWARD);

motorRight.run(FORWARD);

}

void retroceder() {

motorLeft.run(BACKWARD);

motorRight.run(BACKWARD);

}

void frenar() {

motorLeft.run(RELEASE);

motorRight.run(RELEASE);

}

void girarDerecha() {

motorLeft.run(FORWARD);

motorRight.run(BACKWARD);

}

void girarIzquierda() {

motorLeft.run(BACKWARD);

motorRight.run(FORWARD);

}

// -------- FUNCION DE MEDICION --------

int medirDistancia() {

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

long duration = pulseIn(echoPin, HIGH, 20000); // timeout 20 ms

int distancia = duration * 0.034 / 2;

if (distancia == 0) distancia = 100; // Evita lecturas erróneas

return distancia;

}