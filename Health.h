#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>
#include <QFont>

class Health : public QGraphicsTextItem {
public:
    Health(QGraphicsItem * parent=0);
    //parametrize decrease so we can customize the decrease factor for individual enemies
    void decrease(int decreaseFactor);
    int getHealth();
private:
    int health;
};


#endif // SCORE_H
