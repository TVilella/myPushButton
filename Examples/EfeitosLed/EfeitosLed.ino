/*
 *  AUTOR:      Thiago Vilella
 *  YOUTUBE:    https://www.youtube.com/channel/UCpg7_v1Wtvp-XPj-vjh8igQ
 *  CURSO ARDUINO:  http://bit.ly/2ZhypC9
 *  CURSO ROBOTICA: http://bit.ly/2zjK9Eo
 *  COMPRE:     https://www.arducore.com.br/
 *  SKETCH:     EfeitosLed | Exemplo da biblioteca myPushButton.h
 *  VERSÃO:     1.0.2
 *  DATA:     22/08/2019
*/

// INCLUSÃO DE BIBLIOTECAS
#include "myPushButton.h"

// DEFINIÇÕES DE PINOS
#define pinLEDVm 10
#define pinLEDAm 9
#define pinLEDAz 8

#define pinBotao1 7
#define pinBotao2 6
#define pinBotao3 5

// DEFINIÇÕES


#define DEBUG
// INSTANCIANDO OBJETOS
myPushButton botao1(pinBotao1);
myPushButton botao2(pinBotao2);
myPushButton botao3(pinBotao3);

// DECLARAÇÃO DE FUNÇÕES


// DECLARAÇÃO DE VARIÁVEIS	
byte contador = 0;

void setup() {
  pinMode(pinLEDVm, OUTPUT);
  pinMode(pinLEDAm, OUTPUT);
  pinMode(pinLEDAz, OUTPUT);
}

void loop() {
  botao1.lerBotao();
  botao2.lerBotao();
  botao3.lerBotao();

  if (botao1.pressed()) {
     contador++;
  }

  if (botao2.pressed()) {
     contador--;
  }

  if (botao3.pressed()) {
     contador = 0;
  }


  if (contador >= 5) {
     digitalWrite(pinLEDVm, HIGH);
  } else {
     digitalWrite(pinLEDVm, LOW);
  }

  if (contador >= 10) {
     digitalWrite(pinLEDAm, HIGH);
  } else {
     digitalWrite(pinLEDAm, LOW);
  }

  if (contador >= 15) {
     digitalWrite(pinLEDAz, HIGH);
  } else {
     digitalWrite(pinLEDAz, LOW);
  }
}