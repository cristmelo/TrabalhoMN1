#ifndef COMPARATION_H
#define COMPARATION_H

#include <QWidget>

namespace Ui {
class Comparation;
}

class Comparation : public QWidget
{
    Q_OBJECT

public:
    explicit Comparation(QWidget *parent ,int typeMethod,int qtdA,double *valuesA,double error1,double error2,bool useTest1);
    //typeMethod:0-bisseção 1-posição falsa 2-Newton 3-secante
    ~Comparation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Comparation *ui;
};

#endif // COMPARATION_H
