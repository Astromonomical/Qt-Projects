#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

void Player::keyPressEvent(QKeyEvent *event) {

	if (event->key() == Qt::Key_Right) {
		if (pos().x() + rect().height() < 800) setPos(x() + 10, y());
	}
	else if (event->key() == Qt::Key_Left) {
		if (pos().x() > 0) setPos(x() - 10, y());
	}
	else if (event->key() == Qt::Key_Space) {
		// Create a bullet
		Bullet* newBullet = new Bullet();
		newBullet->setPos(x(), y());
		scene()->addItem(newBullet);
	}
}

void Player::spawn() {
	Enemy *enemy = new Enemy();
	scene()->addItem(enemy);
}