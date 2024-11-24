
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addcustomers_clicked();

    void on_AddCar_clicked();



    void on_Rental_clicked();

    void on_imporcustomer_clicked();

    void on_ImportCars_clicked();

    void on_ImportRentalInfo_clicked();

    void on_exportcust_clicked();

    void on_ExportCar_clicked();

    void on_ExportCarRental_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
