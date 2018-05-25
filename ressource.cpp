#include "ressource.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>

Ressource :: Ressource(int Valeur, QGraphicsPixmapItem *parent) :
    Valeur(Valeur),
    QObject(),
    QGraphicsPixmapItem(parent)
{}
Nouritture :: Nouritture() : Ressource(Valeur)
{
    setPixmap(QPixmap(":/images/ressource.png").scaled(QSize(100,50)));
}


void Ressource :: SetValeur(int _Valeur){
    Valeur = _Valeur;
}
int Ressource :: GetValeur()
{
    return Valeur;
}
