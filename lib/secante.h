/*
Autor: Caio Viktor
Classe que implementa método da secante
*/
class Secante{
	double x1,x2,value,e1,e2,a,maxInteration;
	double initX1,initX2,initA;
	ListResults *list;
	double* saveState(int k,double x);
	double Function(double x);
	double interate();
public:
	Secante(double x1,double x2,double e1,double e2,double a,double maxInteration);
	void setX1(double x1);
	void setX2(double x2);
	void setE1(double e1);
	void setE2(double e2);
	void setA(double a);
	void showProcess();
	void setMaxInteration(double x1);
	double getX1();
	double getX2();
	double getE1();
	double getE2();
	double getA();
	double getValue();
	double getMaxInteration();
	ListResults getListResults();
	ListResults calculate();
};