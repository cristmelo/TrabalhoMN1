#include "../lib/imports.h"


GenericMethod::GenericMethod(double aproximacaoInicial, double a, double E1, double E2) {

}


int GenericMethod::getIterationsNumber(){
	return this->iterationsNumber;
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

void GenericMethod::setA(double A){
	this->A = A;
}

void GenericMethod::setE1(double E1){
	this->E1 = E1;
}

void GenericMethod::setE2(double E2){
	this->E2 = E2;
}
