#pragma once

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QPixmap>
#include <QTimer>
#include <qmath.h>

class Enemy : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	Enemy(QGraphicsItem* parent=Q_NULLPTR);
	void rotateToPoint(QPointF p);
public slots:
	void moveForward();
private:
	QList<QPointF> _points;
	QPointF _dest;
	int _point_index;
	int _speed;
};