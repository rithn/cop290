#-------------------------------------------------
#
# Project created by QtCreator 2018-03-29T10:27:33
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -lopengl32 -L../lib -lglut32

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    proj_display.cpp \
    solid_display.cpp \
    ..\src\Solid.cpp \
    ..\src\Line.cpp \
    ..\src\Point.cpp \
    ..\src\Projection.cpp \
    glwidget.cpp

HEADERS += \
        mainwindow.h \
    proj_display.h \
    solid_display.h \
    ..\include\Solid.h \
    ..\include\Line.h \
    ..\include\Point.h \
    ..\include\Projection.h \
    ..\include\glut.h \
    glwidget.h

FORMS += \
        mainwindow.ui \
    proj_display.ui \
    solid_display.ui
