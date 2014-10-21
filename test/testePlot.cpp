#include "../lib/imports.h"

int main(){
	Plot *p = new Plot();


	double erro1 = pow(10,-7);
	Secante2* secante = new Secante2(3.0, 4.0, 0, erro1, erro1);

	secante->loop();

	p->line(secante->getAllResults());

}