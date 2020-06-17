#include <QtDebug>

#include "enemy.h"


Enemy::Enemy()
{
    moveRate = 1000;

    type = "Enemy";

    moveTimer  = new QTimer(this);

    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));

    moveTimer->start(moveRate);

    setShootRate(100);
}

void Enemy::move()
{
    qDebug() << "move method to be override";
}

void Enemy::shoot()
{
    fire();
}

void Enemy::setMoveRate(int rate)
{
    moveRate = rate;
}

int Enemy::getMoveRate() const
{
    return moveRate;
}
