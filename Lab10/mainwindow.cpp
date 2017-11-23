#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <time.h>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.start(100);
    connect(&timer,SIGNAL(timeout()),SLOT(repaint()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QColor bg_color(0,0,0);
    QBrush bg_brush(bg_color);
    QColor cl(0,255,0);
    QPen pl(cl);
    int W=width();
    int H=height();
    int R;
    if(W<H)
    {
        R=W/2;
    }
    else
        R=H/2;

    p.setBrush(bg_brush);
    p.drawRect(0,0,W,H);
    p.setBrush(Qt::NoBrush);
    p.setPen(pl);
    p.drawEllipse(QPoint(W/2,H/2), R, R);

    time_t t=time(0);
    struct tm* tt=localtime(&t);
    qDebug()<<tt->tm_hour
           <<tt->tm_min
          <<tt->tm_sec;
    int a_sec=tt->tm_sec;
    int a_min=tt->tm_min;
    int a_hour=tt->tm_hour;

    int x_sec=R*sin(M_PI*a_sec/30);
    int y_sec=R*cos(M_PI*a_sec/30);
    p.drawLine(QPoint(W/2,H/2),QPoint(W/2+x_sec,H/2-y_sec));
    int x_min=0.8*R*sin(M_PI*a_min/30);
    int y_min=0.8*R*cos(M_PI*a_min/30);
    p.drawLine(QPoint(W/2,H/2),QPoint(W/2+x_min,H/2-y_min));
    int x_hour=0.5*R*sin(M_PI*a_hour/3);
    int y_hour=0.5*R*cos(M_PI*a_hour/3);
    p.drawLine(QPoint(W/2,H/2),QPoint(W/2+x_hour,H/2-y_hour));
}
