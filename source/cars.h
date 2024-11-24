#ifndef CARS_H
#define CARS_H

#include <QDialog>

namespace Ui {
class Cars;
}

class Cars : public QDialog
{
    Q_OBJECT

public:
    explicit Cars(QWidget *parent = nullptr);
    ~Cars();

private slots:
    void on_LoadTable_clicked();

    void on_addCar_clicked();

    void on_UpdateCar_clicked();

    void on_DeleteCar_clicked();

private:
    Ui::Cars *ui;
};

#endif // CARS_H
