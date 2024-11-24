
#include "rentalfunctions.h"

void rentalDB()
{
    QSqlQuery qu;

    qu.prepare("CREATE TABLE IF NOT EXISTS CarRental ("
               "RentID INTEGER PRIMARY KEY, "
               "SosSecNr TEXT NOT NULL, "
               "LastName TEXT NOT NULL, "
               "PhoneNumber INTEGER NOT NULL, "
               "RegNr TEXT NOT NULL, "
                "StartDate TEXT NOT NULL, "
               "ReturnDate TEXT NOT NULL, "
               "ValLicense BOOLEAN NOT NULL, "
               "FOREIGN KEY(SosSecNr) REFERENCES Customers(SosSecNr), "
               "FOREIGN KEY(LastName) REFERENCES Customers(LastName), "
               "FOREIGN KEY(PhoneNumber) REFERENCES Customers(PhoneNumber), "
               "FOREIGN KEY(RegNr) REFERENCES Cars(RegNr)"
               ");"
               );

    if (!qu.exec()) {
        qDebug() << "Error creating rentalDB table: " << qu.lastError().text() << qu.lastError().nativeErrorCode();
    }
    else
    {
        qDebug()<<"rentalDB created";
    }
}

bool assignCar(QString SoSecNr, QString LastName, int PhoneNumber, QString RegNr,
               QString StartDate, QString ReturnDate, bool ValLicense)
{
    ValLicense = false;


    QSqlQuery query;
    query.prepare("INSERT INTO CarRental (SosSecNr, LastName, PhoneNumber, RegNr, StartDate, ReturnDate, ValLicense) "
                  "VALUES (:SosSecNr, :LastName, :PhoneNumber, :RegNr, :StartDate, :ReturnDate, :ValLicense)");
    query.bindValue(":SosSecNr", SoSecNr);
    query.bindValue(":LastName", LastName);
    query.bindValue(":PhoneNumber", PhoneNumber);
    query.bindValue(":RegNr", RegNr);
    query.bindValue(":StartDate", StartDate);
    query.bindValue(":ReturnDate", ReturnDate);
    query.bindValue(":ValLicense", ValLicense);

    if (!query.exec())
    {
        qDebug() << "Failed to assign car: " << query.lastError().text();
        return false;
    }

    qDebug() << "Car assigned successfully";
    return true;
}



void searchRentedCar();

bool UnassignCar(QString SoSecNr)
{
    QSqlQuery q;

    // Check if the customer exists and deletes by SosSec
    q.prepare("SELECT EXISTS(SELECT SosSecNr FROM CarRental WHERE SosSecNr = :SosSecNr)");
    q.bindValue(":SosSecNr", SoSecNr);
    q.exec();

    if(!q.next() || !q.value(0).toBool())
    {
        qDebug()<<"Customer not found";
    }

    q.prepare("DELETE FROM CarRental WHERE SosSecNr = :SosSecNr");
    q.bindValue(":SosSecNr", SoSecNr);

    if (!q.exec())
    {
        qDebug() << "Failed to Unassign" << q.lastError().text() << q.lastError().nativeErrorCode();
        return false;
    }

    return true;
}

