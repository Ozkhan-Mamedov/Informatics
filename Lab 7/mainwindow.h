#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int id;
    double Range;
    double RadialVelocity;
    double Azimut;
    double Angle;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Clear_clicked();

    void on_Add_clicked();

    void on_Range_valueChanged(double arg1);

    void on_Radialvelocity_valueChanged(double arg1);

    void on_Azimut_valueChanged(double arg1);

    void on_Angle_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
