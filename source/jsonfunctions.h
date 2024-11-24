#pragma once
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include <QJsonParseError>
#include <QSqlRecord>


//import
void CustFromJson(const QString& JFP);
void CarsFromJson(const QString& JFP);
void CarRentalFromJson(const QString& JFP);

//from db to json
void CustToJson(const QString& fp);
void CarsToJson(const QString& fp);
void CarRentalToJson(const QString& fp);
