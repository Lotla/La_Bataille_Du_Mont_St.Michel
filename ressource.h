#ifndef RESSOURCE_H
#define RESSOURCE_H
#include "ressource.h"
#include <QGraphicsPathItem>
class Ressource : public QObject , public QGraphicsPixmapItem
{
    protected:
        int Valeur;
    public:
        Ressource(int _Valeur, QGraphicsPixmapItem *parent=0);
        void SetValeur(int);
        int GetValeur();
};
class Nouritture:public Ressource
{
    public:
        Nouritture();
};

#endif // RESSOURCE_H
