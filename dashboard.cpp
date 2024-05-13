#include "dashboard.h"
#include "ui_dashboard.h"
#include <QtWidgets>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QVBoxLayout>
#include "mainwindow.h"
#include"APPClient.h"
#include"ProductBuilder.h"
#include"ImageRequest.h"
#include"DescriptionRequest.h"
#include"UserClientRequest.h"
#include"FactoryUser.h"
#include"CommentsRequest.h"
#include"Product.h"
#include<string>
#include"userClient.h"
int product=0;


DashBoard::DashBoard(QWidget *parent,int userID)
    : QWidget(parent)
    , ui(new Ui::DashBoard)
{
    ui->setupUi(this);

    //apel la server pentru construirea userului cu informatiile sale //client doar care cumpara
    this->setUser(userID);
    this->SetStylePolicyforIcons();
    //this->populareListaProduse();
    this->adaugareFramesToDashBrd();
    //this->ConstructCart();
    //this->ConstructForumPage();


    ui->stackedWidget->setCurrentIndex(0);
}

void DashBoard::ViewForumSection(){

    std::cout<<"VIEW FORUM SECTION"<<std::endl;
}

void DashBoard::ConstructForumPage(){


    QVBoxLayout *horizontalLayout = new QVBoxLayout(ui->scrollContents_5);
    ui->scrollArea_4->setWidgetResizable(true);
    ui->scrollArea_4->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //for(int i=0;i<CommentsRequest::getInstance()->Size();i++)
    for (int i = 0; i < 10; ++i) {

        QFrame *frame = new QFrame;
        frame->setFixedSize(831, 101);
        frame->setStyleSheet("background-color: #B0E0E6;");// Dimensiuni fixe pentru frame
        QVBoxLayout *frameLayout = new QVBoxLayout(frame);

        // Crearea label-ului în interiorul frame-ului
        QLabel *label = new QLabel(frame);
        label->setText("Descrierea sectiunii");
        label->setGeometry(10, 10, 681, 81); // Poziție și dimensiuni pentru label în interiorul frame-ului
        label->setFixedSize(681, 81); // Dimensiuni fixe pentru label
        label->setText("Label " + QString::number(i + 1));
        label->setStyleSheet("background-color: #98FB98; color: #FFFFF0;");
        frameLayout->addWidget(label);        // Textul label-ului

        // Crearea butonului în interiorul frame-ului
        QPushButton *button = new QPushButton(frame);
        button->setGeometry(710, 20, 91, 61); // Poziție și dimensiuni pentru buton în interiorul frame-ului
        button->setFixedSize(91, 61); // Dimensiuni fixe pentru buton
        connect(button, &QPushButton::clicked, this, &DashBoard::ViewForumSection);//!!!!!!!!!!
        button->setText("Button " + QString::number(i + 1)); // Textul butonului
        button->setStyleSheet("background-color: #32CD32; color: #FFFFFF;");
        frameLayout->addWidget(button);

        frame->setLayout(frameLayout);

        horizontalLayout->addWidget(label);
    }
}
void  DashBoard::populareListaProduse() {

    this->allProducts.clear();

    for(int i=0;i<10;i++){

        Product*new_product=new Product();
        //ImageRequest::getInstance()->Construct_Images();
        // new_product->setImage( ImageRequest::getInstance()->getImage());
        //new_product->setTitle(ImageRequest::getInstance()->getTtile());

        if(i%2==0){
            new_product->setCategory("Electronice");
             new_product->setTitle("VerifyElectronice");
        }else{
            new_product->setCategory("Cosmetice");
            new_product->setTitle("TitleCosmetice");
        }
        this->allProducts.append(new_product);
        this->ShowProducts.append(new_product);
    }
}



void DashBoard::ConstructCart(){


    ui->Nume->setText("NumeSabin");
    ui->Prenume->setText("STEFANNN");
    ui->BaniDisponibili->setText("Nu prea am");
    float price =this->user->getCommandPrice();
    QString text = QString::number(price);
    ui->TotalCosCumparaturi->setText(text);



    QGridLayout *gridLayout = new QGridLayout(ui->scrollContents_4);

    //for(int i=0;i<CommentsRequest::getInstance()->Size();i++)


    //if(this->user->GetProductCount()!=0){

   //  for (auto product : this->user->GetListaProduse()) {

   //      QFrame *frameProdus = new QFrame(ui->scrollArea_3);
   //      frameProdus->setFixedSize(570, 91); // Setează dimensiunea fixă a frame-ului produsului
   //      frameProdus->setStyleSheet("background-color: lightBlue;"); // Setează culoarea de fundal a frame-ului produsului


   //      QLabel *labelNumeProdus = new QLabel(product.first.c_str(), this);
   //      labelNumeProdus->setFixedSize(171, 61); // Setează dimensiunea fixă a labelului


   //      QLabel *labelPretProdus = new QLabel(product.second.c_str(), this);
   //      labelPretProdus->setFixedSize(171, 61); // Setează dimensiunea fixă a labelului


   //      QVBoxLayout *frameLayout = new QVBoxLayout;
   //      frameLayout->addWidget(labelNumeProdus);
   //      frameLayout->addWidget(labelPretProdus);
   //      frameProdus->setLayout(frameLayout);


   //      gridLayout->addWidget(frameProdus, i, 0);
   //      i++;
   // // }

}


void DashBoard::setUser(int ID){

    //FactoryUser*new_factory=new FactoryUser();
    //this->user=new_factory->ConstructClientUser(ID);
    this->user=new UserClient();
}
void DashBoard::ButtonClickedProdus(){

    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender()); // Află butonul apăsat

    if (clickedButton) {

        int index = buttonList.indexOf(clickedButton);

        if (index != -1) {

            emit ConstructProductView(index);
        } else {
            qDebug() << "Indexul butonului nu a fost găsit!";
        }
    }
}

void DashBoard::AddProdusToCart(QString title,QString price){

    //this->user->addProductToCart(title.toStdString(),price.toStdString());

    QFrame *frameProdus = new QFrame(ui->scrollArea_3);
    frameProdus->setFixedSize(570, 91); // Setează dimensiunea fixă a frame-ului produsului
    frameProdus->setStyleSheet("background-color: lightBlue;"); // Setează culoarea de fundal a frame-ului produsului


    QLabel *labelNumeProdus = new QLabel(title, this);
    labelNumeProdus->setFixedSize(171, 61); // Setează dimensiunea fixă a labelului


    QLabel *labelPretProdus = new QLabel(price, this);
    labelPretProdus->setFixedSize(171, 61); // Setează dimensiunea fixă a labelului


    QVBoxLayout *frameLayout = new QVBoxLayout;
    frameLayout->addWidget(labelNumeProdus);
    frameLayout->addWidget(labelPretProdus);
    frameProdus->setLayout(frameLayout);


    ui->scrollContents_4->layout()->addWidget(frameProdus);

    QObject::disconnect(ui->Buy, &QPushButton::clicked, nullptr, nullptr);

}

void DashBoard::AddPriceToCart(float price){

    this->user->AddToCart(price);
    ui->TotalCosCumparaturi->setText(QString::number(this->user->getCommandPrice()));
}
bool DashBoard::AddReview(){

    bool ok;
    QString text = QInputDialog::getText(this, "Introducere text", "Introdu un text:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        // Textul a fost introdus și butonul "OK" a fost apăsat
        // Acum poți face ceva cu textul introdus
        qDebug() << "Text introdus:" << text;
        //APPClient::getInstance()->user_client->SetComment(text.toStdString());

    } else {
        // Utilizatorul a apăsat butonul "Cancel" sau a închis fereastra
        qDebug() << "Utilizatorul a anulat introducerea textului.";
        return false;
    }


    bool ok2;
    QString text2 = QInputDialog::getText(this, "Introducere text", "Introdu un text:", QLineEdit::Normal, "", &ok);
    if (ok2 && !text.isEmpty()) {
        // Textul a fost introdus și butonul "OK" a fost apăsat
        // Acum poți face ceva cu textul introdus
        qDebug() << "Text introdus:" << text2;
        //APPClient::getInstance()->user_client->SetNota(text2.toStdString());

    } else {
        // Utilizatorul a apăsat butonul "Cancel" sau a închis fereastra
        qDebug() << "Utilizatorul a anulat introducerea textului.";
        return false;
    }


    return true;

}
void DashBoard::ConstructProductView(int index){


    std::cout<<std::endl<<std::endl<<"Indexul Produsului selectat: "<<index<<std::endl<<std::endl;

    std::vector<std::pair<std::string, std::string>>comments;
    std::string description;

    if(this->allProducts[index]->GetState()==0){

    //setare descriere
    std::cout<<this->allProducts[index]->GetProductID()<<std::endl;
    DescriptionRequest::getInstance()->SetIndex(this->allProducts[index]->GetProductID());
    description=DescriptionRequest::getInstance()->GetDescription();
    this->allProducts[index]->setDescription(description);

    //setare comments
    CommentsRequest::getInstance()->SetIndex(this->allProducts[index]->GetProductID());
    comments=CommentsRequest::getInstance()->GetComments();
    this->allProducts[index]->setComments(comments);


    //ImageRequest::getInstance()->Construct_MoreImages(index);
    //std::vector<QPixmap>new_img=ImageRequest::getInstance()->GetNewImages();
    //this->allProducts[index]->AddMoreImages(new_img);


    //this->allProducts[index]->ModifyState();

    }else{
        description=this->allProducts[index]->getDescription();
        //comments=this->allProducts[index]->getComments();
   }

    ui->scrollArea_3->setWidgetResizable(true);
    ui->scrollArea_3->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea_3->setGeometry(10, 60, 1011, 211);
    ui->scrollArea_3->setMinimumSize(1011, 211);
    ui->scrollArea_3->setContentsMargins(0, 0, 0, 0);

    QGridLayout *gridLayout = new QGridLayout(ui->scrollContent_3);

    std::cout<<std::endl<<std::endl<<"Comment Size : "<<static_cast<int>(comments.size())<<std::endl<<std::endl;

    for (int i = 0; i < static_cast<int>(comments.size()); ++i) {
   // for (int i = 0; i < 10; ++i) {
        QFrame *frame = new QFrame;
        frame->setFixedSize(911, 171);
        frame->setStyleSheet("background-color: white;");


        QLabel *titleLabel = new QLabel("Titlu");
        titleLabel->setFixedSize(161, 31);
        titleLabel->setStyleSheet("background-color: blue;");
        titleLabel->setText(comments[i].first.c_str());
        std::cout<<std::endl<<std::endl<<"First: "<<comments[i].first.c_str()<<std::endl<<std::endl;


        QLabel *descriptionLabel = new QLabel("Descriere");
        descriptionLabel->setFixedSize(881, 111);
        descriptionLabel->setStyleSheet("background-color: blue;");
        descriptionLabel->setText(comments[i].second.c_str());

        std::cout<<std::endl<<std::endl<<"Second: "<<comments[i].second.c_str()<<std::endl<<std::endl;

        QVBoxLayout *frameLayout = new QVBoxLayout;
        frameLayout->addWidget(titleLabel);
        frameLayout->addWidget(descriptionLabel);
        frame->setLayout(frameLayout);


        gridLayout->addWidget(frame, i, 0);
    }


    // ui->Buy->setFixedSize(201, 61);
    // ui->Buy->setMinimumSize(201, 61);
    // ui->Buy->move(440,20);

    // ui->lineEdit_2->setFixedSize(20, 41);
    // ui->lineEdit_2->setMinimumSize(201, 41);
    // ui->lineEdit_2->move(440,15);

    // ui->imageLabel->setFixedSize(401, 391);
    // ui->imageLabel->setMinimumSize(401, 391);
    // ui->imageLabel->move(10, 20);

    // ui->imageLabel->setStyleSheet("background-color: red;");



    // ui->titleLabel->setFixedSize(461, 71);
    // ui->titleLabel->setMinimumSize(461, 71);
    // ui->titleLabel->move(440, 30);
    // ui->titleLabel->setStyleSheet("background-color: white;");



    // ui->descriptionLabel->setFixedSize(461, 291);
    // ui->descriptionLabel->setMinimumSize(461, 291);
    // ui->descriptionLabel->move(440, 120);
    // ui->descriptionLabel->setStyleSheet("background-color: yellow;");


    // ui->Price->setFixedSize(161, 41);
    // ui->Price->setMinimumSize(161, 41);
    // ui->Price->move(10, 410);
    // ui->Price->setStyleSheet("background-color: blue;");
    // ui->Price->setText("10");



    ui->scrollArea_3->setWidget(ui->scrollContent_3);

    ui->imageLabel->setPixmap(this->allProducts[index]->GetNextImage());
    //ui->Price->setText(this->allProducts[index]->getPrice().c_str());


    ui->titleLabel->setText(this->allProducts[index]->getTitle().c_str());
    ui->stackedWidget->setCurrentIndex(3);
    ui->descriptionLabel->setText(this->allProducts[index]->getDescription().c_str());

    QObject::connect(ui->Buy, &QPushButton::clicked, [&]() {
        QString text = ui->Price->text();
        float price = text.toFloat();
        AddPriceToCart(price);
        AddProdusToCart(ui->titleLabel->text(),ui->Price->text());
    });


    QObject::connect(ui->AddReview, &QPushButton::clicked, [&]() {
        if(this->AddReview()){
            //CommentsRequest::getInstance()->SendComment(APPClient::getInstance()->user_client->GetComment()
            //,APPClient::getInstance()->user_client->GetNota());
        }
    });


    QObject::connect(ui->NextImage, &QPushButton::clicked, [&]() {
        ui->imageLabel->setPixmap(this->allProducts[index]->GetNextImage());
    });


}


void DashBoard::adaugareFramesToDashBrd(){


    // QGridLayout *gridLayout = qobject_cast<QGridLayout*>(ui->scrollContens->layout());

    // // Verifică dacă există un QGridLayout și are widget-uri adăugate
    // if (gridLayout && gridLayout->count() > 0) {
    //     // Golesc conținutul QGridLayout-ului
    //     QLayoutItem *child;
    //     while ((child = gridLayout->takeAt(0)) != nullptr) {
    //         delete child->widget();
    //         delete child;
    //     }
    // }


    QGridLayout *layout = new QGridLayout(ui->scrollContens);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //while(strcmp(ImageRequest::getInstance()->GetAnswer(),"end")!=0){}
    //!!!!!!!!!!!!?!??!???????????!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!
    //int vec_size= static_cast<int>(this->ShowProducts.size());
    //std::cout<<vec_size<<std::endl;

    int size =ImageRequest::getInstance()->FindSize();

    for (int i = 0; i <size; ++i){
    //for (int i = 0; i <10; ++i){
        //trebuie luata lungimea sau un semnal de oprire in imagerequest!!!!!!!!

        ImageRequest::getInstance()->Construct_Images();

        QFrame *frame = ProductBuilder::getInstance()->ProduceFrame();
        frame->setObjectName("myFrame");
        frame->setFixedSize(241, 241);
        frame->setMaximumSize(241, 241);
        frame->setStyleSheet("QFrame#myFrame { background-color: yellow; }"); // Setează culoarea de fundal
        QGridLayout *gridLayout = new QGridLayout(frame);
        frame->setLayout(gridLayout);
        // Creează label-ul cu pixmap

        QLabel *pixmapLabel = ProductBuilder::getInstance()->ProducePixmapLable(frame);




        Product*new_product=new Product();
        new_product->setPrice(ImageRequest::getInstance()->GetPrice());
        std::cout<<ImageRequest::getInstance()->GetID()<<std::endl;//bun
        new_product->setID(ImageRequest::getInstance()->GetID());










        // APPClient::getInstance()->getTcpClient()->send("2",2);
        // QPixmap pixmap=APPClient::getInstance()->getTcpClient()->receiveImage();
        // QFrame *frame = new QFrame;
        // frame->setObjectName("myFrame");
        // frame->setFixedSize(241, 241);
        // frame->setMaximumSize(241, 241);
        // frame->setStyleSheet("QFrame#myFrame { background-color: yellow; }"); // Setează culoarea de fundal
        // QGridLayout *gridLayout = new QGridLayout(frame);
        // frame->setLayout(gridLayout);
        // // Creează label-ul cu pixmap

        // QLabel *pixmapLabel = new QLabel(frame);
        // pixmapLabel->setPixmap(pixmap);
        // pixmapLabel->setScaledContents(true);        // Setează imaginea
        // pixmapLabel->setFixedSize(221, 191);
        // pixmapLabel->setMaximumSize(221, 191);
        // pixmapLabel->setGeometry(9, 9, 221, 191);
        // gridLayout->addWidget(pixmapLabel, 0, 0);

        // // Creează cele două label-uri suplimentare
        // QLabel *label1 = new QLabel("Label 1", frame);
        // label1->setFixedSize(121, 31);
        // label1->setMinimumSize(121, 31);
        // label1->setStyleSheet("QLabel { color: green; }"); // Setează culoarea textului verde
        // //gridLayout->addWidget(label1, 0, 0); // Adaugă label1 pe prima poziție a grid-ului
        // label1->setGeometry(9, 201, 121, 31); // Setează coordonatele
        // gridLayout->addWidget(label1, 1, 0);

        // QPushButton *button = new QPushButton("Button", frame);
        // button->setFixedSize(101, 31);
        // button->setMinimumSize(101, 31);
        // button->setStyleSheet("QPushButton { color: blue; border: none; background-color: transparent; }" // Setează culoarea textului albastru și elimină stilurile butonului
        //                       "QPushButton:hover { background-color: #e0e0e0; }" // Adaugă un efect de hover pentru buton
        //                       "QPushButton:pressed { background-color: #c0c0c0; }"); // Adaugă un efect pentru când butonul este apăsat
        // gridLayout->addWidget(button, 1, 1);


        // layout->addWidget(frame, i / 3, i % 3);







































        QPixmap pixmap=APPClient::getInstance()->getTcpClient()->receiveImage();
        new_product->setImage(pixmap);
        pixmapLabel->setPixmap(pixmap);
        pixmapLabel->setScaledContents(true);
        pixmapLabel->setFixedSize(221, 191);
        pixmapLabel->setMaximumSize(221, 191);
        pixmapLabel->setGeometry(9, 9, 221, 191);
        gridLayout->addWidget(pixmapLabel, 0, 0);



        QLabel *label1 = ProductBuilder::getInstance()->ProduceTitle(frame);
        label1->setFixedSize(121, 31);
        label1->setMinimumSize(121, 31);
        label1->setText(ImageRequest::getInstance()->getTtile().c_str());//--!!!!!!!!!!!!!!!
        label1->setText(ImageRequest::getInstance()->getTtile().c_str());
        new_product->setTitle(ImageRequest::getInstance()->getTtile());
        label1->setStyleSheet("QLabel { color: green; }");
        gridLayout->addWidget(label1, 0, 0);
        label1->setGeometry(9, 201, 121, 31);
        gridLayout->addWidget(label1, 1, 0);

        QPushButton *button = ProductBuilder::getInstance()->ProduceButton(frame);
        gridLayout->addWidget(button, 1, 1);
        this->buttonList.append(button);
        connect(button, &QPushButton::clicked, this, &DashBoard::ButtonClickedProdus);
        layout->addWidget(frame, i / 3, i % 3);
        this->allProducts.push_back(new_product);

    }

    ui->scrollArea->setWidget(ui->scrollContens);

}
void DashBoard::ProcesareFiltru(ProductCategory category){

    this->ShowProducts.clear();
    if(category==ProductCategory::ALL){
        for(auto product :this->allProducts){
            this->ShowProducts.append(product);
        }
    }else{
        for(auto product :this->allProducts){
            if(product->getCategory()==category){
                this->ShowProducts.append(product);
            }
        }
    }
    adaugareFramesToDashBrd();
}
void  DashBoard::FiltruSelectat(int index){

    int parametru = ui->comboBox->itemData(index).toInt(); // Obținem parametrul asociat butonului

    // Apelăm funcția corespunzătoare butonului cu parametrul specific
    switch (parametru) {
    case 1:
        ProcesareFiltru(ProductCategory::ALL);
        break;
    case 2:
        ProcesareFiltru(ProductCategory::ELECTRONICS);
        break;
    case 3:
        ProcesareFiltru(ProductCategory::BEAUTY);
        break;
    default:
        break;
    }
}


void DashBoard::SetStylePolicyforIcons(){




    // ComboBox cu butoane

    ui->comboBox->addItem("ALL", QVariant::fromValue(1)); // Parametrul 1 pentru funcția asociată butonului 1
    ui->comboBox->addItem("Electronice", QVariant::fromValue(2)); // Parametrul 2 pentru funcția asociată butonului 2
    ui->comboBox->addItem("Beauty", QVariant::fromValue(3)); // Parametrul 3 pentru funcția asociată butonului 3


    // Conectarea semnalului de schimbare a elementului din ComboBox cu funcția care gestionează apăsarea butoanelor
    connect( ui->comboBox, QOverload<int>::of(&QComboBox::activated),
            this, &DashBoard::FiltruSelectat);




    ui->widget_2->hide();
    QIcon cart(":/img/img/cart_w.png");
    QIcon profile(":/img/img/profile_w.png");
    QIcon notifications(":/img/img/notifications_w.png");
    QIcon dashboard(":/img/img/dashboard_w.png");
    QIcon offerts(":/img/img/offert_w.png");
    QIcon signout(":/img/img/signout_w.png");
    QIcon slide(":/img/img/slide.png");
    QIcon search(":/img/img/search.png");

    ui->cart->setIcon(QIcon(":/img/img/cart_w.png"));
    connect(ui->cart, &QPushButton::toggled, this, [=](bool checked) {
        if (checked) {
            // Setăm pictograma când butonul este verificat
            ui->cart->setIcon(QIcon(":/img/img/cart.png"));
        }else{
            ui->cart->setIcon(QIcon(":/img/img/cart_w.png"));
        }
    });



    ui->cart_short->setIcon(QIcon(":/img/img/cart_w.png"));
    connect(ui->cart_short, &QPushButton::toggled, this, [=](bool checked) {
        if (checked) {
            // Setăm pictograma când butonul este verificat
            ui->cart_short->setIcon(QIcon(":/img/img/cart.png"));
        }else{
            ui->cart_short->setIcon(QIcon(":/img/img/cart_w.png"));
        }
    });

    ui->dashboard->setIcon(QIcon(":/img/img/dashboard_w.png"));
    connect(ui->dashboard, &QPushButton::toggled, this, [=](bool checked) {
        if (checked) {
            // Setăm pictograma când butonul este verificat
            ui->dashboard->setIcon(QIcon(":/img/img/dashboard.png"));
        }else{
            ui->dashboard->setIcon(QIcon(":/img/img/dashboard_w.png"));
        }
    });

    ui->dashboard_short->setIcon(QIcon(":/img/img/dashboard_w.png"));
    connect(ui->dashboard_short, &QPushButton::toggled, this, [=](bool checked) {
        if (checked) {
            // Setăm pictograma când butonul este verificat
            ui->dashboard_short->setIcon(QIcon(":/img/img/dashboard.png"));
        }else{
            ui->dashboard_short->setIcon(QIcon(":/img/img/dashboard_w.png"));
        }
    });


    ui->profile->setIcon(profile);
    ui->profile_short->setIcon(profile);



    ui->notifications_short->setIcon(notifications);
    ui->notifications->setIcon(notifications);

    ui->signout->setIcon(signout);
    ui->signout_short->setIcon(signout);

    ui->offerts->setIcon(offerts);
    ui->offerts_short->setIcon(offerts);

    QSize iconSize(70, 50);

    ui->cart->setIconSize(iconSize);
    ui->cart->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->profile->setIconSize(iconSize);
    ui->profile->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->dashboard->setIconSize(iconSize);
    ui->dashboard->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->notifications->setIconSize(iconSize);
    ui->notifications->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->signout->setIconSize(iconSize);
    ui->signout->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->offerts->setIconSize(iconSize);
    ui->offerts->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    //----------------------------

    ui->cart_short->setIconSize(iconSize);
    ui->cart_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->profile_short->setIconSize(iconSize);
    ui->profile_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->dashboard_short->setIconSize(iconSize);
    ui->dashboard_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->notifications_short->setIconSize(iconSize);
    ui->notifications_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->signout_short->setIconSize(iconSize);
    ui->signout_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->offerts_short->setIconSize(iconSize);
    ui->offerts_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QSize iconSizeSlide(40, 40);
    ui->slide->setIcon(slide);
    ui->slide->setIconSize(iconSizeSlide);
    ui->slide->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);


    ui->search->setIcon(search);
    ui->search->setIconSize(iconSizeSlide);
    ui->search->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);


}
DashBoard::~DashBoard()
{
    delete ui;
}


//void DashBoard::on_pushButton_clicked(){}

void DashBoard::on_slide_clicked()
{

    if(ui->widget->isHidden()){
        ui->widget->show();
        ui->widget_2->hide();
    }else{
        ui->widget->hide();
        ui->widget_2->show();
    }
}


void DashBoard::on_signout_clicked()
{
    this->close();
    MainWindow *main=new MainWindow();
    main->show();
}


void DashBoard::on_signout_short_clicked()
{
    this->close();
    MainWindow *main=new MainWindow();
    main->show();
}




void DashBoard::on_cart_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void DashBoard::on_dashboard_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void DashBoard::on_dashboard_short_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void DashBoard::on_cart_short_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void DashBoard::on_offerts_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void DashBoard::on_offerts_short_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void DashBoard::on_Buy_clicked()
{

}

