#pragma once
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsItem>

class Health : public QGraphicsTextItem {
public:
	Health(QGraphicsItem* parent = Q_NULLPTR);
	void decrease();
	int getHealth();
private:
	int health;

};

