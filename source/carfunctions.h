#pragma once
#include <iostream>
#include <QtSql>


void carTable();
bool addCars(QString RegNr, QString Brand, QString Model, QString Color, int ModelYear);
bool EditCar(QString RegNr, QString Brand, QString Model, QString Color, int ModelYear);
bool DeleteCar(QString RegNr);
bool searchCar(QString Brand);


//check if car is in db
bool CarAdded(QString RegNr);


