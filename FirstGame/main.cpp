#include "Player.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QRandomGenerator>
#include <QTimer>
#include <QObject>

/*
* Main launcher class for game
* Widgets Used
* - QGraphicsScene
* - QGraphicsItem	(QGraphicsRecItem)
* - QGraphicsView
*/
#include "Game.h"

Game* game;

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	game = new Game();
	game->show();

	return a.exec();
}