/*
Autores: Caio Viktor, Geraldo e Matheus Mayron.
*/

class GenericMethod {

public:

    GenericMethod(double aproximacaoInicialDaRaiz, double a, double erro1, double erro2,bool useTest1);
    //~GenericMethod();
	double function(double x);
    virtual double iterationFunction(double x) = 0;
	virtual bool testeParadaErro1();
	virtual bool testeParadaErro2();
	virtual void calcularAproximacaoSeguinte() = 0;
	virtual void salvarEmLista();
    virtual void operacoesAntesDoLoop() = 0;
    virtual void operacoesAposLoop() = 0;
	virtual void loop();
	void show();
    void resetListResult();

//-----Getters and Setters

	int getIterationsNumber();
	double getAproximacaoAtualDaRaiz();
	double getAproximacaoSeguinteDaRaiz();
	double getA();
	double getErro1();
	double getErro2();
	double getIterationResults();
    double getValue();
    int getMaxIteration();
	ListResults getAllResults();
    double getValueAnterior();
	void setAproximacaoAtualDaRaiz(double aproximacaoAtualDaRaiz);
	void setAproximacaoSeguinteDaRaiz(double aproximacaoSeguinteDaRaiz);
	void setIterationsNumber(int iterationsNumber);
	void setA(double a);
	void setErro1(double erro1);
	void setErro2(double erro2);
    void setMaxIteration(int maxIteration);

private:

	int iterationsNumber;
    bool useTest1;
    double value;
    int maxIteration;
	double aproximacaoAtualDaRaiz;
	double aproximacaoSeguinteDaRaiz;
	double a;
	double erro1;
	double erro2;
    double valueAnterior;
	double *iterationResults;
	ListResults *allResults;
};
