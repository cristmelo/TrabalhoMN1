class GenericMethod {
public:
	GenericMethod(double aproximacaoInicial, double a, double E1, double E2);

	void init();
	void testeParadaE1();
	void testeParadaE2();
	void setNovaIteracao();
	void salvaEmLista();
	void loop();
	void show();




//-----Getters and Setters

	double getE1();
	double getE2();

	void setE1(double E1);
	void setE2(double E2);

private:
	double E1;
	double E2;

}