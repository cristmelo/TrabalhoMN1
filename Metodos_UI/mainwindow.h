#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_valueQtdA_valueChanged(int arg1);


    void on_checkBox_toggled(bool checked);

    void on_setUp_clicked();

    void on_comboBisection_currentIndexChanged(int index);

    void on_comboFalse_currentIndexChanged(int index);

    void on_comboNewton_currentIndexChanged(int index);

    void on_comboSec_currentIndexChanged(int index);

    void on_comboBisectrion_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
