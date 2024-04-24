#include "blankwindow.h"

BlankWindow::BlankWindow(QWidget *parent) : QMainWindow(parent) {
    // Configurează fereastra
    setWindowTitle("Blank Window");
    resize(400, 300); // Setează dimensiunea ferestrei

    // Elimină toate widget-urile din interiorul ferestrei
    centralWidget()->setParent(nullptr);
}
