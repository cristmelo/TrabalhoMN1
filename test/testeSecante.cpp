#include "../lib/imports.h"
int main(){
	Secante *sec = new Secante(3,4,pow(10,-7),pow(10,-7),0,1000000);
	cout << setprecision(9);
	double a = 0;
	//sec->showProcess();
	while(a <= 1){
		cout << "-----------------------------  " << a << "----------------------------------\n";
		sec->showProcess();
		a = a + 0.1;
		sec->setA(a);
	}
	return 0;
}