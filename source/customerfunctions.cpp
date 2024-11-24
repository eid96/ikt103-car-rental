
#include "customerfunctions.h"


//initializes the database
void DBConnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("CarRental.sqlite");

    if (!db.open()){

        qDebug() << "Could not connect to the database:" << db.lastError();

    }
}

void customerTable()
{
    //table for customer
    QSqlQuery q;
    if(!q.exec("CREATE TABLE Customers("
                "SosSecNr TEXT PRIMARY KEY, "
                "FirstName TEXT NOT NULL, "
                "LastName TEXT NOT NULL, "
                "Email TEXT NOT NULL, "
                "PhoneNumber INTEGER NOT NULL "
                ")")) {
        qWarning()<<"Failed to create table: "<< q.lastError().text();
    }
    else{
        qDebug()<<"Table created";
    }
}
//function to add customer
bool addCustomersDB(QString SosSecNr, QString FirstName, QString LastName, QString Email,
                    int PhoneNumber)
{
    QSqlQuery q;
    q.prepare("INSERT INTO Customers (SosSecNr, FirstName, LastName, Email, PhoneNumber) "
              "VALUES (:SosSecNr, :FirstName, :LastName, :Email, :PhoneNumber)");
    q.bindValue(":SosSecNr", SosSecNr);
    q.bindValue(":FirstName", FirstName);
    q.bindValue(":LastName", LastName);
    q.bindValue(":Email", Email);
    q.bindValue(":PhoneNumber", PhoneNumber);

    if(!q.exec())
    {
        qDebug() << "Failed to add customer" << q.lastError().text();
        return false;
    }

    return true;
}



bool CustomerAdded(QString SosSecNr)
{
    bool inDB;
    QSqlQuery q;
    q.prepare("SELECT EXISTS(SELECT SosSecNr FROM Customers WEHERE SosSecNr= :SosSecNr)");
    q.addBindValue(SosSecNr);
    q.exec();
    while(q.next())
    {
        inDB=q.value(0).toBool();
    }
    return inDB;
}



bool EditCustomers(QString SosSecNr, QString FirstName, QString LastName, QString Email, int PhoneNumber)
{
    QSqlQuery q;

    // Check if the customer exists
    q.prepare("SELECT EXISTS(SELECT SosSecNr FROM Customers WHERE SosSecNr = :SosSecNr)");
    q.bindValue(":SosSecNr", SosSecNr);
    q.exec();



    if (!q.next() || !q.value(0).toBool())
    {
        qDebug() << "Customer not found";
    }

    // the acutal Update
    q.prepare("UPDATE Customers SET FirstName = :FirstName, LastName = :LastName, "
              "Email = :Email, PhoneNumber = :PhoneNumber WHERE SosSecNr = :SosSecNr");
    q.bindValue(":FirstName", FirstName);
    q.bindValue(":LastName", LastName);
    q.bindValue(":Email", Email);
    q.bindValue(":PhoneNumber", PhoneNumber);
    q.bindValue(":SosSecNr", SosSecNr);

    if (!q.exec())
    {
        qDebug() << "Failed to update customer" << q.lastError().text();
        return false;
    }
    return true;
}

bool DeleteCust(QString SosSecNr)
{
    QSqlQuery q;

    // Check if the customer exists
    q.prepare("SELECT EXISTS(SELECT SosSecNr FROM Customers WHERE SosSecNr = :SosSecNr)");
    q.bindValue(":SosSecNr", SosSecNr);
    q.exec();

    if(!q.next() || !q.value(0).toBool())
    {
        qDebug()<<"Customer not found";
    }
    //The acutal delete function
    q.prepare("DELETE FROM Customers WHERE SosSecNr = :SosSecNr");
    q.bindValue(":SosSecNr", SosSecNr);

    if (!q.exec())
    {
        qDebug() << "Failed to delete customer" << q.lastError().text() ;
        return false;
    }
    return true;
}

bool searchCustomer(int PhoneNumber)
{

    QSqlQuery q;

    q.prepare("SELECT * FROM Customers WHERE PhoneNumber = :PhoneNumber");
    q.bindValue(":PhoneNumber", PhoneNumber);
    q.exec();
    return q.next();

}







