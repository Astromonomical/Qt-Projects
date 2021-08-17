#include "Game.h"
#include "Tower.h"

Game::Game() {
	// Create a scene
	scene = new QGraphicsScene(this);
	scene->setSceneRect(0, 0, 800, 800);

	// set the scene
	setScene(scene);

	// create a tower
	Tower* t = new Tower();

	// add the tower
	scene->addItem(t);

	// disable scroll policies
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}