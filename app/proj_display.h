#ifndef PROJ_DISPLAY_H
#define PROJ_DISPLAY_H

#include <QDialog>

namespace Ui {
class Proj_display;
}

class Proj_display : public QDialog
{
    Q_OBJECT

public:
    explicit Proj_display(QWidget *parent = 0);
    ~Proj_display();

private slots:
    void on_checkBox_toggled(bool checked);

    void on_checkBox_2_toggled(bool checked);

    void on_checkBox_3_toggled(bool checked);

    void on_checkBox_4_toggled(bool checked);

    void on_checkBox_5_toggled(bool checked);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::Proj_display *ui;
};

#endif // PROJ_DISPLAY_H
