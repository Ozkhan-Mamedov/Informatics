#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <winsock2.h>
#include <QTimer>

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
    void onTimer();
    void on_action_triggered();

    void on_Send_clicked();

private:
    Ui::MainWindow *ui;
    SOCKET s;
    QTimer t1;
};

#endif // MAINWINDOW_H
