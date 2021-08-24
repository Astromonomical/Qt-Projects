#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>

class Game: public QGraphicsView {
public:
	// member functions
	Game();
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void setCursor(QString filename);


	// member attributes
	QGraphicsScene* scene;
	QGraphicsPixmapItem* cursor;
};