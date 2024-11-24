#include "cars.h"
#include "carfunctions.h"
#include "ui_cars.h"

QString RegNr;
QString Brand;
QString Model;
QString Color;
int ModelYear;


Cars::Cars(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cars)
{
    ui->setupUi(this);
}

Cars::~Cars()
{
    delete ui;
}

void Cars::on_LoadTable_clicked()
{

    QSqlQueryModel *m = new QSqlQueryModel(this);
    m-> setQuery("SELECT * FROM Cars");

    ui->tableView->setModel(m);
}


void Cars::on_addCar_clicked()
{
    RegNr = nullptr; ;
    Brand = nullptr;
    Model = nullptr;
    Color = nullptr;
    ModelYear = 0;


    RegNr = ui->RegNr->text();
    Brand=ui->Brand->text();
    Model= ui->Model->text();
    Color= ui->Color->text();
    ModelYear= ui->ModelYear->text().toInt();

    if (CarAdded(RegNr))
    {
        std::cout << "Car already added" << std::endl;
    }
    else
    {
        if (addCars(RegNr, Brand, Model, Color, ModelYear))
        {
            std::cout << "Car added to database" << std::endl;
        }
        else
        {
            std::cout << "Car not added" << std::endl;
        }
    }




}


void Cars::on_UpdateCar_clicked()
{
    RegNr = nullptr;
    Brand = nullptr;
    Model = nullptr;
    Color = nullptr;
    ModelYear = 0;

    RegNr = ui->RegNr->text();
    Brand=ui->Brand->text();
    Model= ui->Model->text();
    Color= ui->Color->text();
    ModelYear= ui->ModelYear->text().toInt();

    if (EditCar(RegNr, Brand, Model, Color, ModelYear))
    {
        std::cout << "Car updated" << std::endl;
    }
    else
    {
        std::cout << "Car not Updated" << std::endl;
    }

}


void Cars::on_DeleteCar_clicked()
{
    RegNr = nullptr; ;
    Brand = nullptr;
    Model = nullptr;
    Color = nullptr;
    ModelYear = 0;

    RegNr = ui->RegNr->text();
    Brand=ui->Brand->text();
    Model= ui->Model->text();
    Color= ui->Color->text();
    ModelYear= ui->ModelYear->text().toInt();

    if (DeleteCar(RegNr))
    {
        std::cout << "Car deleted" << std::endl;
    }
    else
    {
        std::cout << "Car not deleted" << std::endl;
    }

}

