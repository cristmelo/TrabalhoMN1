/*
Autor: Matheus Mayron - Oh yeah Bitches!
Classe que implementa método do newtonRaphson
*/


class NewtonRaphson : public GenericMethod{
    bool useTest1;
public:
	NewtonRaphson(double aproximacaoInicialDaRaiz,double a, double Erro1, double Erro2);
    NewtonRaphson(double aproximacaoInicialDaRaiz,double a, double Erro1, double Erro2,bool useTest1);
	double iterationFunction(double x);
	bool testeParadaErro1();
	bool testeParadaErro2();
	void calcularAproximacaoSeguinte();
	void loop();
};
