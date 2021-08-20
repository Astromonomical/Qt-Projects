#include "Game.h"
#include "Tower.h"
#include "Projectile.h"
#include "Enemy.h"

Game::Game() {
	// Create a scene
	scene = new QGraphicsScene(this);
	scene->setSceneRect(0, 0, 800, 800);

	// set the scene
	setScene(scene);

	// create a tower
	Tower* t = new Tower();
	t->setPos(300, 300);

	// add the tower
	scene->addItem(t);

	// disable scroll policies
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// create enemy
	Enemy* enemy = new Enemy();
	enemy->setPos(0, 0);
	scene->addItem(enemy);
}

void Game::mousePressEvent(QMouseEvent* event) {
	// create a bullet
	Projectile* projectile = new Projectile();
	projectile->setPos(event->pos());
	projectile->setRotation(40);
	scene->addItem(projectile);
}
