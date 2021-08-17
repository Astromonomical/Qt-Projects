#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QPainter>

class Tower: public QGraphicsPixmapItem {
public:
	Tower(QGraphicsItem* parent=Q_NULLPTR);
private:
	QGraphicsEllipseItem* attack_area;
};