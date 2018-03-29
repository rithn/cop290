#ifndef SOLID_DISPLAY_H
#define SOLID_DISPLAY_H

#include <QDialog>

namespace Ui {
class Solid_display;
}

class Solid_display : public QDialog
{
    Q_OBJECT

public:
    explicit Solid_display(QWidget *parent = 0);
    ~Solid_display();

private:
    Ui::Solid_display *ui;
};

#endif // SOLID_DISPLAY_H
