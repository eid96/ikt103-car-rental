#include "custupddel.h"
#include "ui_custupddel.h"
#include "customerfunctions.h"

CustUpdDel::CustUpdDel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustUpdDel)
{
    ui->setupUi(this);
}

CustUpdDel::~CustUpdDel()
{
    delete ui;
}

void CustUpdDel::on_tableView_clicked(const QModelIndex &index)
{

    //creates model for data
    QSqlQueryModel *mod = new QSqlQueryModel(this);
    QSqlQuery q;
    q.prepare("SELECT * FROM Customers");
    if (!q.exec()) {
        qDebug() << "Query in on_tableView error:" << q.lastError().text();
        return;
    }

    mod-> setQuery("SELECT * FROM Customers");
    qDebug("Shows customers");
    if (mod->lastError().isValid()) {
        qDebug() << "Query error:" << mod->lastError().text();
    }

    ui->tableView->setModel(mod);
    ui->tableView->viewport()->update();
}

