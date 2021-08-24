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

	// set cursor
	cursor = nullptr;

	// disable scroll policies
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// create enemy
	Enemy* enemy = new Enemy();
	enemy->setPos(300, 157);
	scene->addItem(enemy);

	// test code 
	setCursor(":/images/Tesla.png");
	setMouseTracking(true);
}

void Game::mousePressEvent(QMouseEvent* event) {
	Projectile* projectile = new Projectile();
	
	projectile->setPos(event->pos());
	scene->addItem(projectile);
}

void Game::mouseMoveEvent(QMouseEvent* event) {
	if (cursor) {
		cursor->setPos(event->pos());
	}
}

void Game::setCursor(QString filename) {
	if (cursor) {
		scene->removeItem(cursor);
		delete cursor;
	}

	cursor = new QGraphicsPixmapItem();
	cursor->setPixmap(filename);
	scene->addItem(cursor);
}
