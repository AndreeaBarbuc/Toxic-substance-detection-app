#include "led.h"
#include "buzzer.h"
#include "motor.h"
#include "senzor_gaz.h"

#define ROSU 3
#define VERDE 5
#define ALBASTRU 6

#define BUZZER 13

#define SENZOR A1

#define MOTORSPEED 12
#define DIRA 9
#define DIRB 8

// Valori de referinta
int sensorThres = 430; //valoare referinta senzor (limita)
int med_yellow = sensorThres / 4;
int med_usor = sensorThres - med_yellow; //valoare apropiata de limita -> culoare galbena
int med_grav = sensorThres - med_yellow/2; //valoare foarte apropiata de limita -> culoare mov

//construim obiectele
Led rosu(ROSU);
Led verde(VERDE);
Led albastru(ALBASTRU);

Buzzer buzzer(BUZZER);

Motor motor(MOTORSPEED, DIRA, DIRB);

Senzor senzor(SENZOR);

void setup() 
{
	Serial.begin(9600); //initializam pentru afisarea pe ecran (Serial Monitor)
}

void loop() 
{
 	int val_senzor = senzor.date_senzor(SENZOR); //captam datele de la senzor si le stocam intr-o valoare
 	
 	if (val_senzor >= sensorThres) // daca depaseste limita impusa
 	{
 		rosu.on(); //se aprinde led-ul rosu
 		buzzer.sirena(BUZZER); // sirena incepe sa se auda
 		if(val_senzor >= sensorThres + 30) //daca depaseste limita si mai mult
 		{
 			motor.reglare_viteza(MOTORSPEED, DIRA, DIRB, sensorThres + 30); //porneste elicea care raspandeste substanta
		}
	}
	else if(val_senzor >= med_usor && val_senzor < med_grav) // daca se valoare citita se apropie de limita
	{
      motor.off(MOTORSPEED, DIRA, DIRB);
      // se aprinde un led relativ galben, intensitatea acestuia este data de cantitatea de substanta detectata
	    rosu.reglare_intensitate(ROSU, val_senzor, med_grav);
	    verde.reglare_intensitate(VERDE, val_senzor, med_grav);
	    buzzer.reglare_sunet(BUZZER, val_senzor); // se porneste alarma, avand intensitatea sunetului direct proportionala cu cantitatea substantei
	}
    else if(val_senzor >= med_grav) // daca se valoare citita se apropie foarte mult de limita
	{
	    motor.off(MOTORSPEED, DIRA, DIRB);
      // se aprinde un led relativ galben, intensitatea acestuia este data de cantitatea de substanta detectata
	    albastru.reglare_intensitate(ALBASTRU, val_senzor, sensorThres);
      rosu.reglare_intensitate(ROSU, val_senzor, sensorThres); 
	    buzzer.reglare_sunet(BUZZER, val_senzor); // se porneste alarma, avand intensitatea sunetului direct proportionala cu cantitatea substantei
	}
	else // daca totul este in regula
	{   
      buzzer.off(); 
      motor.off(MOTORSPEED, DIRA, DIRB);
	    verde.verde(VERDE, med_usor, val_senzor); //se aprinde un led verde
	}

}
