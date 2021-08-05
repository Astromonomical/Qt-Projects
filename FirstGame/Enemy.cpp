#include "Enemy.h"
#include <QDebug>

extern Game* game; // external global object called game

Enemy::Enemy() {
	// Generate random position
	int random_x = rand() % 700;

	// Create enemy
	setRect(random_x, 0, 100, 100);

	QTimer* timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

	timer->start(9);
}

void Enemy::move() {
	// Move enemy down
	setPos(x(), y() + 1);

	// Check if enemy is off screen and remove health if so
	if (pos().y() + rect().height() > 600) {
		game->health->decrease();
		scene()->removeItem(this);
		delete this;
	}
}