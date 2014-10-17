#include "../lib/imports.h"

int main(){

	Methods *a = new Methods(0, 1.0, 0.0001, 20);
	
	//a->print_values();

	a->Bisection();

	a->Regula_Falsi();


	return 0;

}