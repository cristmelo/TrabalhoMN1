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
    QLabel *lessValue = ui->labelLessValue;
    QLabel *betterA = ui->labelNameBetterMethod;
    QLabel *lessA = ui->labelNameLessMethod;
    QLabel *qtdBetterInt = ui->labelQTDbetterInterations;
    QLabel *qtdLessInt = ui->labelQTDLessInterations;
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
        Secante2 *method = new Secante2(3,4,valuesA[0],error1,error2,useTest1);
        nameMethod->setText("Secante");
        break;
    }
    table->setRowCount(qtdA);
    for(int i = 0; i < qtdA; i++){

        //TODO: Criar tabela
    }

}

Comparation::~Comparation()
{
    delete ui;
}
