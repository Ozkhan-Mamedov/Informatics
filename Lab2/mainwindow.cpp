#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfile.h"

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

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui -> label -> setText(QString::number(value));
}

void MainWindow::on_pushButton_clicked()
{
    int a = ui -> horizontalSlider -> value();
    QString::number(a);
    QString b = ui -> lineEdit -> text();
    int c = ui -> doubleSpinBox -> value();
    QString::number(c);
    statusBar() -> showMessage("Slider=" + QString::number(a) + "; LineEdit=" + b + "; SpinBox=" + QString::number(c));
    QFile file("2.txt");
    file.open(QIODevice::WriteOnly);
    QString e = "Slider=" + QString::number(a) + "; LineEdit=" + b + "; SpinBox=" + QString::number(c);
    file.write(e.toUtf8());
    file.close();
}
