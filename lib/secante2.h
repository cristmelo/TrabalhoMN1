/*
Autor: Caio Viktor
Classe que implementa método da secante
*/


class Secante2 : public GenericMethod{

private:

	double value, maxInteration;
	double aproximacaoAtualDaRaiz;
	double aproximacaoSeguinteDaRaiz;
    bool useTest1;
	
public:
	
	Secante2(double aproximacaoInicialDaRaiz, double aproximacaoSeguinteDaRaiz,double a, double Erro1, double Erro2);
    Secante2(double aproximacaoInicialDaRaiz, double aproximacaoSeguinteDaRaiz,double a, double Erro1, double Erro2,bool UseTest1);

	void setMaxInteration(double x1);
	double getMaxInteration();
	double getValue();
	double iterationFunction(double x);
	bool testeParadaErro1();
	bool testeParadaErro2();
	void calcularAproximacaoSeguinte();
	void loop();

};
