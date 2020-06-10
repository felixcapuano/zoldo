#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsView>
#include <QTimer>

#include "config.h"
#include "level.h"
#include "adventure.h"

class GameEngine: public QGraphicsView
{
    Q_OBJECT

private:
    QGraphicsScene * scene;

    QGraphicsItemGroup * sceneElements;

    int windowWidth;

    int windowHeight;

    Adventure * adventure;

    Level * currentLevel;

    QTimer * clock;

public slots:
    void updateState();

public:
    GameEngine();

    ~GameEngine();

    void loadAdventure();

    void drawLevel(Level * level);

    void updateUnitState();
};

#endif // GAMEENGINE_H
