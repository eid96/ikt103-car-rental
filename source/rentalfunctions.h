#pragma once
#include <iostream>
#include <QtSql>

void rentalDB();

bool assignCar(
    QString SoSecNr, QString LastName, int PhoneNumber, QString RegNr,
                              QString StartDate,
                              QString ReturnDate,
                              bool ValLicense);



void searchRentedCar();

bool UnassignCar(QString SoSecNr);


/*
QString SoSecNr, QString LastName, int PhoneNumber, QString RegNr,
QString StartDate,
QString ReturnDate,
bool ValLicense, */
