
#include "mainwindow.h"
#include "qdir.h"
#include "ui_mainwindow.h"

#include "cars.h"
#include "customers.h"
#include "carrental.h"
#include "jsonfunctions.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_addcustomers_clicked()
{
    //general window for customer
    Customers cust;
    cust.setModal(true);
    cust.exec();
}


void MainWindow::on_AddCar_clicked()
{
    //general window for cars
    Cars car;
    car.setModal(true);
    car.exec();
}





void MainWindow::on_Rental_clicked()
{
    CarRental cr;
    cr.setModal(true);
    cr.exec();
}


void MainWindow::on_imporcustomer_clicked()
{
    QString fn = "customers.json";
    QDir dir = QDir("C:/Users/morte/ikt103");
    QString path = dir.filePath(fn);

    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen())
    {
        qDebug() << "Error: Database connection not open. Exiting";
        return;
    }
    CustFromJson(path);
}


void MainWindow::on_ImportCars_clicked()
{
    QString fn = "Cars.json";
    QDir dir = QDir("C:/Users/morte/ikt103");
    QString path = dir.filePath(fn);

    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen())
    {
        qDebug() << "Error: Database connection not open. Exiting";
        return;
    }
    CarsFromJson(path);

}


void MainWindow::on_ImportRentalInfo_clicked()
{
    QString fn = "carrental.json";
    QDir dir = QDir("C:/Users/morte/ikt103");
    QString path = dir.filePath(fn);

    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen())
    {
        qDebug() << "Error: Database connection not open. Exiting";
        return;
    }
    CarRentalFromJson(path);
}


void MainWindow::on_exportcust_clicked()
{
    QString fn = "CustToJson.json";
    QDir dir = QDir("C:/Users/morte/ikt103");
    QString path = dir.filePath(fn);
    CustToJson(path); // Pass the full file path instead of just the file name
}


void MainWindow::on_ExportCar_clicked()
{
    QString fn = "CarToJson.json";
    QDir dir = QDir("C:/Users/morte/ikt103");
    QString path = dir.filePath(fn);
    CarsToJson(path);
}



void MainWindow::on_ExportCarRental_clicked()
{
    QString fn = "RentalCarToJson.json";
    QDir dir = QDir("C:/Users/morte/ikt103");
    QString path = dir.filePath(fn);
    CarRentalToJson(path);
}

