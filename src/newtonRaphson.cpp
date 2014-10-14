#include "../lib/imports.h"

NewtonRaphson::NewtonRaphson(double aproximacaoInicialDaRaiz, double a, double erro1, double erro2)
					:GenericMethod(aproximacaoInicialDaRaiz, a, erro1, erro2){
    setAproximacaoSeguinteDaRaiz(getAproximacaoAtualDaRaiz());
};


void NewtonRaphson::loop() {
	do{
		setAproximacaoAtualDaRaiz(getAproximacaoSeguinteDaRaiz());
		calcularAproximacaoSeguinte();
		salvarEmLista();
	}while(testeParadaErro2());
}

double NewtonRaphson::iterationFunction(double x) {

	return -sin(x);
}

void NewtonRaphson::calcularAproximacaoSeguinte(){
    double aproximacaoSeguinteDaRaiz;
    double aproximacaoAtualDaRaiz;

    aproximacaoAtualDaRaiz=getAproximacaoAtualDaRaiz();

    aproximacaoSeguinteDaRaiz = aproximacaoAtualDaRaiz - function(aproximacaoAtualDaRaiz)/iterationFunction(aproximacaoAtualDaRaiz);

    setAproximacaoSeguinteDaRaiz(aproximacaoSeguinteDaRaiz);
}

bool NewtonRaphson::testeParadaErro1() {

	return (abs(function(getAproximacaoSeguinteDaRaiz())-function(getAproximacaoAtualDaRaiz())) > getErro1());
}

bool NewtonRaphson::testeParadaErro2() {

	return (abs(getAproximacaoSeguinteDaRaiz() - getAproximacaoAtualDaRaiz()) > getErro2());
}
