#ifndef POINT_H
#define POINT_H
#include "QGraphicsRectItem"

class point : public QGraphicsRectItem
{
public:
    point();
    bool Collision();
    bool Statut;
};
#endif // POINT_H
