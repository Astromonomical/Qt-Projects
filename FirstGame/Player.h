#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	void keyPressEvent(QKeyEvent* event);
public slots:
	void spawn();
private:
	int height;
	int width;
};