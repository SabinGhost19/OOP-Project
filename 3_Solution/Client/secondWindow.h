#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QPropertyAnimation>
#include <QEvent>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
   // void on_pushButton_clicked();

   // void on_pushButton_2_clicked();

   // void setStyleSheet();

    //bool eventFilter(QObject *obj, QEvent *event);




private:
    Ui::SecondWindow *ui;
    QPropertyAnimation *animation;
};

#endif // SECONDWINDOW_H

