#ifndef LOADINGSCREEN_H
#define LOADINGSCREEN_H

#include <QWidget>

namespace Ui {
class LoadingScreen;
}

class LoadingScreen : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingScreen(QWidget *parent = nullptr);
    void updateImage();
    ~LoadingScreen();

private:
    Ui::LoadingScreen *ui;
    QStringList m_imageList;
    int m_currentImageIndex;
};

#endif // LOADINGSCREEN_H
