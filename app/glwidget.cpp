#include "glwidget.h"
#include "../include/glut.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)

{

}

void GLWidget::initializeGL(){
    glClearColor(0.2,0.2,0.2,1);
}

void GLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);

    glutWireTeapot(0.4);

}

void GLWidget::resize(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0.5,0, 0,0,0, 0,1,0);
}
