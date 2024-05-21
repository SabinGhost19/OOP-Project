#include "companywindow.h"
#include "ui_companywindow.h"
#include"addProduct.h"
#include"ImageRequest.h"
#include"ProductBuilder.h"
#include <QtWidgets>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QVBoxLayout>
#include "mainwindow.h"

CompanyWindow::CompanyWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CompanyWindow)
{
    ui->setupUi(this);
    ConstructProducts();
}

CompanyWindow::~CompanyWindow()
{
    this->DeleteContent();
    delete ui;
}
void  CompanyWindow::SendNewPrice(std::string id)
{
    bool ok;
    QString text = QInputDialog::getText(this, "Introducere text", "Introdu noul pret:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        // Textul a fost introdus și butonul "OK" a fost apăsat
        // Acum poți face ceva cu textul introdus
        qDebug() << "Text introdus:" << text;

        ImageRequest::getInstance()->message="11";
        ImageRequest::getInstance()->Request();


        ImageRequest::getInstance()->message=id;
        ImageRequest::getInstance()->Request();

        ImageRequest::getInstance()->message=text.toStdString();
        ImageRequest::getInstance()->Request();



    } else {
        // Utilizatorul a apăsat butonul "Cancel" sau a închis fereastra
        qDebug() << "Utilizatorul a anulat introducerea textului.";

    }


}
void  CompanyWindow::SendNewQuantity(std::string id){

    bool ok;
    QString text = QInputDialog::getText(this, "Introducere text", "Introdu noul pret:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        // Textul a fost introdus și butonul "OK" a fost apăsat
        // Acum poți face ceva cu textul introdus
        qDebug() << "Text introdus:" << text;

        ImageRequest::getInstance()->message="12";
        ImageRequest::getInstance()->Request();


        ImageRequest::getInstance()->message=id;
        ImageRequest::getInstance()->Request();

        ImageRequest::getInstance()->message=text.toStdString();
        ImageRequest::getInstance()->Request();



    } else {
        // Utilizatorul a apăsat butonul "Cancel" sau a închis fereastra
        qDebug() << "Utilizatorul a anulat introducerea textului.";

    }


}
void  CompanyWindow::ConstructProducts(){



    QGridLayout *layout = new QGridLayout(ui->scrollAreaContents);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    ImageRequest::getInstance()->message="15";
    ImageRequest::getInstance()->Request();
    int size_l =ImageRequest::getInstance()->FindSize();

    QString strNumber = QString::number(size_l);
    ui->NrProduseListate->setText(strNumber.toStdString().c_str());
    ui->NumeCompanie->setText(APPClient::getInstance()->user_company->getNume().c_str());
    ui->profit->setText(APPClient::getInstance()->user_company->getPorfit().c_str());

    for (int i = 0; i <size_l; i++){

        ImageRequest::getInstance()->Construct_Images();


        std::cout<< ImageRequest::getInstance()->getTtile()<<std::endl;
        std::cout<< ImageRequest::getInstance()->GetPrice()<<std::endl;
        std::cout<<ImageRequest::getInstance()->GetID()<<std::endl;


        QFrame *frame = new QFrame;
        frame->setFixedSize(681, 311);
        frame->setStyleSheet("QFrame#myFrame { background-color: yellow; }");



        QPixmap pixmap=APPClient::getInstance()->getTcpClient()->receiveImage();
        // Creare etichetă imagine

        QLabel *imageLabel = new QLabel(frame);
        imageLabel->setScaledContents(true);
        imageLabel->setGeometry(310, 10, 361, 291);
        imageLabel->setPixmap(pixmap);



        ImageRequest::getInstance()->Answer();
        APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
        QString str = QString::fromUtf8(ImageRequest::getInstance()->answer);
        std::string cantitate=str.toStdString();
        std::cout<<cantitate<<std::endl;


        // Creare etichetă nume titlu
        QLabel *titleLabel = new QLabel("Denumirea :", frame);
        titleLabel->setGeometry(20, 20, 131, 51);

        // Creare etichetă titlu
        QLabel *nameLabel = new QLabel(ImageRequest::getInstance()->getTtile().c_str(), frame);
        nameLabel->setGeometry(160, 20, 131, 51);

        // Creare etichetă nume descriere
        QLabel *descriptionNameLabel = new QLabel("Cantitatea: ", frame);
        descriptionNameLabel->setGeometry(20, 80, 131, 51);

        // Creare etichetă descriere
        QLabel *descriptionLabel = new QLabel(cantitate.c_str(), frame);
        descriptionLabel->setGeometry(160, 80, 131, 51);

        // Creare etichetă nume preț
        QLabel *priceNameLabel = new QLabel("Pretul: ", frame);
        priceNameLabel->setGeometry(20, 140, 131, 51);

        // Creare etichetă preț
        QLabel *priceLabel = new QLabel(ImageRequest::getInstance()->GetPrice().c_str(), frame);
        priceLabel->setGeometry(160, 140, 131, 51);






        // Creare buton 1
        QPushButton *button1 = new QPushButton("New Price", frame);
        button1->setGeometry(10, 240, 131, 51);

        // Creare buton 2
        QPushButton *button2 = new QPushButton("New Quantity", frame);
        button2->setGeometry(160, 240, 131, 51);

        std::string id = ImageRequest::getInstance()->GetID();
        connect(button1, &QPushButton::clicked, this, std::bind(&CompanyWindow::SendNewPrice, this, id));
        connect(button2, &QPushButton::clicked, this, std::bind(&CompanyWindow::SendNewQuantity, this, id));


        layout->addWidget(frame, i / 1, i % 1);


    }

    ui->scrollArea->setWidget(ui->scrollAreaContents);

}

void CompanyWindow:: DeleteContent(){

    QLayout *layout = ui->scrollAreaContents->layout();
    if (layout) {
        // Șterge toate widget-urile și layout-urile din grid
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != nullptr) {
            // Verifică dacă item-ul este un widget sau un alt layout
            if (child->widget()) {
                // Dacă este un widget, șterge-l
                delete child->widget();
            } else if (child->layout()) {
                // Dacă este un alt layout, șterge recursiv widget-urile și layout-urile sale
                QLayout *childLayout = child->layout();
                QLayoutItem *childItem;
                while ((childItem = childLayout->takeAt(0)) != nullptr) {
                    if (childItem->widget()) {
                        delete childItem->widget();
                    }
                    delete childItem;
                }
                // Șterge layout-ul copil
                delete childLayout;
            }
            // Șterge item-ul din layout-ul principal
            delete child;
        }
        // Setează layout-ul la nullptr pentru a elibera memoria
        delete layout;
        ui->scrollAreaContents->setLayout(nullptr);
    }
}
void CompanyWindow::on_AddNewProduct_clicked()
{
    this->close();
    AddProduct*new_add_window=new AddProduct();
    new_add_window->show();
}


void CompanyWindow::on_Back_clicked()
{
    this->close();
    MainWindow*m=new MainWindow();
    m->show();
}

