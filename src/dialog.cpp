#include "../lib/imports.h"
#include "../lib/dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent,std::string title,std::string message) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(title));
    ui->labelMessage->setText(QString::fromStdString(message));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    this->close();
}
