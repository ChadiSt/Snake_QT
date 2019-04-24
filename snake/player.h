#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QObject>
#include "localisation.h"
#include "point.h"

class Player: public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent* event);
    void ElargirG();
    void ElargirD();
    void ElargirH();
    void ElargirB();

    void move();
    void Collision();
    bool Perdu();
    void FinJeu();

    // Les Variables De Deplacement
    bool droite;
    bool gauche;
    bool haut;
    bool bas;
    point *p;


    location seg[500];
public slots:
    void moveA();


};

#endif // PLAYER_H
