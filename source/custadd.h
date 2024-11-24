#ifndef CUSTADD_H
#define CUSTADD_H

#include <QDialog>

namespace Ui {
class CustAdd;
}

class CustAdd : public QDialog
{
    Q_OBJECT

public:
    explicit CustAdd(QWidget *parent = nullptr);
    ~CustAdd();

private slots:
    void on_AddCust_clicked();

private:
    Ui::CustAdd *ui;
};

#endif // CUSTADD_H
