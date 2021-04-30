#include "Health.h"

Health::Health(QGraphicsItem *parent)
{
    health = 3;
    setPlainText(QString("SHIELDS: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("SHIELDS: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
