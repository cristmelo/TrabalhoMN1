/*
Autores: Caio Viktor, Geraldo e Matheus Mayron.
Classe que implementa método do newtonRaphson
*/

class NewtonRaphson : public GenericMethod{
    double aproximacaoInicialDaRaiz;
public:
	NewtonRaphson(double aproximacaoInicialDaRaiz,double a, double Erro1, double Erro2);
    NewtonRaphson(double aproximacaoInicialDaRaiz,double a, double Erro1, double Erro2,bool useTest1);

    double iterationFunction(double x);
    void calcularAproximacaoSeguinte();
    void operacoesAntesDoLoop();
    void operacoesAposLoop();
};
