#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor 
{
  private:
    byte motorspeed_pin, DIRA, DIRB;
    
  public:
  	Motor();
    Motor(byte, byte, byte);
    void init();
    void reglare_viteza(byte, byte, byte, int);
    
    void off(byte, byte, byte);
    ~Motor();
};

#endif
