#include "../lib/imports.h"

NewtonRaphson::NewtonRaphson(double aproximacaoInicialDaRaiz, double a, double erro1, double erro2)
                    :GenericMethod(aproximacaoInicialDaRaiz, a, erro1, erro2,true){
}

NewtonRaphson::NewtonRaphson(double aproximacaoInicialDaRaiz, double a, double erro1, double erro2,bool UseTest1)
                    :GenericMethod(aproximacaoInicialDaRaiz, a, erro1, erro2, UseTest1){
}

void NewtonRaphson::operacoesAntesDoLoop(){
    this->resetListResult();
    setAproximacaoSeguinteDaRaiz(getAproximacaoAtualDaRaiz());
    this->aproximacaoInicialDaRaiz=getAproximacaoAtualDaRaiz();
}

void NewtonRaphson::operacoesAposLoop(){
    setAproximacaoAtualDaRaiz(aproximacaoInicialDaRaiz);
    setAproximacaoSeguinteDaRaiz(aproximacaoInicialDaRaiz);
}

double NewtonRaphson::iterationFunction(double x) {

	return -sin(x);
}

void NewtonRaphson::calcularAproximacaoSeguinte(){
    double aproximacaoSeguinteDaRaiz;
    double aproximacaoAtualDaRaiz;
    setAproximacaoAtualDaRaiz(getAproximacaoSeguinteDaRaiz());
    aproximacaoAtualDaRaiz=getAproximacaoAtualDaRaiz();
    aproximacaoSeguinteDaRaiz = aproximacaoAtualDaRaiz - function(aproximacaoAtualDaRaiz)/iterationFunction(aproximacaoAtualDaRaiz);
    setAproximacaoSeguinteDaRaiz(aproximacaoSeguinteDaRaiz);
}



