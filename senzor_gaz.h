#ifndef SENZOR_GAZ_H
#define SENZOR_GAZ_H

#include <Arduino.h>

class Senzor 
{
  private:
    byte pin;
    
  public:
  	Senzor();
    Senzor(byte);
    void init();
	int date_senzor(byte);
	void afisare();
    ~Senzor();
};

#endif
