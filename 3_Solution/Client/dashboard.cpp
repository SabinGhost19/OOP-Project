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
#include"Cartrequest.h"
#include"passwordchangerequest.h"
#include"CardRequest.h"
#include"MoneyAddRequest.h"
#include"Forumrequest.h"

int product_index=0;
int category=0;


DashBoard::DashBoard(QWidget *parent,int userID)
    : QWidget(parent)
    , ui(new Ui::DashBoard)
{
    ui->setupUi(this);
     ui->ForumButton->hide();
    //apel la server pentru construirea userului cu informatiile sale //client doar care cumpara
    this->setUser(userID);
    this->populareForumVector();
    this->SetStylePolicyforIcons();
    //this->populareListaProduse();
    this->adaugareFramesToDashBrd();
    this->ConstructCart();
    this->ConstructForumPage();


    ui->stackedWidget->setCurrentIndex(0);
}
void DashBoard::populareForumVector(){
    std::pair<std::string, std::string> pairO("Periferice", "Mouse, Tastaturi, Imprimante, Multifunctionale, Copiatoare, Consumabile, Camere web, Scannere, Memorii externe, Rack-uri, Hard disk-uri externe, Multimedia, UPS etc.");
    this->forum_list.push_back(pairO);


    std::pair<std::string, std::string> pair3("Comunicatii", "Smartphone-uri, telefoane mobile, accesorii, software mobile");
    this->forum_list.push_back(pair3);

    std::pair<std::string, std::string> pair4("Componente", "Placi de baza, Procesoare, Placi video, Hard disk-uri, SSD-uri, Memorii, Placi de sunet, Surse, Carcase etc.");
    this->forum_list.push_back(pair4);

    std::pair<std::string, std::string> pair5("Gaming", "Lumea jocurilor video. Keep calm and game on.");
    this->forum_list.push_back(pair5);

    std::pair<std::string, std::string> pair6("Software", "You name it.");
    this->forum_list.push_back(pair6);

    std::pair<std::string, std::string> pair7("Retelistiaca", "Routere wireless, Routere wired, Switch-uri, Placi de retea, Placi de retea wireless, Access point-uri, Adaptoare wireless, Antene, Firewall, Print servere, Accesorii retea, Cabinete metalice etc.");
    this->forum_list.push_back(pair7);

    std::pair<std::string, std::string> pair8("Electrocasnice", "Mici sau mari, pentru tine sau pentru toata familia.");
    this->forum_list.push_back(pair8);

    std::pair<std::string, std::string> pair9("Intrebari/Opinii/Sugestii", "Daca iti doresti un produs sau un nou serviciu de la PC Garage, daca ai o nelamurire, sau doar doresti sa ne transmiti ceva, parerile tale sunt asteptate.");
    this->forum_list.push_back(pair9);

    std::pair<std::string, std::string> pair10("Fun", "Orice ne poate descreti fruntile");
    this->forum_list.push_back(pair10);



}
void DashBoard::ViewForumSection(){

    std::cout<<"VIEW FORUM SECTION"<<std::endl;
}

void DashBoard::UpdateForum(){

    QLayout *layout = ui->scrollContents_5->layout();
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
        ui->scrollContents_5->setLayout(nullptr);
    }
}
void DashBoard::ViewForumPage(int index){

    this->UpdateForum();

    ForumRequest forumR;
    forumR.setIndex(index+1);
    category=index+1;
    std::vector<std::pair<std::string, std::string>>page=forumR.RequestForumPage();

    QGridLayout *horizontalLayout = new QGridLayout(ui->scrollContents_5);
    ui->scrollArea_4->setWidgetResizable(true);
    ui->scrollArea_4->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    for(int i=0;i<static_cast<int>(page.size());i++){

        QFrame *frame = new QFrame;


        QVBoxLayout *layout = new QVBoxLayout;


        frame->setFixedHeight(271);
        frame->setFixedWidth(800); // Setează lățimea fixă pentru frame
        frame->setStyleSheet("background-color: white; border-radius: 10px;");


        QLabel *label1 = new QLabel;
        label1->setMaximumSize(251, 71);
        label1->setGeometry(10, 10, 251, 71);
        label1->setStyleSheet("background-color: #FFCDD2; border-radius: 10px;"); // Culoare roșie deschisă
        label1->setText(page[i].first.c_str());

        QLabel *label2 = new QLabel;
        label2->setMaximumHeight(371);
        label2->setGeometry(10, 87, 251, 200);
        label2->setStyleSheet("background-color: #BBDEFB; border-radius: 10px;");
        label2->setText("category");



        QTextEdit *textEdit3 = new QTextEdit;
        textEdit3->setMaximumHeight(371);
        textEdit3->setGeometry(10, 164, 251, 371);
        textEdit3->setStyleSheet("background-color: #C8E6C9; border-radius: 10px;"); // Culoare verde deschis
        textEdit3->setText(page[i].second.c_str());
        textEdit3->setReadOnly(true); // Setează textul ca fiind doar pentru citire, similar cu un QLabel


        layout->addWidget(label1);
        layout->addWidget(label2);
        layout->addWidget(textEdit3);


        frame->setLayout(layout);

        horizontalLayout->addWidget(frame);


    }

}


void DashBoard::ConstructForumPage(){

    this->UpdateForum();

    QGridLayout *horizontalLayout = new QGridLayout(ui->scrollContents_5);
    ui->scrollArea_4->setWidgetResizable(true);
    ui->scrollArea_4->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //for(int i=0;i<CommentsRequest::getInstance()->Size();i++)
    for (int i = 0; i < 9; ++i) {

        // QFrame *frame = new QFrame;
        // frame->setFixedSize(831, 101);
        // frame->setStyleSheet("background-color: #B0E0E6;");// Dimensiuni fixe pentru frame
        // QVBoxLayout *frameLayout = new QVBoxLayout(frame);

        // // Crearea label-ului în interiorul frame-ului
        // QLabel *label = new QLabel(frame);
        // label->setText("Descrierea sectiunii");
        // label->setGeometry(10, 10, 681, 81); // Poziție și dimensiuni pentru label în interiorul frame-ului
        // label->setFixedSize(681, 81); // Dimensiuni fixe pentru label
        // label->setText("Label " + QString::number(i + 1));
        // label->setStyleSheet("background-color: #98FB98; color: #FFFFF0;");
        // frameLayout->addWidget(label);        // Textul label-ului

        // // Crearea butonului în interiorul frame-ului
        // QPushButton *button = new QPushButton(frame);
        // button->setGeometry(710, 20, 91, 61); // Poziție și dimensiuni pentru buton în interiorul frame-ului
        // button->setFixedSize(91, 61); // Dimensiuni fixe pentru buton
        // connect(button, &QPushButton::clicked, this, &DashBoard::ViewForumSection);//!!!!!!!!!!
        // button->setText("Button " + QString::number(i + 1)); // Textul butonului
        // button->setStyleSheet("background-color: #32CD32; color: #FFFFFF;");
        // frameLayout->addWidget(button);


        QFrame *frame = new QFrame;

        // Creează layout-ul vertical
        QVBoxLayout *layout = new QVBoxLayout;

        // Setează dimensiunea frame-ului
        frame->setFixedHeight(300);
        frame->setFixedWidth(831); // Setează lățimea fixă pentru frame
        frame->setStyleSheet("background-color: white; border-radius: 10px;");

        // Creează primul QLabel cu dimensiuni maxime și culoare de fundal diferită
         QFrame *f = new QFrame;
        f->setFixedHeight(72);
        f->setFixedWidth(280); // Setează lățimea fixă pentru frame
        f->setStyleSheet("background-color: white; border-radius: 10px;");
         QHBoxLayout *l = new QHBoxLayout;


        QLabel *label1 = new QLabel;
        label1->setMaximumSize(251, 71);
        label1->setGeometry(10, 10, 251, 71);
        label1->setStyleSheet("background-color: #FFCDD2; border-radius: 10px;"); // Culoare roșie deschisă
        label1->setText(this->forum_list[i].first.c_str());

        // Creează al doilea QLabel cu dimensiunea maximă și culoare de fundal diferită

        QTextEdit *textEdit2 = new QTextEdit;
        textEdit2->setMaximumHeight(371);
        textEdit2->setGeometry(10, 87, 251, 371);
        textEdit2->setStyleSheet("background-color: #BBDEFB; border-radius: 10px;"); // Culoare albastru deschis
        textEdit2->setText(this->forum_list[i].second.c_str());
        textEdit2->setReadOnly(true); // Setează textul ca fiind doar pentru citire


        QPushButton *button = new QPushButton("View");
        // button->setFixedSize(50, 71);
        // button->setGeometry(30,10,50,71);

        button->setStyleSheet("background-color: #E0E0E0; border-radius: 10px;");


        QObject::connect(button, &QPushButton::clicked, this, std::bind(&DashBoard::ViewForumPage, this, i));




        l->addWidget(label1);
        l->addWidget(button);
        f->setLayout(l);        // Culoare gri deschisă
        // Creează al treilea QLabel cu dimensiunea maximă și culoare de fundal diferită
        // QLabel *label3 = new QLabel;
        // label3->setMaximumHeight(371);
        // label3->setGeometry(10, 164, 251, 371);
        // label3->setStyleSheet("background-color: #C8E6C9; border-radius: 10px;"); // Culoare verde deschis

        // Adaugă label-urile la layout-ul vertical
        layout->addWidget(f);
        layout->addWidget(textEdit2);

        //layout->addWidget(label3);

        // Setează layout-ul vertical pentru frame
        frame->setLayout(layout);

        horizontalLayout->addWidget(frame);


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


    ui->Nume->setText(APPClient::getInstance()->user_client->getNume().c_str());
    ui->Prenume->setText(APPClient::getInstance()->user_client->getPrenume().c_str());
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

    QFrame *frameProdus = new QFrame(ui->scrollArea_2);
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


    APPClient::getInstance()->user_client->AddToCart(price);
    ui->TotalCosCumparaturi->setText(QString::number(this->user->getCommandPrice()).toStdString().c_str());
    std::cout<<"-------------------"<<QString::number(this->user->getCommandPrice()).toStdString();

}
bool DashBoard::AddReview(){

    bool ok;
    QString text = QInputDialog::getText(this, "Introducere text", "Introdu un text:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        // Textul a fost introdus și butonul "OK" a fost apăsat
        // Acum poți face ceva cu textul introdus
        qDebug() << "Text introdus:" << text;
        APPClient::getInstance()->user_client->SetComment(text.toStdString());


        // QFrame *frame = new QFrame;
        // frame->setFixedSize(911, 171);
        // frame->setStyleSheet("background-color: white;");


        // QLabel *titleLabel = new QLabel("Titlu");
        // titleLabel->setFixedSize(161, 31);
        // titleLabel->setStyleSheet("background-color: blue;");
        // titleLabel->setText("Your Comment");



        // QLabel *descriptionLabel = new QLabel("Descriere");
        // descriptionLabel->setFixedSize(881, 111);
        // descriptionLabel->setStyleSheet("background-color: blue;");
        // descriptionLabel->setText(text.toStdString().c_str());



        // QVBoxLayout *frameLayout = new QVBoxLayout;
        // frameLayout->addWidget(titleLabel);
        // frameLayout->addWidget(descriptionLabel);
        // frame->setLayout(frameLayout);


        // gridLayout->addWidget(frame, i, 0);



    } else {
        // Utilizatorul a apăsat butonul "Cancel" sau a închis fereastra
        qDebug() << "Utilizatorul a anulat introducerea textului.";
        return false;
    }


    bool ok2;
    QString text2 = QInputDialog::getText(this, "Introducere text", "Introdu un text:", QLineEdit::Normal, "", &ok2);
    if (ok2 && !text.isEmpty()) {
        // Textul a fost introdus și butonul "OK" a fost apăsat
        // Acum poți face ceva cu textul introdus
        qDebug() << "Text introdus:" << text2;
        APPClient::getInstance()->user_client->SetNota(text2.toStdString());

    } else {
        // Utilizatorul a apăsat butonul "Cancel" sau a închis fereastra
        qDebug() << "Utilizatorul a anulat introducerea textului.";
        return false;
    }


    return true;

}

void DashBoard::on_Comanda_clicked()
{
    CartRequest*cart=new CartRequest();
    cart->SetData(APPClient::getInstance()->user_client->getCart());
    if(! cart->SendCart()){
        std::cout<<"NU AM BANIIII"<<std::endl;
    }
}

void DashBoard::UpdateImage(int index){

     ui->imageLabel->setPixmap(this->allProducts[product_index]->GetNextImage());
    std::cout<<"Update image cu indexul: "<<product_index<<std::endl<<std::endl;

    // disconnect(ui->NextImage, &QPushButton::clicked, this, std::bind(&DashBoard::UpdateImage, this, product_index));
}

void DashBoard::ConstructProductView(int index){

    product_index=index;
    std::cout<<index<<" ID MAIN";

    std::cout<<std::endl<<std::endl<<"Indexul Produsului selectat: "<<index<<std::endl<<std::endl;

    std::vector<std::pair<std::string, std::string>>comments;
    std::string description;

    //if(this->allProducts[index]->GetState()==0){

    //setare descriere
    std::cout<<this->allProducts[product_index]->GetProductID()<<std::endl;
    DescriptionRequest::getInstance()->SetIndex(this->allProducts[product_index]->GetProductID());
    description=DescriptionRequest::getInstance()->GetDescription();
    this->allProducts[product_index]->setDescription(description);

    //setare comments
    CommentsRequest::getInstance()->SetIndex(this->allProducts[product_index]->GetProductID());
    comments=CommentsRequest::getInstance()->GetComments();
    this->allProducts[product_index]->setComments(comments);


    ImageRequest::getInstance()->Construct_MoreImages(this->allProducts[product_index]->GetProductID());
    QList<QPixmap>new_img=ImageRequest::getInstance()->GetNewImages();

    this->allProducts[product_index]->AddMoreImages(new_img);


    //this->allProducts[index]->ModifyState();

   // }else{
        //description=this->allProducts[index]->getDescription();
        //comments=this->allProducts[index]->getComments();
   //}

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

    ui->imageLabel->setPixmap(this->allProducts[product_index]->GetNextImage());
    ui->imageLabel->setScaledContents(true);
    ui->Price->setText(this->allProducts[product_index]->getPrice().c_str());


    ui->titleLabel->setText(this->allProducts[product_index]->getTitle().c_str());
    ui->stackedWidget->setCurrentIndex(3);
    ui->descriptionLabel->setText(this->allProducts[product_index]->getDescription().c_str());

    ui->Cantitate->setText(this->allProducts[product_index]->GetQuant().c_str());




    QObject::connect(ui->Buy, &QPushButton::clicked, [&]() {
        std::string cantitate=ui->lineEditCantitate->text().toStdString();
        QString text = ui->Price->text();
        std::cout<<this->allProducts[product_index]->GetProductID()<<"    "<<cantitate<<std::endl;

        float price = text.toFloat();
        AddPriceToCart(price);
        AddProdusToCart(ui->titleLabel->text(),ui->Price->text());
        APPClient::getInstance()->user_client->setToCart
            (this->allProducts[product_index]->GetProductID(),ui->lineEditCantitate->text().toStdString());
        std::cout<<this->allProducts[product_index]->GetProductID()<<"    "<<cantitate<<std::endl;

    });


    QObject::connect(ui->AddReview, &QPushButton::clicked, [&]() {
        if(this->AddReview()){
            CommentsRequest::getInstance()->SendComment(APPClient::getInstance()->user_client->GetNota()
            ,APPClient::getInstance()->user_client->GetComment());
        }
    });



    // void clearGridLayout(QGridLayout *gridLayout) {
    //     QLayoutItem *item;
    //     while ((item = gridLayout->takeAt(0))) {
    //         if (QWidget *widget = item->widget()) {
    //             delete widget; // Șterge widgetul
    //         }
    //         delete item; // Șterge item-ul din layout
    //     }
    // }
    // Conectează funcția de ștergere la semnalul clicked al butonului:
    //                                                                   cpp
    //                                                                       Copy code
    //                                                                           // Conectare funcție la semnalul clicked al butonului
    //                                                                           connect(ui->yourButton, &QPushButton::clicked, [=]() {
    //                                                                               clearGridLayout(yourGridLayout); // Apelarea funcției de ștergere
    //                                                                           });






    QObject::connect(ui->NextImage, &QPushButton::clicked, this, std::bind(&DashBoard::UpdateImage, this, product_index));

    std::cout<<"S-a construit produsul:: "<<product_index<<std::endl<<"-----------------------\n";
    // QObject::connect(ui->NextImage, &QPushButton::clicked, [&]() {
    //     ui->imageLabel->setPixmap(this->allProducts[product_index]->GetNextImage());
    // });

     ui->stackedWidget->setCurrentIndex(6);



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
    ui->cont->setIcon(notifications);

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

    ui->cont->setIconSize(iconSize);
    ui->cont->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

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
    ui->ForumButton->hide();
    ui->stackedWidget->setCurrentIndex(2);
}


void DashBoard::on_dashboard_clicked()
{
    ui->ForumButton->hide();
    ui->stackedWidget->setCurrentIndex(0);


    // Verifică dacă widget-ul pageProgramari are un layout setat
    // QLayout *layout = ui->scrollContent_3->layout();
    // if (layout) {
    //     // Șterge toate widget-urile din layout-ul actual al pageProgramari
    //     QLayoutItem* child;
    //     while ((child = layout->takeAt(0)) != nullptr) {
    //         // Șterge widget-ul din layout
    //         delete child->widget();
    //         // Șterge item-ul din layout
    //         delete child;
    //     }
    //     // Eliberează memoria ocupată de layout
    //     delete layout;
    //     // Setează layout-ul pageProgramari la nullptr pentru a evita referințele nule
    //     ui->scrollContent_3->setLayout(nullptr);
    // }


    QLayout *layout = ui->scrollContent_3->layout();
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
        ui->scrollContent_3->setLayout(nullptr);
    }
}


void DashBoard::on_dashboard_short_clicked()
{
    ui->ForumButton->hide();
    ui->stackedWidget->setCurrentIndex(0);



        // Verifică dacă widget-ul pageProgramari are un layout setat
        // QLayout *layout = ui->scrollContent_3->layout();
        // if (layout) {
        //     // Șterge toate widget-urile din layout-ul actual al pageProgramari
        //     QLayoutItem* child;
        //     while ((child = layout->takeAt(0)) != nullptr) {
        //         // Șterge widget-ul din layout
        //         delete child->widget();
        //         // Șterge item-ul din layout
        //         delete child;
        //     }
        //     // Eliberează memoria ocupată de layout
        //     delete layout;
        //     // Setează layout-ul pageProgramari la nullptr pentru a evita referințele nule
        //     ui->scrollContent_3->setLayout(nullptr);
        // }


    QLayout *layout = ui->scrollContent_3->layout();
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
        ui->scrollContent_3->setLayout(nullptr);
    }


}


void DashBoard::on_cart_short_clicked()
{
    ui->ForumButton->hide();
    ui->stackedWidget->setCurrentIndex(2);

}



void DashBoard::on_offerts_clicked()
{

    ConstructForumPage();
    ui->ForumButton->show();
    ui->stackedWidget->setCurrentIndex(1);
}


void DashBoard::on_offerts_short_clicked()
{
    ConstructForumPage();
     ui->ForumButton->show();
    ui->stackedWidget->setCurrentIndex(1);
}


void DashBoard::on_Buy_clicked()
{

}





void DashBoard::on_NewPasswSUBMIT_clicked()
{


    //trimit 9 si nume parola noua
    std::string pass=ui->VerifyParola->text().toStdString();
    std::string new_pass=ui->NewParola->text().toStdString();
    std::string new_pass_Again=ui->NewParolaAgain->text().toStdString();

    if(pass==APPClient::getInstance()->user_client->getParola()){
        if(new_pass==new_pass_Again){
            PasswordChangeRequest*new_req=new PasswordChangeRequest();
            new_req->SetPass(new_pass);
            new_req->SendPass();
        }
    }

  ui->stackedWidget->setCurrentIndex(3);

}


void DashBoard::on_SchimbaParola_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



//stacked cont parola


//6 produs view


//cont 3
//5 parola
//cos: 2
//0 dashboard
//4 card

void DashBoard::on_cont_clicked()
{
    ui->ForumButton->hide();
    ui->stackedWidget->setCurrentIndex(3);
}


void DashBoard::on_AdaugaCard_clicked()
{
    ui->ForumButton->hide();
    ui->stackedWidget->setCurrentIndex(4);
}


void DashBoard::on_Add_Card_Button_clicked()
{
    Card*new_card=new Card();
    //ordinea de primire de la server
    //numar,owner name,data exp,cvc

    new_card->Number=ui->NumarCard->text().toStdString();
    new_card->cvc=ui->CVC->text().toStdString();
    new_card->Nume_Detinator=ui->Detinator->text().toStdString();
    new_card->Data=ui->DataExpirarii->text().toStdString();

    APPClient::getInstance()->user_client->setCard(new_card);


    ui->VIEWcvc->setText(new_card->cvc.c_str());
    ui->VIEWData->setText(new_card->Data.c_str());
    ui->VIEWNumar->setText(new_card->Number.c_str());
    ui->VIEWOwner->setText(new_card->Nume_Detinator.c_str());
    ui->VIEWCARD->show();

    CardRequest cardReq;
    cardReq.GetData(new_card);
    cardReq.SendCard();


    ui->stackedWidget->setCurrentIndex(3);
}


void DashBoard::on_AdaugaBani_clicked()
{

    if( APPClient::getInstance()->user_client->GetCard()==nullptr){
            QMessageBox::warning(nullptr, "Eroare", "Nu ai introdus inca un card de credit sau de debit valid");
    }else{

    bool ok;
    QString text = QInputDialog::getText(this, "Introducere text", "Introduceti suma dorita", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        // Textul a fost introdus și butonul "OK" a fost apăsat
        // Acum poți face ceva cu textul introdus
        qDebug() << "Text introdus:" << text;
        MoneyAddRequest req;
        req.setValue(text.toStdString());
        req.SendMoneyReq();
    } else {
        // Utilizatorul a apăsat butonul "Cancel" sau a închis fereastra
        qDebug() << "Utilizatorul a anulat introducerea textului.";

     }
    }

}


void DashBoard::on_ForumButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Introducere text", "Introdu un text:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        // Textul a fost introdus și butonul "OK" a fost apăsat
        // Acum poți face ceva cu textul introdus
        qDebug() << "Text introdus:" << text;

        ForumRequest forumR;
        forumR.SendForumComment(category,text.toStdString());
        //------------------------------

        QLayout *lay = ui->scrollContents_5->layout();

        QFrame *frame = new QFrame;


        QVBoxLayout *layout = new QVBoxLayout;


        frame->setFixedHeight(271);
        frame->setFixedWidth(800); // Setează lățimea fixă pentru frame
        frame->setStyleSheet("background-color: white; border-radius: 10px;");


        QLabel *label1 = new QLabel;
        label1->setMaximumSize(251, 71);
        label1->setGeometry(10, 10, 251, 71);
        label1->setStyleSheet("background-color: #FFCDD2; border-radius: 10px;"); // Culoare roșie deschisă
        label1->setText(APPClient::getInstance()->user_client->getNume().c_str());

        QLabel *label2 = new QLabel;
        label2->setMaximumHeight(371);
        label2->setGeometry(10, 87, 251, 200);
        label2->setStyleSheet("background-color: #BBDEFB; border-radius: 10px;");
        label2->setText("category");



        QTextEdit *textEdit3 = new QTextEdit;
        textEdit3->setMaximumHeight(371);
        textEdit3->setGeometry(10, 164, 251, 371);
        textEdit3->setStyleSheet("background-color: #C8E6C9; border-radius: 10px;"); // Culoare verde deschis
        textEdit3->setText(text);
        textEdit3->setReadOnly(true); // Setează textul ca fiind doar pentru citire, similar cu un QLabel


        layout->addWidget(label1);
        layout->addWidget(label2);
        layout->addWidget(textEdit3);


        frame->setLayout(layout);

        lay->addWidget(frame);

    } else {
        // Utilizatorul a apăsat butonul "Cancel" sau a închis fereastra
        qDebug() << "Utilizatorul a anulat introducerea textului.";

    }
}

