#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer 
{
  private:
    byte pin;
    
  public:
  	Buzzer();
    Buzzer(byte pin);
    void init();
    void reglare_sunet(byte, int);
    void sirena(byte);
    void off();
    ~Buzzer();
};

#endif
