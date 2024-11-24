#ifndef CUSTUPDDEL_H
#define CUSTUPDDEL_H

#include <QDialog>

namespace Ui {
class CustUpdDel;
}

class CustUpdDel : public QDialog
{
    Q_OBJECT

public:
    explicit CustUpdDel(QWidget *parent = nullptr);
    ~CustUpdDel();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::CustUpdDel *ui;
};

#endif // CUSTUPDDEL_H
