/*Janela principal responsável pela interação com o usuário.
 * Autores: Caio Viktor;
 *          Cristiano Melo;
 *          Lucas Falcão
*/
#include "../lib/imports.h"
#include "ui_mainwindow.h"
QTableWidget *tableA;
int qtdA = 1;

//Declaração de objetos
Secante2 *secante;
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
            cell->setText(QString::number(value));
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

void MainWindow::updateTableSec(double valueA,double error1,double error2){
    //delete secante;

    std::cout << valueA <<std::endl << error1<<std::endl<<error2<<std::endl;
    QTableWidget *table = ui->tableSec;
    QLabel *labelInteration = ui->valueInterationSec;
    QLabel *labelValuePi = ui->valuePiSec;
    QLabel *labelError = ui->valueErrorSec;

    secante = new Secante2(3,4,valueA,error1,error2);
    secante->loop();
    ListResults results = secante->getAllResults();

    int interations = results.getLength();

    double *interation;

    table->setRowCount(interations);
    for (int i = 0; i < interations; ++i) {
        interation = results.pop();
        //valor Pi
        QTableWidgetItem *Pi = new QTableWidgetItem;
        Pi->setText(QString::number(interation[1]));
        table->setItem(i,0,Pi);
        //Xa
        QTableWidgetItem *Xa = new QTableWidgetItem;
        Xa->setText(QString::number(interation[1]));
        table->setItem(i,1,Xa);
        //F(Xa)
        QTableWidgetItem *FXa = new QTableWidgetItem;
        FXa->setText(QString::number(interation[2]));
        table->setItem(i,2,FXa);
        //Xb
        QTableWidgetItem *Xb = new QTableWidgetItem;
        Xb->setText(QString::number(interation[3]));
        table->setItem(i,3,Xb);
        //F(Xb)
        QTableWidgetItem *FXb = new QTableWidgetItem;
        FXb->setText(QString::number(interation[4]));
        table->setItem(i,4,FXb);
        //Error
        QTableWidgetItem *E = new QTableWidgetItem;
        E->setText(QString::number(interation[2]/interation[1]));
        table->setItem(i,5,E);
    }
    double errorFinal = interation[2]/interation[1];
    double valuePi = interation[1];


    labelInteration->setText(QString::number(interations));
    labelValuePi->setText(QString::number(valuePi));
    labelError->setText(QString::number(errorFinal));

}

//Apertar Botão salvar
void MainWindow::on_setUp_clicked()
{
    //delete secante;
    error1 = ui->valueError1->text().replace(",",".").toDouble();
    error2 = ui->valueError2->text().replace(",",".").toDouble();
    valuesA = new double[qtdA];

    for(int i = 0 ;i < qtdA ;i++){
        QTableWidgetItem *cell = tableA->item(i,0);
        valuesA[i] = cell->text().replace(",",".").toDouble();
    }
    updateTableSec(valuesA[0],error1,error2);
    QComboBox *comboSec = ui->comboSec;
    comboSec->clear();
    for(int i = 0;i< qtdA;i++){
        comboSec->addItem(QString::number(valuesA[i]),valuesA[i]);
        //fazer o mesmo para os outros
    }
    comboSec->addItem("Comparativo",qtdA);
}
//escolher A em Biseção
void MainWindow::on_comboBisection_currentIndexChanged(int index)
{
    //QTableView *table = ui->tableBisection;
}
//TODO:

// IMPORTANTE|\\

// Já criei alguns eventos e capiturei as tabelas necessárias
//Criem as tableas dinamicamente Sigam o exemplo da on_checkBox_toggled(bool checked) no caso de checked pois nele eu fiz isso

// IMPORTANTE|\\

//escolher A em Posição falsa
void MainWindow::on_comboFalse_currentIndexChanged(int index)
{
    //QTableView *table = ui->tableFalse;
}
//escolher A em Newton
void MainWindow::on_comboNewton_currentIndexChanged(int index)
{
    //QTableView *table = ui->tableNewton;
}
//escolher A em secante
void MainWindow::on_comboSec_currentIndexChanged(int index)
{
    if(index < qtdA)
        updateTableSec(valuesA[index],error1,error2);
//    else
//        //TODO:Comparativo dos valores de A
}
//escolher A em Comparação
void MainWindow::on_comboBisectrion_currentIndexChanged(int index)
{
    //QTableView *tableFalse = ui->tableCompareFalse;
    //QTableView *tableNewton = ui->tableCompareNewton;
    //QTableView *tableSec = ui->tableCompareSec;
}
