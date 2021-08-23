#include "Enemy.h"
#include <QDebug>

Enemy::Enemy(QGraphicsItem* parent) {
	// Set pixmap
	QPixmap image = QPixmap(":/enemies/enemy.png");

	setPixmap(image.scaled(50, 50, Qt::KeepAspectRatio));

	// Set points
	_points << QPointF(250, 250) << QPointF(100,50) << QPointF(0, 0);
	_point_index = 0;
	_dest = _points[_point_index];
	rotateToPoint(_dest);

	// connect timer for movement
	QTimer* move_timer = new QTimer(this);
	connect(move_timer, SIGNAL(timeout()), this, SLOT(moveForward()));
	move_timer->start(25);

}

void Enemy::rotateToPoint(QPointF p) {
	QLineF ln(pos(), p);
	setRotation(ln.angle());
}

void Enemy::moveForward() {
	// check if close to dest
	QLineF ln(pos(), _dest);
	rotateToPoint(_dest);
	qDebug() << ln.length();
	if (ln.length() < 25) {
		_point_index++;
		if (_point_index == _points.size()) {
			
			_point_index = 0;
		}

		_dest = _points[_point_index];
		rotateToPoint(_dest);
	}

	_speed = 2;
	double theta = rotation(); // degrees

	// calculate change in x and y
	double dx = _speed * qSin(theta);
	double dy = _speed * qCos(theta);

	setPos(x() + dx, y() + dy);
}