#include <QDebug>
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMouseEvent>
#include "base.h"
#include "mes_fourmies.h"
#include "mainwindow.h"

Creature :: Creature (int Points_de_vie, int Vie_max, int Force, QGraphicsPixmapItem *parent):
    QObject(),
    QGraphicsPixmapItem(parent),
    Points_de_vie(Points_de_vie),
    Vie_max(Vie_max),
    Force(Force)
{}

Ma_Fourmie :: Ma_Fourmie(int Points_de_vie, int Vie_max, int Force, int Experience, int Niveau, int Limite_de_niveau):
    Creature (Points_de_vie, Vie_max, Force),
    Experience(Experience),
    Niveau(Niveau),
    Limite_de_niveau(Limite_de_niveau)
{}

void Ma_Fourmie :: keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left)
    {
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        setPos(x()+10,y());
    }
    if (event->key() == Qt::Key_Up)
    {
        setPos(x(),y()-10);
    }
    if (event->key() == Qt::Key_Down)
    {
        setPos(x(),y()+10);
    }
}

Guerriere :: Guerriere(int Points_de_vie, int Vie_max, int Force, int Experience, int Niveau, int Limite_de_niveau) :
    Ma_Fourmie(Points_de_vie, Vie_max, Force, Experience, Niveau, Limite_de_niveau)
{
    setPixmap(QPixmap(":/images/guerriere.png").scaled(QSize(100,50)));

}


Super_Guerriere :: Super_Guerriere(int Points_de_vie, int Vie_max, int Force, int Experience, int Niveau, int Limite_de_niveau) :
    Guerriere(Points_de_vie, Vie_max, Force, Experience, Niveau, Limite_de_niveau)
{
    setPixmap(QPixmap(":/images/super-guerriere.png").scaled(QSize(100,50)));
setPos(0,150);
}

Reine :: Reine() :
    Ma_Fourmie(Points_de_vie, Vie_max, Force, Experience, Niveau, Limite_de_niveau)
{
    this->Points_de_vie = 50;
    this->Force = 15;
}
Recolteuse :: Recolteuse(bool est_occupee) :
    Ma_Fourmie(Points_de_vie, Vie_max, Force, Experience, Niveau, Limite_de_niveau), est_occupee(est_occupee)
{
    setPixmap(QPixmap(":/images/recolteuse.png").scaled(QSize(50,100)));
    setPos(0,50);
}

int Creature :: GetPV()
{
    return Points_de_vie;
}

int Creature :: GetForce()
{
    return Force;
}

void Creature :: SetPV(int _Points_de_vie)
{
    Points_de_vie = _Points_de_vie;
}

void Creature :: meurs()
{
    Nouritture bouffe;
    bouffe.SetValeur(this->Vie_max);
    //scene()->removeItem(this);
    delete this;
    qDebug() << "Creature supprimee";
}

Creature::~Creature()
{

}

void Ma_Fourmie:: manger(Nouritture bouffe)
{

    this->Points_de_vie+=bouffe.GetValeur();
    if(this->Points_de_vie > this->Vie_max)
        this->Points_de_vie = this->Vie_max;
    delete &bouffe;


}
void Ma_Fourmie :: Attaquer(Creature &cible)
    {
        int difference = cible.GetPV()-this->Force;
        cible.SetPV(difference);
        if (cible.GetPV()<0)
        {
            cible.SetPV(0);

            this->Experience += cible.GetForce();
            if (this->Experience>this->Limite_de_niveau)
            {
                qDebug()<<"LEVEL UP!"<<endl;
                this->Niveau++;
                this->Experience-=this->Limite_de_niveau;
                this->Force+=this->Niveau;
                this->Limite_de_niveau+=5;
                this->Points_de_vie+=6;
            }
            delete &cible;
        }
    }

void Guerriere :: furie()
{
    qDebug()<<"Cette fourmie est furieuse!"<<endl;
    this->Force*=2;
    this->Points_de_vie*=2/3;
}

void Recolteuse :: ramasser(Ressource truc)
{
    if (est_occupee == 1)
        qDebug()<<"Cette fourmie est deja occupee!"<<endl;
    else est_occupee=1;
    while (est_occupee == 1)
    {
        //La position du truc est la meme position que la fourmie
        truc.setPos(this->x(),this->y());
    }
}

void Recolteuse :: deposer(Ressource truc)
{
    if(est_occupee == 0)
        qDebug()<<"Cettefourmie a les mains vides!"<<endl;
    else est_occupee=0;
}


Guerriere::~Guerriere()
{

}

Super_Guerriere::~Super_Guerriere()
{

}

