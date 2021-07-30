#pragma once

#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem {
public:
	Score(QGraphicsItem *parent=Q_NULLPTR);
	void increase();
	int getScore();
private:
	int score;

};

