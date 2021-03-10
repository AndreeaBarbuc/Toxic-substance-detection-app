#include "buzzer.h"

Buzzer::Buzzer()
{	
}

Buzzer::Buzzer(byte pin) 
{
  this->pin = pin;
  init();
}

void Buzzer::init() 
{
  pinMode(pin, OUTPUT);
  off();
}

void Buzzer::reglare_sunet(byte buzzer, int val_senzor) 
{
	tone(buzzer,val_senzor);  //intensitatea sunetului este stabilita de cantitatea detectata de catre senzor
}

void Buzzer::sirena(byte buzzer)
{
   tone(buzzer,494,500);
    delay(30);
    noTone(buzzer);
    tone(buzzer,523,300);
    delay(20);
    tone(buzzer,994,1000);
    delay(30);
    noTone(buzzer);
    tone(buzzer,1023,800);
    delay(20);
}

void Buzzer::off() 
{
  noTone(pin);
}

Buzzer::~Buzzer()
{
}
