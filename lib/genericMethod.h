class GenericMethod {
public:
	GenericMethod(double aproximacaoInicial, double a, double E1, double E2);

	double function1(double x);
	virtual double function2(double x);
	virtual bool testeParadaE1();
	virtual bool testeParadaE2();
	virtual void calcularXK() = 0;
	virtual void salvaEmLista();
	virtual void loop();
	void show();


//-----Getters and Setters

	int getIterationsNumber();

	double getX1();
	double getX2();
	double getA();
	double getE1();
	double getE2();
	double getIterationResults();
	ListResults getAllResults();

	void setX1();
	void setX2();
	void setIterationsNumber(int iterNumber);
	void setA(double a);
	void setE1(double E1);
	void setE2(double E2);

private:
	int iterationsNumber;
	double X1;
	double X2;
	double a;
	double E1;
	double E2;
	double *iterationResults;
	ListResults *allResults;
};