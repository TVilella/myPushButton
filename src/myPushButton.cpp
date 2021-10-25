#include "myPushButton.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

myPushButton::myPushButton (byte pinBotao , int tempoDebounce){
  pinMode( pinBotao , INPUT_PULLUP ); //Indicando modo do pino como input usando o resistor de pullup interno
  debounceBotao = millis();
  pino = pinBotao;
  tempo = tempoDebounce;
}

void myPushButton::lerBotao() {
  estadoBotao = digitalRead(pino);
  apertado = false;
  solto = false;

  if ( ( millis() - debounceBotao ) > tempo ){
    if (!estadoBotao && estadoBotaoAnt) {
      apertado = true;
      debounceBotao = millis();
    } else if (estadoBotao && !estadoBotaoAnt) {
      solto = true;
      debounceBotao = millis();
    }
  }
  
  if (estadoBotao && !estadoBotaoAnt) {
         debounceBotao = millis();
  }
  
  estadoBotaoAnt = estadoBotao;
}

bool myPushButton::pressed(){
  return apertado;
}

bool myPushButton::released(){
  return solto;
}