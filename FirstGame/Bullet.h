#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "Enemy.h"

class Bullet : public QObject, public QGraphicsRectItem {
	Q_OBJECT

public:
	Bullet();
public slots:
	void move();
};