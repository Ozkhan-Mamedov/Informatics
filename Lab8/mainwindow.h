#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int W;
    int H;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Generate_clicked();

    void on_Height_valueChanged(int arg1);

    void on_Width_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};

// Структура, содержащая основной заголовок .bmp-файла.
#pragma pack(push, 1)
typedef struct
{
    char bfType[2]; // Тип файла. Должно хранить "BM".
    unsigned int bfSize; // Размер файла в байтах.
    unsigned int reserved; // Зарезервированное поле.
    unsigned int bfOffBits; // Смещение в байтах до начала данных.
}BMP_FileHeader;
#pragma pack(pop)
// Структура заголовка, содержащего информацию о BMP-файле
typedef struct
{
    unsigned int biSize; // Размер структуры-заголовка.
    int biWidth; // Ширина изображения в пикселях.
    int biHeight; // Высота изображения в пикселях.
    short int biPlanes; // Число плоскостей. Всегда 1.
    short int biBitCount; // Битность изображения.
    unsigned int biCompression; // Сжатие. Не используется.
    unsigned int biSizeImage; // Параметр реального размера
    int biXPelsPerMeter; // Параметр реального размера
    int biYPelsPerMeter; // Параметр реального размера
    unsigned int biClrUsed; // Не используется.
    unsigned int biClrImportant; // Не используется.
}BMP_InfoHeader;
// Структура, хранящая цвет в 32-битном BMP-изображении.
typedef struct
{
    unsigned char rgbBlue; // Синий цвет.
    unsigned char rgbGreen; // Зеленый цвет.
    unsigned char rgbRed; // Красный цвет.
    unsigned char rgbAlpha; // Альфа-канал.
}BMP_Quad;



#endif // MAINWINDOW_H
