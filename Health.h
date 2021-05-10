#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>
#include <QFont>
#include "Score.h"

class Health : public QGraphicsTextItem {

public:
    Health(QGraphicsItem * parent=0);
    
    void decrease(int);
    int getHealth();
    void saveScore();
    void setScore(Score * score);
private:
    int health;
    Score * score;
};


#endif // SCORE_H
