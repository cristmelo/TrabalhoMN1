#include "../lib/imports.h"


Secante2::Secante2(double aproximacaoInicialDaRaiz, double aproximacaoSeguinteDaRaiz, double a, double Erro1, double Erro2) 
					:GenericMethod(aproximacaoInicialDaRaiz, a, Erro1, Erro2){

	this->aproximacaoSeguinteDaRaiz = aproximacaoSeguinteDaRaiz;
};

double Secante2::iterationFunction(double x)	 {

	return x*function(aproximacaoSeguinteDaRaiz) - aproximacaoSeguinteDaRaiz*function(x);
}

void Secante2::calcularAproximacaoSeguinte() {

	aproximacaoSeguinteDaRaiz = aproximacaoAtualDaRaiz 
			- iterationFunction(aproximacaoAtualDaRaiz)/(function(aproximacaoAtualDaRaiz) - function(aproximacaoSeguinteDaRaiz));
}

void Secante2::loop() {

	do{
		calcularAproximacaoSeguinte();
		salvarEmLista();
	}while(testeParadaErro2());
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
