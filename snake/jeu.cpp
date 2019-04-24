#include "jeu.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>


Game::Game()
{
    // Création de la scène
    QGraphicsScene* scene=new QGraphicsScene();
    scene->setBackgroundBrush(Qt::black);

    NbSegement=0;


    //Création et focalisation sur le joueur
    joueur=new Player();
    joueur->setRect(0,0,20,20);
    joueur->setBrush(QBrush((Qt::darkBlue)));
    joueur->setFlag(QGraphicsItem::ItemIsFocusable);
    joueur->setFocus();

    //Ajout du joueur à la scène
    scene->addItem(joueur);

    //Création du view
    QGraphicsView *view=new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //L'affichage du view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    //Positionnez le joueur
    joueur->setPos(view->width()/2,300);

    //Positionnez un premier point
    joueur->p=new point();
    scene->addItem(joueur->p);


}
