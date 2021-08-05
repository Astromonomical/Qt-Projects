#pragma once

#include "Game.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QRandomGenerator>
#include <stdlib.h>

class Enemy : public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	Enemy();
public slots:
	void move();
};