#include "led.h"

Led::Led()
{	
}

Led::Led(byte pin) 
{
  this->pin = pin;
  init();
}

void Led::init() 
{
  pinMode(pin, OUTPUT);
  off();
}

int Led::intensitate(int val_senzor, int limita)	//creste intensitatea luminoasa a led-ului odata cu cresterea gazelor detectate
{
	int valoare = val_senzor * (255 / limita); // se regleaza datele primite prin transformarea lor in valori corespunzatoare intervalului de functionare a afisarii led-ului
	return valoare;
}

void Led::reglare_intensitate(byte pin, int val_senzor, int limita) 
{
	int valoare = intensitate(val_senzor, limita);
  	analogWrite(pin, valoare); //se modifica intensitatea luminoasa in functie de valoarea calculata
}

void Led::verde(byte pin, int limita, int val_senzor)	//scade intensitatea led-ului verde odata cu cresterea detectiei de gaz
{
	int val_nou = limita - val_senzor;// ne asiguram de proprietatea de invers proportionalitate
	int valoare = val_nou * (255 / limita);// stabilim care este valoarea pe care trebuie sa o primeasca data primita pentru a putea fi reprezentata corect de catre led
	if(valoare < 127) valoare = 127; //127 semnifica jumatatea "intensitatii luminoase", 
									//astfel led-ul nu se va stinge cand se va apropia de urmatoarea valoare "limita"
	analogWrite(pin, valoare);
}

void Led::off() 
{
  digitalWrite(pin, LOW);
}

void Led::on() 
{
  digitalWrite(pin, HIGH);
}

Led::~Led()
{
}
