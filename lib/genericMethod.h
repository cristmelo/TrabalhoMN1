class GenericMethod {
public:
	GenericMethod(double aproximacaoInicial, double a, double E1, double E2);

	void init();
	bool testeParadaE1();
	bool testeParadaE2();
	void setNovaIteracao();
	void salvaEmLista();
	void loop();
	void show();


//-----Getters and Setters

	int getIterationsNumber();
	double getA();
	double getE1();
	double getE2();
	double getIterationResults();
	ListResults getAllResults();

	void setIterationsNumber(int iterNumber);
	void setA(double a);
	void setE1(double E1);
	void setE2(double E2);

private:
	int iterationsNumber;
	double a;
	double E1;
	double E2;
	double *iterationResults
	ListResults *allResults
}