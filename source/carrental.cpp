#include "carrental.h"
#include "ui_carrental.h"
#include "rentalfunctions.h"
#include "customerfunctions.h"
#include "carfunctions.h"

QString SoSecNr;
QString LName;
int PNumber;
QString RNR;
QString Brnd;

QString StartDate;
QString ReturnDate;
bool ValLicense;

CarRental::CarRental(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarRental)
{
    ui->setupUi(this);
}

CarRental::~CarRental()
{
    delete ui;
}




void CarRental::on_pushButton_clicked()
{
    //Adding car and person to rentalcar db
    SoSecNr = nullptr;
    LName = nullptr;
    PNumber = 0;
    RNR = nullptr;
    Brnd=nullptr;
    StartDate = nullptr;
    ReturnDate = nullptr;
    ValLicense = false;

     SoSecNr = ui->SosSecNr->text();
     LName = ui->LastName->text();
     PNumber = ui->PhoneNumber->text().toInt();
     RNR = ui->RegNr->text();
     Brnd = ui->Brand->text();
     StartDate = ui->StartDate->dateTime().toString();
     ReturnDate = ui->ReturnDate->dateTime().toString();
     if(ui->checkBox->isChecked())
     {
         ValLicense= true;
         assignCar(SoSecNr, LName, PNumber, RNR, StartDate,  ReturnDate, ValLicense);


     }

     else{
         qDebug()<<"Missing valid license";
     }
}


void CarRental::on_Unnasign_clicked()

{
     //removing from rentalcar db
     SoSecNr = nullptr;
     LName = nullptr;
     PNumber = 0;
     RNR = nullptr;
     StartDate = nullptr;
     ReturnDate = nullptr;
     ValLicense = false;

     SoSecNr = ui->SosSecNr->text();
     LName = ui->LastName->text();
     PNumber = ui->PhoneNumber->text().toInt();
     RNR = ui->RegNr->text();
     StartDate = ui->StartDate->dateTime().toString();
     ReturnDate = ui->ReturnDate->dateTime().toString();

     if
         (UnassignCar(SoSecNr))
     {
         std::cout<<"Car unnasigned"<<std::endl;
     }
     else
     {
         std::cout<<"Unable to unassign car"<<std::endl;
     }
}





void CarRental::on_Loadtable_clicked()
{
     QSqlQueryModel *m = new QSqlQueryModel(this);
     m-> setQuery("SELECT * FROM CarRental");

     ui->tableView->setModel(m);
}




void CarRental::on_SearchC_clicked()
{



      PNumber = 0;
      PNumber = ui->PhoneNumber->text().toInt();
      QSqlQuery q;
      if(searchCustomer(PNumber))
      {
         QSqlQueryModel *m = new QSqlQueryModel(this);


         q.prepare("SELECT * FROM Customers WHERE PhoneNumber = :PhoneNumber");
         q.bindValue(":PhoneNumber", PNumber);
         q.exec();

         m->setQuery(std::move(q));
         ui->Cust->setModel(m);

         qDebug()<<"customer found";

      }
      else
      {
          qDebug()<<"Not found";
      }

}


void CarRental::on_FindCar_clicked()
{

      Brnd = nullptr;
      Brnd = ui->Brand->text();
      QSqlQuery q;

      if (searchCar(Brnd))
      {

          q.prepare("SELECT * FROM Cars WHERE Brand = :Brand");
          q.bindValue(":Brand", Brnd);

          q.exec();

          QSqlQueryModel *m = new QSqlQueryModel(this);
          m->setQuery(std::move(q));
          ui->Cars->setModel(m);

      }

      else
      {
          qDebug()<<"Not found";
      }

}

