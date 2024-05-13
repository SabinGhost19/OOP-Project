#ifndef COMPANYWINDOW_H
#define COMPANYWINDOW_H

#include <QWidget>

namespace Ui {
class CompanyWindow;
}

class CompanyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CompanyWindow(QWidget *parent = nullptr);
    ~CompanyWindow();

private slots:
    void on_AddNewProduct_clicked();

private:
    Ui::CompanyWindow *ui;
};

#endif // COMPANYWINDOW_H
