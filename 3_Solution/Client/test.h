#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QScrollArea>
#include <QGridLayout>

namespace Ui {
class Test;
}

class Test : public QWidget
{
    Q_OBJECT

// public:
//     Test(QWidget *parent = nullptr) : QWidget(parent) {
//         QVBoxLayout *layout = new QVBoxLayout(this);

//         // Adăugarea unui QLabel pentru titlu
//         QLabel *titleLabel = new QLabel("Dashboard Cu Comentarii");
//         titleLabel->setAlignment(Qt::AlignCenter);
//         layout->addWidget(titleLabel);

//         // Crearea unui container pentru produse într-un QScrollArea
//         QScrollArea *productScrollArea = new QScrollArea;
//         QWidget *productWidget = new QWidget;
//         productLayout = new QGridLayout(productWidget);
//         productScrollArea->setWidget(productWidget);
//         productScrollArea->setWidgetResizable(true);
//         layout->addWidget(productScrollArea);

//         // Inițializarea produselor și comentariilor
//         initProducts();
//     }

// private:
//     void initProducts() {
//         // Simularea datelor produselor și comentariilor
//         QStringList products = {"Produs 1", "Produs 2", "Produs 3","Produs 1", "Produs 2", "Produs 3"};
//         QStringList comments = {"Comentariu 1", "Comentariu 2", "Comentariu 3","Comentariu 1", "Comentariu 2", "Comentariu 3"};

//         // Adăugarea produselor, butoanelor pentru comentarii și casetelor de text pentru afișarea comentariilor
//         for (int i = 0; i < 6; ++i) {
//             // Adăugarea numelui produsului într-un QLabel
//             QLabel *productLabel = new QLabel(products[i]);
//             productLayout->addWidget(productLabel, i, 0);

//             // Crearea butonului pentru afișarea comentariilor
//             QPushButton *commentButton = new QPushButton("Comentarii");
//             commentButton->setProperty("productIndex", i); // Stocăm indexul produsului în proprietatea butonului
//             productLayout->addWidget(commentButton, i, 1);

//             // Crearea unei casete de text pentru afișarea comentariilor
//             commentLabels.append(new QLabel);
//             productLayout->addWidget(commentLabels[i], i + 1, 0, 1, 2); // Adăugarea casetei de text sub produs

//             // Conectarea unui slot la semnalul clicked al butonului de comentarii
//             connect(commentButton, &QPushButton::clicked, this, &Test::showProductComments);
//         }
//     }

// private slots:
//     void showProductComments() {
//         QPushButton *button = qobject_cast<QPushButton *>(sender());
//         if (!button) return;

//         int productIndex = button->property("productIndex").toInt();
//         if (productIndex >= 0 && productIndex < productComments.size()) {
//             commentLabels[productIndex]->setText(productComments[productIndex]);
//         }
//     }


public:
    Test(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        // Crearea unui QScrollArea
        QScrollArea *scrollArea = new QScrollArea;
        QWidget *scrollWidget = new QWidget;
        QGridLayout *scrollLayout = new QGridLayout(scrollWidget);

        // Adăugarea unui număr de label-uri în QScrollArea cu aliniament de tip grid
        const int numRows = 5;
        const int numCols = 4;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                QLabel *label = new QLabel(QString("Label %1-%2").arg(i + 1).arg(j + 1));
                scrollLayout->addWidget(label, i, j);
            }
        }

        // Setarea widget-ului interior al QScrollArea și a layout-ului acestuia
        scrollWidget->setLayout(scrollLayout);
        scrollArea->setWidget(scrollWidget);
        scrollArea->setWidgetResizable(true);

        // Adăugarea QScrollArea la layout-ul principal
        layout->addWidget(scrollArea);

        setLayout(layout);
    }

private:
    QGridLayout *productLayout;
    QList<QLabel *> commentLabels; // Lista de QLabel-uri pentru afișarea comentariilor
    QStringList productComments = {"Comentariu 1", "Comentariu 2", "Comentariu 3"}; // Simularea datelor de comentarii pentru produse
    Ui::Test *ui;
    ~Test();
};






#endif // TEST_H
