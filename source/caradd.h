#ifndef CARADD_H
#define CARADD_H

#include <QDialog>

namespace Ui {
class CarAdd;
}

class CarAdd : public QDialog
{
    Q_OBJECT

public:
    explicit CarAdd(QWidget *parent = nullptr);
    ~CarAdd();

private slots:
    void on_addCar_clicked();

private:
    Ui::CarAdd *ui;
};

#endif // CARADD_H
