#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QWidget>
#include<QString>
#include <QList>
#include <QByteArray>

namespace Ui {
class AddProduct;
}

class AddProduct : public QWidget
{
    Q_OBJECT

public:
    explicit AddProduct(QWidget *parent = nullptr);
    ~AddProduct();

private slots:

    void on_AddImage_clicked();
    void AddVisiblePath(QString);

    void on_Submit_clicked();

    void on_Back_clicked();

private:
    std::string category;
    Ui::AddProduct *ui;
    QList<std::string> pathList;
};

#endif // ADDPRODUCT_H
