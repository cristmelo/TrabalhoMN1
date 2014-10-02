#include "../lib/imports.h"


GenericMethod::GenericMethod(double aproximacaoInicial, double a, double E1, double E2) {
	this->X1 = aproximacaoInicial;
	this->a = a;
	this->E1 = E1;
	this->E2 = E2;
	this->iterationsNumber = 0;
	this->allResults = new ListResults();
}

double GenericMethod::function1(double x){

	return cos(x)+(1 - this->a);
}

virtual double GenericMethod::function2(double x){

	return -sin(x);
}

virtual bool GenericMethod::testeParadaE1(){
	
	return (abs(this->function(this->X1)) < this->E1);
}

virtual bool GenericMethod::testeParadaE2(){

	return abs((this->X2) - (this->X1)) >= this->E2;
}

virtual void GenericMethod::calcularXK() {

	(this->X2) = (this->X1) - (this->function1(this->X1))/(this->function2(this->X1));
}

virtual void GenericMethod::setNovaIteracao(){

}

virtual void GenericMethod::salvaEmLista(){
	this->iterationResults = new double[5];
	this->iterationResults[0] = this->iterationsNumber;
	this->iterationResults[1] = this->X1;
	this->iterationResults[2] = this->function1(this->X1)
	this->iterationResults[3] = this->function2(this->X1)
	this->iterationResults[4] = this->X2;
	this->iterationsNumber++;
	allResults->push(this->iterationResults);
}

//TODO:Terminar
virtual void GenericMethod::loop(){
	setNovaIteracao();
	testeParadaE1();
	testeParadaE2();
	salvaEmLista();

}

void GenericMethod::show(){
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


int GenericMethod::getIterationsNumber(){

	return this->iterationsNumber;
}

double GenericMethod::getX1(){

	return this->X1;
}

double GenericMethod::getX2(){

	return this->X2;
}

double GenericMethod::getA(){

	return this->a;
}

double GenericMethod::getE1(){

	return this->E1;
}

double GenericMethod::getE2(){

	return this->E2;
}

double GenericMethod::getIterationResults(){

	return (*this->iterationResults);
}

ListResults GenericMethod::getAllResults(){

	return (*this->allResults);
}

void GenericMethod::setIterationsNumber(int iterNumber){

	iterationsNumber = iterNumber;
}

void GenericMethod::setX1(double X1){

	this->X1 = X1;
}

void GenericMethod::setX2(double X2){

	this->X2 = X2;
}

void GenericMethod::setA(double A){

	this->A = A;
}

void GenericMethod::setE1(double E1){

	this->E1 = E1;
}

void GenericMethod::setE2(double E2){

	this->E2 = E2;
}
