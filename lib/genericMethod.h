class GenericMethod {

public:

	GenericMethod(double aproximacaoInicialDaRaiz, double a, double Erro1, double Erro2);

	double function(double x);
	virtual double iterationFunction(double x);
	virtual bool testeParadaErro1();
	virtual bool testeParadaErro2();
	virtual void calcularAproximacaoSeguinteDaRaiz() = 0;
	virtual void salvaEmLista();
	virtual void loop();
	void show();


//-----Getters and Setters

	int getIterationsNumber();
	double getAproximacaoAtualDaRaiz();
	double getAproximacaoSeguinteDaRaiz();
	double getA();
	double getErro1();
	double getErro2();
	double getIterationResults();
	ListResults getAllResults();

	void setAproximacaoAtualDaRaiz(double aproximacaoAtualDaRaiz);
	void setAproximacaoSeguinteDaRaiz(double aproximacaoSeguinteDaRaiz);
	void setIterationsNumber(int iterationsNumber);
	void setA(double a);
	void setErro1(double Erro1);
	void setErro2(double Erro2);

private:

	int iterationsNumber;
	double aproximacaoAtualDaRaiz;
	double aproximacaoSeguinteDaRaiz;
	double a;
	double Erro1;
	double Erro2;
	double *iterationResults;
	ListResults *allResults;
};