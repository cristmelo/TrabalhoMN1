#include "../lib/imports.h"


GenericMethod::GenericMethod(double aproximacaoInicialdaRaiz, double a, double Erro1, double Erro2) {

	this->aproximacaoAtualDaRaiz = aproximacaoInicialDaRaiz;
	this->aproximacaoSeguinteDaRaiz = aproximacaoInicialDaRaiz;
	this->a = a;
	this->Erro1 = Erro1;
	this->Erro2 = Erro2;
	this->iterationsNumber = 0;
	this->allResults = new ListResults();
}

virtual void GenericMethod::loop() {

	do{
		aproximacaoAtualDaRaiz = aproximacaoSeguinteDaRaiz;
		calcularAproximacaoSeguinteDaRaiz();
		salvarEmLista();
	}while(testeParadaErro2());
}

double GenericMethod::function(double x) {

	return cos(x) + (1 - a);
}

virtual double GenericMethod::iterationFunction(double x) {

	return -sin(x);
}

virtual bool GenericMethod::testeParadaErro1() {
	
	return (abs(function1(aproximacaoAtualDaRaiz)) < Erro1);
}

virtual bool GenericMethod::testeParadaErro2() {

	return (abs(aproximacaoSeguinteDaRaiz - aproximacaoAtualDaRaiz) >= Erro2);
}

virtual void GenericMethod::calcularAproximacaoSeguinte() {

	aproximacaoSeguinteDaRaiz = aproximacaoAtualDaRaiz - function(aproximacaoAtualDaRaiz)/iterationFunction(aproximacaoAtualDaRaiz);
}

virtual void GenericMethod::salvarEmLista() {

	this->iterationResults = new double[5];
	this->iterationResults[0] = this->iterationsNumber;
	this->iterationResults[1] = this->aproximacaoAtualDaRaiz;
	this->iterationResults[2] = this->function(this->aproximacaoAtualDaRaiz)
	this->iterationResults[3] = this->function(this->aproximacaoSeguinteDaRaiz)
	this->iterationResults[4] = this->aproximacaoSeguinteDaRaiz;
	this->iterationsNumber++;
	allResults->push(this->iterationResults);
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
	cout << "Valor obtido: " << this->value << endl;
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

void GenericMethod::setRaizSeguinte(double aproximacaoSeguinteDaRaiz) {

	this->aproximacaoSeguinteDaRaiz = aproximacaoSeguinteDaRaiz;
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
