#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QWheelEvent>
#include <QMouseEvent>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void wheelEvent (QWheelEvent* e);
    void mousePressEvent (QMouseEvent* e);
    void mouseMoveEvent (QMouseEvent* e);
    void drawCube1();
    void drawCube2();
    void drawCube3();
    void drawTank();
    float cp,cr,cz;
    QPoint pt;
signals:

public slots:
};

#endif // GLWIDGET_H
