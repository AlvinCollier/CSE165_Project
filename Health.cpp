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
    if(health <= 0){
        setPlainText(QString("Shields down, game over!"));
    }
}

int Health::getHealth()
{
    return health;
}
