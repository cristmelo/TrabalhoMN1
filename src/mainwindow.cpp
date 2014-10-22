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
        errorFinal = abs((interation[3] - interation[1]));
        E->setText(QString::number(errorFinal));
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
        erroFinal = abs((iteracao[3] - iteracao[1]));
        E->setText(QString::number(erroFinal));
        tabelaNewton->setItem(i,5,E);


    }

    numeroIteracoes->setText(QString::number(numeroIteracoesNewton));
    valorPi->setText(QString::number(iteracao[1],'g',10));
    erroNewton->setText(QString::number(erroFinal));
}

//Apertar Botão salvar
void MainWindow::on_setUp_clicked()
{
    delete secante;
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


    for(int i = 0;i< qtdA;i++){
        comboSec->addItem(QString::number(valuesA[i],'g',10),valuesA[i]);
        comboNewton->addItem(QString::number(valuesA[i],'g',10),valuesA[i]);
        comboComparation->addItem(QString::number(valuesA[i],'g',10),valuesA[i]);
        //fazer o mesmo para os outros
    }
    comboSec->addItem("Comparativo",qtdA);
    comboNewton->addItem("Comparativo",qtdA);

    if(!stateInitial){
        Dialog *dialog = new Dialog(NULL,"Confirmado","Configurações confirmadas");
        dialog->show();
    }
    stateInitial = false;
}
//escolher A em Biseção
void MainWindow::on_comboBisection_currentIndexChanged(int index)
{
    //QTableView *table = ui->tableBisection;
}
//TODO:

//escolher A em Posição falsa
void MainWindow::on_comboFalse_currentIndexChanged(int index)
{
    //QTableView *table = ui->tableFalse;
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
    //Recupera tabelas
    QTableWidget *tableSec = ui->tableCompareSec;
    QTableWidget *tableNewton = ui->tableNewton;
    QTableWidget *tableFalse = ui->tableFalse;

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

    tableSec->setRowCount(interations);
    for (int i = 0; i < interations; ++i) {
        interation = results.pop();
        //valor Pi
        QTableWidgetItem *Pi = new QTableWidgetItem;
        Pi->setText(QString::number(interation[1],'g',10));
        tableSec->setItem(i,0,Pi);

        //Error
        QTableWidgetItem *E = new QTableWidgetItem;
        errorFinal = abs(secante->function(interation[1])) ;
        E->setText(QString::number(errorFinal));
        tableSec->setItem(i,1,E);
    }
    //Fim atualização da secante
    //TODO: As demais tabelas e comparar resultados

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
    if(plot->line(results))
        system("firefox src/saida.html");
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
    if(plot->line(results))
        system("firefox src/saida.html");
    else{
        Dialog *dialog = new Dialog(NULL,"Erro","Erro ao Plotar o gráfico!");
        dialog->show();
    }
    delete plot;
}
