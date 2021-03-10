#include "motor.h"

Motor::Motor()
{	
}

Motor::Motor(byte motorspeed_pin, byte DIRA, byte DIRB) 
{
  this->motorspeed_pin = motorspeed_pin;
  this->DIRA = DIRA;
  this->DIRB = DIRB;
  init();
}

void Motor::init() 
{
  pinMode(motorspeed_pin, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  off(motorspeed_pin, DIRA, DIRB);
}

void Motor::reglare_viteza(byte motorspeed_pin, byte DIRA, byte DIRB, int val_senzor) 
{
  //porneste motorul
  analogWrite(motorspeed_pin, val_senzor + 200);
  //schimb motorul in fiecare directie, pe rand
  analogWrite(DIRA, val_senzor + 200);
  digitalWrite(DIRB, LOW);
  digitalWrite(DIRA, LOW);
  analogWrite(DIRB, val_senzor + 200);
}

void Motor::off(byte motorspeed_pin, byte DIRA, byte DIRB) 
{
  //opreste motorul
  digitalWrite(motorspeed_pin, LOW);
  //daca motorul e pornit atunci aceste instructiuni sunt irelevante
  //opreste cate o parte
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}

Motor::~Motor()
{
}
