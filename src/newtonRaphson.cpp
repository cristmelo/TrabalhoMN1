#include "../lib/imports.h"

NewtonRaphson::NewtonRaphson(double aproximacaoInicialDaRaiz, double a, double erro1, double erro2)
					:GenericMethod(aproximacaoInicialDaRaiz, a, erro1, erro2){
    this->useTest1 = true;
    setAproximacaoSeguinteDaRaiz(getAproximacaoAtualDaRaiz());
}

NewtonRaphson::NewtonRaphson(double aproximacaoInicialDaRaiz, double a, double erro1, double erro2,bool UseTest1)
                    :GenericMethod(aproximacaoInicialDaRaiz, a, erro1, erro2){
    this->useTest1 = UseTest1;
    setAproximacaoSeguinteDaRaiz(getAproximacaoAtualDaRaiz());
}

void NewtonRaphson::loop() {
    this->resetListResult();
    this->aproximacaoInicialDaRaizAntesDoLoop=getAproximacaoAtualDaRaiz();

	do{
		setAproximacaoAtualDaRaiz(getAproximacaoSeguinteDaRaiz());
		calcularAproximacaoSeguinte();
		salvarEmLista();
	}while(testeParadaErro2());

	setAproximacaoAtualDaRaiz(aproximacaoInicialDaRaizAntesDoLoop);
	setAproximacaoSeguinteDaRaiz(aproximacaoInicialDaRaizAntesDoLoop);
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
    if(this->useTest1)
        return (abs(function(getAproximacaoSeguinteDaRaiz())-function(getAproximacaoAtualDaRaiz())) > getErro1());
    else
        return false;
}

bool NewtonRaphson::testeParadaErro2() {

	return (abs(getAproximacaoSeguinteDaRaiz() - getAproximacaoAtualDaRaiz()) > getErro2());
}
