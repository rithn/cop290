#ifndef RECONSTRUCTION_H
#define RECONSTRUCTION_H

#include <QDialog>

namespace Ui {
class Reconstruction;
}

class Reconstruction : public QDialog
{
    Q_OBJECT

public:
    explicit Reconstruction(QWidget *parent = 0);
    ~Reconstruction();

private:
    Ui::Reconstruction *ui;
};

#endif // RECONSTRUCTION_H
