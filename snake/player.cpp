#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "jeu.h"
#include "player.h"
#include <QDebug>
#include <QTimer>
#include <QGraphicsTextItem>
#include "gameover.h"


extern Game* game;


Player::Player()
{
    droite=false;
    gauche=false;
    haut=false;
    bas=false;
    QTimer* timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveA()));
    timer->start(250);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    droite=false;
    gauche=false;
    haut=false;
    bas=false;

    if(event->key()==Qt::Key_Left)
    {
        setPos(x()-20,y());
        gauche=true;
        move();
    }
    else if(event->key()==Qt::Key_Right)
    {
        droite=true;
        setPos(x()+20,y());
        move();
    }
    if(event->key()==Qt::Key_Up)
    {
        setPos(x(),y()-20);
        move();
        haut=true;
    }
    if(event->key()==Qt::Key_Down)
    {
        setPos(x(),y()+20);
        move();
        bas=true;
    }
    Collision();
    FinJeu();
}

/*********************************ELARGISSEMENT A GAUCHE**********************/
void Player::ElargirG()
{
    if(game->NbSegement==0) // Premier Segement du serpent
    {
        // Recupération Des Coordonnées Joueur
        seg[game->NbSegement].x=x();
        seg[game->NbSegement].y=y();

        // Incrémentation Du NbSegement

        game->NbSegement++;

        //Stockage Des Coordonnées du Segement
        seg[game->NbSegement].x=seg[game->NbSegement-1].x-20;
        seg[game->NbSegement].y=seg[game->NbSegement-1].y;

        // Création du ségement
        seg[game->NbSegement].setRect(seg[game->NbSegement].x,seg[game->NbSegement].y,20,20);
        seg[game->NbSegement].setBrush(QBrush((Qt::blue)));
        scene()->addItem(seg+1);
        qDebug() << "Seg Cree";
    }
    else{
        // Incrémentation du NbSegement
        game->NbSegement++;

        // Stockage Des Coordonnées du Segement
        seg[game->NbSegement].x=seg[game->NbSegement-1].x-20;
        seg[game->NbSegement].y=seg[game->NbSegement-1].y;

        //Déclaration D'une variable index
        int i = game->NbSegement;

        //Création Du Segement

        seg[game->NbSegement].setRect(seg[game->NbSegement].x,seg[game->NbSegement].y,20,20);
        seg[game->NbSegement].setBrush(QBrush((Qt::blue)));
        scene()->addItem(seg+i);
    }
}

/*********************************ELARGISSEMENT A DROITE**********************/
void Player::ElargirD()
{
    if(game->NbSegement==0) // Premier Segement du serpent
    {
        // Recupération Des Coordonnées Joueur
        seg[game->NbSegement].x=x();
        seg[game->NbSegement].y=y();

        // Incrémentation Du NbSegement

        game->NbSegement++;

        //Stockage Des Coordonnées du Segement
        seg[game->NbSegement].x=seg[game->NbSegement-1].x+20;
        seg[game->NbSegement].y=seg[game->NbSegement-1].y;

        // Création du ségement
        seg[game->NbSegement].setRect(seg[game->NbSegement].x,seg[game->NbSegement].y,20,20);
        seg[game->NbSegement].setBrush(QBrush((Qt::blue)));
        scene()->addItem(seg+1);
        qDebug() << "Seg Cree";
    }
    else{
        // Incrémentation du NbSegement
        game->NbSegement++;

        // Stockage Des Coordonnées du Segement
        seg[game->NbSegement].x=seg[game->NbSegement-1].x+20;
        seg[game->NbSegement].y=seg[game->NbSegement-1].y;

        //Déclaration D'une variable index
        int i = game->NbSegement;

        //Création Du Segement

        seg[game->NbSegement].setRect(seg[game->NbSegement].x,seg[game->NbSegement].y,20,20);
        seg[game->NbSegement].setBrush(QBrush((Qt::blue)));
        scene()->addItem(seg+i);
    }
}


/*********************************ELARGISSEMENT EN HAUT**********************/

void Player::ElargirH()
{
    if(game->NbSegement==0) // Premier Segement du serpent
    {
        // Recupération Des Coordonnées Joueur
        seg[game->NbSegement].x=x();
        seg[game->NbSegement].y=y();

        // Incrémentation Du NbSegement

        game->NbSegement++;

        //Stockage Des Coordonnées du Segement
        seg[game->NbSegement].x=seg[game->NbSegement-1].x;
        seg[game->NbSegement].y=seg[game->NbSegement-1].y-20;

        // Création du ségement
        seg[game->NbSegement].setRect(seg[game->NbSegement].x,seg[game->NbSegement].y,20,20);
        seg[game->NbSegement].setBrush(QBrush((Qt::blue)));
        scene()->addItem(seg+1);
        qDebug() << "Seg Cree";
    }
    else{
        // Incrémentation du NbSegement
        game->NbSegement++;

        // Stockage Des Coordonnées du Segement
        seg[game->NbSegement].x=seg[game->NbSegement-1].x;
        seg[game->NbSegement].y=seg[game->NbSegement-1].y-20;

        //Déclaration D'une variable index
        int i = game->NbSegement;

        //Création Du Segement

        seg[game->NbSegement].setRect(seg[game->NbSegement].x,seg[game->NbSegement].y,20,20);
        seg[game->NbSegement].setBrush(QBrush((Qt::blue)));
        scene()->addItem(seg+i);
    }
}

/*********************************ELARGISSEMENT EN BAS**********************/
void Player::ElargirB()
{
    if(game->NbSegement==0) // Premier Segement du serpent
    {
        // Recupération Des Coordonnées Joueur
        seg[game->NbSegement].x=x();
        seg[game->NbSegement].y=y();

        // Incrémentation Du NbSegement

        game->NbSegement++;

        //Stockage Des Coordonnées du Segement
        seg[game->NbSegement].x=seg[game->NbSegement-1].x;
        seg[game->NbSegement].y=seg[game->NbSegement-1].y+20;

        // Création du ségement
        seg[game->NbSegement].setRect(seg[game->NbSegement].x,seg[game->NbSegement].y,20,20);
        seg[game->NbSegement].setBrush(QBrush((Qt::blue)));
        scene()->addItem(seg+1);
        qDebug() << "Seg Cree";
    }
    else{
        // Incrémentation du NbSegement
        game->NbSegement++;

        // Stockage Des Coordonnées du Segement
        seg[game->NbSegement].x=seg[game->NbSegement-1].x;
        seg[game->NbSegement].y=seg[game->NbSegement-1].y+20;

        //Déclaration D'une variable index
        int i = game->NbSegement;

        //Création Du Segement

        seg[game->NbSegement].setRect(seg[game->NbSegement].x,seg[game->NbSegement].y,20,20);
        seg[game->NbSegement].setBrush(QBrush((Qt::blue)));
        scene()->addItem(seg+i);
    }
}




/*******************************DEPLACEMENT DES SEGEMENTS*******************/
void Player::move()
{
    int N=game->NbSegement;

    // Mise à Jour Des Coordonnées
    for(int i=N;i>0;i--)
    {
        seg[i].x=seg[i-1].x;
        seg[i].y=seg[i-1].y;
    }
    // Mise à Jour Des Coordonnées Joueur

    seg[0].x=x();
    seg[0].y=y();

    // Déplacement
    for(int i=1;i<=N;i++)
    {
        seg[i].setRect(seg[i].x,seg[i].y,20,20);
    }
}


/***********************************COLLISION AVEC POINT************************/

void Player::Collision()
{
    if(p->x()==this->x() && p->y()==this->y())
    {
        scene()->removeItem(p);
        if(haut==true)
        {
            ElargirB();
        }
        if(bas==true)
        {
            ElargirH();
        }
        if(gauche==true)
        {
            ElargirD();
        }
        if(droite==true)
        {
            ElargirG();
        }
        p=new point();
        scene()->addItem(p);

    }
}

bool Player::Perdu()
{
    bool Perdu=false;
    for(int i=1;i<game->NbSegement;i++)
    {
        if(seg[0].x==seg[i].x && seg[0].y==seg[i].y)
        {
            Perdu=true;
        }
    }
    if(this->x()>780 || this->x()<0 || this->y()<0 || this->y()>580)
    {
        Perdu=true;
    }
    return Perdu;
}

void Player::FinJeu()
{
    if(Perdu()==true)
    {
        GameOver *g=new GameOver();
        g->setPos(250,220);
        scene()->addItem(g);
        scene()->removeItem(p);
        scene()->removeItem(this);
        delete(this);

    }
}

void Player::moveA()
{

        if(haut==true)
        {
            setPos(x(),y()-20);
            move();
        }
        else if(bas==true)
        {
            setPos(x(),y()+20);
            move();
        }
        else if(droite==true)
        {
            setPos(x()+20,y());
            move();
        }
        else if(gauche==true)
        {
            setPos(x()-20,y());
            move();
        }
        Collision();
        FinJeu();

}




