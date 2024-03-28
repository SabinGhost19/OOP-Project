#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>

namespace Ui {
class DashBoard;
}

class DashBoard : public QDialog
{
    Q_OBJECT

public:
    explicit DashBoard(QWidget *parent = nullptr);
    ~DashBoard();

private:
    Ui::DashBoard *ui;
};

#endif // DASHBOARD_H
