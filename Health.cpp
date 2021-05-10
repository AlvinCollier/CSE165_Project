#include "Health.h"
#include <fstream>

Health::Health(QGraphicsItem *parent)
{
    health = 3;
    
    setPlainText(QString("SHIELDS: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
}
void Health::setScore(Score * score){
    this->score = score;
}

void Health::decrease(int damage)
{
    health -= damage;
    setPlainText(QString("SHIELDS: ") + QString::number(health));
    if(health <= 0){
        setPlainText(QString("Shields down, game over!"));
        saveScore();
    }
}

int Health::getHealth()
{
    return health;
}
void Health::saveScore(){
        if(score->getScore() > score->getBestScore()){
            std::ofstream ofs("score.txt", std::ofstream::trunc);

            ofs << score->getScore();

            ofs.close();
        }
}