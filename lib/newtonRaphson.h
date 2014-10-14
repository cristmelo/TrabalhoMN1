/*
Autor: Matheus Mayron - Oh yeah Bitches!
Classe que implementa método do newtonRaphson
*/
#include "../lib/genericMethod.h"

class NewtonRaphson : public GenericMethod{

public:
	NewtonRaphson(double aproximacaoInicialDaRaiz,double a, double Erro1, double Erro2);
	double iterationFunction(double x);
	bool testeParadaErro1();
	bool testeParadaErro2();
	void calcularAproximacaoSeguinte();
	void loop();
};
