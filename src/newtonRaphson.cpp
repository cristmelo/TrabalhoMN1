#include "../lib/imports.h"

//Linha de Resultados


ListResults* newtonRaphson(double xi,double a, double e1, double e2)
{
    int k;
    double fi;
    double dfi;
    double xk;
    k=0;
    double *lineResult;
    ListResults *listR;
    listR=new ListResults();
    xk=xi;

    do{
        xi=xk;
        lineResult=new double[5];

        lineResult[0]=k;
        lineResult[1]=xi;

        fi=cos(xi)+(1-a);
        lineResult[2]=fi;

        dfi=-sin(xi);
        lineResult[3]=dfi;

        xk=xi-fi/dfi;
        lineResult[4]=xk;
        k++;
        listR->push(lineResult);

    }while(abs(xk-xi)>=e2);
    return listR;
}

int main(){
    ListResults *lista;
    double *line;
    cout << setprecision(9);
    lista=newtonRaphson(3.0,0.0,pow(10,-7),pow(10,-7));
    cout<< "\n\nTodos os valores de xi";
    while(!lista->isEmpty()){
        line=lista->pop();
        cout <<"k: "<<line[0]<<"   xi: "<< line[1]<<"\n ";
    }
    cout<<"Acabou"<<endl;
}
