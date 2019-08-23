#ifndef myPushButton_h
#define myPushButton_h

#include "Arduino.h"

class myPushButton {
  public:
    myPushButton (byte pinBotao , int tempoDebounce = 200 );
    void lerBotao();
    bool pressed();
    bool unpressed();
  private:
    unsigned long debounceBotao;
    bool estadoBotaoAnt = HIGH;
    bool estadoBotao;
    bool apertado;
    bool soltado;
    byte pino;
    byte tempo;  
};

#endif