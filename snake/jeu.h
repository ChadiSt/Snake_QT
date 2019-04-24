#ifndef JEU_H
#define JEU_H
#include <QGraphicsView>
#include <player.h>
#include "localisation.h"
#include "point.h"

class Game:public QGraphicsView
{
public:
    Game();
    QGraphicsScene* scene;
    Player* joueur;
    int NbSegement;
};

#endif // JEU_H
