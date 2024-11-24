#include "customers.h"
#include "customerfunctions.h"
#include "ui_customers.h"
QString SosSecNr;
QString FirstName;
QString LastName;
QString Email;
int PhoneNumber;
Customers::Customers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Customers)
{
    ui->setupUi(this);
}

Customers::~Customers()
{
    delete ui;
}

void Customers::on_LoadTable_clicked()
{
    //creates model for data
    QSqlQueryModel *mod = new QSqlQueryModel(this);
    mod-> setQuery("SELECT * FROM Customers");

    ui->tableView->setModel(mod);

    /*funksjon for å automatisk oppdatere?*/
    //ui->tableView->viewport()->update();
}


void Customers::on_pushButton_clicked()
{
    //add button
    SosSecNr = nullptr;
    FirstName = nullptr;
    LastName = nullptr;
    Email = nullptr;
    PhoneNumber = 0;

    SosSecNr = ui->SosSecNr->text();
    FirstName = ui->FirstName->text();
    LastName = ui->LastName->text();
    Email = ui->Email->text();
    PhoneNumber = ui->PhoneNr->text().toInt();

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


void Customers::on_EditCustomer_clicked()
{

   //edit button
    SosSecNr = nullptr;
    FirstName = nullptr;
    LastName = nullptr;
    Email = nullptr;
    PhoneNumber = 0;

    SosSecNr = ui->SosSecNr->text();
    FirstName = ui->FirstName->text();
    LastName = ui->LastName->text();
    Email = ui->Email->text();
    PhoneNumber = ui->PhoneNr->text().toInt();



        if (EditCustomers(SosSecNr, FirstName, LastName, Email, PhoneNumber))
        {
            std::cout << "Customer updated" << std::endl;
        }
        else
        {
            std::cout << "Customer not added" << std::endl;
        }


}


void Customers::on_DeleteCustomer_clicked()
{
    SosSecNr = nullptr;
    FirstName = nullptr;
    LastName = nullptr;
    Email = nullptr;
    PhoneNumber = 0;

    SosSecNr = ui->SosSecNr->text();
    FirstName = ui->FirstName->text();
    LastName = ui->LastName->text();
    Email = ui->Email->text();
    PhoneNumber = ui->PhoneNr->text().toInt();


        if (DeleteCust(SosSecNr))
        {
            std::cout << "Customer deleted" << std::endl;
        }
        else
        {
            std::cout << "Customer not added" << std::endl;
        }


}

