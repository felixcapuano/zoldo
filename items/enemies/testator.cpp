#include "testator.h"


Testator::Testator()
{

    //movement parameters
    setMoveRate(10);

    // setup enemy stats
    movementSpeed = 2;
    health = 100;

    // setup graphics
    setHeight(50);
    setWidth(50);
    setSprite(":/ressources/images/test/enemy_test.png");
}

void Testator::move()
{
    setVerticalMov((rand() % 3) - 1);
    setHorizontalMov((rand() % 3) - 1);
}