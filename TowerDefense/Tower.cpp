#include "Tower.h"
#include "Game.h"

extern Game* game;

Tower::Tower(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
	// set the graphics
	setPixmap(QPixmap(":/images/Tesla.png"));

	// set variables
	int LEVEL_FACTOR = 40;
	int level = 0;
	int diameter = 300 + (level * LEVEL_FACTOR);
	int radius = diameter / 2;
	_attack_rate = 1000;

	// get center coords of pixmap
	QSizeF size = this->boundingRect().size();
	int pix_x = this->pos().x() + size.width() / 2;
	int pix_y = this->pos().y() + size.height() / 2;

	// set height and width members
	_height = size.height();
	_width = size.width();
	_tower_center = QPointF(pix_x, pix_y);

	// setup aoe coords
	int x = pix_x - radius;
	int y = pix_y - radius;

	// draw attack area
	_attack_area = new QGraphicsEllipseItem(x, y, diameter, diameter, this);

	// connect an attack timer
	QTimer* timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(attack_target()));
	timer->start(_attack_rate);
}

void Tower::attack_target() {
	Projectile* round = new Projectile();
	round->setPos(_tower_center);

	QLineF ln(_tower_center, _target);

	// angle returns counter clockwise integer
	// multiply by -1 to get clockwise angle
	double angle = ln.angle() * -1;

	round->setRotation(angle);
	game->scene->addItem(round);
}