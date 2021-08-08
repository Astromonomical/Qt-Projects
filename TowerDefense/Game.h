#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>

class Game: public QGraphicsView {
public:
	// member functions
	Game();

	// member attributes
	QGraphicsScene* scene;
};