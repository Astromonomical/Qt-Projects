#pragma once

#include <QMainWindow>

namespace Ui {
}

class MainWindow : public MainWindow {
	Q_OBJECT

public:
	MainWindow(QMainWindow* parent=Q_NULLPTR);
	~MainWindow();

private:
	Ui::MainWindow() ui;
	QString currentFile = "";
};