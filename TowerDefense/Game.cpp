#include "Game.h"
#include "Tower.h"

Game::Game() {
	// Create a scene
	scene = new QGraphicsScene(this);

	// set the scene
	setScene(scene);

	// create a tower
	Tower* t = new Tower();

	// add the tower
	scene->addItem(t);

	setFixedSize(800, 600);
}