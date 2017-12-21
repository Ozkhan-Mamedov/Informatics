#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    cp=cr=cz=0;
    cz=-5;
    cp=30;
    cr=45;
}

void GLWidget::wheelEvent(QWheelEvent *e)
{
    cz += 0.001 * e->angleDelta().y();
    updateGL();

}

void GLWidget::mousePressEvent(QMouseEvent *e)
{
   if(e->buttons()& Qt::LeftButton)
            pt=e->pos();
}

void GLWidget::drawCube1()
{

    float s = 0.5;
    GLfloat x[8] = {s, -s, -s, s, s, -s, -s, s};
    GLfloat y[8] = {s, s, -s, -s, s, s, -s, -s};
    GLfloat z[8] = {-s, -s, -s, -s, s, s, s, s};
    int f[6][4] = { {0, 1, 2, 3},
                    {0, 1, 5, 4},
                    {1, 5, 6, 2},
                    {2, 6, 7, 3},
                    {3, 7, 4, 0},
                    {4, 5, 6, 7}};
    glColor3f(1, 0.25, 10);
    glBegin(GL_QUADS);
    for(int a=0; a<6; a++)
    {
        for(int b=0; b<4; b++)
        {
            int idx = f[a][b];
            glVertex3f(x[idx], y[idx], z[idx]);
        }
    }
    glEnd();

}

void GLWidget::drawCube2()
{

    float s = 0.5;
    GLfloat x[8] = {s, -s, -s, s, s, -s, -s, s};
    GLfloat y[8] = {s, s, -s, -s, s, s, -s, -s};
    GLfloat z[8] = {-s, -s, -s, -s, s, s, s, s};
    int f[6][4] = { {0, 1, 2, 3},
                    {0, 1, 5, 4},
                    {1, 5, 6, 2},
                    {2, 6, 7, 3},
                    {3, 7, 4, 0},
                    {4, 5, 6, 7}};
    glColor3f(2, 0.5, 10);
    glBegin(GL_QUADS);
    for(int a=0; a<6; a++)
    {
        for(int b=0; b<4; b++)
        {
            int idx = f[a][b];
            glVertex3f(x[idx], y[idx], z[idx]);
        }
    }
    glEnd();

}

void GLWidget::drawCube3()
{

    float s = 0.5;
    GLfloat x[8] = {s, -s, -s, s, s, -s, -s, s};
    GLfloat y[8] = {s, s, -s, -s, s, s, -s, -s};
    GLfloat z[8] = {-s, -s, -s, -s, s, s, s, s};
    int f[6][4] = { {0, 1, 2, 3},
                    {0, 1, 5, 4},
                    {1, 5, 6, 2},
                    {2, 6, 7, 3},
                    {3, 7, 4, 0},
                    {4, 5, 6, 7}};
    glColor3f(3, 1, 10);
    glBegin(GL_QUADS);
    for(int a=0; a<6; a++)
    {
        for(int b=0; b<4; b++)
        {
            int idx = f[a][b];
            glVertex3f(x[idx], y[idx], z[idx]);
        }
    }
    glEnd();

}

void GLWidget::drawTank()
{
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glScalef(2, 3, 1);
    drawCube1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 1.25);
    glScalef(1, 2, 0.5);
    drawCube2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 1, 1.25);
    glScalef(0.5, 2, 0.2);
    drawCube3();
    glPopMatrix();
}

void GLWidget::mouseMoveEvent(QMouseEvent *e)
{
   if(e->buttons()& Qt::LeftButton)
     {
       QPoint diff=e->pos()-pt;
       cp +=diff.x();
       cr +=diff.y();
       pt=e->pos();
       updateGL();

     }
}


void GLWidget:: initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0,0,0,0);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void GLWidget:: paintGL()
{
    int W=width();
    int H=height();
    float D=(float)W/H;
        glClear(GL_COLOR_BUFFER_BIT
                | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glLoadIdentity();
        glFrustum(-D,D,-1,1,1,500);

    glTranslatef(0,0,cz);
    glRotatef(cr,1,0,0);
    glRotatef(cp,0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_LINES);
        //X
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        //y
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        //z
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,1);
        glEnd();

    drawTank();

}
