#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class Game: public QGraphicsView {
public:
	// member functions
	Game();
	void mousePressEvent(QMouseEvent* event);

	// member attributes
	QGraphicsScene* scene;
};