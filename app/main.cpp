#include "mainwindow.h"
#include "../include/glut.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
