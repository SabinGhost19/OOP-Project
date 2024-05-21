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
    void ConstructProducts();
    void  DeleteContent();


private slots:
    void on_AddNewProduct_clicked();
    void  SendNewPrice(std::string id);
    void  SendNewQuantity(std::string id);

    void on_Back_clicked();

private:
    Ui::CompanyWindow *ui;
};

#endif // COMPANYWINDOW_H
