/*
Autores: Caio Viktor, Geraldo e Matheus Mayron.
Classe que implementa método da secante
*/


class Secante2 : public GenericMethod{

private:
	double aproximacaoAtualDaRaiz;
	double aproximacaoSeguinteDaRaiz;
	
public:
	
	Secante2(double aproximacaoInicialDaRaiz, double aproximacaoSeguinteDaRaiz,double a, double Erro1, double Erro2);
    Secante2(double aproximacaoInicialDaRaiz, double aproximacaoSeguinteDaRaiz,double a, double Erro1, double Erro2,bool UseTest1);

	double iterationFunction(double x);
	void calcularAproximacaoSeguinte();
    void operacoesAntesDoLoop();
    void operacoesAposLoop();

};
