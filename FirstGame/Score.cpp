#include "Score.h"


Score::Score(QGraphicsItem* parent): QGraphicsTextItem(parent) {
	// Initalise
	score = 0;

	// Draw text
	setPlainText(QString("Score: ") + QString::number(score));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("times", 16));

}

void Score::increase() {
	score++;
	setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore() {
	return score;
}