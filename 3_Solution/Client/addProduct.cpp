#include "addProduct.h"
#include "ui_addproduct.h"
#include <QFileDialog>
#include <QPixmap>
#include <QByteArray>
#include <QVBoxLayout>
#include <QBuffer>
#include "CompanyAddRequest.h"
#include"companywindow.h"

AddProduct::AddProduct(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddProduct)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(ui->Pathframe);
    ui->Pathframe->setLayout(layout);

    ui->comboBox->setStyleSheet(
        "QComboBox {"
        "   border: 1px solid #ccc;"
        "   border-radius: 15px;"  // Marginile rotunjite
        "   padding: 10px 20px;"   // Spatierea interioară
        "   font-family: Arial, sans-serif;"
        "   font-size: 14px;"
        "   color: #333;"
        "   background-color: #f5f5f5;" // Culoarea fundalului
        "}"
        "QComboBox::down-arrow {"
        "   width: 10px;" // Dimensiunea săgeții în jos
        "   height: 10px;"
        "   image: url(:/down_arrow.png);" // Imaginea săgeții în jos
        "   subcontrol-origin: padding;"
        "   subcontrol-position: center right;" // Poziționarea săgeții
        "   padding-right: 10px;" // Spațiul pentru săgeată
        "   color: #0078d7;" // Culoarea săgeții
        "}"
        "QComboBox::drop-down {"
        "   border: none;" // Eliminarea conturului săgeții
        "   background-color: transparent;" // Fondul transparent
        "}"
        "QComboBox::hover {"
        "   background-color: #0078d7;" // Fondul când cursorul este deasupra
        "   color: #f5f5f5;" // Textul când cursorul este deasupra
        "}"
        "QListView {"
        "   border: 1px solid #ccc;"
        "   border-radius: 15px;" // Marginile rotunjite
        "   background-color: #f5f5f5;" // Culoarea fundalului listei derulante
        "   font-family: Arial, sans-serif;"
        "   font-size: 14px;"
        "   color: #333;"
        "}"
        "QListView::item {"
        "   padding: 10px 20px;" // Spatierea între elemente
        "}"
        "QListView::item:selected {"
        "   background-color: #0078d7;" // Culoarea de fundal pentru elementul selectat
        "   color: #f5f5f5;" // Textul pentru elementul selectat
        "}"
        );

    ui->comboBox->addItem("ELECTRONICS");
    ui->comboBox->addItem("CLOTHING");
    ui->comboBox->addItem("BOOKS");
    ui->comboBox->addItem("BEAUTY");
    ui->comboBox->addItem("FOOD");
    ui->comboBox->addItem("SPORTS");

    QObject::connect(ui->AddImage, &QPushButton::clicked, [=]() {

        QString imagePath = QFileDialog::getOpenFileName(this, "Selectează imagine", "", "Imagini (*.png *.jpg *.jpeg)");
        QPixmap image(imagePath);

        if (!imagePath.isEmpty()) {
            AddVisiblePath(imagePath);
            this->pathList.append(imagePath.toStdString());
        }
    });

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        // Obține textul butonului selectat
        QString category = ui->comboBox->itemText(index);
        std::cout<<std::endl<<std::endl<<"CATETGORY SELECTED:"<<category.toStdString()<<std::endl<<std::endl;
        std::cout<<std::endl<<std::endl<<"CATETGORY SELECTED IMDEX:"<<index<<std::endl<<std::endl;
        this->category=category.toStdString();
        // Returnează indexul butonului selectat și categoria corespunzătoare
        qDebug() << "Index:" << index << "Categorie:" << category;
    });


}


AddProduct::~AddProduct()
{
    delete ui;
}
void AddProduct::AddVisiblePath(QString path){

    QLabel *pathLabel = new QLabel(path);
    ui->Pathframe->layout()->addWidget(pathLabel);
}

void AddProduct::on_AddImage_clicked()
{

}

void AddProduct::on_Submit_clicked()
{
    std::string title=ui->lineEditTitle->text().toStdString();
    std::string description=ui->lineEditDescription->text().toStdString();
    std::string price=ui->lineEditPrice->text().toStdString();
    std::string cantitate=ui->lineEditQuantity->text().toStdString();
    std::string type="Laptopuri";
    std::string id="3";
    int size=static_cast<int>(this->pathList.size());
    std::stringstream ss;
    ss << size;
    std::string size_str = ss.str();
    CompanyAddRequest*new_req=new CompanyAddRequest();
    new_req->sendText(id);
    new_req->sendText(title);
    new_req->sendText(this->category);
    new_req->sendText(description);
    new_req->sendText(price);
    new_req->sendText(cantitate);
    new_req->sendText(size_str);

    for(auto path: this->pathList){
        new_req->sendImage(path);
    }



}


void AddProduct::on_Back_clicked()
{
    this->close();
    CompanyWindow*new_compW=new CompanyWindow();
    new_compW->show();
}

