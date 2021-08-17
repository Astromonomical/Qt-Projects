#include "Tower.h"


//Points: (1,0), (2,0) (3,1) (3,2) (2,3) (1, 3) (0, 2) (0, 1)

Tower::Tower(QGraphicsItem *parent) {
	// set the graphics
	setPixmap(QPixmap(":/images/Tesla.png"));

	// set variables
	int LEVEL_FACTOR = 40;
	int level = 0;
	int diameter = 300 + (level * LEVEL_FACTOR);
	int radius = diameter / 2;

	// get center coords of pixmap
	QSizeF size = this->boundingRect().size();
	int pix_x = this->pos().x() + size.width() / 2;
	int pix_y = this->pos().y() + size.height() / 2;

	// setup aoe coords
	int x = pix_x - radius;
	int y = pix_y - radius;

	// draw attack area
	attack_area = new QGraphicsEllipseItem(x, y, diameter, diameter, this);
}