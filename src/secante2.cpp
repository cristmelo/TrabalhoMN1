#include "../lib/imports.h"


Secante2::Secante2(double aproximacaoInicialDaRaiz, double aproximacaoSeguinte, double a, double erro1, double erro2) 
					:GenericMethod(aproximacaoInicialDaRaiz, a, erro1, erro2){

	setAproximacaoSeguinteDaRaiz(aproximacaoSeguinte);
};

double Secante2::iterationFunction(double x)	 {

	return x*function(getAproximacaoSeguinteDaRaiz()) - getAproximacaoSeguinteDaRaiz()*function(x);
}

bool Secante2::testeParadaErro1() {

	return (abs(function(getAproximacaoSeguinteDaRaiz())) < getErro1());
}

void Secante2::calcularAproximacaoSeguinte() {
	cout << "aproxAtual: " << getAproximacaoAtualDaRaiz() << endl;
	cout << "aproxSeguinte: " << getAproximacaoSeguinteDaRaiz() << endl;
	cout << "a: " << getA() << endl;
	cout << "erro1: " << getErro1() << endl;
	cout << "testeParadaErro1: " << testeParadaErro1() << endl;
	cout << "testeParadaErro2: " << testeParadaErro2() << endl << endl;

	double aux = getAproximacaoSeguinteDaRaiz();

	setAproximacaoSeguinteDaRaiz(iterationFunction(getAproximacaoAtualDaRaiz())/(function(getAproximacaoSeguinteDaRaiz()) - function(getAproximacaoAtualDaRaiz())));
	
	setAproximacaoAtualDaRaiz(aux);

	cout << "aproxAtual: " << getAproximacaoAtualDaRaiz() << endl;
	cout << "aproxSeguinte: " << getAproximacaoSeguinteDaRaiz() << endl;
	cout << "a: " << getA() << endl;
	cout << "erro1: " << getErro1() << endl;
	cout << "testeParadaErro1: " << testeParadaErro1() << endl;
	cout << "testeParadaErro2: " << testeParadaErro2() << endl << endl;

}

void Secante2::loop() {

	salvarEmLista();

	do{
	
		calcularAproximacaoSeguinte();
		salvarEmLista();
		cout << "testeParadaErro1: " << testeParadaErro1() << endl;
	cout << "testeParadaErro2: " << testeParadaErro2() << endl << endl;
	}while(!testeParadaErro1() && !testeParadaErro2());
}

void Secante2::setMaxInteration(double maxInteration){
	this->maxInteration = maxInteration;
}

double Secante2::getValue(){
	return this->value;
}

double Secante2::getMaxInteration(){
	return this->maxInteration;
}
