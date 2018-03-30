#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

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

void MainWindow::on_pushButton_clicked()
{
    QString input_solid = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "../inputfiles",
                "All files (*.*);;Text File (*.txt)"
                );
    Solid solid;
    std::ifstream solfile(input_solid.toStdString());
    solid.getData(solfile);
    solid.datadisp();
    //::render(&solid);
    //std::cout << "Input solid file: " << input_solid.toStdString() << std::endl;
    //QDesktopServices::openUrl( QUrl("file:///"+input_solid, QUrl::TolerantMode) );
    //QMessageBox::information(this,tr("File Name"),filename);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString input_proj = QFileDialog::getOpenFileName(this,tr("Open File"),"C:/Users/Harshit(SH)/Desktop/ed_data","All files (*.*);;Text File (*.txt)");
}

void MainWindow::on_pushButton_4_clicked()
{
    projection = new Proj_display(this);
    projection->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    reconstruction = new Solid_display(this);
    reconstruction->show();
}
