#include "../lib/imports.h"


Secante2::Secante2(double aproximacaoInicialDaRaiz, double aproximacaoSeguinte, double a, double erro1, double erro2) 
					:GenericMethod(aproximacaoInicialDaRaiz, a, erro1, erro2){
    this->useTest1 = true;
	setAproximacaoSeguinteDaRaiz(aproximacaoSeguinte);
}
Secante2::Secante2(double aproximacaoInicialDaRaiz, double aproximacaoSeguinte, double a, double erro1, double erro2,bool UseTest1)
                    :GenericMethod(aproximacaoInicialDaRaiz, a, erro1, erro2){
    this->useTest1 = UseTest1;
    setAproximacaoSeguinteDaRaiz(aproximacaoSeguinte);
}
double Secante2::iterationFunction(double x)	 {

	return x*function(getAproximacaoSeguinteDaRaiz()) - getAproximacaoSeguinteDaRaiz()*function(x);
}

bool Secante2::testeParadaErro1() {
    if(this->useTest1)
        return (abs(function(getAproximacaoSeguinteDaRaiz())) < getErro1());
    else
        return false;
}

bool Secante2::testeParadaErro2() {

	return (abs(getAproximacaoSeguinteDaRaiz() - getAproximacaoAtualDaRaiz()) < getErro2());
}

void Secante2::calcularAproximacaoSeguinte() {

	double aproxAtualRaiz = getAproximacaoAtualDaRaiz();
	double aproxSeguinteRaiz = getAproximacaoSeguinteDaRaiz();

	setAproximacaoSeguinteDaRaiz(iterationFunction(aproxAtualRaiz)
									/(function(aproxSeguinteRaiz) - function(aproxAtualRaiz)));
	
	setAproximacaoAtualDaRaiz(aproxSeguinteRaiz);
}

void Secante2::loop() {

	salvarEmLista();

	while(!testeParadaErro1() && !testeParadaErro2()){
	
		calcularAproximacaoSeguinte();
		salvarEmLista();
	}
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
