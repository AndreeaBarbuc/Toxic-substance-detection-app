#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led 
{
  private:
    byte pin;
    
  public:
  	Led();
    Led(byte pin);
    void init();
    int intensitate(int, int);
    void reglare_intensitate(byte, int, int);
    void verde(byte, int, int);
    void off();
    void on(); 
    ~Led();
};

#endif
