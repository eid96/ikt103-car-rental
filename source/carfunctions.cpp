
#include "carfunctions.h"

//Creates table cars
void carTable(){
    QSqlQuery q;
    if(!q.exec("CREATE TABLE Cars("
                "RegNr TEXT PRIMARY KEY, "
                "Brand TEXT NOT NULL, "
                "MODEL TEXT NOT NULL, "
                "COLOR TEXT NOT NULL, "
                "ModelYear INTEGER NOT NULL "

                ")")){
        qDebug()<<"Failed to create table: "<< q.lastError().text();
    }
    else{
        qDebug()<<"Table created";
    }
}

//add car
bool addCars(QString RegNr, QString Brand, QString Model, QString Color, int ModelYear)
{
    //query to add cars
    QSqlQuery q;
    q.prepare("INSERT INTO Cars (RegNr, Brand, Model, Color, ModelYear)"
              "VALUES(:RegNr, :Brand, :Model, :Color, :ModelYear)");
    q.bindValue(":RegNr", RegNr);
    q.bindValue(":Brand", Brand);
    q.bindValue(":Model", Model);
    q.bindValue(":Color", Color);
    q.bindValue(":ModelYear", ModelYear);


    //execute or error
    if(!q.exec())
    {
        qDebug() << "Failed to add car: " << q.lastError().text();
        return false;
    }
    return true;
}

//Check if car already exists in db based on its RegNr
bool CarAdded(QString RegNr)
{
    bool added;
    QSqlQuery q;
    q.prepare("Select EXISTS(SELECT RegNr FROM Cars WHERE RegNr = :RegNr)");
    q.addBindValue(RegNr);
    q.exec();
    while (q.next()) {
        added=q.value(0).toBool();
    }
    return added;
}

//edit added cars
bool EditCar(QString RegNr, QString Brand, QString Model, QString Color, int ModelYear)
{
    QSqlQuery q;

    // Check if the car exists
    q.prepare("SELECT EXISTS(SELECT RegNr FROM Cars WHERE RegNr = :RegNr)");
    q.bindValue(":RegNr", RegNr);
    q.exec();

    if (!q.next() || !q.value(0).toBool())
    {
        qDebug() << "Car not found";
        return false;
    }

    // The actual update
    q.prepare("UPDATE Cars SET Brand = :Brand, Model = :Model, Color = :Color, "
              "ModelYear = :ModelYear WHERE RegNr = :RegNr");
    q.bindValue(":Brand", Brand);
    q.bindValue(":Model", Model);
    q.bindValue(":Color", Color);
    q.bindValue(":ModelYear", ModelYear);
    q.bindValue(":RegNr", RegNr);

    if (!q.exec())
    {
        qDebug() << "Failed to update car" << q.lastError().text();
        return false;
    }

    return true;
}

//function to delete cars
bool  DeleteCar(QString RegNr)
{
    QSqlQuery q;
    q.prepare("Select EXISTS(SELECT RegNr FROM Cars WHERE RegNr = :RegNr)");
    q.bindValue(":RegNr", RegNr);
    q.exec();
    if(!q.next() || !q.value(0).toBool())
    {
        qDebug()<<"Car not found";
    }
    q.prepare("DELETE FROM Cars WHERE RegNr = :RegNr");
    q.bindValue(":RegNr", RegNr);
    if (!q.exec())
    {
        qDebug() << "Failed to delete car" << q.lastError().text();
        return false;
    }
    return true;
}

//search for cars based on availability and brand
bool searchCar(QString Brand)
{
    QSqlQuery q;

    q.prepare("SELECT * FROM Cars WHERE Brand = :Brand");
    q.bindValue(":Brand", Brand);

    q.exec();

    return q.next();
}






