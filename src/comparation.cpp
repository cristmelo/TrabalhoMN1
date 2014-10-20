#include "../lib/imports.h"
#include "../lib/comparation.h"
#include "ui_comparation.h"

Comparation::Comparation(QWidget *parent,int typeMethod,int qtdA,double *valuesA,double error1,double error2,bool useTest1) :
    QWidget(parent),
    ui(new Ui::Comparation)
{
    ui->setupUi(this);
    QTableWidget *table = ui->tableComparateA;
    QLabel *nameMethod = ui->labelNameMethod;
    QLabel *betterValue = ui->labelbetterValue;
    QLabel *fastValue = ui->labelLessValue;
    QLabel *betterA = ui->labelNameBetterMethod;
    QLabel *fastA = ui->labelNameLessMethod;
    QLabel *qtdBetterInt = ui->labelQTDbetterInterations;
    QLabel *qtdFastInt = ui->labelQTDLessInterations;
    switch(typeMethod){
    case 0:
        nameMethod->setText("Bisseção");
        break;
    case 1:
        nameMethod->setText("Ponto falso");
        break;
    case 2:
        nameMethod->setText("Newton-Rapshon");
        break;
    case 3:
        nameMethod->setText("Secante");
        break;
    }

    table->setRowCount(qtdA);

    ComparationStruct best,fast;
    best.error = 2147483647;
    fast.qtdInterations = 2147483647;

    for(int i = 0; i < qtdA; i++){
        switch(typeMethod){
        case 0:

            break;
        case 1:

            break;
        case 2: //Newton
            if (1){
            //SE EU REMOVER ESTE IF, O CÓDIGO NÃO COMPILA, NÃO SE PERGUNTE PORQUE,
            //APENAS ACEITE, POIS NEM TUDO NA VIDA É PERFEITO.
            //Edit By Caio: Sábias palavras jovem. Me lembro do sábio que as proferiu e iluminou nossa vida com o conformismo.kkkkkkkkkkkkkkkkkkkk

                NewtonRaphson *metodoNewton = new NewtonRaphson(3,valuesA[i],error1,error2,useTest1);
                metodoNewton->loop();
                //Recebe resultado das iterações do método de Newton
                ListResults resultadoNewton;
                resultadoNewton = metodoNewton->getAllResults();
                int numeroIteracoesNewton = resultadoNewton.getLength();
                //Próximo passo: dar pop() em resultadoNewton até chegar
                //à última iteração...
                double *ultimaIteracao;
                for(int i = 0;i < numeroIteracoesNewton;i++){
                   ultimaIteracao = resultadoNewton.pop();
                }

                //Insere o A na tabela de comparações:
                QTableWidgetItem *itemValorANewton = new QTableWidgetItem;
                itemValorANewton->setText(QString::number(valuesA[i],'g',10));
                table->setItem(i,0,itemValorANewton);

                //Para cada A, insere na tabela o valor de Pi achado:
                QTableWidgetItem *itemValorPi = new QTableWidgetItem;
                itemValorPi->setText(QString::number(ultimaIteracao[1],'g',10));
                table->setItem(i,1,itemValorPi);

                //Para cada A, insere na tabela o número de Iterações:
                QTableWidgetItem *itemNumeroIteracoes = new QTableWidgetItem;
                itemNumeroIteracoes->setText(QString::number(numeroIteracoesNewton,'g',10));
                table->setItem(i,2,itemNumeroIteracoes);

                //Para cada A, insere o Erro Relativo
                //Primeiro: acha o valor no ponto:
                double erroAbs = abs(metodoNewton->function(ultimaIteracao[1]));

                QTableWidgetItem *itemValorErro = new QTableWidgetItem;
                itemValorErro->setText(QString::number(erroAbs));
                table->setItem(i,3,itemValorErro);


                if(erroAbs < best.error){
                     best.error = erroAbs;
                     best.name = valuesA[i];
                     best.qtdInterations = numeroIteracoesNewton;
                     best.valuePi = ultimaIteracao[1];
                }
                if(numeroIteracoesNewton < fast.qtdInterations){
                     fast.error = erroAbs;
                     fast.name = valuesA[i];
                     fast.qtdInterations = numeroIteracoesNewton;
                     fast.valuePi = ultimaIteracao[1];
                }
            }
            break;
        case 3:
            Secante2 *method = new Secante2(3,4,valuesA[i],error1,error2,useTest1);
            method->loop();
            double valuePi = method->getValue();
            double errorAbs = abs(method->function(method->getValue())) ;
            int interations = method->getIterationsNumber();

            QTableWidgetItem *itemValueA = new QTableWidgetItem;
            itemValueA->setText(QString::number(valuesA[i],'g',10));
            table->setItem(i,0,itemValueA);

            QTableWidgetItem *itemValuePi = new QTableWidgetItem;
            itemValuePi->setText(QString::number(valuePi,'g',10));
            table->setItem(i,1,itemValuePi);

            QTableWidgetItem *itemValueInterations = new QTableWidgetItem;
            itemValueInterations->setText(QString::number(interations));
            table->setItem(i,2,itemValueInterations);

            QTableWidgetItem *itemValueError = new QTableWidgetItem;
            itemValueError->setText(QString::number(errorAbs));
            table->setItem(i,3,itemValueError);
            if(errorAbs < best.error){
                best.error = errorAbs;
                best.name = valuesA[i];
                best.qtdInterations = interations;
                best.valuePi = valuePi;
            }
            if(interations < fast.qtdInterations){
                fast.error = errorAbs;
                fast.name = valuesA[i];
                fast.qtdInterations = interations;
                fast.valuePi = valuePi;
            }
            break;
        }
    }

    betterA->setText(QString::number(best.name,'g',10));
    betterValue->setText(QString::number( best.valuePi,'g',10));
    qtdBetterInt->setText(QString::number( best.qtdInterations));

    fastA->setText(QString::number(fast.name,'g',10));
    fastValue->setText(QString::number( fast.valuePi,'g',10));
    qtdFastInt->setText(QString::number( fast.qtdInterations));

}

Comparation::~Comparation()
{
    delete ui;
}
