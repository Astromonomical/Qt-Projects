#include "Bullet.h"
#include "Game.h"

#include <QDebug>

extern Game* game; // external global object called game
Bullet::Bullet() {
	// Draw rectangle
	setRect(0, 0, 10, 50);

	// Connect slot
	QTimer* timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

	timer->start(50);
}

void Bullet::move() {
	setPos(x(), y()-10);

	// Check for contact
	QList<QGraphicsItem*> colliding_items = collidingItems();
	for (int i = 0; i < colliding_items.size(); i++) {
		if (typeid(*colliding_items[i]) == typeid(Enemy)) {
			// Increase score
			game->score->increase();

			// Destroy items
			scene()->removeItem(colliding_items[i]);
			scene()->removeItem(this);
			delete colliding_items[i];
			delete this;
			return;
		}
	}

	// Check if bullet is off screen
	if (pos().y() + rect().height() < 0) {
		scene()->removeItem(this);
		delete this;
	}
}
