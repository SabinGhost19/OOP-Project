#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>

namespace Ui {
class DashBoard;
}

class DashBoard : public QWidget
{
    Q_OBJECT

public:
    explicit DashBoard(QWidget *parent = nullptr);
    ~DashBoard();

private slots:


    void on_pushButton_clicked();

    void on_signout_clicked();

    void on_signout_short_clicked();

    void on_search_clicked();

private:
    Ui::DashBoard *ui;
};

#endif // DASHBOARD_H
