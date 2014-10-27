/*Janela principal responsável pela interação com o usuário.
 * Autores: Caio Viktor;
 *          Cristiano Melo;
 *          Lucas Falcão
*/
#include "../lib/imports.h"
#include "../lib/mainwindow.h"
#include "ui_mainwindow.h"
QTableWidget *tableA;
QDialog *janela;
int qtdA = 1;
bool stateInitial = true;
//Declaração de objetos
Secante2 *secante;
Secante2 *secanteComp;
NewtonRaphson *newton;
NewtonRaphson *newtonComp;
Methods *falsi;
Methods *falsiComp;
double *valuesA;
double error1,error2;
//Declaração de objetos FIM
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->valueError1->setValue(pow(10,-7));
    ui->valueError2->setValue(pow(10,-7));
    tableA = ui->tableValueA;
    on_setUp_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_valueQtdA_valueChanged(int arg1)
{

    qtdA = arg1;

    tableA->setRowCount(arg1);
    for (int i = 0; i < arg1; ++i) {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString("0"));
        tableA->setItem(i,0,item);

    }
    ui->checkBox->setChecked(false);
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked){
        QString startRangeS = ui->valueStartRange->text().replace(",",".");
        QString endRangeS = ui->valueEndRange->text().replace(",",".");
        double startRange = startRangeS.toDouble();
        double endRange = endRangeS.toDouble();
        double increment = (endRange - startRange)/qtdA;
        double value = startRange;
        for(int i=0; i < qtdA; i++){
            QTableWidgetItem *cell = tableA->item(i,0);
            cell->setText(QString::number(value,'g',10));
            value+=increment;
        }
    }
    else{
        for(int i=0; i < qtdA; i++){
            QTableWidgetItem *cell = tableA->item(i,0);
            cell->setText("0");
        }
    }
}
//Atualiza tabela secante
void MainWindow::updateTableSec(double valueA,double error1,double error2){
    //delete secante;

//    std::cout << valueA <<std::endl << error1<<std::endl<<error2<<std::endl;
    QTableWidget *table = ui->tableSec;
    QLabel *labelInteration = ui->valueInterationSec;
    QLabel *labelValuePi = ui->valuePiSec;
    QLabel *labelError = ui->valueErrorSec;
    QRadioButton *RadioUseTeste1 = ui->setUseTest1;

    bool useTest1 = RadioUseTeste1->isChecked();
    secante = new Secante2(3,4,valueA,error1,error2,useTest1);
    secante->loop();
    ListResults results = secante->getAllResults();

    int interations = results.getLength();
    double errorFinal = 1;
    double *interation = 0;

    table->setRowCount(interations);
    for (int i = 0; i < interations; ++i) {
        interation = results.pop();
        //valor Pi
        QTableWidgetItem *Pi = new QTableWidgetItem;
        Pi->setText(QString::number(interation[1],'g',10));
        table->setItem(i,0,Pi);
        //Xa
        QTableWidgetItem *Xa = new QTableWidgetItem;
        Xa->setText(QString::number(interation[1],'g',10));
        table->setItem(i,1,Xa);
        //F(Xa)
        QTableWidgetItem *FXa = new QTableWidgetItem;
        FXa->setText(QString::number(interation[2],'g',10));
        table->setItem(i,2,FXa);
        //Xb
        QTableWidgetItem *Xb = new QTableWidgetItem;
        Xb->setText(QString::number(interation[3],'g',10));
        table->setItem(i,3,Xb);
        //F(Xb)
        QTableWidgetItem *FXb = new QTableWidgetItem;
        FXb->setText(QString::number(interation[4],'g',10));
        table->setItem(i,4,FXb);
        //Error
        QTableWidgetItem *E = new QTableWidgetItem;
        if(i > 1){
            errorFinal = abs((interation[3] - interation[1]));
            E->setText(QString::number(errorFinal));
        }
        else{
            E->setText("Chute Inicial");
        }
        table->setItem(i,5,E);
    }

    labelInteration->setText(QString::number(interations,'g',10));
    labelValuePi->setText(QString::number(secante->getValue(),'g',10));
    labelError->setText(QString::number(errorFinal));

}

//Atualiza tabela Newton
void MainWindow::updateTableNewton(double valueA,double error1,double error2){

    //Tabela que mostrará as iterações do método de newton:
    QTableWidget *tabelaNewton = ui->tableNewton;

    //Cria ponteiros para os itens logo abaixo da tabela na aba Newton
    QLabel *numeroIteracoes = ui->valueInterationNewton;
    QLabel *valorPi = ui->valuePiNewton;
    QLabel *erroNewton = ui->valueErrorNewton;

    QRadioButton *RadioUseTeste1 = ui->setUseTest1Newton;

    bool useTest1Newton = RadioUseTeste1->isChecked();
    //Chamada pro método de Newton
    newton = new NewtonRaphson(3,valueA,error1,error2,useTest1Newton);
    newton->loop();

    ListResults resultNewton = newton->getAllResults();

    int numeroIteracoesNewton = resultNewton.getLength();
    double erroFinal = 1;
    double *iteracao;

    //Define o número de linhas da tabela
    tabelaNewton->setRowCount(numeroIteracoesNewton);

    //PREENCHIMENTO DAS LINHAS:
    for (int i = 0; i < numeroIteracoesNewton; i++){
        iteracao = resultNewton.pop();
        //Valor de Pi
        QTableWidgetItem *Pi = new QTableWidgetItem;
        Pi->setText(QString::number(iteracao[1],'g',10));
        tabelaNewton->setItem(i,0,Pi);
        //Xa
        QTableWidgetItem *Xa = new QTableWidgetItem;
        Xa->setText(QString::number(iteracao[1],'g',10));
        tabelaNewton->setItem(i,1,Xa);
        //F(Xa)
        QTableWidgetItem *FXa = new QTableWidgetItem;
        FXa->setText(QString::number(iteracao[2],'g',10));
        tabelaNewton->setItem(i,2,FXa);
        //Xb
        QTableWidgetItem *Xb = new QTableWidgetItem;
        Xb->setText(QString::number(iteracao[3],'g',10));
        tabelaNewton->setItem(i,3,Xb);
        //F(Xb)
        QTableWidgetItem *FXb = new QTableWidgetItem;
        FXb->setText(QString::number(iteracao[4],'g',10));
        tabelaNewton->setItem(i,4,FXb);
        //Error
        QTableWidgetItem *E = new QTableWidgetItem;
        if(i>0){
            erroFinal = abs((iteracao[3] - iteracao[1]));
            E->setText(QString::number(erroFinal));
        }
        else{
            E->setText("Chute Inicial");
        }
        tabelaNewton->setItem(i,5,E);


    }

    numeroIteracoes->setText(QString::number(numeroIteracoesNewton));
    valorPi->setText(QString::number(iteracao[1],'g',10));
    erroNewton->setText(QString::number(erroFinal));
}

void MainWindow::updateTableFalse( double valueA, double error1, double error2 ){

    //Tabela que mostrará as iterações do método regula_falsi:
    QTableWidget *tabelaFalse = ui->tableFalse;

    //Cria ponteiros para os itens logo abaixo da tabela na aba Regula_Falsi
    QLabel *numeroIteracoes = ui->valueInterationFalse;
    QLabel *valorPi = ui->valuePiFalse;
    QLabel *erroFalse = ui->valueErrorFalse;


    //Chamada pro método Regula_Falsi
    falsi = new Methods(3, 4, valueA, error1, 500);
    falsi->Regula_Falsi();
    ListResults resultFalse = falsi->getAllResults();

    int numeroIteracoesFalse = resultFalse.getLength();
    double erroFinal = 1;
    double *iteracao;

    //Define o número de linhas da tabela
    tabelaFalse->setRowCount( numeroIteracoesFalse );

    //PREENCHIMENTO DAS LINHAS:
  for ( int i = 0; i < numeroIteracoesFalse; i++ ){
      iteracao = resultFalse.pop();
        //Valor de Pi
      QTableWidgetItem *Pi = new QTableWidgetItem;
      Pi->setText(QString::number(iteracao[0],'g',10));
      tabelaFalse->setItem(i,0,Pi);

      //Valor F_Pi
      QTableWidgetItem *F_Pi = new QTableWidgetItem;
      F_Pi->setText(QString::number(iteracao[1],'g',10));
      tabelaFalse->setItem(i,1,F_Pi);

        //Xa
      QTableWidgetItem *Xa = new QTableWidgetItem;
      Xa->setText(QString::number(iteracao[2],'g',10));
      tabelaFalse->setItem(i,2,Xa);
        //F(Xa)
      QTableWidgetItem *FXa = new QTableWidgetItem;
      FXa->setText(QString::number(iteracao[3],'g',10));
      tabelaFalse->setItem(i,3,FXa);
        //Xb
      QTableWidgetItem *Xb = new QTableWidgetItem;
      Xb->setText(QString::number(iteracao[4],'g',10));
      tabelaFalse->setItem(i,4,Xb);
        //F(Xb)
      QTableWidgetItem *FXb = new QTableWidgetItem;
      FXb->setText(QString::number(iteracao[5],'g',10));
      tabelaFalse->setItem(i,5,FXb);
        //Error
      QTableWidgetItem *E = new QTableWidgetItem;
      erroFinal = abs(iteracao[6] );
      E->setText(QString::number(erroFinal));
      tabelaFalse->setItem(i,6,E);


  }
  if(numeroIteracoesFalse > 0 ){
      numeroIteracoes->setText(QString::number(numeroIteracoesFalse));
      valorPi->setText(QString::number(iteracao[0],'g',10));
      erroFalse->setText(QString::number(erroFinal));
    }
}

//Apertar Botão salvar
void MainWindow::on_setUp_clicked()
{
    delete secante;
    delete newton;
    delete valuesA;
    error1 = ui->valueError1->text().replace(",",".").toDouble();
    error2 = ui->valueError2->text().replace(",",".").toDouble();
    valuesA = new double[qtdA];

    for(int i = 0 ;i < qtdA ;i++){
        QTableWidgetItem *cell = tableA->item(i,0);
        valuesA[i] = cell->text().replace(",",".").toDouble();
    }
    //Atualiza e preenche combo da secante
    updateTableSec(valuesA[0],error1,error2);
    QComboBox *comboSec = ui->comboSec;
    comboSec->clear();

    //criar campos para método de Newton
    updateTableNewton(valuesA[0],error1,error2);
    QComboBox *comboNewton = ui->comboNewton;
    comboNewton->clear();


    //Cria campos para comparação de métodos
    updateTableComp(valuesA[0], error1, error2);
    QComboBox *comboComparation = ui->comboComparation;
    comboComparation->clear();

    //Cria campos para posicao falsa
    updateTableFalse(valuesA[0], error1, error2);
    QComboBox *comboFalse = ui->comboFalse;
    comboFalse->clear();

    for(int i = 0;i< qtdA;i++){
        comboSec->addItem(QString::number(valuesA[i],'g',10),valuesA[i]);
        comboNewton->addItem(QString::number(valuesA[i],'g',10),valuesA[i]);
        comboComparation->addItem(QString::number(valuesA[i],'g',10),valuesA[i]);
        comboFalse->addItem(QString::number(valuesA[i],'g',10),valuesA[i]);
        //fazer o mesmo para os outros
    }
    comboSec->addItem("Comparativo",qtdA);
    comboNewton->addItem("Comparativo",qtdA);
    comboFalse->addItem("Comparativo",qtdA);
    if(!stateInitial){
        Dialog *dialog = new Dialog(NULL,"Confirmado","Configurações confirmadas");
        dialog->show();
    }
    stateInitial = false;
}

//escolher A em Posição falsa
void MainWindow::on_comboFalse_currentIndexChanged(int index)
{
    if (index <qtdA){
            updateTableFalse(valuesA[index],error1,error2);
    }
    else{
        Comparation *compare = new Comparation(NULL,1,qtdA,valuesA,error1,error2,true);
        compare->show();
    }

}
//escolher A em Newton
void MainWindow::on_comboNewton_currentIndexChanged(int index)
{
    if (index <qtdA){
            updateTableNewton(valuesA[index],error1,error2);
    }
    else{
        Comparation *compare = new Comparation(NULL,2,qtdA,valuesA,error1,error2,ui->setUseTest1Newton->isChecked());
        compare->show();
    }
}
//escolher A em secante
void MainWindow::on_comboSec_currentIndexChanged(int index)
{
    if(index < qtdA)
        updateTableSec(valuesA[index],error1,error2);
    else{
        Comparation *compare = new Comparation(NULL,3,qtdA,valuesA,error1,error2,ui->setUseTest1->isChecked());
        compare->show();
    }

}
//escolher A em Comparação
void MainWindow::on_comboComparation_currentIndexChanged(int index)
{
    updateTableComp(valuesA[index],error1,error2);
}
//configura se usará teste 1 na secante
void MainWindow::on_setUseTest1_toggled(bool checked)
{
    QComboBox *comboSec = ui->comboSec;
    int index = comboSec->currentIndex();
    if(index < qtdA)
            updateTableSec(valuesA[index],error1,error2);
    else{
        Comparation *compare = new Comparation(NULL,3,qtdA,valuesA,error1,error2,checked);
        compare->show();
    }
}
//configura se usará teste 1 em newton
void MainWindow::on_setUseTest1Newton_toggled(bool checked)
{
    QComboBox *comboNewton = ui->comboNewton;
    int index = comboNewton->currentIndex();
    if(index < qtdA)
            updateTableNewton(valuesA[index],error1,error2);
    else{
        Comparation *compare = new Comparation(NULL,2,qtdA,valuesA,error1,error2,checked);
        compare->show();
    }
}


//Atualiza tabelas comparativo
void MainWindow::updateTableComp(double valueA,double error1,double error2){
    delete secanteComp;
    delete newtonComp;
    //Recupera tabelas
    QTableWidget *tableSec = ui->tableCompareSec;
    QTableWidget *tableNewton = ui->tableCompareNewton;
    QTableWidget *tableFalse = ui->tableCompareFalse;

    //Recupera labels melhor aproximação.
    QLabel *labelBestPi= ui->valueBestPiCompare;
    QLabel *labelBestQtdInteretion= ui->valueBestInterationCompare;
    QLabel *labelBestError = ui->valueBestErrorCompare;
    QLabel *labelBestName = ui->valueBestNamePi;

    //Recupera labels aproximação mais rápida.
    QLabel *labelFastPi= ui->valueFastPiCompare;
    QLabel *labelFastQtdInteretion= ui->valueFastInterationCompare;
    QLabel *labelFastError = ui->valueFastErrorCompare;
    QLabel *labelFastName = ui->valueFastNamePi;

    //Teste 1
    QRadioButton *RadioUseTeste1 = ui->setTest1Comparation;
    bool useTest1 = RadioUseTeste1->isChecked();

    //Atualiza tabela da secante
    secanteComp = new Secante2(3,4,valueA,error1,error2,useTest1);
    secanteComp->loop();
    ListResults results = secanteComp->getAllResults();

    int interations = results.getLength();
    double errorFinal;
    double *interation;
    double piAnteriorSec = 4;
    tableSec->setRowCount(interations);

    for (int i = 0; i < interations; ++i) {
        interation = results.pop();
        //valor Pi
        QTableWidgetItem *Pi = new QTableWidgetItem;
        Pi->setText(QString::number(interation[1],'g',15));
        tableSec->setItem(i,0,Pi);

        //Error
        QTableWidgetItem *E = new QTableWidgetItem;
        if(i>1){
            //errorFinal = abs(secanteComp->function(interation[1])) ;
            errorFinal = abs((interation[1]-piAnteriorSec))/abs(interation[1]);
            E->setText(QString::number(errorFinal));
            piAnteriorSec = interation[1];
        }
        else{
            E->setText("Chute Inicial");
        }
        tableSec->setItem(i,1,E);
    }
    //Fim atualização da secante

    //Atualiza a tabela de Newton:
        newtonComp = new NewtonRaphson(3,valueA,error1,error2,useTest1);
        newtonComp->loop();
        results = newtonComp->getAllResults();

        int numIteracoes = results.getLength();
        double erroFinal;
        double *iteracaoAtual;
        double piAnteriorNew = 3;
        tableNewton->setRowCount(numIteracoes);

        for (int i = 0; i < numIteracoes;i++){
            iteracaoAtual = results.pop();

            //Valor de pi:
            QTableWidgetItem *Pi = new QTableWidgetItem;
            Pi->setText(QString::number(iteracaoAtual[1],'g',15));
            tableNewton->setItem(i,0,Pi);
            //Colocar o erro de acordo com o Pi encontrado:
            QTableWidgetItem *Erro = new QTableWidgetItem;
            //erroFinal = abs(newtonComp->function(iteracaoAtual[1]));
            if(i > 0){
                erroFinal = abs((iteracaoAtual[1] - piAnteriorNew))/abs(iteracaoAtual[1]);
                Erro->setText(QString::number(erroFinal));
                piAnteriorNew = iteracaoAtual[1];
            }
            else{
                Erro->setText("Chute Inicial");
            }
            tableNewton->setItem(i,1,Erro);

        }

        //Atualiza a tabela da Posição Falsa:
        falsiComp = new Methods(3,4,valueA,error1,500);
        falsiComp->Regula_Falsi();
        results = falsiComp->getAllResults();

        numIteracoes = results.getLength();
        tableFalse->setRowCount(numIteracoes);

        for (int i = 0; i < numIteracoes;i++){
            iteracaoAtual = results.pop();

            //Valor de pi:
            QTableWidgetItem *PiFalse = new QTableWidgetItem;
            PiFalse->setText(QString::number(iteracaoAtual[0],'g',15));
            tableFalse->setItem(i,0,PiFalse);
            //Colocar o erro, que no caso é o range:
            QTableWidgetItem *ErroFalse = new QTableWidgetItem;
            //ErroFalse->setText(QString::number(abs((iteracaoAtual[4] - iteracaoAtual[0])/iteracaoAtual[4]),'g',10));
            ErroFalse->setText(QString::number(abs(iteracaoAtual[6]/iteracaoAtual[0]),'g',10));
            tableFalse->setItem(i,1,ErroFalse);


        }

        //Comparação de resultados:

        //Primeiro: MAIS RÁPIDO:
        int numIteracoesNewton = tableNewton->rowCount();
        int numIteracoesSec = tableSec->rowCount();
        int numIteracoesFalso = tableFalse->rowCount();

        int menorNumIter;
        QTableWidgetItem *piMaisRapido;
        QTableWidgetItem *erroMaisRapido; //nome péssimo pra essa variável, eu sei x.x'

        //SE O NEWTON FOR O MAIS RAPIDO:
        if (numIteracoesFalso>0){
            if ((numIteracoesNewton <= numIteracoesSec) && (numIteracoesNewton <= numIteracoesFalso)){
                piMaisRapido = tableNewton->item((numIteracoesNewton-1),0);
                erroMaisRapido = tableNewton->item((numIteracoesNewton-1),1);
                menorNumIter = numIteracoesNewton;
                labelFastName->setText("Newton-Raphson");
            }
            else{//SE SECANTE FOR MAIS RAPIDO:
                if ((numIteracoesSec <= numIteracoesNewton) && (numIteracoesSec <= numIteracoesFalso)){
                    piMaisRapido = tableSec->item((numIteracoesSec-1),0);
                    erroMaisRapido = tableSec->item((numIteracoesSec-1),1);
                    menorNumIter = numIteracoesSec;
                    labelFastName->setText("Secante");

                }
                else{//SE POSICAO FALSA FOR MAIS RAPIDO
                    piMaisRapido = tableFalse->item((numIteracoesFalso-1),0);
                    erroMaisRapido = tableFalse->item((numIteracoesFalso-1),1);
                    menorNumIter = numIteracoesFalso;
                    labelFastName->setText("Posição Falsa");
                }
            }
        } else {//PARA O POSICAO FALSA NAO ACHAR VALOR ALGUM:
            if ((numIteracoesNewton <= numIteracoesSec)){ //SE NEWTON MAIS RAPIDO
                piMaisRapido = tableNewton->item((numIteracoesNewton-1),0);
                erroMaisRapido = tableNewton->item((numIteracoesNewton-1),1);
                menorNumIter = numIteracoesNewton;
                labelFastName->setText("Newton-Raphson");
            }
            else{//SE SECANTE FOR MAIS RAPIDO
                piMaisRapido = tableSec->item((numIteracoesSec-1),0);
                erroMaisRapido = tableSec->item((numIteracoesSec-1),1);
                menorNumIter = numIteracoesSec;
                labelFastName->setText("Secante");
            }
        }

        //Preenchimento do resto dos campos do método mais rápido:
        labelFastPi->setText(piMaisRapido->text());
        labelFastError->setText(erroMaisRapido->text());
        labelFastQtdInteretion->setText(QString::number(menorNumIter));

        //Agora: MAIS PRECISO

        //Pega o erro de cada método:
        QTableWidgetItem *erroNewtonTab = tableNewton->item(numIteracoesNewton-1,1);
        QTableWidgetItem *erroSecTab = tableSec->item(numIteracoesSec-1,1);
        double erroFalso;
        if (numIteracoesFalso>0){
            QTableWidgetItem *erroFalsoTab = tableFalse->item(numIteracoesFalso-1,1);
            erroFalso = QString(erroFalsoTab->text()).toDouble();
        }
        else{
            erroFalso = 99999;//caso o metodo da posicao falsa nao faca iteracoes,
                              //uso um valor alto para o erro para falhar nas comparacoes
        }
        double erroNewton = QString(erroNewtonTab->text()).toDouble();
        double erroSec = QString(erroSecTab->text()).toDouble();


        QTableWidgetItem *piMaisPreciso;
        //QTableWidgetItem *erroMaisPreciso; //nome péssimo de novo D:

        if ((erroNewton <= erroSec) && (erroNewton <= erroFalso)){
            //SE NEWTON FOR MAIS PRECISO
            piMaisPreciso=tableNewton->item(numIteracoesNewton-1,0);
            labelBestName->setText("Newton-Raphson");
            labelBestError->setText(QString::number(erroNewton));
            labelBestQtdInteretion->setText(QString::number(numIteracoesNewton));

        }
        else{//SE SECANTE FOR MAIS PRECISO
            if ((erroSec <= erroNewton) && (erroSec <= erroFalso)){
                piMaisPreciso=tableSec->item(numIteracoesSec-1,0);
                labelBestName->setText("Secante");
                labelBestError->setText(QString::number(erroSec));
                labelBestQtdInteretion->setText(QString::number(numIteracoesSec));
            }
            else{//SE POSICAO FALSA FOR MAIS PRECISO
                piMaisPreciso=tableFalse->item(numIteracoesFalso-1,0);
                labelBestName->setText("Posicão Falsa");
                labelBestError->setText(QString::number(erroFalso));
                labelBestQtdInteretion->setText(QString::number(numIteracoesFalso));

            }



        }

        //Preenchendo o que não foi feito caso a caso:
        labelBestPi->setText(piMaisPreciso->text());



}

void MainWindow::on_setTest1Comparation_toggled(bool checked)
{
    QComboBox *comboComparation = ui->comboComparation;
    int index = comboComparation->currentIndex();
    updateTableComp(valuesA[index],error1,error2);
}

void MainWindow::on_buttonPlotSecante_clicked()
{
    ListResults results = secante->getAllResults();
    Plot *plot = new Plot();
    if(plot->line(results)){
        if(system("google-chrome src/saida.html"))
            system("firefox src/saida.html");
    }
    else{
        Dialog *dialog = new Dialog(NULL,"Erro","Erro ao Plotar o gráfico!");
        dialog->show();
    }
    delete plot;
}

void MainWindow::on_buttonPlotNewton_clicked()
{
    ListResults results = newton->getAllResults();
    Plot *plot = new Plot();
    if(plot->line(results)){
        if(system("google-chrome src/saida.html"))
            system("firefox src/saida.html");
    }
    else{
        Dialog *dialog = new Dialog(NULL,"Erro","Erro ao Plotar o gráfico!");
        dialog->show();
    }
    delete plot;
}
