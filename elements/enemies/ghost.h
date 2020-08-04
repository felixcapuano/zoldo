#ifndef GHOST_H
#define GHOST_H

#include "core/enemy.h"


class Ghost : public Enemy
{
    Q_OBJECT
public:
    Ghost();

    void move() override;
};

#endif // GHOST_H
