#pragma once

#include <QWidget>

class PaintWindow : public QWidget
{
    Q_OBJECT

public:
    PaintWindow(QWidget *parent = Q_NULLPTR);
    ~PaintWindow();

private:
    Ui::PaintWindowClass ui;
    QString currentFile = "";
};
