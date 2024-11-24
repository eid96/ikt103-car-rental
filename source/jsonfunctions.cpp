
#include "jsonfunctions.h"


void CustFromJson(const QString& JFP)
{
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen())
    {
        qDebug() << "Error: Database connection not open. Exiting";
        return;
    }

    //Function to check if the JSon file exsits
    QFile f(JFP);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: Failed to open JSON file. Exiting";
        return;
    }

    QByteArray jData = f.readAll();
    f.close();

    QJsonParseError pError;
    QJsonDocument jDoc = QJsonDocument::fromJson(jData, &pError);
    if (pError.error != QJsonParseError::NoError)
    {
        qDebug() << "Error parsing JSON: " << pError.errorString();
        return;
    }

    if (!jDoc.isObject())  // Expecting an object, not an array
    {
        qDebug() << "Error: Invalid JSON format. Expecting an object." << pError.errorString();
        return;
    }

    QJsonObject jObject = jDoc.object();
    QJsonArray jArray = jObject.value("Customers").toArray();  // Access the "Customers" array within the object

    QSqlQuery q;

    if (!q.prepare("INSERT INTO Customers (SosSecNr, FirstName, LastName, Email, PhoneNumber) "
                   "VALUES (:sosSecNr, :firstName, :lastName, :email, :phoneNumber)"))
    {
        qDebug() << "Failed to prepare query: ";
        return;
    }

    // Execute the query for each customer
    for (const auto& jValue : jArray)
    {
        QJsonObject jCustomer = jValue.toObject();

        q.bindValue(":sosSecNr", jCustomer["SosSecNr"].toString());
        q.bindValue(":firstName", jCustomer["FirstName"].toString());
        q.bindValue(":lastName", jCustomer["LastName"].toString());
        q.bindValue(":email", jCustomer["Email"].toString());
        q.bindValue(":phoneNumber", jCustomer["PhoneNumber"].toInt());

        if (!q.exec())
        {
            qDebug() << "Error executing query: ";
            return;
        }
    }
    qDebug() << "Data imported";
}


void CarsFromJson(const QString& JFP)
{
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen())
    {
        qDebug() << "Error: Database connection not open. Exiting";
        return;
    }

    QFile f(JFP);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: Failed to open JSON file. Exiting";
        return;
    }

    QByteArray jData = f.readAll();
    f.close();

    QJsonParseError pError;
    QJsonDocument jDoc = QJsonDocument::fromJson(jData, &pError);
    if (pError.error != QJsonParseError::NoError)
    {
        qDebug() << "Error parsing JSON: " << pError.errorString();
        return;
    }

    if (!jDoc.isObject())  // Expecting an object, not an array
    {
        qDebug() << "Error: Invalid JSON format. Expecting an object.";
        return;
    }

    QJsonObject jObject = jDoc.object();
    QJsonArray jArray = jObject.value("Cars").toArray();  // Access the "Customers" array within the object

    QSqlQuery q;
    if (!q.prepare("INSERT INTO Cars (RegNr, Brand, Model, Color, ModelYear) "
                   "VALUES (:regNr, :brand, :model, :color, :modelYear)"))
    {
        qDebug() << "Failed to prepare query: " << q.lastError().text();
        return;
    }

    // Execute the query for each car record
    for (const auto& jValue : jArray)
    {
        QJsonObject jCar = jValue.toObject();

        q.bindValue(":regNr", jCar["RegNr"].toString());
        q.bindValue(":brand", jCar["Brand"].toString());
        q.bindValue(":model", jCar["Model"].toString());
        q.bindValue(":color", jCar["Color"].toString());
        q.bindValue(":modelYear", jCar["ModelYear"].toInt());

        if (!q.exec())
        {
            qDebug() << "Error executing query: " << q.lastError().text();
            return;
        }
    }
}

void CarRentalFromJson(const QString& JFP)
{
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen())
    {
        qDebug() << "Error: Database connection not open. Exiting";
        return;
    }

    QFile f(JFP);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: Failed to open JSON file. Exiting";
        return;
    }

    QByteArray jData = f.readAll();
    f.close();

    QJsonParseError pError;
    QJsonDocument jDoc = QJsonDocument::fromJson(jData, &pError);
    if (pError.error != QJsonParseError::NoError)
    {
        qDebug() << "Error parsing JSON: " << pError.errorString();
        return;
    }

    if (!jDoc.isObject())  // Expecting an object, not an array
    {
        qDebug() << "Error: Invalid JSON format. Expecting an object.";
        return;
    }

    QJsonObject jObject = jDoc.object();
    QJsonArray jArray = jObject.value("CarRental").toArray();

    QSqlQuery q;
    if (!q.prepare("INSERT INTO CarRental (RentID, SosSecNr, LastName, PhoneNumber, RegNr, StartDate, ReturnDate, ValLicense) "
                   "VALUES (:rentID, :sosSecNr, :lastName, :phoneNumber, :regNr, :startDate, :returnDate, :valLicense)"))
    {
        qDebug() << "Failed to prepare query: " << q.lastError().text();
        return;
    }


    for (const auto& jValue : jArray)
    {
        QJsonObject jRental = jValue.toObject();

        q.bindValue(":rentID", jRental["RentID"].toInt());
        q.bindValue(":sosSecNr", jRental["SosSecNr"].toString());
        q.bindValue(":lastName", jRental["LastName"].toString());
        q.bindValue(":phoneNumber", jRental["PhoneNumber"].toInt());
        q.bindValue(":regNr", jRental["RegNr"].toString());
        q.bindValue(":startDate", jRental["StartDate"].toString());
        q.bindValue(":returnDate", jRental["ReturnDate"].toString());
        q.bindValue(":valLicense", jRental["ValLicense"].toBool());

        if (!q.exec())
        {
            qDebug() << "Error executing query: " << q.lastError().text();
            return;
        }
    }
}

void CustToJson(const QString& fp)
{
    QSqlQuery q;
    if(!q.exec("SELECT * FROM Customers"))
    {
        qDebug()<<"Error executing query"<<q.lastError().text();
        return;
    }
    //loops though the rows and creates JSON arrays
    QJsonArray jArray;
    while(q.next())
    {
        QJsonObject jObject;
        QSqlRecord rec = q.record();
        for (int i = 0; i < rec.count(); ++i)
        {
            QString fn = rec.fieldName(i);
            QVariant val = rec.value(i);
            jObject[fn] = QJsonValue::fromVariant(val);
        }
        jArray.append(jObject);
    }
     QJsonDocument jDoc(jArray);

    QFile output(fp);
     if(output.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        output.write(jDoc.toJson());
        qDebug()<<"Customers exported to: "<<fp;
    }
     else
     {
        qDebug() << "Error writing to file: " << output.errorString();
     }
}
void CarsToJson(const QString& fp)
{
     QSqlQuery q;
     if(!q.exec("SELECT * FROM Cars"))
     {
        qDebug()<<"Error executing query"<<q.lastError().text();
        return;
     }

     QJsonArray jArray;
     while(q.next())
     {
        QJsonObject jObject;
        QSqlRecord rec = q.record();
        for (int i = 0; i < rec.count(); ++i)
        {
            QString fn = rec.fieldName(i);
            QVariant val = rec.value(i);
            jObject[fn] = QJsonValue::fromVariant(val);
        }
        jArray.append(jObject);
     }
     QJsonDocument jDoc(jArray);

     QFile output(fp);
     if(output.open(QIODevice::WriteOnly | QIODevice::Text))
     {
        output.write(jDoc.toJson());
        qDebug()<<"Cars exported to: "<<fp;
     }
     else
     {
        qDebug() << "Error writing to file: " << output.errorString();
     }
}
void CarRentalToJson(const QString& fp)
{
     QSqlQuery q;
     if(!q.exec("SELECT * FROM CarRental"))
     {
        qDebug()<<"Error executing query"<<q.lastError().text();
        return;
     }

     QJsonArray jArray;
     while(q.next())
     {
        QJsonObject jObject;
        QSqlRecord rec = q.record();
        for (int i = 0; i < rec.count(); ++i)
        {
            QString fn = rec.fieldName(i);
            QVariant val = rec.value(i);
            jObject[fn] = QJsonValue::fromVariant(val);
        }
        jArray.append(jObject);
     }
     QJsonDocument jDoc(jArray);

     QFile output(fp);
     if(output.open(QIODevice::WriteOnly | QIODevice::Text))
     {
        output.write(jDoc.toJson());
        qDebug()<<"CarRental exported to: "<<fp;
     }
     else
     {
        qDebug() << "Error writing to file: " << output.errorString();
     }
}
