/*
Autor: Caio Viktor
Classe que implementa método da secante
*/
#include "../lib/genericMethod.h"

class Secante2 : public GenericMethod{

private:

	double value, maxInteration;
	double aproximacaoAtualDaRaiz;
	double aproximacaoSeguinteDaRaiz;
	
public:
	
	Secante2(double aproximacaoInicialDaRaiz, double aproximacaoSeguinteDaRaiz,double a, double Erro1, double Erro2);

	void setMaxInteration(double x1);
	double getMaxInteration();
	double getValue();
	double iterationFunction(double x);
	bool testeParadaErro1();
	void calcularAproximacaoSeguinte();
	void loop();

};