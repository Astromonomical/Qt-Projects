#include "PaintWindow.h"

PaintWindow::PaintWindow(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("Hello World");
}