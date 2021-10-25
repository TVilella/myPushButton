#ifndef myPushButton_h
#define myPushButton_h

#include "Arduino.h"

class myPushButton {
  public:
    myPushButton (byte pinBotao , int tempoDebounce = 50 );
    void lerBotao();
    bool pressed();
    bool released();
  private:
    unsigned long debounceBotao;
    bool estadoBotaoAnt = HIGH;
    bool estadoBotao;
    bool apertado;
    bool solto;
    byte pino;
    byte tempo;  
};

#endif