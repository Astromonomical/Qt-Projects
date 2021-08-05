#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>

class Tower: public QGraphicsPixmapItem {
public:
	Tower(QGraphicsItem* parent);
private:
	QGraphicsPolygonItem* attack_area;
};

