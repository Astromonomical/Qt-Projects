#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <qmath.h>

class Projectile : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	Projectile(QGraphicsItem* parent = Q_NULLPTR);
public slots:
	void move();
private:
	int projectile_speed;
};