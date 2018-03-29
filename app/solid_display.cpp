#include "solid_display.h"
#include "ui_solid_display.h"

Solid_display::Solid_display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Solid_display)
{
    ui->setupUi(this);
}

Solid_display::~Solid_display()
{
    delete ui;
}
