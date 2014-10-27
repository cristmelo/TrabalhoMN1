#include "../lib/imports.h"
#include "../lib/comparation.h"
#include "ui_comparation.h"
ListResults *listResults;
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

    listResults = new ListResults();
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
        case 0: //Este case está abandonado, o método da bisseção não existe mais no trabalho :'(

            break;
        case 1: //Posição Falsa
            if (1){
            //Explicação convincente e válida da existência deste if
            //está presente no próximo case. Aprecie o conhecimento.
                Methods *metodoFalse = new Methods(3,4,valuesA[i],error1,500);
                //A VARIAVEL ACIMA FOI APELIDADA CARINHOSAMENTE
                metodoFalse->Regula_Falsi();
                //Recebe o resultado das iterações do método da Posição Falsa:
                ListResults resultadoFalse;
                resultadoFalse = metodoFalse->getAllResults();
                int numeroIteracoesFalse = resultadoFalse.getLength();

                if(numeroIteracoesFalse == 0){
                    //Insere o A:
                    QTableWidgetItem *itemValorAFalse = new QTableWidgetItem;
                    itemValorAFalse->setText(QString::number(valuesA[i],'g',10));
                    table->setItem(i,0,itemValorAFalse);

                    //Para cada A, insere o valor de Pi achado
                    //Mas aqui é o IF do caso de não achar Pi
                    QTableWidgetItem *itemValorPi = new QTableWidgetItem;
                    itemValorPi->setText("-");
                    table->setItem(i,1,itemValorPi);

                    //Para cada A, insere o número de Iterações
                    QTableWidgetItem *itemNumIterFalse = new QTableWidgetItem;
                    itemNumIterFalse->setText("0");
                    table->setItem(i,2,itemNumIterFalse);

                    //Para cada A, insere o erro.
                    QTableWidgetItem *itemErroFalse = new QTableWidgetItem;
                    itemErroFalse->setText("-");
                    table->setItem(i,3,itemErroFalse);

                    double *iterationResults = new double[5];

                    iterationResults[0] = i;
                    iterationResults[1] = 0; //valor de pi
                    iterationResults[2] = 0;
                    iterationResults[3] = 0;//aproximacaoSeguinteDaRaiz;
                    iterationResults[4] = 0;//function(aproximacaoSeguinteDaRaiz);
                    listResults->push(iterationResults);
                }
                else{ //CASO ELE ACHE ALGUMA RAIZ
                    double *ultimaIteracao;

                    for(int k = 0;k < numeroIteracoesFalse;k++){
                       ultimaIteracao = resultadoFalse.pop();
                    }


                    //Insere o A na tabela de comparações:
                    QTableWidgetItem *itemValorAFalse = new QTableWidgetItem;
                    itemValorAFalse->setText(QString::number(valuesA[i],'g',10));
                    table->setItem(i,0,itemValorAFalse);

                    //Para cada A, insere na tabela o valor de Pi achado:
                    QTableWidgetItem *itemValorPi = new QTableWidgetItem;
                    itemValorPi->setText(QString::number(ultimaIteracao[0],'g',10));
                    table->setItem(i,1,itemValorPi);

                    //Para cada A, insere na tabela o número de Iterações:
                    QTableWidgetItem *itemNumeroIteracoes = new QTableWidgetItem;
                    itemNumeroIteracoes->setText(QString::number(numeroIteracoesFalse,'g',10));
                    table->setItem(i,2,itemNumeroIteracoes);

                    //Para cada A, insere o Erro, que no caso é o Intervalo
                    QTableWidgetItem *itemValorErro = new QTableWidgetItem;
                    itemValorErro->setText(QString::number(ultimaIteracao[6]));
                    table->setItem(i,3,itemValorErro);

                    double erroAbs = ultimaIteracao[6];
                    if(erroAbs < best.error){
                         best.error = erroAbs;
                         best.name = valuesA[i];
                         best.qtdInterations = numeroIteracoesFalse;
                         best.valuePi = ultimaIteracao[0];
                    }
                    if(numeroIteracoesFalse < fast.qtdInterations){
                         fast.error = erroAbs;
                         fast.name = valuesA[i];
                         fast.qtdInterations = numeroIteracoesFalse;
                         fast.valuePi = ultimaIteracao[0];
                    }
                    double *iterationResults = new double[5];

                    iterationResults[0] = i;
                    iterationResults[1] = ultimaIteracao[0]; //valor de pi
                    iterationResults[2] = erroAbs;
                    iterationResults[3] = ultimaIteracao[0];//aproximacaoSeguinteDaRaiz;
                    iterationResults[4] = erroAbs;//function(aproximacaoSeguinteDaRaiz);
                    listResults->push(iterationResults);




                }
            }

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
                double *penultimaIteracao;
                for(int k = 0;k < numeroIteracoesNewton;k++){
                   penultimaIteracao = ultimaIteracao;
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
                double erroAbs = abs((penultimaIteracao[3] - penultimaIteracao[1])/penultimaIteracao[3]);

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
                double *iterationResults = new double[5];
                iterationResults[0] = i;
                iterationResults[1] = ultimaIteracao[1];
                iterationResults[2] = erroAbs;
                iterationResults[3] = ultimaIteracao[1];//aproximacaoSeguinteDaRaiz;
                iterationResults[4] = erroAbs;//function(aproximacaoSeguinteDaRaiz);
                listResults->push(iterationResults);

                delete metodoNewton;
            }
            break;
        case 3:
            Secante2 *method = new Secante2(3,4,valuesA[i],error1,error2,useTest1);
            method->loop();
            ListResults interation = method->getAllResults();
            double *results;
            for(int j = 0;j < interation.getLength() - 1; j++){
                results = interation.pop();
            }
            double valuePi = method->getValue();
            //double errorAbs = abs(method->function(valuePi));
            double errorAbs = abs((results[3] - results[1])/results[3]);
//            double errorAbs = abs((method->getAproximacaoSeguinteDaRaiz() - method->getAproximacaoAtualDaRaiz())/method->getAproximacaoSeguinteDaRaiz());
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

            double *iterationResults = new double[5];
            iterationResults[0] = i;
            iterationResults[1] = valuePi;
            iterationResults[2] = errorAbs;
            iterationResults[3] = valuePi;//aproximacaoSeguinteDaRaiz;
            iterationResults[4] = errorAbs;//function(aproximacaoSeguinteDaRaiz);
            listResults->push(iterationResults);

            delete method;
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

void Comparation::on_pushButton_clicked()
{

    Plot *plot = new Plot();
    if(plot->line((*listResults))){
        if(system("google-chrome src/saida.html"))
            system("firefox src/saida.html");
    }
    else{
        Dialog *dialog = new Dialog(NULL,"Erro","Erro ao Plotar o gráfico!");
        dialog->show();
    }
    delete plot;
}
