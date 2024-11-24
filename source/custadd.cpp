#include "custadd.h"
#include "customerfunctions.h"
#include "ui_custadd.h"

CustAdd::CustAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustAdd)
{
    ui->setupUi(this);
}

CustAdd::~CustAdd()
{
    delete ui;
}

void CustAdd::on_AddCust_clicked()
{
    QString SosSecNr = ui->SosSecNr->text();
    QString FirstName = ui->FirstName->text();
    QString LastName = ui->LastName->text();
    QString Email = ui->Email->text();
    int PhoneNumber = ui->PhoneNr->text().toInt();

    if (CustomerAdded(SosSecNr))
    {
        std::cout << "Customer already added" << std::endl;
    }
    else
    {
        if (addCustomersDB(SosSecNr, FirstName, LastName, Email, PhoneNumber))
        {
            std::cout << "Customer added to database" << std::endl;
        }
        else
        {
            std::cout << "Customer not added" << std::endl;
        }
    }
}

