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

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	int playerWidth = 100;
	int playerHeight = 100;

	// Create main scene
	QGraphicsScene *mainScene = new QGraphicsScene();

	// Create item
	Player* player = new Player();
	player->setRect(0, 0, playerWidth, playerHeight);

	// Add to scene
	mainScene->addItem(player);

	// Make focusable
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	mainScene->setFocusItem(player);

	// Add a view
	QGraphicsView* view = new QGraphicsView(mainScene);

	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// Show view
	view->show();
	view->setFixedSize(800, 600);
	mainScene->setSceneRect(0, 0, 800, 600);

	int centerX = (view->width() / 2) - (playerWidth / 2);
	int bottomY = view->height() - playerHeight;
	player->setPos(centerX, bottomY);

	// Spawn enemies
	QTimer *enemy_spawn = new QTimer();
	QObject::connect(enemy_spawn, SIGNAL(timeout()), player, SLOT(spawn()));
	enemy_spawn->start(2000);

	return a.exec();
}