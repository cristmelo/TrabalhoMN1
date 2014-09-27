/*
Autor: Caio Viktor
Classe que implementa método da secante
*/
#include "../lib/imports.h"
//Contrutor
Secante::Secante(double x1,double x2,double e1,double e2, double a,double maxInteration){
	this->x1 = x1;
	this->x2 = x2;
	this->initX1 = x1;
	this->initX2 = x2;
	this->value = x1;
	this->e1 = e1;
	this->e2 = e2;
	this->a = a;
	this->list = new ListResults();
	this->maxInteration = maxInteration;
	cout << "Método da secante criado\n";
	this->calculate();
}
//Métodos Getters e Setters
void Secante::setX1(double x1){
	this->x1 = x1;
}

void Secante::setX2(double x2){
	this->x2 = x2;
}

void Secante::setE1(double e1){
	this->e1 = e1;
}

void Secante::setE2(double e2){
	this->e2 = e2;
}

void Secante::setA(double a){
	this->a = a;
	delete this->list;
	this->x1 = this->initX1;
	this->x2 = this->initX2;
	this->list = new ListResults();
	this->calculate();
}

void Secante::setMaxInteration(double maxInteration){
	this->maxInteration = maxInteration;
}

double Secante::getX1(){
	return this->x1;
}

double Secante::getX2(){
	return this->x2;
}

double Secante::getE1(){
	return this->e1;
}

double Secante::getE2(){
	return this->e2;
}
double Secante::getA(){
	return this->a;
}
double Secante::getValue(){
	return this->value;
}

double Secante::getMaxInteration(){
	return this->maxInteration;
}

ListResults Secante::getListResults(){
	return (*this->list);
}
//Fim métodos Getters e Setters
//Método privado de aplecação da função
double Secante::Function(double x){
	return cos(x)+(1 - this->a);
}
//método que consegui novo ponto. Caso seguíssimos o padrão seria necessário fazer apenas ele para cada classe
double Secante::interate(){
	double f2 = this->Function(this->x2);
	double f1 = this->Function(this->x1);
	return ( this->x1 * f2 - this->x2 * f1 ) / ( f2 - f1 );

}
//Salva estado da interação na lista
double* Secante::saveState(int k,double x){
	double *state = new double[6];
	state[0] = k;
	state[1] = this->x1;
	state[2] = this->x2;
	state[3] = this->Function(this->x1);
	state[4] = this->Function(this->x2);
	state[5] = x;
	return state;
}
//Calcula aproximação
ListResults Secante::calculate(){
	// cout << "começou\n";
	delete this->list;
	int k = 0;
	double *state;
	this->list = new ListResults();
	this->value = this->x1;
	if ( (abs( this->Function(this->x1) ) ) < this->e1){
		state = saveState(k,this->x1);
		this->list->push(state);
		return (*this->list);
	}
	if( (abs(this->Function(this->x2)) < e1)  || (abs(this->x2 - this->x1) < e2) ){
		this->value = this->x2;
		state = saveState(k,this->x2);
		this->list->push(state);
		return (*this->list);
	}
	k++;
	// cout << "vai para o loop";
	do{
		double x = this->interate();
		// cout << k << " Valor: " << x << endl;
		state = saveState(k,x);
		this->list->push(state);
		if( (abs(this->Function(x)) < e1)  || (abs(x - this->x2) < e2) || k >= this->maxInteration ){
			this->value = x;
			// cout << "Saiu " << x << endl;
			return (*this->list);
		}
		this->x1 = this->x2;
		this->x2 = x;
		k++;
	}while(true);
}
//Mostra processo de refinamento
void Secante::showProcess(){
	ListResults list = (*this->list);
	double *interation;
	while(!list.isEmpty()){
		// cout << "loop\n";
		interation = list.pop();
		cout << "Interação: " << interation[0];
		cout << "    X" << interation[0]- 1 << ": " << interation[1];
		cout << "    X" << interation[0] << ": " << interation[2];
		cout << "    F(X" << interation[0] - 1<<  "): " << interation[3];
		cout << "    F(X" << interation[0] << "): " << interation[4];
		cout << "    X" << interation[0] + 1 << ": " << interation[5] << endl;
	}
	cout << "Valor obtido: " << this->value << endl;
}