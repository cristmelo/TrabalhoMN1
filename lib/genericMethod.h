class GenericMethod {

public:

	GenericMethod(double aproximacaoInicial, double a, double Erro1, double Erro2);

	double function1(double x);
	virtual double function2(double x);
	virtual bool testeParadaErro1();
	virtual bool testeParadaErro2();
	virtual void calcularXk() = 0;
	virtual void salvaEmLista();
	virtual void loop();
	void show();


//-----Getters and Setters

	int getIterationsNumber();

	double getRaizAtual();
	double getX2();
	double getA();
	double getErro1();
	double getErro2();
	double getIterationResults();
	ListResults getAllResults();

	void setRaizAtual();
	void setX2();
	void setIterationsNumber(int iterationsNumber);
	void setA(double a);
	void setErro1(double Erro1);
	void setErro2(double Erro2);

private:

	int iterationsNumber;
	double raizAtual;
	double raizProxima;
	double a;
	double Erro1;
	double Erro2;
	double *iterationResults;
	ListResults *allResults;
};