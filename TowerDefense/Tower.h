#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>

class Tower: public QGraphicsPixmapItem {
public:
	Tower(QGraphicsItem* parent=Q_NULLPTR);
private:
	QGraphicsPolygonItem* attack_area;
};

