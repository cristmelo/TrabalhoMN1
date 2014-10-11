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

	double aux = getAproximacaoSeguinteDaRaiz();

	setAproximacaoSeguinteDaRaiz(iterationFunction(getAproximacaoAtualDaRaiz())/(function(getAproximacaoSeguinteDaRaiz()) - function(getAproximacaoAtualDaRaiz())));
	
	setAproximacaoAtualDaRaiz(aux);
}

void Secante2::loop() {

	salvarEmLista();

	do{
	
		calcularAproximacaoSeguinte();
		salvarEmLista();
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
