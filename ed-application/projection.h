#ifndef PROJECTION_H
#define PROJECTION_H

#include <QDialog>

namespace Ui {
class Projection;
}

class Projection : public QDialog
{
    Q_OBJECT

public:
    explicit Projection(QWidget *parent = 0);
    ~Projection();

private slots:
    void on_checkBox_toggled(bool checked);

    void on_checkBox_2_toggled(bool checked);

    void on_checkBox_3_toggled(bool checked);

    void on_checkBox_4_toggled(bool checked);

    void on_checkBox_5_toggled(bool checked);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::Projection *ui;
};

#endif // PROJECTION_H
