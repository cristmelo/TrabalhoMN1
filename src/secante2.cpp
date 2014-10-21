#include "../lib/imports.h"


Secante2::Secante2(double aproximacaoInicialDaRaiz, double aproximacaoSeguinte, double a, double erro1, double erro2) 
                    :GenericMethod(aproximacaoInicialDaRaiz, a, erro1, erro2, true){
	setAproximacaoSeguinteDaRaiz(aproximacaoSeguinte);
}
Secante2::Secante2(double aproximacaoInicialDaRaiz, double aproximacaoSeguinte, double a, double erro1, double erro2,bool UseTest1)
                    :GenericMethod(aproximacaoInicialDaRaiz, a, erro1, erro2, UseTest1){
    setAproximacaoSeguinteDaRaiz(aproximacaoSeguinte);
}
double Secante2::iterationFunction(double x)	 {

	return x*function(getAproximacaoSeguinteDaRaiz()) - getAproximacaoSeguinteDaRaiz()*function(x);
}


void Secante2::calcularAproximacaoSeguinte() {

	double aproxAtualRaiz = getAproximacaoAtualDaRaiz();
	double aproxSeguinteRaiz = getAproximacaoSeguinteDaRaiz();

	setAproximacaoSeguinteDaRaiz(iterationFunction(aproxAtualRaiz)
									/(function(aproxSeguinteRaiz) - function(aproxAtualRaiz)));
	
	setAproximacaoAtualDaRaiz(aproxSeguinteRaiz);
}

void Secante2::operacoesAntesDoLoop(){
    salvarEmLista();
}
void Secante2::operacoesAposLoop(){

}
