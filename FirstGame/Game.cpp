#include "Game.h"


Game::Game(QWidget *parent) {
	int playerWidth = 100;
	int playerHeight = 100;

	// Create main scene
	scene = new QGraphicsScene();

	// Add scene to view
	setScene(scene);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// Set screen size
	setFixedSize(800, 600);
	scene->setSceneRect(0, 0, 800, 600);

	// Add the player
	player = new Player();
	player->setRect(0, 0, playerWidth, playerHeight);
	scene->addItem(player);
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	scene->setFocusItem(player);
	int centerX = (width() / 2) - (playerWidth / 2);
	int bottomY = height() - playerHeight;
	player->setPos(centerX, bottomY);

	// Spawn enemies
	QTimer* enemy_spawn = new QTimer();
	QObject::connect(enemy_spawn, SIGNAL(timeout()), player, SLOT(spawn()));
	enemy_spawn->start(2000);

	show();
}