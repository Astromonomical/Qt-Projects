#pragma once

#include "Projectile.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QPainter>
#include <QObject>
#include <QTimer>

class Tower: public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	Tower(QGraphicsItem* parent=Q_NULLPTR);

	double distanceTo(QGraphicsItem* item);
public slots:
	void acquire_target();
private:
	QGraphicsEllipseItem* _attack_area;
	QPointF _target;
	QPointF _tower_center;
	int _attack_rate;
	int _height, _width;
	bool _has_target;

	void attack_target();
};