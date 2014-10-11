#include "../lib/imports.h"

int main(){

	cout << setprecision(9);

	double erro1 = pow(10,-7);

	Secante2* zeroPelaSecante = new Secante2(3.0, 4.0, 0, erro1, erro1);

	zeroPelaSecante->loop();
	zeroPelaSecante->show();

	return 0;
}