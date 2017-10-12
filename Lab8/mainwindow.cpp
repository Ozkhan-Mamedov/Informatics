#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <cassert>
#include <fstream>
#include <cstdint>
#include "math.h"

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


void MainWindow::on_Height_valueChanged(int arg1)
{
    H = arg1;
}

void MainWindow::on_Width_valueChanged(int arg1)
{
    W = arg1;
}

void MainWindow::on_Generate_clicked()
{
    BMP_FileHeader fh;
    BMP_InfoHeader IH;

    memset (&fh, 0, sizeof(BMP_FileHeader));
    int rawBits = sizeof(BMP_FileHeader) + sizeof(BMP_InfoHeader); // С++
    int rawSize = rawBits + W*H*4;

    fh.bfType[0] = 'B';
    fh.bfType[1] = 'M';
    fh.bfSize = rawSize;
    fh.bfOffBits = rawBits;

    memset (&IH, 0, sizeof(BMP_InfoHeader));
    IH.biSize = sizeof(BMP_InfoHeader); // C++
    IH.biHeight=H;
    IH.biWidth=W;
    IH.biPlanes=1;
    IH.biBitCount=32;
    IH.biCompression = 0;
    IH.biSizeImage = 0;
    IH.biXPelsPerMeter = 0;
    IH.biYPelsPerMeter = 0;
    IH.biClrUsed = 0;
    IH.biClrImportant = 0;

    void* mem_ptr = (void*) malloc((size_t) rawSize);

    size_t offset = 0;

    memcpy(mem_ptr, &fh, sizeof(fh));
    offset += sizeof(fh);

    memcpy(mem_ptr + offset, &IH, sizeof(IH));
    offset += sizeof(IH);

    BMP_Quad color;
    for (int i = 0; i < W * H; ++i)
    {
        color.rgbRed = 0 + 2 * i / W;
        color.rgbBlue = 255 - i / W;
        color.rgbGreen = 0 + 2 * i / W;
        color.rgbAlpha = 1;
        memcpy(mem_ptr + offset, &color, sizeof(BMP_Quad));
        offset += sizeof(BMP_Quad);
    }

    FILE* f=fopen("D:\\DGI\\Vasilchenko\\2.2\\blabla2\\image.bmp","wb");
    fwrite(mem_ptr,rawSize,1,f);
    fclose(f);



}

