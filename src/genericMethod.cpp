#include "../lib/imports.h"


GenericMethod::GenericMethod(double aproximacaoInicial, double a, double Erro1, double Erro2) {

	this->raizAtual = aproximacaoInicial;
	this->a = a;
	this->Erro1 = Erro1;
	this->Erro2 = Erro2;
	this->iterationsNumber = 0;
	this->allResults = new ListResults();
}

virtual void GenericMethod::loop() {

	raizSeguinte = raizAtual;
	do{
		raizAtual = raizSeguinte;
		calcularXK();
		salvaEmLista();
	}while(testeParadaErro2())
}

double GenericMethod::function1(double x) {

	return cos(x) + (1 - a);
}

virtual double GenericMethod::function2(double x) {

	return -sin(x);
}

virtual bool GenericMethod::testeParadaErro1() {
	
	return (abs(function1(raizAtual)) < Erro1);
}

virtual bool GenericMethod::testeParadaErro2() {

	return (abs(raizSeguinte - raizAtual) >= Erro2);
}

virtual void GenericMethod::calcularRaizSeguinte() {

	raizSeguinte = raizAtual - function1(raizAtual)/function2(raizAtual);
}

virtual void GenericMethod::salvaEmLista() {

	this->iterationResults = new double[5];
	this->iterationResults[0] = this->iterationsNumber;
	this->iterationResults[1] = this->raizAtual;
	this->iterationResults[2] = this->function1(this->raizAtual)
	this->iterationResults[3] = this->function2(this->raizAtual)
	this->iterationResults[4] = this->raizSeguinte;
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


int GenericMethod::getIterationsNumber() {

	return iterationsNumber;
}

double GenericMethod::getRaizAtual() {

	return raizAtual;
}

double GenericMethod::getRaizSeguinte() {

	return raizSeguinte;
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

void GenericMethod::setRaizAtual(double xAtual) {

	this->xAtual = xAtual;
}

void GenericMethod::setRaizSeguinte(double xProximo) {

	this->xProximo = xProximo;
}

void GenericMethod::setA(double A) {

	this->A = A;
}

void GenericMethod::setErro1(double Erro1) {

	this->Erro1 = Erro1;
}

void GenericMethod::setErro2(double Erro2) {

	this->Erro2 = Erro2;
}
