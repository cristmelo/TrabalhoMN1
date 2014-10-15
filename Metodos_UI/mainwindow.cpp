#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
QTableWidget *tableA;
int qtdA;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
//Apertar Botão salvar
void MainWindow::on_setUp_clicked()
{

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
    //QTableView *table = ui->tableSec;
}
//escolher A em Comparação
void MainWindow::on_comboBisectrion_currentIndexChanged(int index)
{
    //QTableView *tableFalse = ui->tableCompareFalse;
    //QTableView *tableNewton = ui->tableCompareNewton;
    //QTableView *tableSec = ui->tableCompareSec;
}
