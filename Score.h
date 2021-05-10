#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem {
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    int getScore();
    int getBestScore();
private:
    int score;
    int bestScore;
};


#endif // SCORE_H
