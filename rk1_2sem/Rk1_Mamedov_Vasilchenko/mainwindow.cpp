#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

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

int pox;
int poy;

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    int x = arg1;
    pox = x;
    ui->radioButton->move(x,poy);
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    int y = arg1;
    poy = y;
    ui->radioButton->move(pox,y);
}

void MainWindow::on_pushButton_clicked()
{
    FILE* f1=fopen("/Users/ozkhanmamedov/Desktop/rk1_true/coord.txt", "wb");
    fwrite(&pox, sizeof(pox), 1, f1);
    fwrite(&poy, sizeof(poy), 1, f1);
    fclose(f1);
}

void MainWindow::on_pushButton_2_clicked()
{
    FILE* f1=fopen("/Users/ozkhanmamedov/Desktop/rk1_true/coord.txt", "rb");
    fread(&pox, sizeof(pox), 1, f1);
    fread(&poy, sizeof(poy), 1, f1);
    qDebug() << pox << poy;
    ui->radioButton->move(pox,poy);
    fclose(f1);
    ui->spinBox->setValue(pox);
    ui->spinBox_2->setValue(poy);
}
