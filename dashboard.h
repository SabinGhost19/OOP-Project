#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include<QFrame>
#include<QPushButton>
#include"userClient.h"
#include"Product.h"
#include<QString>

namespace Ui {
class DashBoard;
}

class DashBoard : public QWidget
{
    Q_OBJECT

public:
    explicit DashBoard(QWidget *parent = nullptr,int userID=0);
    explicit DashBoard(int userID);
    ~DashBoard();

private slots:

     void on_signout_clicked();

     void on_signout_short_clicked();

     bool AddReview();

     void adaugareFramesToDashBrd();

     void SetStylePolicyforIcons();

     void on_cart_clicked();

     void on_dashboard_clicked();

     void on_dashboard_short_clicked();

    void on_cart_short_clicked();

     void ConstructProductView(int);

     void setUser(int ID);

     void ConstructCart();

     void  populareListaProduse();

     void FiltruSelectat(int index);

    void ProcesareFiltru(ProductCategory category);

     void on_slide_clicked();

    void on_offerts_clicked();

     void on_offerts_short_clicked();

     void ConstructForumPage();

     void ViewForumSection();

     void on_Buy_clicked();

     void AddPriceToCart(float);

     void AddProdusToCart(QString,QString);

     void on_Comanda_clicked();

     void on_NewPasswSUBMIT_clicked();

     void on_SchimbaParola_clicked();

     void on_cont_clicked();

     void on_AdaugaCard_clicked();

     void on_Add_Card_Button_clicked();

     void on_AdaugaBani_clicked();

     void UpdateImage(int index);

     void ViewForumPage(int index);

     void populareForumVector();


     void UpdateForum();


     void on_ForumButton_clicked();

 public slots:
    void ButtonClickedProdus();

private:
    QList<Product*>allProducts;
    QList<Product*>ShowProducts;
    std::vector<std::pair<std::string,std::string>>forum_list;

    Ui::DashBoard *ui;
    UserClient*user=nullptr;
    QList<QPushButton*> buttonList;
};

#endif // DASHBOARD_H

