#ifndef CARRENTAL_H
#define CARRENTAL_H

#include <QDialog>

namespace Ui {
class CarRental;
}

class CarRental : public QDialog
{
    Q_OBJECT

public:
    explicit CarRental(QWidget *parent = nullptr);
    ~CarRental();

private slots:


    void on_pushButton_clicked();

    void on_Unnasign_clicked();



    void on_Loadtable_clicked();



    void on_SearchC_clicked();

    void on_FindCar_clicked();

private:
    Ui::CarRental *ui;
};

#endif // CARRENTAL_H
