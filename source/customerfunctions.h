#pragma once
#include <iostream>
#include <QtSql>

//connects to db
void DBConnect();

//Functions for custmers
void customerTable();
bool addCustomersDB(QString SosSecNr, QString FirstName, QString LastName, QString Email,
                    int PhoneNumber);
bool EditCustomers(QString SosSecNr, QString FirstName, QString LastName, QString Email, int PhoneNumber);
bool DeleteCust(QString SosSecNr);
//check if customer is added to db
bool CustomerAdded(QString SosSecNr);

//Search for customer, however used when renitng car

bool searchCustomer(int PhoneNumber);


//TEMP REMOVE WHEN CLEANING!
void PrintCustomers();
