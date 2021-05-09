#include "Health.h"

Health::Health(QGraphicsItem *parent)
{
    health = 3;
    setPlainText(QString("SHIELDS: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
}
// //parametrize decrease so we can customize the decrease factor for individual enemies
void Health::decrease(int decreaseFactor)
{
    health-=decreaseFactor;
    setPlainText(QString("SHIELDS: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
