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
        case 2:

            break;
        case 3:
            Secante2 *method = new Secante2(3,4,valuesA[i],error1,error2,useTest1);
            method->loop();
            double valuePi = method->getValue();
            double errorAbs = abs(method->function(method->getValue())) ;
            int interations = method->getIterationsNumber();

            QTableWidgetItem *itemValueA = new QTableWidgetItem;
            itemValueA->setText(QString::number(valuesA[i]));
            table->setItem(i,0,itemValueA);

            QTableWidgetItem *itemValuePi = new QTableWidgetItem;
            itemValuePi->setText(QString::number(valuePi));
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

    betterA->setText(QString::number(best.name));
    betterValue->setText(QString::number( best.valuePi));
    qtdBetterInt->setText(QString::number( best.qtdInterations));

    fastA->setText(QString::number(fast.name));
    fastValue->setText(QString::number( fast.valuePi));
    qtdFastInt->setText(QString::number( fast.qtdInterations));

}

Comparation::~Comparation()
{
    delete ui;
}
