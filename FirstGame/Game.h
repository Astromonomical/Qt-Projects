#pragma once

#include "Player.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QRandomGenerator>
#include <QTimer>
#include <QObject>
#include "Score.h"

class Game : public QGraphicsView {

public:
	Game(QWidget *parent=Q_NULLPTR);
	QGraphicsScene* scene;
	Player* player;
	Score* score;
};

