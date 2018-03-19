#include "projection.h"
#include "ui_projection.h"

Projection::Projection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Projection)
{
    ui->setupUi(this);
}

Projection::~Projection()
{
    delete ui;
}

void Projection::on_checkBox_toggled(bool checked)
{
    if(checked){
        //show projection
        printf("checkBox1 is checked");
    }
    else{
        //hide projection
        printf("checkBox1 is un-checked");
    }
}

void Projection::on_checkBox_2_toggled(bool checked)
{
    if(checked){
        //show projection
        printf("checkBox1 is checked");
    }
    else{
        //hide projection
        printf("checkBox1 is un-checked");
    }
}

void Projection::on_checkBox_3_toggled(bool checked)
{
    if(checked){
        //show projection
        printf("checkBox1 is checked");
    }
    else{
        //hide projection
        printf("checkBox1 is un-checked");
    }
}

void Projection::on_checkBox_4_toggled(bool checked)
{
    if(checked){
        //show projection
        printf("checkBox1 is checked");
    }
    else{
        //hide projection
        printf("checkBox1 is un-checked");
    }
}

void Projection::on_checkBox_5_toggled(bool checked)
{
    if(checked){
        //show projection
        printf("checkBox1 is checked");
    }
    else{
        //hide projection
        printf("checkBox1 is un-checked");
    }
}

void Projection::on_radioButton_clicked()
{
    //set mode as 3D
}

void Projection::on_radioButton_2_clicked()
{
    //set mode as 2D
}
