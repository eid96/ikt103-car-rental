#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QDialog>

namespace Ui {
class Customers;
}

class Customers : public QDialog
{
    Q_OBJECT

public:
    explicit Customers(QWidget *parent = nullptr);
    ~Customers();

private slots:
    void on_LoadTable_clicked();

    void on_pushButton_clicked();

    void on_EditCustomer_clicked();

    void on_DeleteCustomer_clicked();

private:
    Ui::Customers *ui;
};

#endif // CUSTOMERS_H
