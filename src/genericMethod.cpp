#include "../lib/imports.h"


GenericMethod::GenericMethod(double aproximacaoInicialDaRaiz, double a, double Erro1, double Erro2) {

	aproximacaoAtualDaRaiz = aproximacaoInicialDaRaiz;
	this->aproximacaoSeguinteDaRaiz = aproximacaoInicialDaRaiz;
	this->a = a;
	this->Erro1 = Erro1;
	this->Erro2 = Erro2;
	this->iterationsNumber = 0;
	this->allResults = new ListResults();
}

void GenericMethod::loop() {

	do{
		aproximacaoAtualDaRaiz = aproximacaoSeguinteDaRaiz;
		calcularAproximacaoSeguinte();
		salvarEmLista();
	}while(testeParadaErro2());
}

double GenericMethod::function(double x) {

	return cos(x) + (1 - a);
}

double GenericMethod::iterationFunction(double x) {

	return -sin(x);
}

bool GenericMethod::testeParadaErro1() {
	
	return (abs(function(aproximacaoAtualDaRaiz)) < Erro1);
}

bool GenericMethod::testeParadaErro2() {

	return (abs(aproximacaoSeguinteDaRaiz - aproximacaoAtualDaRaiz) >= Erro2);
}

void GenericMethod::calcularAproximacaoSeguinte() {

	aproximacaoSeguinteDaRaiz = aproximacaoAtualDaRaiz - function(aproximacaoAtualDaRaiz)/iterationFunction(aproximacaoAtualDaRaiz);
}

void GenericMethod::salvarEmLista() {

	iterationResults = new double[5];
	iterationResults[0] = iterationsNumber;
	iterationResults[1] = aproximacaoAtualDaRaiz;
	iterationResults[2] = function(aproximacaoAtualDaRaiz);
	iterationResults[3] = function(aproximacaoSeguinteDaRaiz);
	iterationResults[4] = aproximacaoSeguinteDaRaiz;
	iterationsNumber++;
	allResults->push(iterationResults);
}

void GenericMethod::show() {

	ListResults list = (*this->allResults);
	double *interation;
	while(!list.isEmpty()){
		// cout << "loop\n";
		interation = list.pop();
		cout << "Iteração: " << interation[0];
		cout << "    X" << interation[0]- 1 << ": " << interation[1];
		cout << "    X" << interation[0] << ": " << interation[2];
		cout << "    F(X" << interation[0] - 1<<  "): " << interation[3];
		cout << "    F(X" << interation[0] << "): " << interation[4];
		cout << "    X" << interation[0] + 1 << ": " << interation[5] << endl;
	}
}


//-----Getters and Setters

//TODO: Analisar quais desses getters e setters são desnecessários e excluí-los
int GenericMethod::getIterationsNumber() {

	return iterationsNumber;
}

double GenericMethod::getAproximacaoAtualDaRaiz() {

	return aproximacaoAtualDaRaiz;
}

double GenericMethod::getAproximacaoSeguinteDaRaiz() {

	return aproximacaoSeguinteDaRaiz;
}

double GenericMethod::getA() {

	return a;
}

double GenericMethod::getErro1() {

	return Erro1;
}

double GenericMethod::getErro2() {

	return Erro2;
}

double GenericMethod::getIterationResults() {

	return *iterationResults;
}

ListResults GenericMethod::getAllResults() {

	return *this->allResults;
}

void GenericMethod::setIterationsNumber(int iterationsNumber) {

	this->iterationsNumber = iterationsNumber;
}

void GenericMethod::setAproximacaoAtualDaRaiz(double aproximacaoAtualDaRaiz) {

	this->aproximacaoAtualDaRaiz = aproximacaoAtualDaRaiz;
}

void GenericMethod::setA(double a) {

	this->a = a;
}

void GenericMethod::setErro1(double Erro1) {

	this->Erro1 = Erro1;
}

void GenericMethod::setErro2(double Erro2) {

	this->Erro2 = Erro2;
}
