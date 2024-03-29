#include "Health.h"

Health::Health(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
	// Initalise
	health = 3;

	// Draw text
	setPlainText(QString("Health: ") + QString::number(health));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times", 16));
}

void Health::decrease() {
	health--;
	setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth() {
	return health;
}