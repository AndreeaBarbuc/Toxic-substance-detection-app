#include "senzor_gaz.h"

Senzor::Senzor()
{	
}

Senzor::Senzor(byte pin) 
{
  this->pin = pin;
  init();
}

void Senzor::init() 
{
  pinMode(pin, INPUT);
}

int Senzor::date_senzor(byte pin)
{
	int analogSensor = analogRead(pin); // citesc date senzor
	afisare(); // afisarea are loc imediat dupa fiecare citire
	return analogSensor;
}

void Senzor::afisare() // afisez in Serial Monitor
{
  Serial.print("Pin: ");
  Serial.println(analogRead(pin));
}

Senzor::~Senzor()
{
}
