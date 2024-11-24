
#include "mainwindow.h"
#include "carfunctions.h"
#include "customerfunctions.h"
#include "rentalfunctions.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //connect to db
    DBConnect();
    //creates tables
    carTable();

    customerTable();

    rentalDB();




    return a.exec();
}
