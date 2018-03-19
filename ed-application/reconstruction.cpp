#include "reconstruction.h"
#include "ui_reconstruction.h"

Reconstruction::Reconstruction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reconstruction)
{
    ui->setupUi(this);
}

Reconstruction::~Reconstruction()
{
    delete ui;
}
