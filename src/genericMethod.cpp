#include "../lib/imports.h"


GenericMethod::GenericMethod(double aproximacaoInicialDaRaiz, double a, double erro1, double erro2) {

	aproximacaoAtualDaRaiz = aproximacaoInicialDaRaiz;
	this->a = a;
	this->erro1 = erro1;
	this->erro2 = erro2;
	iterationsNumber = 0;
	allResults = new ListResults();
}

void GenericMethod::loop() {
	aproximacaoSeguinteDaRaiz = aproximacaoAtualDaRaiz;
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

	return (abs(function(aproximacaoAtualDaRaiz)) < erro1);
}

bool GenericMethod::testeParadaErro2() {

	return (abs(aproximacaoSeguinteDaRaiz - aproximacaoAtualDaRaiz) < erro2);
}

void GenericMethod::calcularAproximacaoSeguinte() {

	aproximacaoSeguinteDaRaiz = aproximacaoAtualDaRaiz - function(aproximacaoAtualDaRaiz)/iterationFunction(aproximacaoAtualDaRaiz);
}

void GenericMethod::salvarEmLista() {

	iterationResults = new double[5];
	iterationResults[0] = iterationsNumber;
	iterationResults[1] = aproximacaoAtualDaRaiz;
	iterationResults[2] = function(aproximacaoAtualDaRaiz);
	iterationResults[3] = aproximacaoSeguinteDaRaiz;
	iterationResults[4] = function(aproximacaoSeguinteDaRaiz);
	iterationsNumber++;
	allResults->push(iterationResults);
}

void GenericMethod::show() {

	ListResults list = (*this->allResults);
	double *iteration;
	while(!list.isEmpty()){
		// cout << "loop\n";
		iteration = list.pop();
		cout << "Iteração: " << iteration[0];
		cout << "    X" << iteration[0] << ": " << iteration[1];
		cout << "    F(X" << iteration[0] << "): " << iteration[2];
		cout << "    X" << iteration[0] + 1<<  ": " << iteration[3];
		cout << "    F(X" << iteration[0] + 1<< "): " << iteration[4];
		cout << endl;
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

	return erro1;
}

double GenericMethod::getErro2() {

	return erro2;
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

void GenericMethod::setAproximacaoSeguinteDaRaiz(double aproximacaoSeguinteDaRaiz) {

	this->aproximacaoSeguinteDaRaiz = aproximacaoSeguinteDaRaiz;
}

void GenericMethod::setA(double a) {

	this->a = a;
}

void GenericMethod::setErro1(double erro1) {

	this->erro1 = erro1;
}

void GenericMethod::setErro2(double erro2) {

	this->erro2 = erro2;
}
