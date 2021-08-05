#pragma once

#include "Player.h"
#include "Health.h"
#include "Score.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QRandomGenerator>
#include <QTimer>
#include <QObject>

class Game : public QGraphicsView {

public:
	Game(QWidget *parent=Q_NULLPTR);
	QGraphicsScene* scene;
	Player* player;
	Score* score;
	Health* health;
};

