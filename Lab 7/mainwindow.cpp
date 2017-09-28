#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Range_valueChanged(double arg1)
{
    Range = arg1;
}

void MainWindow::on_Radialvelocity_valueChanged(double arg1)
{
   RadialVelocity = arg1;
}

void MainWindow::on_Azimut_valueChanged(double arg1)
{
    Azimut = arg1;
}

void MainWindow::on_Angle_valueChanged(double arg1)
{
    Angle = arg1;
}

void MainWindow::on_Clear_clicked()
{
    ui->tableWidget->setRowCount(0);

}

void MainWindow::on_Add_clicked()
{
    int a = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(a+1);
    id = a+1;
    //::string write = std::to_string(id);
    QTableWidgetItem* kek;
    kek = new QTableWidgetItem(QString::number(id));
    ui->tableWidget->setItem(a, 0, kek);
    kek = new QTableWidgetItem(QString::number(Range));
    ui->tableWidget->setItem(a, 1, kek);
    kek = new QTableWidgetItem(QString::number(RadialVelocity));
    ui->tableWidget->setItem(a, 2, kek);
    kek = new QTableWidgetItem(QString::number(Azimut));
    ui->tableWidget->setItem(a, 3, kek);
    kek = new QTableWidgetItem(QString::number(Angle));
    ui->tableWidget->setItem(a, 4, kek);
}




