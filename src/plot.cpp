#include "../lib/imports.h"

Plot::Plot(){

}

bool Plot::line(ListResults	listaDeResultados){
	double* iteracao;
	string abscissas;
	string ordenadas;
	stringstream strStream;

	ifstream fin("src/template.html");
	ofstream fout("src/saida.html");
	string linha;

	while(!listaDeResultados.isEmpty()){
		iteracao = listaDeResultados.pop();
		strStream << iteracao[1];
		abscissas += strStream.str() + ", ";
		strStream.str("");
		strStream << iteracao[3];
		abscissas += strStream.str();
		strStream.str("");
		
		if(!listaDeResultados.isEmpty())
			abscissas += ", ";
		else
			abscissas += "]\n";
		
		strStream << iteracao[2];
		ordenadas += strStream.str() + ", ";
		strStream.str("");
		strStream << iteracao[4];
		ordenadas += strStream.str();
		strStream.str("");
		
		if(!listaDeResultados.isEmpty())
			ordenadas += ", ";
		else
			ordenadas += "]\n";
	}

	if(fin.is_open()){
		for(int i = 0; i < 17; i++){
			getline(fin, linha);
			fout << linha << endl;
		}
		
		fout << abscissas << endl;
		
		for(int i = 0; i < 10; i++){
			getline(fin, linha);
			fout << linha << endl;
		}
		
		fout << ordenadas << endl;
		
		while(fin.good()){
			getline(fin, linha);
			fout << linha << endl;
		}
        return true;
	}
	else{
		cout << "erro" << endl;
        return false;
	}
}
