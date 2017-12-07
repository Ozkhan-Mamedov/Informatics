#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ws2tcpip.h>
#define _WIN32_WINNT 0x0501

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2,2), &wsadata);
    t1.start(100);
    connect(&t1,SIGNAL(timeout()),SLOT(onTimer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    s = socket(AF_INET, SOCK_STREAM, 0);
    if(s == INVALID_SOCKET)
    {
        ui->textEdit->append("Unable to create socket");
    }
    char* hostname = ui->addrspin->text().toLatin1().data(); // IP-адрес или имя удаленного узла
    char* port = ui->portspin->text().toLatin1().data(); // Порт удаленного узла в виде строки
    int err;
    sockaddr_in addr;
    struct addrinfo *result = NULL;
    err = getaddrinfo(hostname, port, NULL, &result);
    if(err != 0)
    {
        ui->textEdit->append("Unable to connect");
    /*Ошибка определения имени сервера, result использовать нелья*/
    }
    else
    {
    memcpy(&addr, result->ai_addr, sizeof(addr));
    }
    freeaddrinfo(result);

    int timeout=20;
    setsockopt(s,SOL_SOCKET, SO_RCVTIMEO,(char*)&timeout,sizeof(timeout));

    err=::connect(s,(sockaddr*)&addr,sizeof(addr));
    if (err!=0)
        ui->textEdit->append("Unable to connect");
    else
        ui->textEdit->append("Connected");
    u_long m=1;
    ioctlsocket(s,FIONBIO,&m);
}

void MainWindow::on_Send_clicked()
{
    QByteArray q= ui->lineEdit_2->text().toUtf8();
    int err = send(s,q.data(),q.size(),0);
    ui->lineEdit_2->setText("");
}

void MainWindow::onTimer()
{
    if (s==0) return;
    char buf[128];
    int err = recv(s, buf, 128, 0);
    if(err < 0)
    {
//        if(WSAGetLastError() == WSAEWOULDBLOCK) return;
//        closesocket(s);
//        ui->textEdit->append("Unable to receive data");
        return;
    }
    if(err == 0)
    {
        closesocket(s);
        ui->textEdit->append("Remote host has closed connection\n");
        return;
    }
//    err = send(s, buf, err, 0);
//    if(err < 0)
//    {
//        closesocket(s);
//        ui->textEdit->append("Unable to send data");
//        return;
//    }
    QString s=QString::fromUtf8(buf,err);
    ui->textEdit->append(s);
}

