#include "Tower.h"
#include "Game.h"
#include "Enemy.h"
#include <QDebug>

extern Game* game;

Tower::Tower(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
	// set the graphics
	setPixmap(QPixmap(":/images/Tesla.png"));

	// set variables
	QSizeF size = this->boundingRect().size();
	int LEVEL_FACTOR = 40;
	int level = 0;
	int diameter = 300 + (level * LEVEL_FACTOR);
	int radius = diameter / 2;
	_has_target = false;
	_attack_rate = 1000;
	_height = size.height();
	_width = size.width();

	// get center coords of pixmap
	int pix_x = this->pos().x() + size.width() / 2;
	int pix_y = this->pos().y() + size.height() / 2;
	_tower_center = QPointF(pix_x, pix_y);

	// setup aoe coords
	int x = pix_x - radius;
	int y = pix_y - radius;

	// draw attack area
	_attack_area = new QGraphicsEllipseItem(x, y, diameter, diameter, this);

	// connect an attack timer
	QTimer* timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(acquire_target()));
	timer->start(_attack_rate);
}

void Tower::attack_target() {
	Projectile* round = new Projectile();

	// Get center of tower
	_tower_center = QPointF(pos().x(), pos().y());
	round->setPos(_tower_center);

	QLineF ln(_tower_center, _target);

	// angle returns counter clockwise integer
	// multiply by -1 to get clockwise angle
	double angle = ln.angle() * -1;

	round->setRotation(angle);
	game->scene->addItem(round);
}

double Tower::distanceTo(QGraphicsItem* item) {
	QLineF ln(pos(), item->pos());
	return ln.length();
}

void Tower::acquire_target() {
	// Get list of all colliding objects
	QList<QGraphicsItem*> colliding_items = _attack_area->collidingItems();

	// If colliding items only has 1 (itself), return
	if (colliding_items.size() == 1) {
		_has_target = false;
		return;
	}

	double closest_distance = 300;
	QPointF closest_pt = QPointF(0, 0);
	for (size_t i = 0; i < colliding_items.size(); i++) {
		Enemy* enemy = dynamic_cast<Enemy*>(colliding_items[i]);

		if (enemy) {
			double this_distance = distanceTo(enemy);
			if (this_distance < closest_distance) {
				closest_distance = this_distance;
				closest_pt = QPointF(colliding_items[i]->pos());
				_has_target = true;
			}
		}
	}

	_target = closest_pt;
	attack_target();
}