#include "caradd.h"
#include "ui_caradd.h"
#include "carfunctions.h"

QString RegNr;
QString Brand;
QString Model;
QString Color;
int ModelYear;

CarAdd::CarAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarAdd)
{
    ui->setupUi(this);
}

CarAdd::~CarAdd()
{
    delete ui;
}

void CarAdd::on_addCar_clicked()
{
    //resets values
    RegNr = nullptr;
    Brand = nullptr;
    Model = nullptr;
    Color = nullptr;
    ModelYear = 0;

    RegNr = ui->RegNr->text();
    Brand = ui->Brand->text();
    Model = ui->Model->text();
    Color = ui->Color->text();
    ModelYear = ui->ModelYear->text().toInt();

    if(CarAdded(RegNr))
    {
        std::cout<<"Car already added"<<std::endl;

    }
    else
    {
        if(addCars(RegNr, Brand, Model, Color, ModelYear))
        {
            std::cout<<"Car added to database"<<std::endl;
        }
        else
        {
            std::cout<<"Failed to add car"<<std::endl;
        }
    }
}

