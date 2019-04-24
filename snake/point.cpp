#include "point.h"
#include <stdlib.h>
#include "jeu.h"

extern Game* game;

point::point()
{
    Statut=false;
    int x1=rand()%700;
    int y1=rand()%500;
    while(x1%20!=0)
    {
        x1++;
    }
    while(y1%20!=0)
    {
        y1++;
    }
    setRect(0,0,20,20);
    setPos(x1,y1);
    setBrush(QBrush((Qt::white)));
}



