# Robot-Autonomo
Proyecto de robot autónomo con sensor ultrasónico y control de motores

Este proyecto consiste en un robot móvil autónomo que utiliza un sensor ultrasónico para detectar obstáculos y decidir su dirección de movimiento.
El sistema controla dos motores de tracción mediante un Adafruit Motor Shield, y un servomotor que gira el sensor para escanear el entorno.

 Funcionalidad
Mide la distancia al frente.
Si no hay obstáculo (más de 20 cm), avanza.
Si detecta un obstáculo, se detiene, retrocede y gira hacia el lado con más espacio.
Repite el ciclo continuamente.

Componentes
Arduino UNO o similar
Sensor ultrasónico HC-SR04
Servomotor (para rotar el sensor) Adafruit Motor Shield
Motores DC y chasis de robot

 Librerías
#include <AFMotor.h>
#include <Servo.h>

Tipo de control
El sistema es de lazo cerrado, ya que utiliza la retroalimentación del sensor ultrasónico para decidir el movimiento de los motores. 

Autores
Laime Rodolfo, Olivera Romina y Campos Wendy.

