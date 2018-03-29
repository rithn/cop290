#include "proj_display.h"
#include "ui_proj_display.h"

Proj_display::Proj_display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Proj_display)
{
    ui->setupUi(this);
}

Proj_display::~Proj_display()
{
    delete ui;
}

void Proj_display::on_checkBox_toggled(bool checked)
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

void Proj_display::on_checkBox_2_toggled(bool checked)
{
    if(checked){
        //show projection
        printf("checkBox2 is checked");
    }
    else{
        //hide projection
        printf("checkBox2 is un-checked");
    }
}

void Proj_display::on_checkBox_3_toggled(bool checked)
{
    if(checked){
        //show projection
        printf("checkBox3 is checked");
    }
    else{
        //hide projection
        printf("checkBox3 is un-checked");
    }
}

void Proj_display::on_checkBox_4_toggled(bool checked)
{
    if(checked){
        //show projection
        printf("checkBox4 is checked");
    }
    else{
        //hide projection
        printf("checkBox4 is un-checked");
    }
}

void Proj_display::on_checkBox_5_toggled(bool checked)
{
    if(checked){
        //show projection
        printf("checkBox5 is checked");
    }
    else{
        //hide projection
        printf("checkBox5 is un-checked");
    }
}

void Proj_display::on_radioButton_clicked()
{
    //set mode as 3D
}

void Proj_display::on_radioButton_2_clicked()
{
    //set mode as 2D
}
