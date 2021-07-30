#include "Bullet.h"

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
	for (QGraphicsItem *item : colliding_items) {
		if (typeid(item) == typeid(Enemy)) {
			scene()->removeItem(item);
			scene()->removeItem(this);
			delete item;
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
