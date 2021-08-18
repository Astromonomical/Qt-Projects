#include "Projectile.h"

Projectile::Projectile(QGraphicsItem* parent) {
	// set graphics
	setPixmap(QPixmap(":/projectiles/arrow.png"));

	// set the speed
	projectile_speed = 30;

	// connect a timer to move()
	QTimer* move_timer = new QTimer(this);
	connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));

	move_timer->start(50);
}

void Projectile::move() {
	// get angle
	double theta = qDegreesToRadians(rotation());

	// calculate change in x and y
	double dx = projectile_speed * qSin(theta);
	double dy = projectile_speed * qCos(theta);

	setPos(x() + dx, y() + dy);
}