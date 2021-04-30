#include "Score.h"

Score::Score(QGraphicsItem *parent)
{
    score = 0;
    setPlainText(QString("SCORE: ") + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Score::increase()
{
    score += 100;
    setPlainText(QString("SCORE: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
