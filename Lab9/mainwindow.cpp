#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "qlistwidget.h"
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

void MainWindow::on_open_clicked()
{
  QString path = QFileDialog::getOpenFileName(this,"Open file",".","Ini file(*.ini);;All files(*)");
  if (path.isEmpty())
    return;

  fileLines.clear();
  vector<string> fileLines;
  FILE * F = fopen(path.toUtf8().data(),"rb");
  while(!feof(F))
  {
      char str[256];
      fgets(str, 256, F);
      fileLines.push_back(str);
  }
  fclose(F);

  ui->listWidget->clear();
  for (int a=0; a<fileLines.size(); a++)
  {
      QString s = QString::fromStdString(fileLines[a]);
      ui->listWidget->addItem(s);
  }


}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
   //QString s = ui->names_list->currentItem()->text();


}
