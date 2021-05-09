#include "Health.h"

Health::Health(QGraphicsItem *parent)
{
    health = 3;
    setPlainText(QString("SHIELDS: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
}

void Health::decrease(int damage)
{
    health -= damage;
    setPlainText(QString("SHIELDS: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
